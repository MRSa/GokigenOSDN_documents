# その他のプロジェクト

-----

## [BME688を使用して、においを検出する](https://github.com/MRSa/SamplingBME688Serial)

匂いを判別するために、[BME688](https://www.bosch-sensortec.com/products/environmental-sensors/gas-sensors/bme688/)をATOM Liteにつないで、さらにWindowsマシンにUSBで接続し、データベースに蓄積、機械学習をして匂いを判別するためのアプリ一式です。

![においの検出](https://raw.githubusercontent.com/MRSa/SamplingBME688Serial/master/images/Overview2.png)

-----

## [PiZeroDockerForSensors : Raspberry Pi Zero で Docker & センサデータの収集](https://github.com/MRSa/PiZeroDockerForSensors)

Raspberry Pi Zero に Dockerを載せて、コンテナを３つ（Redis, Grafana, Python）立ち上げ、I2Cで接続した(BME688の)センサーからデータを5分ごとに収集してRedisに時系列データとして蓄積し、Grafanaを使ってグラフ表示できるようにしたものです。

![概要図](https://raw.githubusercontent.com/MRSa/PiZeroDockerForSensors/main/pics/pizero.jpg)

-----

## [桃太郎からの挑戦状](../Okaken/Readme.md)

岡山に関係する４択問題を出題するクイズゲームです。

* [紹介ムービー(mp4, 47秒)](../Okaken/AChallengeFromMOMOTARO.mp4)
* [ソースコード](https://github.com/MRSa/gokigen/tree/master/osdn-cvs/Okaken)

-----

## 映像で遊ぼう

* [プロジェクションマッピング実施例](Pjmap_ProjectionMapping1.wmv)

以上
