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
