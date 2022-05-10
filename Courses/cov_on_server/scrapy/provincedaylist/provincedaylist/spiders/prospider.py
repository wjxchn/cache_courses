# -*- coding: utf-8 -*-
import scrapy
import json
import provincedaylist.items as pi

class ProspiderSpider(scrapy.Spider):
    name = "prospider"
    allowed_domains = ["news.qq.com"]
    start_urls = 'https://api.inews.qq.com/newsqa/v1/query/pubished/daily/list'

    def start_requests(self):
        data = [
            {'province': "台湾"},
            {'province': "广东"},
            {'province': "香港"},
            {'province': "云南"},
            {'province': "福建"},
            {'province': "浙江"},
            {'province': "四川"},
            {'province': "上海"},
            {'province': "北京"},
            {'province': "江苏"},
            {'province': "湖南"},
            {'province': "天津"},
            {'province': "陕西"},
            {'province': "河南"},
            {'province': "澳门"},
            {'province': "安徽"},
            {'province': "辽宁"},
            {'province': "湖北"},
            {'province': "内蒙古"},
            {'province': "广西"},
            {'province': "山西"},
            {'province': "海南"},
            {'province': "宁夏"},
            {'province': "重庆"},
            {'province': "贵州"},
            {'province': "黑龙江"},
            {'province': "吉林"},
            {'province': "甘肃"},
            {'province': "新疆"},
            {'province': "河北"},
            {'province': "山东"},
            {'province': "青海"},
            {'province': "江西"},
            {'province': "西藏"},
        ]

        for province in data:
            yield scrapy.FormRequest(url=self.start_urls, formdata=province, callback=self.parse)

    def parse(self, response):
        result = json.loads(response.text)['data']
        list = result[len(result) - 2: len(result)]
        for children in list:
            item = pi.ProvincedaylistItem()
            item['date'] = children['date']
            item['name'] = children['province'] + "（省/直辖市/特别行政区/自治区）"
            item['y'] = children['year']
            item['confirm'] = children['confirm']
            item['confirmAdd'] = children['confirm_add']
            item['heal'] = children['heal']
            item['healAdd'] = children['newHeal']
            item['dead'] = children['dead']
            item['deadAdd'] = children['newDead']
            yield item
