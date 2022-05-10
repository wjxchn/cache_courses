# -*- coding: utf-8 -*-
import scrapy
import json
import time
import oversea_cov.items as os


class OscovspiderSpider(scrapy.Spider):
    name = "oscovspider"
    allowed_domains = ["news.qq.conm"]
    start_urls = ['https://api.inews.qq.com/newsqa/v1/automation/foreign/country/ranklist',
                  'https://api.inews.qq.com/newsqa/v1/automation/modules/list?modules=FAutoGlobalStatis,FAutoGlobalDailyList,FAutoCountryConfirmAdd']
    def parse(self, response):
        result = json.loads(response.text)
        url = str(response.url)
        if url == 'https://api.inews.qq.com/newsqa/v1/automation/foreign/country/ranklist':
            # 海外
            list = result['data']
            datetime = time.strftime("%Y-%m-%d %H:%M:%S", time.localtime())
            for children in list:
            # children = list[0]
                pass
                item = os.Item()
                item['name'] = children['name']
                if item['name'] == '日本本土':
                    item['name'] = '日本'
                item['confirm'] = children['confirm']
                item['confirmAdd'] = children['confirmAdd']
                item['nowConfirm'] = children['nowConfirm']
                item['nowConfirmAdd'] = children['nowConfirmCompare']
                item['heal'] = children['heal']
                item['healAdd'] = children['healCompare']
                item['dead'] = children['dead']
                item['deadAdd'] = children['deadCompare']
                item['time'] = datetime
                yield item
        elif url == 'https://api.inews.qq.com/newsqa/v1/automation/modules/list?modules=FAutoGlobalStatis,FAutoGlobalDailyList,FAutoCountryConfirmAdd':
            children = result['data']['FAutoGlobalStatis']
            item = os.Item()
            item['name'] = '外国'
            item['confirm'] = children['confirm']
            item['confirmAdd'] = children['confirmAdd']
            item['nowConfirm'] = children['nowConfirm']
            item['nowConfirmAdd'] = children['nowConfirmAdd']
            item['heal'] = children['heal']
            item['healAdd'] = children['healAdd']
            item['dead'] = children['dead']
            item['deadAdd'] = children['deadAdd']
            item['time'] = children['lastUpdateTime']
            yield item
