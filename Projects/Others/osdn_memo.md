# リポジトリ移動の備忘録

OSDNからGitHubにリポジトリ移動を行ったときの備忘録

## Gitリポジトリの移動

1. 移動元のベアリポジトリを取得
    - git clone --mirror (移動元アドレス)
    - SSLのエラーが出た場合は、 "-c http.sslVerify=false" オプションをつける必要あり
2. 移動先の(空の)リポジトリを作成
3. .git のあるリポジトリに移動し、移動先のリポジトリへ push
    - git push --mirror (移動先アドレス)
4. 移動先のリポジトリを確認

## GitリポジトリのリモートURL変更

サイト入れ替えだけでなく、プロトコル変更(https → ssh)も同じ手段で対応する。

1. 現在のリポジトリ設定を確認
    - git remote -v
2. リポジトリ設定を書き換え
    - git remote set-url origin (新しいリモートURL)
3. リポジトリ設定が変わっていることを確認する
    - git remote -v
