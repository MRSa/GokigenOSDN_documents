# QSteerControl

QSteerControlは、[チョロQハイブリッド！](http://ja.wikipedia.org/wiki/%E3%83%81%E3%83%A7%E3%83%ADQ%E3%83%8F%E3%82%A4%E3%83%96%E3%83%AA%E3%83%83%E3%83%89!) や [Qステア](http://ja.wikipedia.org/wiki/Q%E3%82%B9%E3%83%86%E3%82%A2)を制御するための Android ADK + Android(3.1以上)のアプリケーションです。[EDASH](http://www.takaratomy.co.jp/products/edash/) でも動きました。）
OpenCVを使用し、マニュアル操作だけではなくて、何か面白い事ができないかと、考えています。（とりあえず、カメラの前にチョロQを置くと認識して動作指示を出すところまでを作りました。）

![作品イメージ](../../images/attachments/QsteerControl_ChoroQ.jpg "作品イメージ")

## 概要

### 今できること

* **チョロQの２台同時制御（バンドA と バンドB）**
  A, B同時に同一コマンドを発行、Aは左回転, Bは右回転(Publish Only Turn Commandにチェックした時)
  画面右側の画像の上をタッチしスライドさせることでAndroid端末からコマンド発行
* **カメラによる物体認識**
  画面左側の画像をタッチしたときからの差分を確認し、物体が置かれたかどうかを認識する。
* **チョロQの認識(１台)と自動運転**
  物体認識時にチョロQの動作コマンドを２台分同時発行。物体が消えた時に動作コマンドを停止する。
  Aは左回転, Bは右回転のコマンドを発行（Auto pilot Modeにチェックした時）

### スクリーンショット

![起動直後](../../images/attachments/QsteerControl_Proto2.png "起動直後")
![物体認識](../../images/attachments/QsteerControl_Proto1.png "物体認識")

### 紹介ムービー

[プロトタイプの説明(30秒, wmv)](../../images/attachments/QsteerControl_QSteerControl.wmv "プロトタイプの説明(30秒, wmv)")

### 使用部品

* Andriod端末 (3.1以上)
* Qステア or チョロQハイブリッド！（リモコンタイプ）
* [Arduino MEGA ADK](http://arduino.cc/en/Main/ArduinoBoardADK)（ [スイッチサイエンス](http://www.switch-science.com/products/detail.php?product_id=680)さんから入手しました。）
* 赤外LED （[【SID 313BP】5mm汎用・リモコン用赤外LED @マルツパーツ館さん](http://www.marutsu.co.jp/shohin_49755/) を使いました。）

### ADKの準備

**D12** と **GND** に赤外LEDを差し込む（足の長い方をD12、足の短い方をGNDに差し込む）スタイルで使いました。
（Arduino MEGA ADKではD13にLEDが乗っているので、別の用途に使えるよう一つ飛ばしたところの **D12** を使いました。）

![Arduino MEGA ADK + IR LED](../../images/attachments/QsteerControl_ARDUINO_MEGA_ADK.jpg "Arduino MEGA ADK + IR LED")

```comment
（とりあえずのメモ）
 * Android端末 (3.1以上)
 * Qステア or チョロQハイブリッド！
 * 赤外LED
 * 普通のLED（１個）
 * ブレッドボード
 * スイッチ(２個)
 * 抵抗少々
 * ジャンパ線少々
 * USBケーブル
```

スケッチ[qsteercontrol2.pde](https://github.com/MRSa/gokigen/blob/master/osdn-cvs/QSteerController/assets/qsteercontrol2.pde) をコンパイルし、ADKにアップロードしました。
（問題がなければ、電源を入れるとボード上のLEDが点滅するはずです。）

## ソースコード

ソースコードは本プロジェクトのSVN および CVSに格納しています。ご自由に参照・ご利用ください。
まだADK側スケッチは、1.0にバージョンアップしていませんので、.pdeです。。。
また、Android側アプリは、OpenCV(2.4.0正式版)のライブラリを抱え込んでいるため、サイズはかなり大きいです。。

### ADK側(スケッチ)

#### お手軽版

  もう単純に、赤外LEDだけ（ **D12** と **GND** のソケットに赤外LEDを指すだけ）にしてハードウェアは簡単にした版です。ボード上に実装されている **D13** も点滅させています。

* [qsteercontrol2.pde](https://github.com/MRSa/gokigen/blob/master/osdn-cvs/QSteerController/assets/qsteercontrol2.pde)

#### 通常版

  動作確認をしながらすすめるためにブレッドボード上にタクトスイッチを２個、通常のLEDを１個、そして赤外LEDを１個搭載した版です。
  （タクトスイッチは D10 と **D12**、通常のLEDは **D4**、赤外LEDは **D2** に接続しています。）

* [QSteerControl.pde](https://github.com/MRSa/gokigen/blob/master/osdn-svn/Arduino/QSteerControl/QSteerControl.pde)

#### Android側アプリ

* [ソースリポジトリ](https://github.com/MRSa/gokigen/tree/master/osdn-cvs/QSteerController)

## その他

ネットで公開されているチョロQを制御する先行事例には、大変お世話になりました。ありがとうございます。
特に次のページについては、そのまんま参考とさせて頂きました。本当にありがとうございます。

* [Q-STEER赤外線信号解析](http://homepage2.nifty.com/stear/doc/QSir.htm)
* [ArduinoからQSTEERを操作してみた。](http://d.hatena.ne.jp/o2mana/20091122/1258912540)
