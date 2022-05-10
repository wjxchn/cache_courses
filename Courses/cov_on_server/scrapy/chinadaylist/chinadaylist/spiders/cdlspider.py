# -*- coding: utf-8 -*-
import scrapy
import json
import chinadaylist.items as ci


class CdlspiderSpider(scrapy.Spider):
    name = "cdlspider"
    allowed_domains = ["news.qq.com"]
    start_urls = ['https://api.inews.qq.com/newsqa/v1/query/inner/publish/modules/list?modules=chinaDayList']

    def parse(self, response):
        result = json.loads(response.text)
        data = result['data']['chinaDayList']
        # print(data[0])
        for children in data:
            item = ci.ChinadaylistItem()
            item['date'] = children['date']
            item['y'] = children['y']
            item['confirm'] = children['confirm']
            item['nowConfirm'] = children['nowConfirm']
            item['heal'] = children['heal']
            item['healRate'] = children['healRate']
            item['dead'] = children['dead']
            item['deadRate'] = children['deadRate']
            item['noInfect'] = children['noInfect']
            item['noInfectH5'] = children['noInfectH5']
            item['nowSevere'] = children['nowSevere']
            item['suspect'] = children['suspect']
            item['importedCase'] = children['importedCase']
            item['localConfirm'] = children['localConfirm']
            item['localConfirmH5'] = children['localConfirmH5']
            yield item
