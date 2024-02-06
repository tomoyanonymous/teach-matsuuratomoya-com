const fs = require("fs");
//青空文庫から落としたファイルの場合、一度shift-jisからutf-8に変換すること。
//例で使用したのはフランツ・カフカ「変身」
//https://www.aozora.gr.jp/cards/001235/card49866.html
const src = "henshin.txt";
//ファイルをテキストデータとして読み込み
const txt = fs.readFileSync(src).toString();

//長いデータの中身を見てみたい場合は、頭の1000文字だけ取り出してコンソールに流すなどする
// const summary = txt.slice(0,1000);
// console.log(summary)

// 主人公の名前だけを抜き出して空白に置き換える
const no_gregor = txt.replace(/グレゴール/gm, "《    》");

fs.writeFileSync("henshin_nogregor.txt", no_gregor);

let only_gregor = "";
let lines = txt.split(/\n/);

//逆に、主人公の名前以外は全て◻︎で置き換えてみよう
for (l of lines) {
    const array = l.split("グレゴール");
    if (array.length > 1) {
        only_gregor += array.map((s) => "□".repeat(s.length)).join('グレゴール');
    } else {
        only_gregor += "□".repeat(array[0].length)
    }
    only_gregor += "\n"
}
fs.writeFileSync("henshin_onlygregor.txt", only_gregor);

//会話だけを抜き出してみる
let only_spoken_words = "";
for (l of lines) {
    // let matches=  l.match(/「(.*)」/g);
    let matches = l.match(/「([^」]+)」/g);
    if (matches != null) {
        only_spoken_words += matches.join("\n") + "\n"
    }
}
fs.writeFileSync("henshin_onlyspokenwords.txt", only_spoken_words);

//会話の中で!で終わるものだけを抜き出してみる
let excramation = "";
for (l of lines) {
    let matches = l.match(/(?!。|　|「)([^。　「]*?)！/g);
    if (matches != null) {
        excramation += matches.join("\n") + "\n"
    }
}

fs.writeFileSync("henshin_excramation.txt", excramation);


//テキストを文字の配列として扱い、後半に行くにつれて文字コードを確率的にずらしていく
let nextunicode = "";
let probability = 0.0;
const tarray = Array.from(txt);
for (const c of tarray) {
    if (c.at(0) == "\n") {
        nextunicode += "\n";
    } else {
        nextunicode += String.fromCodePoint(c.codePointAt(0) + Math.floor(Math.random() * probability * 6));
    }
    probability += 1 / tarray.length;
}

fs.writeFileSync("henshin_nextunicode.txt", nextunicode);