import scrapy
from qiushipro.items import QiushiproItem


class PipelinetestSpider(scrapy.Spider):
    name = 'pipelinetest'
    #allowed_domains = ['www.xxx.com']
    start_urls = ['https://www.qiushibaike.com/text/']

    def parse(self, response):
        div_list = response.xpath('//div[@id="content"]/div/div[2]/div')
        for div in div_list:
            author = div.xpath('./div[@class="author clearfix"]/a[2]/h2/text()')[0].extract()
            content =  div.xpath('./a[1]/div/span//text()').extract()
            content = ''.join(content)

            item = QiushiproItem()
            item['author'] = author
            item['content'] = content

            yield item #将item提交给了管道
