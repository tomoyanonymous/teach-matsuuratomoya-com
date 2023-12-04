---
title: 第5週
date: 2023-10-31
weight: 5
draft: false
params:
  pdf_path: 2023-media-art-programming2-5.pdf
---

# 2023年 メディアアート・プログラミング 第5回

## スライド

{{< embed_pdf >}}

## テキスト操作のサンプルコード

### load_text.js(ファイルの読み込み)

```js
//ファイル読み込みライブラリを使用
const fs = require("fs");
//ファイル名の指定（./はこのjsファイルと同階層にあることを明示）
const src = "./henshin.txt";
//ファイルを読み込み
const bytes = fs.readFileSync(src);
//バイト列から文字列に
const txt = bytes.toString();
console.log(txt);
```

{{< button href="load_text.js">}}load_text.js{{< /button >}}

### text_as_array.js （文字列から文字をインデックスで取り出す）

文字列オブジェクトはJavascriptの中では配列のように`str[idx]`として先頭から`idx`番目の文字を取り出せます。

```js
//ファイル読み込みライブラリを使用
const fs = require("fs");
//ファイル名の指定（./はこのjsファイルと同階層にあることを明示）
const src = "./henshin.txt";
//ファイルを読み込み
const bytes = fs.readFileSync(src);
//バイト列から文字列に
const txt = bytes.toString();
//配列として先頭から100文字コンソールに表示
for (let i =0;i<100;i++) {
    console.log(txt[i])
}
```

{{< button href="text_as_array.js">}}text_as_array.js{{< /button >}}

### text_as_array2.js （文字列を文字の配列オブジェクトにする）

より明確に1文字ずつを要素とした配列オブジェクトにすることもできます。

こちらのやり方だと、配列を変換する`map`や`filter`、`reduce`などの便利な関数が使えます。

```js
//ファイル読み込みライブラリを使用
const fs = require("fs");
//ファイル名の指定（./はこのjsファイルと同階層にあることを明示）
const src = "./henshin.txt";
//ファイルを読み込み
const bytes = fs.readFileSync(src);
//バイト列から文字列に
const txt = bytes.toString();
//文字の配列にする
const arr = Array.from(txt);
console.log(arr);
```

{{< button href="text_as_array2.js">}}text_as_array2.js{{< /button >}}

### text_sort.js （文字列を文字コード順でソート）

```js
//ファイル読み込みライブラリを使用
const fs = require("fs");
//ファイル名の指定（./はこのjsファイルと同階層にあることを明示）
const src = "./henshin.txt";
//ファイルを読み込み
const bytes = fs.readFileSync(src);
//バイト列から文字列に
const txt = bytes.toString();
//文字の配列にする
const arr = Array.from(txt);
//配列を文字コード順でソート
const sorted = arr.sort();
//ソートした配列を（区切り文字なしで）結合
const sorted_str = sorted.join("");
//ファイルに保存
fs.writeFileSync("henshin_sorted.txt",sorted_str);
```
{{< button href="text_sort.js">}}text_sort.js{{< /button >}}

### text_reversed.js （文字列を前後逆転）

```js
//ファイル読み込みライブラリを使用
const fs = require("fs");
//ファイル名の指定（./はこのjsファイルと同階層にあることを明示）
const src = "./henshin.txt";
//ファイルを読み込み
const bytes = fs.readFileSync(src);
//バイト列から文字列に
const txt = bytes.toString();
//文字の配列にする
const arr = Array.from(txt);
//配列を反転
const reversed = arr.reverse();
//反転した配列を（区切り文字なしで）結合
const reversed_str = reversed.join("");
//ファイルに保存
fs.writeFileSync("henshin_reversed.txt",reversed_str);
```

{{< button href="text_reversed.js">}}text_reversed.js{{< /button >}}

### text_unicode_shift.js （文字列のUnicodeコードポイントを一つずつずらす）

```js
//ファイル読み込みライブラリを使用
const fs = require("fs");
//ファイル名の指定（./はこのjsファイルと同階層にあることを明示）
const src = "./henshin.txt";
//ファイルを読み込み
const bytes = fs.readFileSync(src);
//バイト列から文字列に
const txt = bytes.toString();
//文字の配列にする
const arr = Array.from(txt);
//配列の文字コードを1つ隣へずらす
const shifted = arr.map( c => String.fromCodePoint(c.codePointAt(0)+1));
//ソートした配列を（区切り文字なしで）結合
const shifted_str = shifted.join("");
//ファイルに保存
fs.writeFileSync("henshin_shifted.txt",shifted_str);
```

{{< button href="text_unicode_shift.js">}}text_unicode_shift.js{{< /button >}}

### text_unicode_shift_grad.js （文字列のUnicodeコードポイントをずらす確率を段々上げていく）


```js
//ファイル読み込みライブラリを使用
const fs = require("fs");
//ファイル名の指定（./はこのjsファイルと同階層にあることを明示）
const src = "./henshin.txt";
//ファイルを読み込み
const bytes = fs.readFileSync(src);
//バイト列から文字列に
const txt = bytes.toString();
//文字の配列にする
const arr = Array.from(txt);

//文字コードをずらす確率
let probability = 0.0;
const shifted = arr.map(c => {
    //配列の最初：0%-最後:100%になるように確率を変更していく
    probability += 1 / arr.length;
    //randomは0~1の乱数
    if (Math.random() < probability) {
        //配列の文字コードを1つ隣へずらす
        return String.fromCodePoint(c.codePointAt(0) + 1)
    } else {
        return c
    }
});
//ソートした配列を（区切り文字なしで）結合
const shifted_str = shifted.join("");
//ファイルに保存
fs.writeFileSync("henshin_shifted_grad.txt", shifted_str);
```

{{< button href="text_unicode_shift_grad.js">}}text_unicode_shift_grad.js{{< /button >}}
