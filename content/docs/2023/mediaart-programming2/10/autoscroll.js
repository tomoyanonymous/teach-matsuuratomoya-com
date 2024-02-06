async function autoScroll(page, maxScrolls) {
    await page.evaluate(async maxScrolls => {
        await new Promise((then) => {
            let distance = 1000;
            let scrolls = 0; 
            let timer = setInterval(() => {
                window.scrollBy(0, distance);
                scrolls += 1;
               if (scrolls >= maxScrolls) {
                    clearInterval(timer);
                    then();
                }
            }, 100);
        });
    }, maxScrolls);
}

exports.autoScroll = autoScroll;