const puppeteer = require('puppeteer');

const take_screen_shot = async (browser, url, index) => {
    let page = await browser.newPage();
    let path = `${index}.png`;
    await page.goto(url);
    await page.screenshot({ path: path });
    await page.close();
}

const main = async () => {
    let browser = await puppeteer.launch({ headless: false ,args: ["--window-size=1920,1080"],timeout:0});
    const urllist = ["https://www.youtube.com",
        "https://www.google.com",
        "https://www.geidai.ac.jp",
        "https://yahoo.co.jp"]
    await Promise.all(urllist.map((url, index) => take_screen_shot(browser, url, index)));
    await browser.close();
}

main();