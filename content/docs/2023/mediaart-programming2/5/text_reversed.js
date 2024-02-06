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
