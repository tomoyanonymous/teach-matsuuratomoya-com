# [teach.matsuuratomoya.com](https://teach.matsuuratomoya.com)

[![License: CC BY-NC-SA 4.0](https://img.shields.io/badge/License-CC%20BY--NC--SA%204.0-lightgrey.svg)](https://creativecommons.org/licenses/by-nc-sa/4.0/)

Repository for [teach.matsuuratomoya.com](https://teach.matsuuratomoya.com).

## Author 

Tomoya Matsuura 松浦 知也
 
https://matsuuratomoya.com

# Contact

- me\[at\]matsuuratomoya.com

授業関係の連絡はこちら↓ Related to courseworks

- teach\[at\]matsuuratomoya.com


# 使い方のメモ

## 新しい授業資料更新のファイル作成コマンド

```sh
hugo new --kind class content/docs/2023/code-design/10
```

## カスタムショートコード

テーマのショートコードも使える。

https://github.com/alex-shpak/hugo-book#shortcodes　


### `embed_pdf` PDFの埋め込み

embedで埋め込むだけ。Page Bundleになっている必要があるので`index.md`と同ディレクトリでないと使えない

```md
{{< embed_pdf >}} 
```

mdと同ディレクトリにあるPDFのうち一番先頭のファイルを埋め込む。

```md
---
...
params:
    pdf_path:hoge.pdf
...
---

{{< embed_pdf >}} 
```

フロントマッターで相対指定したPDFファイルを埋め込む。

```md
{{< embed_pdf href = "hoge.pdf">}} 
```

インライン指定したPDFファイルを埋め込む。

### `slides_jpg`

```md
{{< slides_jpg >}} 
```

Page Resourcesの中のJPGを全部名前順に連番で表示する。keynoteでjpgエクスポートした連番ファイルをそのまま突っ込んで表示できる想定。

### `preview_code`

指定したファイルを読み込んで通常のコードハイライト表示をし、ダウンロードのボタンを追加する。
これも埋め込むファイルがPage Resourcesになっている必要がある（サブディレクトリに入れることはできない。）
`type`でシンタックスハイライトの種類を指定できる。

```md
{{< preview_code href="tone_minimal.ino" type= "ino">}}
```
