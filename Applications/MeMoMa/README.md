English Translation link : http://translate.google.co.jp/translate?u=http://sourceforge.jp/projects/gokigen/wiki/MeMoMa&sl=ja&tl=en&hl=&ie=UTF-8
----

[[PageOutline]]

----
[[PageBreak]]
= MeMoMaとは =

!MeMoMaは、ブレーンストーミングを行い、その結果を整理・活用するためのAndroidタブレット用アプリケーションです。AndroidのIce Cream Sandwich(4.0)以降で動作します。

!MeMoMaを使うことで、ホワイトボードに付箋を貼りつけて考えをまとめる、といった作業をAndroidタブレット上で実現することができます。

[[Thumb(memoma0.png, size=large, caption=MeMoMaのスクリーンショット)]]

自分の発散的な考えをまとめ、整理するのに使おうと、今回作成してみました。もしよろしければご利用ください。

'''(注)''' 本文書では、記入して画面内に並べていくアイテムのことを「オブジェクト」と呼びます。


= 機能概略 =

== オブジェクト（付箋）の貼付け、削除、複製 ==
 * 形状選択 （１１種類）、カラー選択、塗りつぶし、強調表示、ラベルフォントサイズ（３種類）
 * ユーザのチェックマーク設定
 * 大きさ拡大、縮小

== オブジェクト（付箋）の関係性設定 ==
 * 線で接続（６種類）

== 背景色、背景画像設定 ==
 * 背景画像は、ギャラリーから選択が可能です。
 * 背景色は、背景画像を設定していない場合有効です。（設定画面を使い、文字列で色を指定します。）

== 表示の拡大、縮小 ==
 * 0.1倍～10倍
 * 表示位置、表示倍率のリセット

== 表示データの保存、読み出し ==
 * ローカルストレージのフォルダに記録する


バックアップファイルを最大５世代保管する (/sdcard/Gokigen/!MeMoMa/backup フォルダに記録する)
 * 保存ボタンを用意し、任意のタイミングで保存を行う。

== オブジェクトの一覧表示、エクスポート ==
 * 外部ストレージ( Download/gokigen フォルダ)に CSV形式 または XML形式で保存（エクスポート）する
 * 外部ストレージ( Pictures/gokigen フォルダ(に、画像(png形式)で保存する
 * CSV形式、png形式でエクスポートしたファイルを共有する （Gmailアプリ等に送り、メールに添付して送信が可能です）

== その他 ==
 * 情報ダイアログで、説明サイト（本サイト）へのリンクを表示する。
 * ユーザ定義のチェックボックスの使用が設定可能（使用状態でチェックを入れるとオブジェクトにマークがつく。）


= 起動 =

!MeMoMaは、通常のAndroidアプリケーションですのでアイコンをタッチすると起動します。
起動後は、前回編集していたページを前回の大きさ、表示位置で表示します。

[[Thumb(icon1.png, size=large, caption=MeMoMaのアイコン)]]


= 画面説明 =

!MeMoMaは、メイン画面、オブジェクト一覧画面、設定画面の３画面で構成し、起動直後は必ずメイン画面を開きます。ボタンやメニューからオブジェクト一覧画面や設定画面に切り替えます。

[[Thumb(overview.png, size=large, caption=画面遷移)]]

!MeMoMaは、基本的にポートレイト固定で利用するように設計しています。ご了承ください。

[[PageBreak]]
= メイン画面 =
[[Thumb(memoma-overview-en.png, size=large, caption=main screen)]]

 * '''Change Title''' : 今開いているページのタイトル名を変更します。（タイトル名は、そのまま保存ファイル名として利用しています。）

 * '''Title (Change Data)''' : 開いているページを切り替えます。

 * '''Create New''' : 新規ページを作成します。

 * '''Operation Icons''' : 操作アイコンです。

 * '''Zoom In/Out''' : 画面の拡大・縮小を行います。（0.1倍～10倍）

 * '''Data Save''' : ページの保存を手動で行います。


== 操作アイコンについて ==

[[Thumb(operation-icons.png, size=large, caption=操作アイコン)]]

 * '''Home''' : 画面表示を初期化します。（画面の表示位置、ズームサイズを1.0倍に初期化します。）

 * '''Append''' : オブジェクト追加モード(Appendモード)に切り替えを行います。オブジェクト追加モードの時に押すと、移動モード(Moveモード)に切り替えます。

 * '''Cut''' : オブジェクト削除・切り離しモード(Cutモード)に切り替えを行います。オブジェクト削除・切り離しモードの時に押すと、移動モード(Moveモード)に切り替えます。

 * '''Line Shape''' : オブジェクトを繋ぐ関連線の形状を切り替えます。

 * '''List''' : オブジェクト一覧画面に移動します。

[[PageBreak]]
== 操作モードについて ==

[[Thumb(operation-mode-icons.png, size=large, caption=操作モード)]]

 * '''Move''' : 表示領域を移動させるモードです。

 * '''Append''' : オブジェクトを追加するモードです。

 * '''Cut''' : 線を切断するモードです。


== 関連線の形状について ==

関連線は、直線、曲線、階段線それぞれが矢印付きと矢印なしの３種類×２＝６種類設定できます。
関連線の形状を変えるには、ボタンを押すと変わります。

[[Thumb(line-shapes.png, size=large, caption=関連線の形状)]]


== 機能説明 ==

=== ページの新規作成 ===

画面右上のプラスボタンを押すと、ページを新規作成となります。

[[Thumb(createNew.png, size=large, caption=新規作成ボタン)]]

今表示している内容をクリアして本当に新規作成をするか、確認を行います。
（保存する必要があれば、先に保存を行なってください。）

[[Thumb(discard.png, size=large, caption=新規作成の確認)]]

OKボタンを押したあと、タイトルを入力する画面になります。

[[Thumb(titleInput.png, size=large, caption=タイトルの入力)]]

入力したタイトルで、ページを新規作成します。

このとき、Cancelボタンを押すと、今のページのオブジェクト全クリア状態になります。

=== ページの読み込み ===

一度保存したページは、タイトルをタッチすると一覧を表示し、そこから選択すると読み込むことができます。

[[Thumb(titleSelection.png, size=large, caption=読み込むページの選択)]]


=== オブジェクト（付箋）の追加 ===

オブジェクトを追加するには、Appendモードで、オブジェクトを表示していない領域をタッチしてください。

画面にオブジェクトができます。


[[Thumb(object.png, size=large, caption=オブジェクト)]]


=== オブジェクトの移動 ===

オブジェクトをタッチして、そのままスライドさせると、オブジェクトの位置が変わります。画面から離した位置にオブジェクトが移動します。

[[Thumb(moveObject.png, size=large, caption=オブジェクトの移動)]]

=== オブジェクトへの情報記入 ===

オブジェクトを軽くタッチすると、オブジェクト情報入力ダイアログを表示します。

見出し、詳細情報を記入するだけでなく、オブジェクト形状や色、塗りつぶし、フォントサイズを変更することができます。

[[Thumb(objectinput-2.png, size=large, caption=オブジェクトへの情報入力)]]

[[Thumb(objects.png, size=large, caption=オブジェクトの形状)]]

[[Thumb(objectStyle.png, size=large, caption=オブジェクト表示の違い)]]



=== オブジェクトの操作 ===

オブジェクトを長押しすると、オブジェクトの操作メニューを表示します。

[[Thumb(operation-dialog.png, size=large, caption=操作メニュー)]]

 * '''削除 (Delete)'''
    * オブジェクトを削除します。

 * '''複製 (Duplicate)'''
    * オブジェクトの内容をコピーして、もうひとつ作ります。

 * '''サイズ拡大 (Expand)'''
    * オブジェクトのサイズ（オブジェクトの枠）を大きくします。

 * '''サイズ縮小 (Shrink)'''
    * オブジェクトのサイズ（オブジェクトの枠）を小さくします。


=== 線の接続 ===

オブジェクトとオブジェクトを重ね合わせるようにすると、線がつながります。
（線がつながるだけで、オブジェクトは移動しません。）

[[Thumb(connectLine3.png, size=large, caption=線の接続)]]

=== 線の切断 ===

Cutモードにして、線と線の間を横切るようにタッチして動かすと、線が消えます。

[[Thumb(disconnectLine.png, size=large, caption=線の切断)]]

不具合があり、線が切れない場合もあるようです。そういった場合は、メニューの「複製」を選び、オブジェクトを複製してから、古いオブジェクトを削除するようにして対応してください。
ご迷惑をおかけしますが、よろしくお願いします。


=== オブジェクトの削除 ===

Cutモードにしてオブジェクトをタッチ、あるいは操作メニューから削除を選択すると、オブジェクトの削除ができます。
オブジェクト削除前に、本当にオブジェクトを削除しても良いか確認しますので、OKボタンを押してください。
Cancelすると、オブジェクトの削除は行いません。

[[Thumb(deleteConfirmation.png, size=large, caption=オブジェクト削除の確認)]]


== メニュー ==

画面右上のメニューボタンを押すと、メニューを表示します。
[[Thumb(menuButton.png, size=large, caption=Menuボタン)]]

[[Thumb(menu-en.png, size=large, caption=Menu)]]

 * 保存... (Save...)
   * ページを保存します。

 * タイトル変更... (Rename Title...)
   * ページタイトルを変更します。

 * 背景画像... (Select Background...)
   * 背景画像を選択します。

 * その他... (Etc...)
   * オブジェクト一覧画面を開きます。

 * 設定 (Preferences)
   * 設定画面を開きます。

 * 情報 (About)
   * 情報ダイアログを表示します。

=== 保存... ===

メニューから保存を選択すると、データを保存します。
また画面右下にあるフロッピーディスクアイコンを押すと保存することができます。

[[Thumb(save.png, size=large, caption=保存ボタン)]]

アプリ終了時、画面切り替え時に要所要所で自動保存を行なっていますが、自分の心の平穏を得るために用意しました。

保存データはxml形式で /sdcard/Gokigen/!MeMoMa ディレクトリに置きます。

以前に保存したファイルは、/sdcard/Gokigen/!MeMoMa/backup ディレクトリに５世代分保管しています。

データを消してしまった！！という場合には、あわてず騒がず上記ディレクトリを探すと残っていることがあります。
（自動保存機能もありますので、直後のバックアップファイルでは消えていることがありますので、ご注意ください。）



=== タイトル変更... ===
現在の表示中のデータ名を変更します。
（ここで入力したファイル名が、データのファイル名になります。）

[[Thumb(titleInput.png, size=large, caption=タイトル変更)]]

=== 背景画像... ===
背景画像を選択します。

背景画像を選択するとき、利用するアプリケーションを選択する画面が出ることがあるかもしれません。
その時は、利用するアプリケーション（例えば「ギャラリー」とか）を選択してください。

[[Thumb(selectBackground.png, size=large, caption=利用するアプリケーションの選択)]]

背景画像を貼ると、見栄えがグッと変わりますので、お試しください。

[[Thumb(background.png, size=large, caption=背景画像の貼付け)]]

また、背景画像を利用して、後述の枠の画像を設定してアイデアを分類することができます。（というか、こっちが本命です。）

後述する 背景画像事例集 に、いくつかの画像データサンプルを用意しましたので、よろしければご活用ください。

[[Thumb(square-example.png, size=large, caption=背景画像に枠を設定してアイデアを分類)]]


=== その他 ===
一覧画面を開きます。

=== 設定 ===
設定画面を開きます。

[[PageBreak]]
=== 情報 ===

!MeMoMaのクレジットダイアログを表示します。リンクを押すと操作説明ページ（本ページ）を表示します。

[[Thumb(aboutDialog.png, size=large, caption=情報)]]


== ズーム倍率の変更 ==

画面下部のスライダーを動かすことで、表示内容の拡大・縮小が実施できます。画面右下に倍率を表示します。

[[Thumb(zoomin.png, size=large, caption=表示の拡大例)]]


= オブジェクト一覧画面 =
入力したオブジェクトの一覧をリスト形式で保存します。
[[Thumb(listview.png, size=large, caption=オブジェクト一覧画面)]]


== CSV形式で保存 ==
このメニューを選ぶと、現在表示中のオブジェクト一覧データをCSV形式で保存します。

=== CSVファイルの形式について ===

 * 漢字コードは、UTF-8 で保存しています。（直接Microsoft Excelで開けないかもしれません。）

 * データの並びは、１件は「見出し」,「詳細」,「ユーザチェック状態」,「オブジェクト形状」,「オブジェクトスタイル」,「オブジェクトの中心座標(X軸)」,「オブジェクトの中心座標(Y軸)」,「オブジェクトの幅」,「オブジェクトの高さ」の順番に並んでいます。
   * 詳細は、ダブルクオーテーションで囲まれた改行を含む文字列です。
   * ユーザチェック状態は、「True」または「False」です。
   * オブジェクト形状は、0～10の数値です。
   * オブジェクトスタイルは、枠の場合は「STROKE」、塗りつぶしの場合は「FILL」です。
   * オブジェクトの中心座標は、負の数を含む数値です。
   * オブジェクトの幅及びオブジェクトの高さは、正の数値です。


== 共有 ==

表示しているオブジェクト一覧画面の情報を、CSV形式でエクスポートし、さらに他アプリケーションと共有する操作を行います。

想定しているのは、オブジェクトのデータを Gmailを使ってメール送信をする操作です。

[[Thumb(share-dialog.png, size=large, caption=share)]]

Gmailの場合は、CSV形式のファイルを添付とし、タイトル・本文を定形フォーマットで挿入します。

[[Thumb(gmail.png, size=large, caption=)]]

送り先を入力して送信ボタンを押すだけで、メール送信ができます。


= 設定画面 =

[[Thumb(preferences.png, size=large, caption=設定画面)]]

== ユーザ定義チェックボックス ==

オブジェクト情報入力ダイアログで、ユーザ定義のチェックボックスを利用するかどうかの設定を行います。
チェックを入れると、ユーザ定義のチェックボックスが利用可能になります。

ユーザ定義のチェックボックスが利用可能な状態になっているとき、オブジェクト情報入力ダイアログでチェックを入れると、
オブジェクトに '''*''' マークが付きます。

[[Thumb(userChecked.png, size=large, caption=ユーザチェック付きのオブジェクト)]]


== ユーザ定義チェックボックスのタイトル ==

オブジェクト情報入力ダイアログに表示するユーザ定義のチェックボックスのタイトルを設定します。
[[Thumb(userCheckBox.png, size=large, caption=ユーザ定義チェックボックスのタイトル)]]

オブジェクト情報入力ダイアログでは、設定したタイトルを表示します。

[[Thumb(userChecked-2.png, size=large, caption=ユーザ定義チェックボックス)]]


== 背景画像(URI) ==

背景画像を選択した時の情報を表示します。通常は意識する必要はありませんが、背景画像を削除したい場合には、ここに記述されている文字列をすべて削除してください。

== 背景色 ==

背景色を文字列で設定します。Andoroidで決められている色のシンボル（BLUEとか...）、数値(#rrggbb 形式) で指定することができます。

[[Thumb(backColor.png, size=large, caption=背景色)]]

タブレット端末ではなく、ICSのスマートフォンの場合、入力ダイアログの中身が表示されないことがあります。その時は、スマートフォンを縦に持ち替えていただくと入力できるようになると思いますので、お試しください。



== オブジェクトの見出し ==

オブジェクトの見出しとしてメイン画面に表示する方法を選択します。
見出しを省略して１行だけ表示するか、それとも見出しに設定した文字列すべて表示するかを選択できます。

見出しに長い文字列を入れてしまい、オブジェクトの枠からはみ出してしまって格好が悪い、といったときに見出しを省略して表示し、見栄えを優先させることもできます。


[[Thumb(object-label.png, size=large, caption=オブジェクトの見出し)]]


[[Thumb(objectlabel.png, size=large, caption=オブジェクトの見出しの違い)]]

= 制約事項 =

 * データファイルを消去する機能は持っていません。他のファイラーアプリをご活用ください。

[[PageBreak]]
= ソースコードのありか =

!MeMoMaはオープンソースです。ソースコードの参照、取得は、以下のサイトから可能です。
 * http://sourceforge.jp/cvs/view/gokigen/MeMoMa/

= アイコンの元ネタ =
...パワポです。（わ、笑わないでください...。）
 * http://sourceforge.jp/projects/gokigen/wiki/MeMoMa/attach/めもまアイコン.ppt


= apkファイルの入手 =

!MeMoMaは、Android Market より入手可能です。
 * https://market.android.com/details?id=jp.sourceforge.gokigen.memoma

!MeMoMaは、Android Marketに公開していますが、以下のCVSリポジトリからapkファイルを取得することができます。
ただし、デバッグ用の産物のため、あらゆる意味で保証できませんのでその点ご承知おきください。
 * http://sourceforge.jp/cvs/view/gokigen/MeMoMa/bin/MeMoMa.apk?view=co


= 使い方（例） =

以下が自分が想定している使い方です。主に３つのフェーズを想定しています。

 1. ブレーンストーミング
 1. 関連付け・整理
 1. 整理結果の活用、エクスポート


== ブレーンストーミング ==

画面上にオブジェクト（付箋）を並べていくフェーズです。とにかく並べます。
自分は、全然関連性のないものが浮かんできますので、それを右や左に（あまり場所を考えず）貼りつけていきます。


== 関連付け・整理 ==

考え、頭に浮かんでくることを吐き出したら、今度は関連付けを行います。
なんか似たようなものを場所を右や左、上や下に寄せます。
これ、同じじゃん、とか、関連しているなあ、と思えば、線で結びます。

そうやって、あれ、このグループはこういったカテゴライズができるな、と思うと、その名前をまた貼り付けます。これで整理を行います。


== 整理結果の活用、エクスポート ==

整理した結果を、そのままto doリストとして使うことができます。

あるいは、そのデータをCSV形式で出力し、共有機能で他アプリに送って、別の環境で活用することもできます。


= 応用事例 =

== タスクかんばん ==
!MeMoMaは、ホワイトボード＋付箋紙をタブレット端末上で再現するイメージですので、例えばタスクかんばんのタブレット化も利用可能です。

[[Embed(http://sourceforge.jp/projects/gokigen/wiki/MeMoMa/attach/Memoma00.png)]]


[http://sourceforge.jp/projects/gokigen/wiki/MeMoMa/attach/task-kanban.jpg タスクかんばん]の写真を背景画像に設定することで実現できます。


== 背景画像事例集 ==
アイデアまとめをする場合、ある程度の枠（フォーマット）があるとスムーズになる場合があります。!MeMoMaは、背景画像に枠の画像を設定することができます。
いくつかサンプルの画像を起きます。（すべて1280×720の大きさです。）

[[Thumb(three.PNG, size=large, caption=３分割（黒枠）)]]
[[Thumb(three2.png, size=large, caption=３分割（グレー枠）)]]
[[Thumb(SWOT.png, size=large, caption=SWOT分析用（黒枠）)]]
[[Thumb(SWOT2.png, size=large, caption=SWOT分析用（グレー枠）)]]
[[Thumb(square.PNG, size=large, caption=４分割（黒枠）)]]
[[Thumb(square2.PNG, size=large, caption=４分割（グレー枠）)]]
[[Thumb(nine.png, size=large, caption=９分割（黒枠）)]]
[[Thumb(nine2.png, size=large, caption=９分割（グレー枠）)]]
[[Thumb(axis.png, size=large, caption=XY軸１（黒枠）)]]
[[Thumb(axis2.png, size=large, caption=XY軸１（グレー枠）)]]
[[Thumb(port.png, size=large, caption=XY軸２（黒枠）)]]
[[Thumb(port2.png, size=large, caption=XY軸２（グレー枠）)]]
[[Thumb(center-2.png, size=large, caption=中心線１（黒枠）)]]
[[Thumb(center-22.png, size=large, caption=中心線１（グレー枠）)]]
[[Thumb(center.png, size=large, caption=中心線２（黒枠）)]]
[[Thumb(center2.png, size=large, caption=中心線２（グレー枠）)]]
[[Thumb(2c.png, size=large, caption=２つの円（黒枠）)]]
[[Thumb(2c2.png, size=large, caption=２つの円（グレー枠）)]]
[[Thumb(3c.PNG, size=large, caption=３つの円１（黒枠）)]]
[[Thumb(3c2.PNG, size=large, caption=３つの円１（グレー枠）)]]
[[Thumb(circle.png, size=large, caption=３つの円２（黒枠）)]]
[[Thumb(circle2.png, size=large, caption=３つの円２（グレー枠）)]]
[[Thumb(triangle.png, size=large, caption=ピラミッド（黒枠）)]]
[[Thumb(triangle2.png, size=large, caption=ビラミッド（グレー枠）)]]


= 参考資料 =

 * ファシリテーション・グラフィック
   * http://www.amazon.co.jp/dp/4532312884

 * 発想法
   * http://www.amazon.co.jp/dp/4121001362

 * 続・発想法
   * http://www.amazon.co.jp/dp/4121002105

以上