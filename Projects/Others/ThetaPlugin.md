# THETA プラグインの作成・公開 備忘録

ThetaThoughtShutter というRICOH製 THETAプラグインを [https://pluginstore.theta360.com/plugins/jp.osdn.gokigen.thetathoughtshutter/ RICOH THETA Plug-in Store] で2021年3月に公開しました。
このプラグイン公開までの流れを備忘録として残したいと思います。

2023年 5月からは、Thetaプラグインストアは [GitHub](https://github.com/ricohapi/theta-plugins)に移行しました。
そのため、[ThetaThoughtShutter](https://github.com/ricohapi/theta-plugins/tree/main/plugins/jp.osdn.gokigen.thetathoughtshutter)の公開場所が変わっています。

2023年 5月以降も「プラグインの登録、更新申請の方法に変更はありません。」とのことですが、公開・更新の申請手続きについて確認を行っていませんので、ご注意ください。

* [RICOH THETAプラグインストアページ URL変更のお知らせ 2023年02月14日](https://topics.theta360.com/ja/news/2023-02-14/)
* [RICOH THETAプラグインストアページのURLを変更しました 2023年05月30日](https://topics.theta360.com/ja/news/2023-05-30/)

## 概要

* 基本は Support (RICOH THETA Plug-in Partner Program) からのメール駆動の登録〜公開でした。英文で飛んできました。
  * If you allow to receive only specific domains as a countermeasure against spam email, please accept a domain of "plugin.theta360.com" and "theta-plugin.zendesk.com".  とある通り、受信ドメインの許可設定が必要かもしれません。
  * 自動返信は plugin.theta360.com から、Action Requiredなメールは  theta-plugin.zendesk.com から送られて来ていました。
* プラグイン情報の内容に問題があった場合、「最初からやり直し」となる、ようです。(「ここだけ訂正して継続」は、できなさそうです。)
* Terms of Use は、ライセンス情報(Apache 2.0とか)で良さそうです。
* サポートページ（英語）は、Google Translateでも許してもらえるようです。
* プラグインの登録情報と uses-feature の設定は整合していないといけません。はじかれます。

-----

### THETAプラグインプログラムの作成

単純に動かすだけであれば、普通のAndroidアプリケーションの作成方法で問題なさそうです。ちなみに ThetaThoughtShutter は、 minSdkVersion 25, targetSdkVersion 30 、kotlinで作成しました。

Plugin Activity を継承した Activity にして、このあたりを読んで開発するぐらいです。

* https://api.ricoh/docs/theta-plugin/

Android Studio の Enpty Activityプロジェクトを作成し、THETA特有に記述を追加したのは、以下の箇所ぐらいです。
WifiやBluetooth等の機能を使ったりする場合は、一般的なAndroidアプリケーションと同様に、それらを使うための記述が必要です。

#### MainActivity.kt

```kotlin:MainActivity.kt
    :
import com.theta360.pluginlibrary.activity.PluginActivity
    :
class MainActivity : PluginActivity()
{
    :
    :
}
```

#### app/src/main/AndroidManifest.xml

```xml:app/src/main/AndroidManifest.xml
     <manifest  ...>
          <uses-feature android:name="com.theta360.receptor.v" android:required="true"/>
          <uses-feature android:name="com.theta360.receptor.z1" android:required="true"/>
              :
              :
     </manifest>
```

#### app/build.gradle

```gradle:app/build.gradle
dependencies {
       :
     implementation 'com.theta360:pluginlibrary:2.1.0'
       :
}
```

#### build.gradle

```gradle:build.gradle
      :
allprojects {
    repositories {
        google()
        jcenter()
        maven { url 'https://github.com/ricohapi/theta-plugin-library/raw/master/repository' }
    }
}
      :
```

-----

### プラグイン情報登録

RICOH THETA Plug-in Partner Program (Partner Menu) ページでプラグイン情報を登録します。 以下の情報を記入して登録します。

1. プラグインのパッケージ名
   * ThetaThoughtShutter  の場合は、 jp.osdn.gokigen.thetathoughtshutter としました。（プラグインストアのページ名になっていました）
2. プラグインで使用しているパーミッションの一覧
   * 使っている permissionの一覧をカンマ区切りで記述する
3. プラグインでWebUIを使っているかどうか
    * Yes か  No か
4. 暗号化しているかどうか、暗号化の方式とか（一般的な暗号化なのかどうか）
5. プラグイン名称（英語）
6. プラグインの説明（英語）
7. プラグインの説明（日本語、任意）
8. 動作対象とする THETAのファームウェアバージョン (Z1)
    * Android Manifest の uses-feature と合っていないと rejectされるので注意 ( uses-feature の com.theta360.receptor.z1 の required が yesだったら、この項目で none を選択しているとrejectされる )
9. 動作対象とする THETAのファームウェアバージョン (V)
    * Android Manifest の uses-feature と合っていないと rejectされるので注意 ( uses-feature の com.theta360.receptor.v  の required が yesだったら、この項目で none を選択しているとrejectされる )
10. 利用規約の書かれたページのURL
    * 「利用規約」とはいっても、公開されているプラグインの前例に倣い、ソースコードの Apache 2.0 ライセンスへのリンクにしたところ、特に何も言われませんでした。
11. 年齢制限の有無
12. ユーザ個人情報が必要かどうか、必要な場合はプライバシーポリシー等のURLを記載する
13. サポートページへのURL（英語、必須）
    * 日本語の説明ページを、Google Translate で変換したURLでも大丈夫だった。
14. サポートページへのURL（日本語、任意）
15. プラグインのポリシーに従っているかどうかの確認
    * チェックを入れる。

これらを記入して登録すると、メールで記述内容が自動で送られてくる。続報を待つ。

### プラグインバイナリをアーカイブファイルのアップロード

数日ぐらいして、apkと、画像ファイル（960 x 520、最大5枚で、1.jpg, 2.jpg, ... 5.jpg という名前にする）を１つにまとめたzipアーカイブファイルをここにアップロードしてくれ、というメールが来るので、その指示通りにアップロードする。
１週間以内にアップロードしないと、URLは無効になる、とのことも記載されているので、見逃し注意。

### プラグイン公開の確認

アップロード後、（数日？）待つと、「公開していいか？ 返信くれ。1か月連絡なかったら、なかったことにするからな（意訳）」というメールが来るので、このメールに返信（reply）する。
（プラグイン公開についての意思確認だと思うので、返信内容は Please publish ぐらいで良いのではないか、と思います。）

### プラグイン公開の連絡

数日後ぐらいに「このURLで公開したよ」というメールが送られて来て、公開完了となっていました。

以上
