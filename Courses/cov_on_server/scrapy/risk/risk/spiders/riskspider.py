# -*- coding: utf-8 -*-
import json
import scrapy
import re
import risk.items as ri

class RiskspiderSpider(scrapy.Spider):
    name = "riskspider"
    allowed_domains = ["news.qq.com"]
    start_urls = ['https://api.inews.qq.com/newsqa/v1/query/inner/publish/modules/list?modules=statisGradeCityDetail']

    def parse(self, response):
        result = json.loads(response.text)
        list = result['data']['statisGradeCityDetail']
        print(list)
        dict = {'name': 'dictionary'}
        for area in list:
            item = ri.RiskItem()
            grade = area['grade']
            low = re.search('低风险', grade)
            mid = re.search('中风险', grade)
            if low is not None:
                risk = 0
            elif mid is not None:
                risk = 1
            else:
                risk = 2
            province = area['province'] + "（省/直辖市/特别行政区/自治区）"
            if dict.get(province) is None:
                dict[province] = risk
            elif dict.get(province) < risk:
                dict[province] = risk
            item['name'] = province
            item['risk'] = dict[province]
            yield item
            item['name'] = area['city'] + "（" + province + "）"
            dict[item['name']] = risk
            item['risk'] = risk
            yield item

