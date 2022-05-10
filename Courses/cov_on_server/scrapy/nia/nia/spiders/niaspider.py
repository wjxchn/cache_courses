import scrapy
import nia.items as ni
import time
import json

class NiaspiderSpider(scrapy.Spider):
    name = 'niaspider'
    allowed_domains = ['www.nia.gov.cn']
    start_urls = ['https://www.nia.gov.cn/n794014/n1050176/n1077211/n1215569/n1215576/index.html',
                  'https://www.nia.gov.cn/n794014/n1050176/n1077211/n1215569/n1215581/index.html']

    def parse(self, response):
        url = str(response.url)
        if url == 'https://www.nia.gov.cn/n794014/n1050176/n1077211/n1215569/n1215576/index.html':
            pass
            list = scrapy.Selector(text=response.text).xpath('/html/body/div[3]/ul/li')
            # print(list.extract())
            datetime = time.strftime("%Y-%m-%d %H:%M:%S", time.localtime())
            print(len(list))
            for country in list:
                name = country.xpath('./dl/dt/a/text()').extract()[0]
                content = country.xpath('./dl/dd/text()').extract()[0]
                item = ni.NiaItem()
                item['name'] = name
                item['content'] = content
                item['time'] = datetime
                item['index'] = 0
                yield item
            print(item)
        else:
            pass
            list = scrapy.Selector(text=response.text).xpath('/html/body/div[1]/div[1]/div[4]/div/ul/li')
            # print(list.extract())
            datetime = time.strftime("%Y-%m-%d %H:%M:%S", time.localtime())
            print(len(list))
            for port in list:
                province = port.xpath('./@province').extract()[0]
                name = port.xpath('./div[1]/p/text()').extract()[0]
                contentlist = port.xpath('./div[2]/p/text()')
                content = ''
                for ct in contentlist:
                    content += ct.extract() + '  '
                item = ni.NiaItem()
                item['name'] = name
                item['province'] = province
                item['content'] = content
                item['time'] = datetime
                item['index'] = 1
                yield item
                # print(item)
