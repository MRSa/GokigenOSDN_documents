IRrecvDumpV3.ino.diff
  → IRRemoteESP8266のサンプルプログラムである IRrecvDumpV3 を  SSD1306というOLEDディスプレイに結果を表示させるようにしたもの。
    unified diff形式で、オリジナルの IRrecvDumpV3.ino にパッチコマンドで適用する。

pass_through_serial.ino
    → PC側のUSB シリアル通信(Serial)を、M5側のUARTポート(Serial2)に中継するスケッチ。
       Windows用アプリケーションで、デバイスの設定変更等をUART経由で行いたいときに使用した。

check_internal_imu.ino
    → M5の内蔵IMUの動作を確認するために使用したスケッチ。単純にセンサからの値を画面とシリアルに出力するだけ。
