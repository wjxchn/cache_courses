cd /home/scrapy/airline
nohup /usr/local/bin/scrapy crawl airlinespider >> airline.log 2>&1 &
cd /home/scrapy/train
nohup /usr/local/bin/scrapy crawl trainspider >> train.log 2>&1 &
