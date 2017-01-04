## サクラエディタ２改造版
* サクラエディタを改造しています。主に他のエディタでよかった機能とか見た目の実装。
* 気になったところの修正とかもやってます。
* 使いそうでマージ可能なものはマージしています。  
* プロポーショナルフォントは使用していないのでスルーしています。

## 変更内容
<sup>†</sup> レジストリによる調整が可能な項目
* 履歴の数を変更（検索、置換、Grep）<sup>†</sup>
* 多重オープンの許可（Shiftを押しながらファイルドロップ）
* 行番号表示
  - 最上部行・最終行・10行おきに数値、1・5行おきに指定文字（Borland IDE like） <sup>†</sup>
  - フォントサイズの変更（固定化） <sup>†</sup>
* キャレット
  - サイズの変更 <sup>†</sup>
  - 1バイトコードの時は1px、2バイトコードの時は2px (Mozillaっぽく) <sup>†</sup>
  - 半角入力の時は1px、全角入力の時は2px <sup>†</sup>
  - キャレット位置を左にずらす <sup>†</sup>
  - カーソル移動リピート時の幅を 1 に変更 <sup>†</sup>
* 行を中央ぞろえにする（本家は上揃え、余白が下につく）
* 水平スクロール
  - スクロール開始マージンを 1 に変更。画面の端でスクロール開始 <sup>†</sup>
  - スクロール幅を 16 に設定。一度に大きく移動することで見やすくする (動きはメモ帳参照) <sup>†</sup>
* 半角空白
  - 半角空白文字に "･" を描画 (SublimeTextっぽく)
* タブ文字
  - タブ文字（矢印）の鏃(>)は表示しない (SublimeTextっぽく)
  - 「短い矢印」廃止
* カーソル行アンダーラインは左端（行番号）から
* UIフォントを "MS UI Gothic" に変更
* アウトライン解析ダイアログ
  - フォントをメインフォントにする <sup>†</sup>
  - ドッキング時にウィンドウカラーをテキストに合わせない <sup>†</sup>
* 選択領域
  - テキスト、背景のブレンド率指定 <sup>†</sup>
* 空白TAB,改行のカラーを変更（現在のテキスト色と現在の背景色をブレンドする） <sup>†</sup>
  カラー設定を無効化。設定の手間を省く。コメント中の色も変更される。
* コメント行
  - 改行以降もカラーを有効にする <sup>†</sup>
* シングルクォートとダブルクォートの統合（使い続けていて分けて使うことがなかったので…）
* 折り返し記号表示時に折り返し位置の線を引かない <sup>†</sup>
* ステータスバー
  - タイプ名を表示  
  - タブサイズを表示  
  - RECの色を赤にする  
  - 「○ 行 ○ 桁」→「(○, ○)」に変更、左端に表示  
* 対カッコ検索モード（カッコが続くと直前のカッコも対象になると混乱のもとになるため）
* 正規表現検索の際、検索文字列の正規表現記号をクォートする <sup>†</sup>
* Grep変更
  - Grepするフォルダの指定を UI的に増やす<br>
    カンマで区切るより分かれていた方が扱いやすいし、履歴管理もしやすい
  - 指定フォルダをすべてチェックをはずすと「現在編集中のファイルから検索」とする
  - 「現在編集中のファイルから検索」をチェックした時の状態を保持しないようにする<br>
    本来の「現在編集中のファイルから検索」を使用すると、影響を受ける他のチェックボックスの状態が変更したまま戻らないのが嫌だから
  - ファイル(フィルタ)指定はフォルダのあとに置く (フォルダのほうが変更する機会が多いため)  
  - 検索中のダイアログを中央に置かない（リアルタイム時に見づらい）
* 置換変更
  - 置換後文字列に置換前文字列を設定する <sup>†</sup>
* フォルダ選択ダイアログを変更 <sup>†</sup>
  - CLSID_FileOpenDialogを使用 
* ダイレクトタグジャンプ一覧を変更
  - 表示するカラムの選別と並び替え  
* 外部コマンド実行ダイアログを変更
  - ウィンドウの位置が決まった位置にでるようにする

## 修正内容
* 数値色付け u ul ll 1. 0.f の形に対応
* 検索マーク切り替えの際に検索ダイアログの「正規表現」が外れるのを回避
* インクリメンタルサーチの際に検索ダイアログの「正規表現」にチェックがついたままなのを回避
* ウェイトカーソルを文字列削除時に表示しない（アンドゥのときなど）
* ルーラー非表示時は「ルーラーとテキストの隙間」を無視する
* 行番号縦線を行番号の色で描画に変更
* カーソル上下移動時に次の条件?のときに画面の更新が間に合わずに描画が崩れる
  - キーリピートが早い  
  - 裏で描画を頻繁に行うアプリが動いている
* カーソル移動時のちらつきを暫定で対処（MacType使用時に顕著）
