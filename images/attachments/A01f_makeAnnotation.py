#  makeAnnotation.py : make pascal VOC annotation 

import os
import glob
import object_detector as od
import cv2

## TensorFlow Lite Object Detection Model
#TFLITE_MODEL_FILE = '/home/pi/tflite/models/efficientdet_lite0.tflite'
TFLITE_MODEL_FILE = '/home/pi/tflite/models/aoi-model0-1.tflite'

## 読み込む画像ファイルの場所
pictureDir = '/home/pi/Pictures/'
## アノテーションを行った結果を出力する場所
targetDir = '/home/pi/Pictures/result'

## アノテーションファイルを出力する
def outputAnnotationFile(imageFile, annotationFile, width, height, depth, detection):
    #print("    image size: " + str(width) + 'x' + str(height) + ' ' + str(depth) + ' ' + annotationFile + ' (' + imageFile + ')' )
    detect_label = detection.categories[0].label
    box_width = abs(detection.bounding_box.left - detection.bounding_box.right)
    box_height = abs(detection.bounding_box.top - detection.bounding_box.bottom)
    print('  ' + os.path.basename(imageFile) + '  ' + detection.categories[0].label + ' ' + str(width) + 'x' + str(height) + ' position : (' + str(detection.bounding_box.left) + ',' +  str(detection.bounding_box.top) + ') - (' + str(detection.bounding_box.right) + ',' +  str(detection.bounding_box.bottom) + ')' + '  size : (' + str(box_width) + ',' + str(box_height) + ')'+ ' ' + str(detection.categories[0].score))
    with open(targetDir + '/' + annotationFile, 'w') as file:
        print('<annotation>', file=file)
        print('<folder>aoi</folder>', file=file)
        print("<filename>{}</filename>".format(os.path.basename(imageFile)), file=file)
        print("<path>{}</path>".format(os.path.basename(imageFile)), file=file)
        print('<source>', file=file)
        print('	<database>Unknown</database>', file=file)
        print('</source>', file=file)
        print('<size>', file=file)
        print('	<width>{}</width>'.format(str(width)), file=file)
        print('	<height>{}</height>'.format(str(height)), file=file)
        print("	<depth>{}</depth>".format(str(depth)), file=file)
        print('</size>', file=file)
        print('<segmented>0</segmented>', file=file)
        print('<object>', file=file)
        print('	<name>{}</name>'.format(detect_label), file=file)
        print('	<pose>Unspecified</pose>', file=file)
        print('	<truncated>0</truncated>', file=file)
        print('	<difficult>0</difficult>', file=file)
        print('	<bndbox>', file=file)
        print('		<xmin>{}</xmin>'.format(str(detection.bounding_box.left)), file=file)
        print('		<ymin>{}</ymin>'.format(str(detection.bounding_box.top)), file=file)
        print('		<xmax>{}</xmax>'.format(str(detection.bounding_box.right)), file=file)
        print('		<ymax>{}</ymax>'.format(str(detection.bounding_box.bottom)), file=file)
        print('	</bndbox>', file=file)
        print('</object>', file=file)
        print('</annotation>', file=file)

## 結果を格納するディレクトリがなければ、作成する
if not os.path.exists(targetDir):
    os.makedirs(targetDir)

## get target picture file List
targetFileList = glob.glob(pictureDir + "*.[Jj][Pp][Gg]")

detector = od.ObjectDetector(TFLITE_MODEL_FILE)

for targetFile in targetFileList:
    annotationFile = (os.path.basename(targetFile).split('.', 1)[0] + ".xml").lower()
    image = cv2.imread(targetFile)
    result = detector.detect(image)
    for detection in result:
      if detection.categories[0].score > 0.6:
          outputAnnotationFile(targetFile, annotationFile, image.shape[1], image.shape[0], image.shape[2], detection)
          break
