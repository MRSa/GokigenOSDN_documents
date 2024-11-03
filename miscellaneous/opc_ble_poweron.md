# Olympus Air A01 を Bluetooth LE 経由で電源ONにする （備忘録）

Olympus Air A01 の電源を Bluetooth LE経由で電源をONにする方法 (備忘録)

## 参考にした情報

[Olympus camera kit bluetooth wakeup (stack overflow)](https://stackoverflow.com/questions/39272712)

* [https://stackoverflow.com/questions/39272712](https://stackoverflow.com/questions/39272712)

## 概要

Characteristicへパスコードを送った後、電源ON指示を書き込むことで、電源をONにできます。

OA.Centralでパスコードを設定していないときは、電源ON指示をするだけで、電源をONにできます。

## 書き込み先

**Characteristic UUID** : d15464da-de00-41d4-bec8-7c2b2cc8b2ee (Handle: 0x0012)

## 書き込む内容

### パスコード

「01 01 09 0c 01 02 AA BB CC DD EE FF ss 00」の14バイトを送信します。

AA BB CC DD EE FF は、パスコードとして設定した６文字で、ss は、 0c からパスコード末尾のチェックサムの値を設定します。

例えば、後述の例にあるパスコードが 123456 の場合は、 0x0c + 0x01 + 0x02 + 0x31 + 0x32 + 0x33 + 0x34 + 0x35 + 0x36 = 0x0144 なので、
チェックサムの値は 0x44 となります。

### 電源ON指示

「01 01 04 0f 01 01 02 13 00」の9バイトを送信します。

３バイト目の04が、データのバイト数（続けて４バイトのデータがある）ことを示し、
データの後ろにある 13 がチェックサムバイトだと思われます。。

## 注意点

データ書き込み後、少し待ってから電源ONの指示を送る必要があります。
待たないとエラーになるようです。2.5秒ぐらい待てば大丈夫なようです。

## gatttool を使ってOlympus Airを起動する例

パスコードは 123456 (0x31, 0x32, 0x33, 0x34, 0x35, 0x36) と設定してある場合のコマンド例です。
また、実際に使用する場合は、 xx:xx:xx:xx:xx:xx の部分は、電源をONにするOlympus Air のID に置き換えてください。

````
sudo gatttool -b xx:xx:xx:xx:xx:xx -I
connect
char-write-req 0x0012 0101090c01023132333435364400
char-write-char-write-req 0x0012 0101040f0101021300
exit
````

## AirA01c での処理

このロジックを実装した、AirA01cでの具体的な処理は、 OlympusAirBleCallback.kt を参照してください。

以上