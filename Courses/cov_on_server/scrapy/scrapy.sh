cd /home/scrapy/domesticcov
nohup /usr/local/bin/scrapy crawl dcovspider >> dcov.log 2>&1 &
cd /home/scrapy/oversea_cov
nohup /usr/local/bin/scrapy crawl oscovspider >> oscov.log 2>&1 &
cd /home/scrapy/risk
nohup /usr/local/bin/scrapy crawl riskspider >> risk.log 2>&1 &
cd /home/scrapy/chinadaylist
nohup /usr/local/bin/scrapy crawl cdlspider >> cdl.log 2>&1 &
cd /home/scrapy/overseadaylist
nohup /usr/local/bin/scrapy crawl oslspider >> osl.log 2>&1 &
cd /home/scrapy/provincedaylist
nohup /usr/local/bin/scrapy crawl prospider >> pro.log 2>&1 &
cd /home/scrapy/countrydaylist
nohup /usr/local/bin/scrapy crawl cdlspider >> cdl.log 2>&1 &
cd /home/scrapy/news
nohup /usr/local/bin/scrapy crawl newspider >> news.log 2>&1 &
cd /home/scrapy/nia
nohup /usr/local/bin/scrapy crawl niaspider >> nia.log 2>&1 &
cd /home/scrapy/vaccination
nohup /usr/local/bin/scrapy crawl vcspider >> vc.log 2>&1 &
cd /home/scrapy/vaccinationtrend
nohup /usr/local/bin/scrapy crawl vtspider >> vt.log 2>&1 &
cd /home/scrapy/mangshi
nohup /usr/local/bin/scrapy crawl mangshispider >> ms.log 2>&1 &
