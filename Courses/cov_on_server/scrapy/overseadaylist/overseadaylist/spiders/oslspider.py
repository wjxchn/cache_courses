# -*- coding: utf-8 -*-
import scrapy
import json
import overseadaylist.items as oi

class OslspiderSpider(scrapy.Spider):
    name = "oslspider"
    allowed_domains = ["news.qq.com"]
    start_urls = ['https://api.inews.qq.com/newsqa/v1/automation/modules/list?modules=FAutoGlobalStatis,FAutoGlobalDailyList,FAutoCountryConfirmAdd']

    def parse(self, response):
        result = json.loads(response.text)
        data = result['data']['FAutoGlobalDailyList']
        print(data[0])
        for children in data:
            item = oi.OverseadaylistItem()
            item['date'] = children['date']
            item['y'] = children['y']
            item['confirm'] = children['all']['confirm']
            item['confirmAdd'] = children['all']['newAddConfirm']
            item['heal'] = children['all']['heal']
            item['healRate'] = children['all']['healRate']
            item['dead'] = children['all']['dead']
            item['deadRate'] = children['all']['deadRate']
            # print(item)
            yield item