# OLYMPUS AIR A01 カメラプロパティ（基本）

| 分類 | 項目 | プロパティ(KEY) | 補足 | Wi-Fi | BLE | iAuto | P | A | S | M | ART | movieP | movieA | movieS | movieM | 備考 |
| :----: | :----: | :----: | :----: | :----: | :----: | :----: | :----: | :----: | :----: | :----: | :----: | :----: | :----: | :----: | :----: | :----: |
| 基本設定 | 絞り値（F値） | APERTURE | 範囲: F1.0～F91 | RW | RW | - | - | OK | - | OK | - | - | OK | - | OK | - |
| ^ | 測光方式 | AE | 中央重点/デジタルESP/指定位置 | RW | RW | - | OK | OK | OK | OK | OK | - | - | - | - | - |
| ^ | 撮影モード | TAKEMODE | movieの撮影モードは動画撮影モードで設定 | RW | RW | OK | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | ISO感度 | ISO | Low～12800 | RW | RW | - | OK | OK | OK | OK | OK | - | - | - | - | - |
| ^ | 露出補正値 | EXXPREV | 範囲:-5.0～+5.0 | RW | RW | - | OK | OK | OK | - | OK | OK | OK | OK | - | - |
| ^ | ドライブモード | TAKE_DRIVE | 1コマ(NORMAL)/連写(CONTINUE) | RW | RW | OK | OK | OK | OK | OK | OK | - | - | - | - | - |
| ^ | アスペクト比 | ASPECT_RATIO | 4:3 / 3:2 / 16:9 / 3:4 / 6:6(1:1) | RW | RW | OK | OK | OK | OK | OK | OK | - | - | - | - | - |
| ^ | シャッター速度 | SHUTTER | 範囲: 4" ～ 16000 | RW | RW | - | - | - | OK | OK | - | - | - | OK | OK | - |
| ^ | 連写速度 | CONTINUOUS_SHOOTING_VELOCITY | 範囲: 1fps ～10fps | RW | RW | OK | OK | OK | OK | OK | OK | - | - | - | - | - |
| ^ | 動画撮影モード | EXPOSE_MOVIE_SELECT | P / A / S / M | RW | RW | - | - | - | - | - | - | OK | OK | OK | OK | - |
| ^ | 露出固定（AEロック） | AE_LOCK_STATE | LOCK / UNLOCK | RW | RW | OK | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| 画質・画像保存 | 静止画サイズ | IMAGESIZE | 4608x3456 ～ 640x480 | RW | RW | OK | OK | OK | OK | OK | OK | - | - | - | - | - |
| ^ | RAW設定 | RAW | OFF / ON | RW | RW | OK | OK | OK | OK | OK | OK | - | - | - | - | - |
| ^ | 圧縮率 | COMPRESSIBILITY_RATIO | CMP_2_7(Super Fine) / CMP_4 (Fine) / CMP_8(Normal) / CMP_12(Basic) | RW | RW | OK | OK | OK | OK | OK | OK | - | - | - | - | - |
| ^ | 動画画質モード | QUALITY_MOVIE | FHD FINE / FHD NORMAL / HD FINE / HD NORMAL / SHORT MOVIE | RW | RW | - | - | - | - | - | - | OK | OK | OK | OK | - |
| ^ | 撮影画像保存先 | DESTINATION_FILE | MEDIA / WIFI(単写時のみ有効) | RW | RW | OK | OK | OK | OK | OK | OK | - | - | - | - | - |
| ^ | クリップ記録時間 | QUALITY_MOVIE_SHORT_MOVIE_RECORD_TIME | 範囲: 1～8 | RW | RW | - | - | - | - | - | - | OK | OK | OK | OK | - |
| フォーカス | フォーカスモード 静止画用 | FOCUS_STILL | MF / SAF | RW | RW | OK | OK | OK | OK | OK | OK | - | - | - | - | - |
| ^ | フォーカス固定(AFロック) | AF_LOCK_STATE | LOCK / UNLOCK | RW | RW | OK | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | フルタイムAF | FULL_TIME_AF | OFF / ON | RW | RW | OK | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | フォーカスモード 動画用 | FOCUS_MOVIE | MF / SAF / CAF | RW | RW | - | - | - | - | - | - | OK | OK | OK | OK | - |
| 撮影補助 | 顔検出 | FACE_SCAN | OFF / ON / NEAR | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | IS焦点距離 | ANTI_SHAKE_FOCAL_LENGTH | 範囲: 8 ～ 1000 | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | タッチAF可能範囲（左上座標） | TOUCH_EFFECTIVE_AREA_UPPER_LEFT | - | RO | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | タッチAF可能範囲（右下座標） | TOUCH_EFFECTIVE_AREA_LOWER_RIGHT | - | RO | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | 撮影確認画像 | RECVIEW | OFF / ON | RW | RW | OK | OK | OK | OK | OK | OK | - | - | - | - | - |
| ^ | タッチAE可能範囲（左上座標） | TOUCH_AE_EFFECTIVE_AREA_UPPER_LEFT | - | RO | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | タッチAE可能範囲（右下座標） | TOUCH_AE_EFFECTIVE_AREA_LOWER_RIGHT | - | RO | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | レンズ手振れ補正優先 | LENS_PRIORITY_ANTI_SHAKE | OFF / ON | RW | RW | OK | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | 動画手ぶれ補正 | ANTI_SHAKE_MOVIE | OFF / ON | RW | RW | OK | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| そのほか | バッテリーレベル | BATTERY_LEVEL | LOW / FULL  | RO | RO | OK | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | 音量レベル | SOUND_VOLUME_LEVEL | OFF / 1 / 2 / 3 / 4 / 5 | RW | RW | OK | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | Wi-Fi SSID | SSID | (SSID) | RO | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | Exif位置付与設定 | GPS | OFF / ON | RW | RW | OK | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | Wi-Fiチャンネル | WIFI_CH | 範囲: AUTO / 1 ～ 11 | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
