const puppeteer = require('puppeteer');
const autoScroll = require("./autoscroll.js").autoScroll;

const main = async () => {
    let browser = await puppeteer.launch({ headless: false });
    let page = await browser.newPage();
    await page.goto('https://www.youtube.com/');
    for (let i = 0; i < 1000; i++) {
        const urllist = await page.$$eval("a#thumbnail", elems => elems.map(elem => elem.href));
        const url = urllist[3];
        console.log(url)
        await page.goto(url);
        await autoScroll(page, 10);
        await page.screenshot({ path: `${i}.png`, fullPage: true });
    }
    await page.close();
    await browser.close();
}
main();