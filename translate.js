const fs = require("fs").promises;
const path = require("path");
const API_KEY = process.env.DEEPL_API_KEY;
const deepl = require('deepl-node');
const translator = new deepl.Translator(API_KEY);


const main = async () => {
    try {
        if (!process.argv[2]) {
            throw new Error("File path is not set.")
        }
        const file_path = process.argv[2];
        const writepath = path.dirname(file_path) + '/' + path.parse(file_path).name + ".en" + path.extname(file_path);
        console.log(`source: ${file_path}\ndst: ${String(writepath)}`)
        console.log(`API_KEY:${API_KEY}`)
        const data = await fs.readFile(file_path, 'utf8');
        let chunk = [];
        const last = data.split('\n').reduce((acc, line) => {
            if (acc && acc.length > 5000) {
                chunk.push(acc);
                acc = "";
                return line
            } else {
                return acc + "\n" + line
            }
        }, "");
        chunk.push(last);
        if (chunk[0]) {
            const res = await Promise.all(chunk.map(c => {
                console.debug(c);
                return deeplTranslate(c)
            }
            ))
            const resstr = fixWrongFormatting(res.join("\n"));
            await fs.writeFile(writepath, resstr)
        }
    } catch (error) {
        console.error(error)
    }
}
async function deeplTranslate(deeplInput) {
    return translator
        .translateText(deeplInput, "ja", 'en-us')
        .then((result) => {
            return result.text
        })
}
function fixWrongFormatting(src) {
    let res = "";
    //fix codeblock
    res = src.replace(/You can use the ``sh/g, "```sh");
    res = res.replace(/`{2}sh\n/g, "```sh\n");

    res = res.replace(/^.*``([a-z]*)\n/g, "```$1\n");
    res = res.replace(/`{4,}/g, "```");
    //fix inline code
    res = res.replace(/`{2}(.+)`{2}/g, "`$1`");
    //fix image link
    res = res.replace(/![\t\s]+\[/g, "![");
    //fix link

    res = res.replace(/\][\t\s]+\(/g, "](");
    //fix hugo shortcode
    res = res.replace(/>\}{2,}/g, ">}}");
    return res
}
main();