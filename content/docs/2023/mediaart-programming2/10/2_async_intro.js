const puppeteer = require('puppeteer');

const main = async () =>
    puppeteer.launch({ headless: false })
        .then(browser => browser.newPage()
            .then(page => page.goto('https://www.youtube.com/')
                .then(_response => page.screenshot({ path: "./ss.png" })
                    .then(_ => page.close()
                        .then(_ => browser.close())))));

main();
