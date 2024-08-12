# AirA01c : Olympus Airのメンテナンスを行うAndroidアプリケーション

-----

- [AirA01c : Olympus Airのメンテナンスを行うAndroidアプリケーション](#aira01c--olympus-airのメンテナンスを行うandroidアプリケーション)
  - [概要](#概要)
    - [機能概要](#機能概要)
    - [操作概要](#操作概要)
    - [インストール](#インストール)
  - [操作説明](#操作説明)
  - [画面遷移](#画面遷移)
    - [「Home」画面](#home画面)
    - [「OLYMPUS AIR設定」画面](#olympus-air設定画面)
    - [「こんな時は？」画面](#こんな時は画面)
  - [その他](#その他)
    - [permissionについて](#permissionについて)
    - [制御対象カメラ](#制御対象カメラ)
    - [ソースコード](#ソースコード)

-----

## 概要

AirA01cは、[OLYMPUS（現OMデジタルソリューションズ）社](https://www.olympus.co.jp/technology/museum/camera/products/digital-opf/aira-01/)製デジタルカメラ、[OLYMPUS AIR A01](https://jp.omsystem.com/cms/record/dslr/a01/index.pdf)に、Wi-Fi経由で接続し、メンテナンスを行うAndroid用アプリケーションです。
[既に公開が終了した、OLYMPUS純正のアプリ](https://digital-faq.jp.omsystem.com/faq/public/app/servlet/qadoc?QID=005801)「[OA. Central](https://www.google.com/search?q=oa.+central+olympus+air+a01)」で実施できた操作を肩代わりすることを目的としており、撮影機能などは持ちません。撮影や画像の転送機能は、[AirA01a](https://github.com/MRSa/GokigenOSDN_documents/tree/main/Applications/AirA01a)や[AirA01b](https://github.com/MRSa/GokigenOSDN_documents/tree/main/Applications/AirA01b)など、別のアプリケーションを利用してください。
また、AirA01cに、[OA. Central](https://www.google.com/search?q=oa.+central+olympus+air+a01)のすべての機能を搭載しているわけではありません。あらかじめご了承ください。

![AirA01cイメージ](https://github.com/MRSa/GokigenOSDN_documents/blob/main/Applications/AirA01c/images/AirA01c-image.JPG?raw=true)

### 機能概要

AirA01cは、以下の機能を持ちます。

- カメラのモード変更
- カメラの状態確認
- 時刻の設定(Androidとの同期)
- カードのフォーマット
- カード内画像の全消去
- ピクセルマッピング
- 水準器の調整（リセット、キャリブレーション）
- 操作の説明

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

-----

## 操作説明

## 画面遷移

AirA01cの画面遷移を以下に示します。起動直後は、「Home」画面を開きます。この画面で、OLYMPUS AIR A01と Wi-Fi接続を行ってください。
接続後、メンテナンス操作は「OLYMPUS AIR設定」画面で操作を行ってください。この他に、操作で困ったときの説明を記載した「こんな時は？」画面があります。

![AirA01c ナビゲーション](https://github.com/MRSa/GokigenOSDN_documents/blob/main/Applications/AirA01c/images/AirA01c-nav.png?raw=true)

### 「Home」画面

![Home 画面](https://github.com/MRSa/GokigenOSDN_documents/blob/main/Applications/AirA01c/images/AirA01c-home.png?raw=true)

### 「OLYMPUS AIR設定」画面

![OLYMPUS AIR設定 画面](https://github.com/MRSa/GokigenOSDN_documents/blob/main/Applications/AirA01c/images/AirA01c-maintenance.png?raw=true)

![OLYMPUS AIRと未接続の場合](https://github.com/MRSa/GokigenOSDN_documents/blob/main/Applications/AirA01c/images/AirA01c-notconnect.png?raw=true)

![メンテナンスコマンド実行](https://github.com/MRSa/GokigenOSDN_documents/blob/main/Applications/AirA01c/images/AirA01c-execute.png?raw=true)

![単体コマンド実行](https://github.com/MRSa/GokigenOSDN_documents/blob/main/Applications/AirA01c/images/AirA01c-command.png?raw=true)

### 「こんな時は？」画面

![Tips画面](https://github.com/MRSa/GokigenOSDN_documents/blob/main/Applications/AirA01c/images/AirA01c-tips.png?raw=true)

-----

## その他

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

### 制御対象カメラ

[**OLYMPUS AIR A01**](https://jp.omsystem.com/cms/record/dslr/a01/index.pdf)

- [「OLYMPUS AIR A01」 は 2018年 3月 31日をもって販売を終了いたしました。](https://digital-faq.jp.omsystem.com/faq/public/app/servlet/relatedqa?QID=005796)
- [主な仕様](https://jp.omsystem.com/cms/record/dslr/a01/spec.pdf)
- [製品外観](https://jp.omsystem.com/cms/record/dslr/a01/design.pdf)
- [Q&A(よくあるお問い合わせ)](https://digital-faq.jp.omsystem.com/faq/public/app/servlet/search?PROD=001005001&MAIN=001)
- [How can we help you with your AIR A01(英語サイト)](https://learnandsupport.getolympus.com/support/air-a01)
- [AIR A01 Instruction Manual(英語)](https://learnandsupport.getolympus.com/sites/default/files/media/files/2018/03/AIR_A01_MANUAL.pdf)

### ソースコード

AirA01c のソースコードは、以下のGitリポジトリから取得可能です。

- [https://github.com/MRSa/AirA01c.git](https://github.com/MRSa/AirA01c.git)
