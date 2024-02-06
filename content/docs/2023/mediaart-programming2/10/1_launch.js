const puppeteer = require('puppeteer');

const main = async () => {
    let browser = await puppeteer.launch({ headless: false });
    let page = await browser.newPage();
    await page.goto('https://www.youtube.com/');
    await page.screenshot({ path: "./ss.png", fullPage: true });
    await page.close();
    await browser.close();
};

main();
