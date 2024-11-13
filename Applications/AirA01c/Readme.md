# AirA01c : OLYMPUS AIR A01のメンテナンスを行うAndroidアプリケーション

-----

- [AirA01c : OLYMPUS AIR A01のメンテナンスを行うAndroidアプリケーション](#aira01c--olympus-air-a01のメンテナンスを行うandroidアプリケーション)
  - [概要](#概要)
    - [機能概要](#機能概要)
    - [操作概要](#操作概要)
    - [インストール](#インストール)
  - [操作説明](#操作説明)
  - [画面遷移](#画面遷移)
    - [「Home」画面](#home画面)
      - [「アプリ起動」ダイアログで起動可能なアプリについて](#アプリ起動ダイアログで起動可能なアプリについて)
      - [「BLUETOOTH」起動ダイアログ](#bluetooth起動ダイアログ)
    - [「OLYMPUS AIR設定」画面](#olympus-air設定画面)
      - [microSDカード](#microsdカード)
      - [水準器調整](#水準器調整)
      - [OLYMPUS AIR設定](#olympus-air設定)
      - [高度](#高度)
        - [単体コマンド 発行ダイアログ](#単体コマンド-発行ダイアログ)
        - [スタンドアロン撮影 設定ダイアログ](#スタンドアロン撮影-設定ダイアログ)
        - [カメラ設定ダイアログ](#カメラ設定ダイアログ)
    - [「こんな時は？」画面](#こんな時は画面)
  - [その他情報](#その他情報)
    - [permissionについて](#permissionについて)
    - [制御対象カメラ(OLYMPUS AIR A01)についての情報](#制御対象カメラolympus-air-a01についての情報)
      - [OLYMPUS AIR A01のBLUETOOTH LE操作情報](#olympus-air-a01のbluetooth-le操作情報)
    - [ソースコード](#ソースコード)

-----

## 概要

AirA01cは、[OLYMPUS（現OMデジタルソリューションズ）社](https://www.olympus.co.jp/technology/museum/camera/products/digital-opf/aira-01/)製デジタルカメラ、[OLYMPUS AIR A01](https://jp.omsystem.com/cms/record/dslr/a01/index.pdf)に、Wi-Fi経由で接続し、メンテナンスを行うAndroid用アプリケーションです。
[既に公開が終了した、OLYMPUS純正のアプリ](https://digital-faq.jp.omsystem.com/faq/public/app/servlet/qadoc?QID=005801)「[OA. Central](https://www.google.com/search?q=oa.+central+olympus+air+a01)」で実施できた操作を肩代わりすることを目的としており、撮影機能などは持ちません。撮影や画像の転送機能は、[AirA01a](https://github.com/MRSa/GokigenOSDN_documents/tree/main/Applications/AirA01a)や[AirA01b](https://github.com/MRSa/GokigenOSDN_documents/tree/main/Applications/AirA01b)など、別のアプリケーションを利用してください。
また、AirA01cに、[OA. Central](https://www.google.com/search?q=oa.+central+olympus+air+a01)のすべての機能を搭載しているわけではありません。あらかじめご了承ください。

![AirA01cイメージ](https://github.com/MRSa/GokigenOSDN_documents/blob/main/Applications/AirA01c/images/AirA01c-image.JPG?raw=true)

### 機能概要

AirA01cは、以下の機能を持ちます。

- Bluetooth LE経由での電源ON
- カメラのモード変更
- カメラの状態確認
- 時刻の設定(Androidとの同期)
- カードのフォーマット
- カード内画像の全消去
- ピクセルマッピング
- 水準器の調整（リセット、キャリブレーション）
- スタンドアローン撮影時の設定（撮影モード、ピクチャーモード、ホワイトバランス、ISO感度等）
- カメラの設定（操作音、スリープまでの時間、レンズリセット、RAW撮影等）
- 操作の説明
- AIR A01用のアプリケーション起動

### 操作概要

AirA01cは、以下のような使用方法を想定しています。

1. AirA01cを起動
2. 『Wi-Fi設定』で、OLYMPUS AIR A01のWiFiを選択し接続
3. 『接続』で、OLYMPUS AIR A01に接続
4. 「OLYMPUS AIR設定」画面に移動し、カードのフォーマットなど、OLYMPUS AIR A01のメンテナンス操作を行う
5. 「Home」画面に戻り、『切断』でOLYMPUS AIR A01と切断し電源OFF、アプリケーションを終了する

### インストール

Google Play で配布しています。アプリケーションを[Google Playよりインストール](https://play.google.com/store/apps/details?id=jp.osdn.gokigen.aira01c)してください。

- [https://play.google.com/store/apps/details?id=jp.osdn.gokigen.aira01c](https://play.google.com/store/apps/details?id=jp.osdn.gokigen.aira01c)

アプリケーションのapkファイルは、[GitHubのリリース](https://github.com/MRSa/AirA01c/releases)にも置いています。Android バージョン4.0 以上に対応しています。
Androidのバージョンが古く、Google Playにアクセスできない場合には、こちらのapkファイルを取得し、インストールをしてみてください。

-----

## 操作説明

## 画面遷移

AirA01cの画面遷移を以下に示します。起動直後は、「Home」画面を開きます。この画面で、OLYMPUS AIR A01と Wi-Fi接続を行ってください。
接続後、メンテナンス操作は「OLYMPUS AIR設定」画面で操作を行ってください。この他に、操作で困ったときの説明を記載した「こんな時は？」画面があります。

![AirA01c ナビゲーション](https://github.com/MRSa/GokigenOSDN_documents/blob/main/Applications/AirA01c/images/AirA01c-nav.png?raw=true)

画面右上の『(i)』ボタンを押すと、AirA01cの操作説明ページ（本ページ）へのリンクを表示します。リンクをタッチすることで、本ページを開くとことができます。

![本ページへのリンク](https://github.com/MRSa/GokigenOSDN_documents/blob/main/Applications/AirA01c/images/AirA01c-credit.png?raw=true)

-----

### 「Home」画面

AirA01cの起動後、Home画面が開きます。Home画面で、OLYMPUS AIR A01と、Wi-Fi接続を行ってください。
『Wi-Fi設定』ボタンを押すと、Androidのネットワーク画面を開きますので、OLYMPUS AIR A01のネットワークを選択し、接続した後、『接続』ボタンで OLYMPUS AIR A01 に接続を行います。
OLYMPUS AIR A01に接続ができると、有効なボタンが変わります。

![Home 画面](https://github.com/MRSa/GokigenOSDN_documents/blob/main/Applications/AirA01c/images/AirA01c-home1.png?raw=true)

以下、ボタン押下時の振る舞いを説明します。

- **接続**
  - 切断時のみ有効です。ボタンを押すと OLYMPUS AIR A01と接続を行います。接続が完了すると、有効なボタンが変わります。
- **切断**
  - 接続時に有効です。ボタンを押すと、OLYMPUS AIR A01の電源を切り、アプリケーションを終了します。
- **Wi-Fi設定**
  - 常時有効です。ボタンを押すと、Androidのネットワーク設定画面を開きます。OLYMPUS AIR A01のWi-Fiと接続する場合に利用してください。
- **アプリ起動**
  - 常時有効です。ボタンを押すと、アプリ起動ダイアログを表示します。起動したいAIR A01用アプリを選択し、 **起動** ボタンを押して、アプリを起動させてください。
- **BLUETOOTH**
  - 常時有効です。ボタンを押すと、BLUETOOTH LE 経由で電源を入れるためのダイアログを表示します。起動したいAIR A01を選択し、起動コードを記入して、**起動** ボタンを押して AIR A01 を起動させてください。
- **モード初期化**
  - 接続時有効です。ボタンを押すと、OLYMPUS AIR A01のモードを初期化（standaloneモードに変更）します。
- **時刻同期**
  - 接続時有効です。ボタンを押すと、Androidの時刻をOLYMPUS AIR A01に設定します。
- **ステータス取得**
  - 接続時有効です。ボタンを押すと、OLYMPUS AIRのステータスを表示します。以下の情報がわかります。
    - メディア状態
    - カード残容量
    - レンズマウント状態
    - 撮像センサの温度状態
    - 装着レンズの焦点距離、電動ズーム駆動の可否、マクロ対応レンズのマクロ状態
    - バッテリー残量
    - ボディ（OLYMPUS AIR A01）および装着レンズのファームウェアバージョン

#### 「アプリ起動」ダイアログで起動可能なアプリについて

![アプリ起動ダイアログ](https://github.com/MRSa/GokigenOSDN_documents/blob/main/Applications/AirA01c/images/AirA01c-launch.png?raw=true)

**アプリ起動** ダイアログから起動できるアプリケーションの一覧を以下に示します。

- [AirA01b](https://play.google.com/store/apps/details?id=jp.osdn.gokigen.aira01b)
- [AirA01a](https://play.google.com/store/apps/details?id=jp.osdn.gokigen.aira01a)
- [A01GR2](https://play.google.com/store/apps/details?id=net.osdn.gokigen.gr2control)
- [A01e](https://play.google.com/store/apps/details?id=jp.osdn.gokigen.mangle)
- [A01DL](https://play.google.com/store/apps/details?id=net.osdn.gokigen.pkremote)
- [A01d](https://play.google.com/store/apps/details?id=net.osdn.gokigen.a01d)
- [OA.ModeDial / YouTube](https://www.youtube.com/watch?v=OGz6UOUWDpA)
- [OA.Viewer / YouTube](https://www.youtube.com/watch?v=IQ9le3FOaNo)
- [OA.ArtFilter / YouTube](https://www.youtube.com/watch?v=9lw7XDN00go)
- [OA.Central / YouTube](https://www.youtube.com/watch?v=eL8h0PKI4QY)
- OA.ColorCreator

#### 「BLUETOOTH」起動ダイアログ

![BLUETOOTHダイアログ](https://github.com/MRSa/GokigenOSDN_documents/blob/main/Applications/AirA01c/images/AirA01c-ble.png?raw=true)

-----

### 「OLYMPUS AIR設定」画面

OLYMPUS AIRのメンテナンス操作を行う画面です。

![OLYMPUS AIR設定 画面](https://github.com/MRSa/GokigenOSDN_documents/blob/main/Applications/AirA01c/images/AirA01c-maintenance.png?raw=true)

各ボタンが、OLYMPUS AIR A01のメンテナンスコマンドですが、OLYMPUS AIR A01に接続していない場合は、最初に接続してくださいと表示し、コマンドは実行しません。

![OLYMPUS AIRと未接続の場合](https://github.com/MRSa/GokigenOSDN_documents/blob/main/Applications/AirA01c/images/AirA01c-notconnect.png?raw=true)

ボタンを押すと、本当に実行してよいか、確認を行います。『OK』を押すと実行が始まりますので、しばらくお待ちください。
実行が終了すると、『CLOSE』ボタンが有効になりますので、ボタンを押してダイアログを閉じてください。
コマンドが失敗する場合も同様な振る舞いを示しますが、通信エラーなど、OLYMPUS AIR A01と動作モードが不整合となる場合がありますので、
その場合は「Home」画面で『モード初期化』を行い、モードを standalone モードに戻してください。

![メンテナンスコマンド実行](https://github.com/MRSa/GokigenOSDN_documents/blob/main/Applications/AirA01c/images/AirA01c-execute.png?raw=true)

AirA01cでは、以下のメンテナンスコマンドが実行可能です。

#### microSDカード

- **フォーマット**
  - microSDカードのフォーマットを行います。実行後は、フォルダ等もすべて消去されます。
- **全消去**
  - microSDカードの画像ファイルをすべて消去します。画像ファイルではないファイルは残ります。

#### 水準器調整

- **水準器リセット**
  - 水準器の原点復帰を行います。
- **水準器キャリブレーション**
  - カメラの現在の姿勢を原点とするよう、水準器を調整します。

#### OLYMPUS AIR設定

- **ピクセルマッピング**
  - 実行すると、ピクセルマッピングを行います。実行時にはレンズを外し、ボディキャップを装着してください。
- **設定初期化**
  - 実行すると、ネットワーク設定等を除くカメラの設定を初期化します。

#### 高度

- **コマンド**
  - OLYMPUS AIR A01に対し、単体のコマンドを発行するダイアログ（単体コマンド 発行ダイアログ）を表示します。

- **スタンドアロン撮影**
  - スタンドアロン撮影時の設定を変更するダイアログ（スタンドアロン撮影 設定ダイアログ）を表示します。

- **その他**
  - カメラの設定を変更するダイアログ（カメラ設定ダイアログ）を表示します。

##### 単体コマンド 発行ダイアログ

AirA01cは、「オープンプラットフォームカメラ通信仕様書 1.0」に基づいて作成しており、この通信仕様書のコマンド群を単独で送ることができます。

![単体コマンド実行](https://github.com/MRSa/GokigenOSDN_documents/blob/main/Applications/AirA01c/images/AirA01c-command.png?raw=true)

ダイアログの上部にある４つのボタンは、カメラの動作モードを変更するボタンです。ワンタッチでモード変更が可能ですので、お試しください。
なお、動作モードの遷移には以下のような制約があり、変更ができない（モード変更エラーとなる）場合がありますので、ご注意ください。

![OLYMPUS AIR A01の動作モード](https://github.com/MRSa/GokigenOSDN_documents/blob/main/Applications/AirA01c/images/OlympusAir-Modes.png?raw=true)

##### スタンドアロン撮影 設定ダイアログ

本ダイアログでは、スタンドアロン撮影で使用する設定項目を変更することができます。
ダイアログを開くと、現在の設定が表示されます。右上の『Refresh』ボタンを押すと、カメラの設定データを再度読み出します。
設定を変更し、画面下部の『設定』ボタンを押すと、カメラに設定を反映させます。『設定』ボタンを押すまで、設定は反映されませんのでご注意ください。

![スタンドアロン撮影 設定ダイアログ](https://github.com/MRSa/GokigenOSDN_documents/blob/main/Applications/AirA01c/images/AirA01c-standalone.png?raw=true)

スタンドアロン撮影 設定ダイアログは、以下の項目が設定できます。

- **撮影モード**
  - iAuto, P, A, S, M, ART, movie, Genius
- **ピクチャーモード**
  - I_FINISH, VIVID, NATURAL, FLAT, Portrait, Monotone, ePortrait, COLOR_CREATOR, POPART, FANTASIC_FOCUS,
  - DAYDREAM, LIGHT_TONE, ROUGH_MONOCHROME, TOY_PHOTO, MINITURE, CROSS_PROCESS,
  - GENTLE_SEPIA, DRAMATIC_TONE, LIGNE_CLAIR, PASTEL, VINTAGE, PARTCOLOR
- **ホワイトバランス**
  - WB_AUTO, MWB_FINE, MWB_SHADE, MWB_CLOUD, MWB_LAMP, MWB_FLUORESCENCE1, MWB_WATER_1, WB_CUSTOM1
- **ISO感度**
  - Auto, Low, 200 ～ 12800
- **アスペクト比**
  - 04_03, 16_09, 03_02, 06_06, 03_04
- **動画画質 (movieモードのみ)**
  - QUALITY_MOVIE_FULL_HD_FINE, QUALITY_MOVIE_FULL_HD_NORMAL, QUALITY_MOVIE_HD_FINE,
  - QUALITY_MOVIE_HD_NORMAL, QUALITY_MOVIE_SHORT_MOVIE
- **絞り値 (A, Mモードのみ)**
  - 1.0 ～ 91
- **シャッター速度 (S, Mモードのみ)**
  - 4" ～ 16000

##### カメラ設定ダイアログ

本ダイアログでは、スタンドアロン撮影で使用する設定項目を変更することができます。
ダイアログを開くと、現在の設定が表示されます。右上の『Refresh』ボタンを押すと、カメラの設定データを再度読み出します。
設定を変更し、画面下部の『登録』ボタンを押すと、カメラに設定を反映させます。『登録』ボタンを押すまで、設定は反映されませんのでご注意ください。

![カメラ設定ダイアログ](https://github.com/MRSa/GokigenOSDN_documents/blob/main/Applications/AirA01c/images/AirA01c-others.png?raw=true)

カメラ設定ダイアログは、以下の項目が設定できます。

- **スリープ時間**
  - 1, 3, 5, 10
- **操作音**
  - OFF, 1, 2, 3, 4, 5
- **レンズリセット**
  - OFF, ON
- **撮影画質**
  - 4608x3456, 3200x2400, 2560x1920, 1920x1440, 1600x1200, 1280x960, 1024x768, 640x480
- **圧縮率**
  - CMP_2_7, CMP_4, CMP_8, CMP_12
- **RAW撮影**
  - OFF, ON

-----

### 「こんな時は？」画面

OLYMPUS AIR A01 操作時に、ちょっと困ったとき、情報を確認できるようにした画面です。各部の名称は、LEDの点滅状態、リセットのやり方などが表示できます。
画面上部にあるタイトル部分は選択できるようになっていますので、知りたい情報を選んで確認してください。

![Tips画面](https://github.com/MRSa/GokigenOSDN_documents/blob/main/Applications/AirA01c/images/AirA01c-tips.png?raw=true)

-----

## その他情報

### permissionについて

AirA01c は、次のパーミッションを指定し使用しています。

- android.permission.INTERNET
  - カメラ(Olympus Air)と無線LAN接続をするため
- android.permission.VIBRATE
  - 一部の操作時に、バイブレーションでフィードバックを伝えるため
- android.permission.ACCESS_NETWORK_STATE
  - カメラ(Olympus Air)と無線LAN接続をするため
- android.permission.ACCESS_WIFI_STATE
  - カメラ(Olympus Air)と無線LAN接続をするため
- android.permission.ACCESS_MEDIA_LOCATION
  - 現在未使用 (撮影画像から位置情報を取得するため、ベースとしたアプリから消し忘れた権限でした...すみません)

### 制御対象カメラ(OLYMPUS AIR A01)についての情報

[**OLYMPUS AIR A01**](https://jp.omsystem.com/cms/record/dslr/a01/index.pdf) の関連リンクです。

- [アプリで楽しむ一眼画質、オープンプラットフォームカメラ「OLYMPUS AIR（エアー）A01」を発売 (2015年2月5日)](https://www.olympus.co.jp/jp/news/2015a/nr150205opcj.html)
- [「OLYMPUS AIR A01」 は 2018年 3月 31日をもって販売を終了いたしました。](https://digital-faq.jp.omsystem.com/faq/public/app/servlet/relatedqa?QID=005796)
- [主な仕様](https://jp.omsystem.com/cms/record/dslr/a01/spec.pdf)
- [製品外観](https://jp.omsystem.com/cms/record/dslr/a01/design.pdf)
- [Q&A(よくあるお問い合わせ)](https://digital-faq.jp.omsystem.com/faq/public/app/servlet/search?PROD=001005001&MAIN=001)
- [How can we help you with your AIR A01(英語サイト)](https://learnandsupport.getolympus.com/support/air-a01)
- [AIR A01 Instruction Manual(英語)](https://learnandsupport.getolympus.com/sites/default/files/media/files/2018/03/AIR_A01_MANUAL.pdf)
- [OlympusCameraKit(英語, Wayback Machine経由)](https://web.archive.org/web/20210204200324/https://dl-support.olympus-imaging.com/opc/files/en/OlympusCameraKit_EN.zip)
- [OPC Communication Protocol(英語, Wayback Machine経由)](https://web.archive.org/web/20210325165614/https://dl-support.olympus-imaging.com/opc/files/en/OPC_Communication_Protocol_EN.zip)

#### OLYMPUS AIR A01のBLUETOOTH LE操作情報

- [Olympus Air A01 を Bluetooth LE 経由で電源ONにする （備忘録）](https://github.com/MRSa/GokigenOSDN_documents/blob/main/miscellaneous/opc_ble_poweron.md)

### ソースコード

AirA01c のソースコードは、以下のGitリポジトリから取得可能です。

- [https://github.com/MRSa/AirA01c.git](https://github.com/MRSa/AirA01c.git)

本アプリケーションは、「オープンプラットフォームカメラ通信仕様書 1.0」および独自調査に基づいて実装しており、Olympus Camera Kitには依存しておりません。
