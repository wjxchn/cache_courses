# -*- coding: utf-8 -*-
import scrapy
import json
import vaccinationtrend.items as vi

class VtspiderSpider(scrapy.Spider):
    name = "vtspider"
    allowed_domains = ["news.qq.com"]
    start_urls = ['https://api.inews.qq.com/newsqa/v1/automation/modules/list?modules=ChinaVaccineTrendData']

    def parse(self, response):
        result = json.loads(response.text)
        data = result['data']['ChinaVaccineTrendData']
        # print(data)
        for children in data:
            item = vi.VaccinationtrendItem()
            item['date'] = children['date']
            item['y'] = children['y']
            item['total_vaccinations'] = children['total_vaccinations']
            item['total_vaccinations_per_hundred'] = children['total_vaccinations_per_hundred']
            print(item)
            yield item