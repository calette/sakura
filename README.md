サクラエディタ 改  

**Introduction**  

自分勝手に修正しています.  
Sublime Text や Atom を参考にモダンな感じにしているつもりです.  

MacTypeと併用していて画面崩れがひどかったので対応をしています.  
高速にスクロールとかすると前の描画が残ってしまって見苦しい状態になることが多いです.  
同じような状態に陥っている人には効果があるかもしれません.  
サクラエディタのソースが初見殺しな感じでカオスなので一時しのぎな対応ですが…  


<br>

**Download**  

変更内容はコミットログを参照してください.  

+ [sakura-mix-2.11.zip](http://mimix.sakura.ne.jp/release/sakura-mix-2.11.zip) (952KB)  
  \- 履歴データを ini から json に変更
+ [sakura-mix-2.10.zip](http://mimix.sakura.ne.jp/release/sakura-mix-2.10.zip) (926KB)  
  \- 強調キーワードをファイルから読み込む  

<br>

**Setup**  

ダウンロードしたファイルをすでに使用しているサクラエディタに上書きコピーしてください.  
`sakura.default.ini`と`sakura.keywordset.json`は実行ファイルと同じ場所に置き, 実行ファイル名が違う場合は`sakura`の部分を変更してください.  

+ [sakura.default.ini](https://github.com/mimix33/sakura_2201/raw/master/resource/sakura.default.ini)  
  デフォルト設定値を設定してあるファイルです. ここに初期値を設定することで常にその状態で起動します.  
  ここで設定した値のままの場合は`sakura.ini`には出力されなくなります.  

+ [sakura.keywordset.json](https://github.com/mimix33/sakura_2201/raw/master/resource/sakura.keywordset.json)  
  強調キーワードのセットリストです. セット名, 大文字小文字の区別, ファイル名を指定します.  
  共通設定からの強調キーワード設定は可能ですが保存はされなくなりますので注意が必要です. 必要に応じてエクスポートしてください.  

+ 最新のキーワードセットはこちら [keyword_pack.zip](https://github.com/mimix33/sakura_2201/raw/master/doc/keyword_pack.zip) (355KB)  

<br>

**Build environment**  
+ 2.2.0.1をベースに[リポジトリ](http://svn.code.sf.net/p/sakura-editor/code/sakura/trunk2)の追っかけ. ベースリビジョンからのマージ情報は[こちら](https://github.com/mimix33/sakura_2201/raw/master/doc/changes_from_r4011.txt). あと、[パッチ](https://sourceforge.net/p/sakura-editor/patchunicode/)のマージ  
+ MSVC2017でビルド  
+ Boostを使用  
+ 挙動の制御 (共有フラグ)としてレジストリを使用しています  

<br>

**Changed**  
+ ファイル系
  - 履歴は別ファイル (sakura.recent.json)で扱う  
  - ~~起動時に存在しない履歴を削除する~~  
  - デフォルト設定ファイルの使用 (sakura.default.ini)  
  - 強調キーワード設定はファイルから読み込む (sakura.keywordset.json)  
  - カラー設定のインポートはカラー情報だけを適用させる  
  - 履歴 (検索, 置換, Grep)の値を少なめに変更  
  - 多重オープンの許可 (Shiftを押しながらファイルのドロップ)  

+ 表示系
  - EOFのみの行 (起動時とか)にも行番号を表示  
  - 行を中央ぞろえにする  
    (デフォルトでは上揃えになっていて行の間隔が下に付加されている)  
  - 半角空白文字を `･` で描画, NBSPも半角空白として `×` で表示  
  - タブ文字を線のみで描画 (Sublime Textみたいな)  
  - コメント行の背景カラーを改行以降もその色で描画  
  - 空白, タブ, 改行, EOFのカラーは現在のテキストカラーから自動で設定  
  - 選択範囲カラーは元のテキストカラーをそのまま使用する (Text:0%, Back:100%)  
  - 太字装飾の文字列を選択したときに選択範囲カラーの装飾の影響を受けないように修正  
  - カーソル行アンダーラインを行番号から引っ張る  

+ 操作, 編集系
  - ミニマップを編集ウィンドウに合わせてスクロール  
  - キャレットのサイズを変更可能に  
  - 垂直, 水平スクロールの挙動をメモ帳の挙動と同じにする  
  - 検索, ジャンプなどのカーソルが大きく移動する処理ではジャンプ先のカーソル行をセンタリングする  
  - タブ入力文字の切り替え機能 (`S_ChangeTabWidth` マクロを修正, 負の値を設定するとタブと空白を相互に切り替えます)  

+ UI系
  - タブと編集ウィンドウのバグ修正とスタイル調整 (モダンに?)  
  - リソース (ダイアログ)のフォントを `9, "ＭＳ Ｐゴシック"` から `9, "MS Shell Dlg"` へ変更  
  - 状態に応じてタブ名のカラーを変更 (変更, キーマクロ記録中)  
  - タブをダブルクリックで閉じられるようにする  
  - 選択タブのアクティブ化をマウス押下時に行う  
    (デフォルトではマウス押上時にアクティブにするのでワンテンポ遅く感じる)  
  - Grepフォルダの指定を物理的に4つに増やした (`;` で区切ると履歴管理が面倒…)  
  - Grep「現在編集中のファイルから検索」をチェックした時の状態を保持しないようにする  
    (現在編集中からのGrepって「今回だけ！」ってことが多いと思います)  
  - 置換ダイアログの置換後テキストに置換前テキストを設定  
  - 正規表現検索のときに正規表現記号をクォート (`^abc$` を検索する場合 `\^abc\$` にする)  
  - アウトライン解析ダイアログのドッキング時に背景カラーを使用しない (コントロール色のまま)  
  - ステータスバーのカスタマイズ  
    \- カーソル移動時のちらつき抑制  
    \- 表示情報の内容を修正  
    \- 左クリックでメニューを表示  
  - タグファイル作成時にフォルダの初期位置を`tags`ファイルがあるところまで辿る  
  - ダイレクトジャンプ一覧の表示カラムを選別  

<br>

**Bugfix**  
+ 検索マーク切り替え, インクリメンタルサーチの際に検索ダイアログの「正規表現」が影響を受けないように  
  \- 常時、正規表現で検索しているとコレ結構ストレスたまります  

+ ルールファイルを設定してアウトライン解析をするとデフォルトが逆順になっている  

+ 行番号縦線を行番号の色で描画する  
  \- 行番号縦線はその行に変更があった場合, その行だけ変更色で縦線が引かれてしまうので区切りの線としては微妙だったため  

+ 行番号が非表示でブックマークが表示のときブックマークは線で描画する  
  \- 行番号非表示時のブックマーク表示がなかったのでブックマークのカラー設定を無効にしている時と同じように表示する  

<br>


(C) 2017 mimix.
