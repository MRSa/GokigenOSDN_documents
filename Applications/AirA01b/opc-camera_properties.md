# OLYMPUS AIR A01 カメラプロパティ

- [OLYMPUS AIR A01 カメラプロパティ](#olympus-air-a01-カメラプロパティ)
  - [基本](#基本)
  - [アートフィルター関連](#アートフィルター関連)
  - [仕上がり・ピクチャーモード関連](#仕上がりピクチャーモード関連)
  - [ホワイトバランス](#ホワイトバランス)

----

## 基本

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

----

## アートフィルター関連

OLYMPUS AIR A01のアートフィルター関連の設定は、[OLYMPUS PEN E-PL8](https://download.omsystem.com/pages/inst/epl8/manual_epl8_JPN.pdf) や [OLYMPUS PEN-F](https://download.omsystem.com/pages/inst/penf/manual_penf_JPN.pdf) と同等のようです。
[E-PL8の取扱説明書](https://download.omsystem.com/pages/inst/epl8/manual_epl8_JPN.pdf) や [OLYMPUS PEN-F](https://download.omsystem.com/pages/inst/penf/manual_penf_JPN.pdf) も参照してください。

| 分類 | 項目 | プロパティ値 | 補足 | Wi-Fi | BLE | iAuto | P | A | S | M | ART | movieP | movieA | movieS | movieM | 備考 |
| :----: | :----: | :----: | :----: | :----: | :----: | :----: | :----: | :----: | :----: | :----: | :----: | :----: | :----: | :----: | :----: | :----: |
| アートフィルター | アートフィルター　種別 | RECENTLY_ART_FILTER | POPART, FANTASIC_FOCUS, DAYDREAM, LIGHT_TONE, ROUGH_MONOCHROME, TOY_PHOTO, MINIATURE, CROSS_PROCESS, GENTLE_SEPIA, DRAMATIC_TONE, LIGNE_CLAIR, PASTEL, VINTAGE, PARTCOLOR | RW | RW | - | - |- | - | - | OK | - | - | - | - | - |
| パートカラー用 | パートカラー用　色相 | COLOR_PHASE | 色相パターン:0～17 | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| アートフィルター バリエーション | アートフィルター　バリエーション ポップアート | ART_EFFECT_TYPE_POPART | TYPE_I, TYPE_II | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | アートフィルター　バリエーション デイドリーム | ART_EFFECT_TYPE_DAYDREAM | TYPE_I, TYPE_II | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | アートフィルター　バリエーション ラフモノクローム | ART_EFFECT_TYPE_ROUGH_MONOCHROME | TYPE_I, TYPE_II | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | アートフィルター　バリエーション トイフォト | ART_EFFECT_TYPE_TOY_PHOTO | TYPE_I, TYPE_II, TYPE_III | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | アートフィルター　バリエーション ジオラマ | ART_EFFECT_TYPE_MINIATURE | TYPE_I, TYPE_II | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | アートフィルター　バリエーション クロスプロセス | ART_EFFECT_TYPE_CROSS_PROCESS | TYPE_I, TYPE_II | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | アートフィルター　バリエーション ドラマチックトーン | ART_EFFECT_TYPE_DRAMATIC_TONE | TYPE_I, TYPE_II | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | アートフィルター　バリエーション リーニュ　クレール | ART_EFFECT_TYPE_LIGNE_CLAIR | TYPE_I, TYPE_II | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | アートフィルター　バリエーション ウォーターカラー  | ART_EFFECT_TYPE_PASTEL | TYPE_I, TYPE_II | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | アートフィルター　バリエーション ヴィンテージ | ART_EFFECT_TYPE_VINTAGE | TYPE_I, TYPE_II, TYPE_III | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | アートフィルター　バリエーション パートカラー |  ART_EFFECT_TYPE_PARTCOLOR | TYPE_I, TYPE_II, TYPE_III | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| アートエフェクト | アートエフェクト ポップアート | ART_EFFECT_HYBRID_POPART | OFF, FANTASIC_FOCUS, TOY_PHOTO, WHITE_EDGE, FRAME_JAGGY, STARLIGHT, MINIATURE_VERTICAL, MINIATURE_HORIZON | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | アートエフェクト ファンタジックフォーカス | ART_EFFECT_HYBRID_FANTASIC_FOCUS | OFF, WHITE_EDGE, STARLIGHT | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | アートエフェクト デイドリーム | ART_EFFECT_HYBRID_DAYDREAM | OFF, FANTASIC_FOCUS, TOY_PHOTO, WHITE_EDGE, FRAME_JAGGY, STARLIGHT, MINIATURE_VERTICAL, MINIATURE_HORIZON | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | アートエフェクト ライトトーン  | ART_EFFECT_HYBRID_LIGHT_TONE | OFF, FRAME_JAGGY, MINIATURE_VERTICAL, MINIATURE_HORIZON | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | アートエフェクト ラフモノクローム | ART_EFFECT_HYBRID_ROUGH_MONOCHROME | OFF, TOY_PHOTO, WHITE_EDGE, FRAME_JAGGY | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | アートエフェクト トイフォト | ART_EFFECT_HYBRID_TOY_PHOTO | OFF, FRAME_JAGGY | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | アートエフェクト ジオラマ | ART_EFFECT_HYBRID_MINIATURE | OFF, FRAME_JAGGY | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | アートエフェクト クロスプロセス | ART_EFFECT_HYBRID_CROSS_PROCESS | OFF, FANTASIC_FOCUS, TOY_PHOTO, WHITE_EDGE, FRAME_JAGGY, MINIATURE_VERTICAL, MINIATURE_HORIZON | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | アートエフェクト ジェントルセピア | ART_EFFECT_HYBRID_GENTLE_SEPIA | OFF, FANTASIC_FOCUS, TOY_PHOTO, WHITE_EDGE, FRAME_JAGGY, MINIATURE_VERTICAL, MINIATURE_HORIZON | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | アートエフェクト ドラマチックトーン | ART_EFFECT_HYBRID_DRAMATIC_TONE | OFF, TOY_PHOTO, WHITE_EDGE, FRAME_JAGGY, STARLIGHT, MINIATURE_VERTICAL, MINIATURE_HORIZON | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | アートエフェクト リーニュ　クレール | ART_EFFECT_HYBRID_LIGNE_CLAIR | OFF, FANTASIC_FOCUS, TOY_PHOTO, WHITE_EDGE, FRAME_JAGGY, STARLIGHT | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | アートエフェクト ウォーターカラー | ART_EFFECT_HYBRID_PASTEL | OFF, FANTASIC_FOCUS, TOY_PHOTO, WHITE_EDGE, FRAME_JAGGY | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | アートエフェクト ヴィンテージ | ART_EFFECT_HYBRID_VINTAGE | OFF, FANTASIC_FOCUS, TOY_PHOTO, WHITE_EDGE, FRAME_JAGGY, STARLIGHT, MINIATURE_VERTICAL, MINIATURE_HORIZON, SHADING_VERTICAL, SHADING_HORIZON | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | アートエフェクト パートカラー | ART_EFFECT_HYBRID_PARTCOLOR | OFF, FANTASIC_FOCUS, TOY_PHOTO, WHITE_EDGE, FRAME_JAGGY, STARLIGHT, MINIATURE_VERTICAL, MINIATURE_HORIZON | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| アートフィルター ブラケット撮影 | アートフィルター　ブラケット撮影 ポップアートフィルターの使用 | BRACKET_PICT_POPART | ON, OFF | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | アートフィルター　ブラケット撮影 ファンタジックフォーカスフィルターの使用 | BRACKET_PICT_FANTASIC_FOCUS | ON, OFF | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | アートフィルター　ブラケット撮影 デイドリームフィルターの使用 | BRACKET_PICT_DAYDREAM | ON, OFF | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | アートフィルター　ブラケット撮影 ライトトーンフィルターの使用 | BRACKET_PICT_LIGHT_TONE | ON, OFF | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | アートフィルター　ブラケット撮影 ラフモノクロームフィルターの使用 | BRACKET_PICT_ROUGH_MONOCHROME | ON, OFF | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | アートフィルター　ブラケット撮影 トイフォトフィルターの使用 | BRACKET_PICT_TOY_PHOTO | ON, OFF | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | アートフィルター　ブラケット撮影 ジオラマフィルターの使用 | BRACKET_PICT_MINIATURE | ON, OFF | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | アートフィルター　ブラケット撮影 クロスプロセスフィルターの使用 | BRACKET_PICT_CROSS_PROCESS | ON, OFF | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | アートフィルター　ブラケット撮影 ジェントルセピアフィルターの使用 | BRACKET_PICT_GENTLE_SEPIA | ON, OFF | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | アートフィルター　ブラケット撮影 ドラマチックトーンフィルターの使用 | BRACKET_PICT_DRAMATIC_TONE | ON, OFF | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | アートフィルター　ブラケット撮影 リーニュ　クレールフィルターの使用 | BRACKET_PICT_LIGNE_CLAIR | ON, OFF | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | アートフィルター　ブラケット撮影 ウォーターカラーフィルターの使用 | BRACKET_PICT_PASTEL | ON, OFF | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | アートフィルター　ブラケット撮影 ヴィンテージフィルターの使用 | BRACKET_PICT_VINTAGE | ON, OFF | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | アートフィルター　ブラケット撮影 パートカラーフィルターの使用 | BRACKET_PICT_PARTCOLOR | ON, OFF | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |

----

## 仕上がり・ピクチャーモード関連

OLYMPUS AIR A01のピクチャーモード関連の設定も、[OLYMPUS PEN E-PL8](https://download.omsystem.com/pages/inst/epl8/manual_epl8_JPN.pdf) や [OLYMPUS PEN-F](https://download.omsystem.com/pages/inst/penf/manual_penf_JPN.pdf) と同等のようです。
アートフィルター同様、[E-PL8の取扱説明書](https://download.omsystem.com/pages/inst/epl8/manual_epl8_JPN.pdf) や [OLYMPUS PEN-F](https://download.omsystem.com/pages/inst/penf/manual_penf_JPN.pdf) も合わせて参照してください。

| 分類 | 項目 | プロパティ値 | 補足 | Wi-Fi | BLE | iAuto | P | A | S | M | ART | movieP | movieA | movieS | movieM | 備考 |
| :----: | :----: | :----: | :----: | :----: | :----: | :----: | :----: | :----: | :----: | :----: | :----: | :----: | :----: | :----: | :----: | :----: |
| ピクチャーモード | 仕上がり・ピクチャーモード | COLORTONE | FLAT, NATURAL, Monotone, Portrait, I_FINISH, VIVID, ePortrait, COLOR_CREATOR, … | RW | RW | - | OK | OK | OK | OK | - | OK | OK | OK | OK | - |
| ^ | ピクチャーモードの仕上がり設定 (コントラスト/i-Finish) | CONTRAST_I_FINISH | -2, -1, 0, +1, +2 | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | ピクチャーモードの仕上がり設定 (コントラスト/Vivid) | CONTRAST_VIVID | -2, -1, 0, +1, +2 | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | ピクチャーモードの仕上がり設定 (コントラスト/NATURAL) | CONTRAST_NATURAL | -2, -1, 0, +1, +2 | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | ピクチャーモードの仕上がり設定 (コントラスト/FLAT) | CONTRAST_FLAT | -2, -1, 0, +1, +2 | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | ピクチャーモードの仕上がり設定 (コントラスト/Portrait) | CONTRAST_SOFT | -2, -1, 0, +1, +2 | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | ピクチャーモードの仕上がり設定 (コントラスト/モノトーン) | CONTRAST_MONOCHROME | -2, -1, 0, +1, +2 | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | ピクチャーモードの仕上がり設定 (シャープネス/i-Finish) | SHARP_I_FINISH | -2, -1, 0, +1, +2 | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | ピクチャーモードの仕上がり設定 (シャープネス/Vivid) | SHARP_VIVID | -2, -1, 0, +1, +2 | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | ピクチャーモードの仕上がり設定 (シャープネス/NATURAL) | SHARP_NATURAL | -2, -1, 0, +1, +2 | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | ピクチャーモードの仕上がり設定 (シャープネス/FLAT) | SHARP_FLAT | -2, -1, 0, +1, +2 | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | ピクチャーモードの仕上がり設定 (シャープネス/Portrait) | SHARP_SOFT | -2, -1, 0, +1, +2 | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | ピクチャーモードの仕上がり設定 (シャープネス/モノトーン) | SHARP_MONOCHROME | -2, -1, 0, +1, +2 | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | ピクチャーモードの仕上がり設定 (彩度/i-Finish) | SATURATION_LEVEL_I_FINISH | -2, -1, 0, +1, +2 | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | ピクチャーモードの仕上がり設定 (彩度/Vivid) | SATURATION_LEVEL_VIVID | -2, -1, 0, +1, +2 | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | ピクチャーモードの仕上がり設定 (彩度/NATURAL) | SATURATION_LEVEL_NATURAL | -2, -1, 0, +1, +2 | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | ピクチャーモードの仕上がり設定 (彩度/FLAT) | SATURATION_LEVEL_FLAT | -2, -1, 0, +1, +2 | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | ピクチャーモードの仕上がり設定 (彩度/Portrait) | SATURATION_LEVEL_SOFT | -2, -1, 0, +1, +2 | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | ピクチャーモードの仕上がり設定 (階調/i-Finish) | TONE_I_FINISH | AUTO, NORMAL, HIGHKEY, LOWKEY | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | ピクチャーモードの仕上がり設定 (階調/Vivid) | TONE_VIVID | AUTO, NORMAL, HIGHKEY, LOWKEY | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | ピクチャーモードの仕上がり設定 (階調/NATURAL) | TONE_NATURAL | AUTO, NORMAL, HIGHKEY, LOWKEY | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | ピクチャーモードの仕上がり設定 (階調/FLAT) | TONE_FLAT | AUTO, NORMAL, HIGHKEY, LOWKEY | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | ピクチャーモードの仕上がり設定 (階調/Portrait) | TONE_SOFT | AUTO, NORMAL, HIGHKEY, LOWKEY | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | ピクチャーモードの仕上がり設定 (階調/モノトーン) | TONE_MONOCHROME | AUTO, NORMAL, HIGHKEY, LOWKEY | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | ピクチャーモードの仕上がり設定 (効果協調/i-Finish) | EFFECT_LEVEL_I_FINISH | HIGH, STANDARD, NORMAL | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | トーンコントロール (シャドー部) | TONE_CONTROL_LOW | -7 ～ +7 | RW | RW | - | OK | OK | OK | OK | OK | - | - | - | - | - |
| ^ | トーンコントロール (中間部) | TONE_CONTROL_MIDDLE | -7 ～ +7 | RW | RW | - | OK | OK | OK | OK | OK | - | - | - | - | - |
| ^ | トーンコントロール (ハイライト部) | TONE_CONTROL_HIGH | -7 ～ +7 | RW | RW | - | OK | OK | OK | OK | OK | - | - | - | - | - |
| ^ | モノクロフィルター効果 (ピクチャーモード: モノトーン) | MONOTONEFILTER_MONOCHROME | NORMAL, YELLOW, ORANGE, RED, GREEN | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | モノクロフィルター効果 (アートフィルター: ラフモノクローム) | MONOTONEFILTER_ROUGH_MONOCHROME | NORMAL, YELLOW, ORANGE, RED, GREEN | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | モノクロフィルター効果 (アートフィルター: ドラマチックトーン) | MONOTONEFILTER_DRAMATIC_TONE | NORMAL, YELLOW, ORANGE, RED, GREEN | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | 調色効果 (ピクチャーモード: モノトーン) | MONOTONECOLOR_MONOCHROME | NORMAL, LIKE_SEPIA, LIKE_BLUE, LIKE_PURPLE, LIKE_GREEN | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | 調色効果 (アートフィルター: ラフモノクローム) | MONOTONECOLOR_ROUGH_MONOCHROME | NORMAL, LIKE_SEPIA, LIKE_BLUE, LIKE_PURPLE, LIKE_GREEN | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | 調色効果 (アートフィルター: ドラマチックトーン) | MONOTONECOLOR_DRAMATIC_TONE | NORMAL, LIKE_SEPIA, LIKE_BLUE, LIKE_PURPLE, LIKE_GREEN | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | カラークリエーター用　色相 | COLOR_CREATOR_COLOR | 0 ～ 29 | RW | RW | - | OK | OK | OK | OK | - | OK | OK | OK | OK | - |
| ^ | カラークリエーター用　彩度 | COLOR_CREATOR_VIVID | -4 ～ +3 | RW | RW | - | OK | OK | OK | OK | - | OK | OK | OK | OK | - |

----

## ホワイトバランス

| 分類 | 項目 | プロパティ値 | 補足 | Wi-Fi | BLE | iAuto | P | A | S | M | ART | movieP | movieA | movieS | movieM | 備考 |
| :----: | :----: | :----: | :----: | :----: | :----: | :----: | :----: | :----: | :----: | :----: | :----: | :----: | :----: | :----: | :----: | :----: |
| ホワイトバランス | ホワイトバランス | WB | WB_AUTO, MWB_FINE, MWB_SHADE, MWB_CLOUD, MWB_LAMP, MWB_FLUORESCENCE1, MWB_WATER_1, WB_CUSTOM1 | RW | RW | - | OK | OK | OK | OK | OK | OK | OK | OK | OK | - |
| ^ | カスタムホワイトバランス色温度 | CUSTOM_WB_KELVIN_1 | 2000K ～ 14000K | RW | RW | - | OK | OK | OK | OK | - | OK | OK | OK | OK | - |
| ^ | ホワイトバランス補正 (WB補正A-電球) | WB_REV_3000K | -7 ～ +7 | RW | RW | - | OK | OK | OK | OK | - | OK | OK | OK | OK | - |
| ^ | ホワイトバランス補正 (WB補正A-蛍光灯) | WB_REV_4000K | -7 ～ +7 | RW | RW | - | OK | OK | OK | OK | - | OK | OK | OK | OK | - |
| ^ | ホワイトバランス補正 (WB補正A-晴天) | WB_REV_5300K | -7 ～ +7 | RW | RW | - | OK | OK | OK | OK | - | OK | OK | OK | OK | - |
| ^ | ホワイトバランス補正 (WB補正A-曇天) | WB_REV_6000K | -7 ～ +7 | RW | RW | - | OK | OK | OK | OK | - | OK | OK | OK | OK | - |
| ^ | ホワイトバランス補正 (WB補正A-日陰) | WB_REV_7500K | -7 ～ +7 | RW | RW | - | OK | OK | OK | OK | - | OK | OK | OK | OK | - |
| ^ | ホワイトバランス補正 (WB補正A-Auto) | WB_REV_AUTO | -7 ～ +7 | RW | RW | - | OK | OK | OK | OK | - | OK | OK | OK | OK | - |
| ^ | ホワイトバランス補正 (WB補正A-水中) | WB_REV_AUTO_UNDER_WATER | -7 ～ +7 | RW | RW | - | OK | OK | OK | OK | - | OK | OK | OK | OK | - |
| ^ | ホワイトバランス補正 (WB補正G-電球) | WB_REV_G_3000K | -7 ～ +7 | RW | RW | - | OK | OK | OK | OK | - | OK | OK | OK | OK | - |
| ^ | ホワイトバランス補正 (WB補正G-蛍光灯) | WB_REV_G_4000K | -7 ～ +7 | RW | RW | - | OK | OK | OK | OK | - | OK | OK | OK | OK | - |
| ^ | ホワイトバランス補正 (WB補正G-晴天) | WB_REV_G_5300K | -7 ～ +7 | RW | RW | - | OK | OK | OK | OK | - | OK | OK | OK | OK | - |
| ^ | ホワイトバランス補正 (WB補正G-曇天) | WB_REV_G_6000K | -7 ～ +7 | RW | RW | - | OK | OK | OK | OK | - | OK | OK | OK | OK | - |
| ^ | ホワイトバランス補正 (WB補正G-日陰) | WB_REV_G_7500K | -7 ～ +7 | RW | RW | - | OK | OK | OK | OK | - | OK | OK | OK | OK | - |
| ^ | ホワイトバランス補正 (WB補正G-Auto) | WB_REV_G_AUTO | -7 ～ +7 | RW | RW | - | OK | OK | OK | OK | - | OK | OK | OK | OK | - |
| ^ | ホワイトバランス補正 (WB補正G-水中) | WB_REV_G_AUTO_UNDER_WATER | -7 ～ +7 | RW | RW | - | OK | OK | OK | OK | - | OK | OK | OK | OK | - |
| ^ | WBオート　電球色残し | AUTO_WB_DENKYU_COLORED_LEAVING | OFF, ON | RW | RW | - | OK | OK | OK | OK | - | OK | OK | OK | OK | - |

----
