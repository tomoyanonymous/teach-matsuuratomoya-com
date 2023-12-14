const puppeteer = require('puppeteer');
const autoScroll = require("./autoscroll.js").autoScroll;

const main = async () => {
    let browser = await puppeteer.launch({ headless: false });
    let page = await browser.newPage();
    await page.goto('https://www.youtube.com/');
    await autoScroll(page,10);
    await page.screenshot({ path: "ss_full.png", fullPage: true })
    await page.close();
    await browser.close();
}
main();