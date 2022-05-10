import scrapy


class XhSpider(scrapy.Spider):
    name = 'xh'
    #allowed_domains = ['www.xxx.com']
    start_urls = ['http://www.521689.com/meinvxiaohua']

    def parse(self, response):
        pass
