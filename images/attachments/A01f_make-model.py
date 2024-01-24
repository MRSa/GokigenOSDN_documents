######   TFLite Model Maker   ######
###### https://github.com/tensorflow/examples/tree/master/tensorflow_examples/lite/model_maker
import numpy as np
import os
import glob
import pathlib

from tflite_model_maker.config import QuantizationConfig
from tflite_model_maker.config import ExportFormat
from tflite_model_maker import model_spec
from tflite_model_maker import object_detector

import tensorflow as tf
assert tf.__version__.startswith('2')

tf.get_logger().setLevel('ERROR')
from absl import logging
logging.set_verbosity(logging.ERROR)


# TUTORIAL : Object Detection with TensorFlow Lite Model Maker
#   https://www.tensorflow.org/lite/tutorials/model_maker_object_detection

#####  Path to images with Pascal VOC annotation  #####
annotations_path = '(full path to a images-annotation directory)' 
validations_path = '(full path to a images-validation directory)'
tests_path = '(full path to a images-test directory)'

# ----- size: 4.4MB, latency: 37ms
spec = model_spec.get('efficientdet_lite0')
# ----- size: 5.8MB, latency: 49ms
#spec = model_spec.get('efficientdet_lite1')
# ----- size: 7.2MB, latency: 69ms
#spec = model_spec.get('efficientdet_lite2')
# ----- size: 11.4MB, latency: 116ms
#spec = model_spec.get('efficientdet_lite3')
# ----- size: 19.9MB, latency: 260ms
#spec = model_spec.get('efficientdet_lite4')


targetFileList = glob.glob(annotations_path + "*.xml")
validationFileList = glob.glob(validations_path + "*.xml")
testFileList = glob.glob(tests_path + "*.xml")

listAnnotationXml = []
for annotationFile in targetFileList:
    listAnnotationXml.append(os.path.basename(annotationFile).split('.', 1)[0])

listValidationXml = []
for validationFile in validationFileList:
    listValidationXml.append(os.path.basename(validationFile).split('.', 1)[0])

listTestXml = []
for testFile in testFileList:
    listTestXml.append(os.path.basename(testFile).split('.', 1)[0])


train_data = object_detector.DataLoader.from_pascal_voc(annotations_path, annotations_path, label_map={1: "aoi"}, annotation_filenames = listAnnotationXml)
validation_data = object_detector.DataLoader.from_pascal_voc(validations_path, validations_path, label_map={1: "aoi"}, annotation_filenames = listValidationXml)
test_data = object_detector.DataLoader.from_pascal_voc(tests_path, tests_path, label_map={1: "aoi"}, annotation_filenames = listTestXml)

print("----- data read -----")

model = object_detector.create(train_data, model_spec=spec, batch_size=8, train_whole_model=True, validation_data=validation_data)

print(" ----- model created -----")

model.evaluate(test_data)

print(" ----- test finished -----")

model.export(export_dir='.')

print(" ----- model exported -----")

model.evaluate_tflite('model.tflite', test_data)

print(" ----- model evaluated -----")
