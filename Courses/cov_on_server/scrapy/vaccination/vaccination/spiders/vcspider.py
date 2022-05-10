# -*- coding: utf-8 -*-
import scrapy
import json
import vaccination.items as vc

class VcspiderSpider(scrapy.Spider):
    name = "vcspider"
    allowed_domains = ["news.qq.com"]
    start_urls = ['https://api.inews.qq.com/newsqa/v1/automation/modules/list?modules=VaccineSituationData',
                  'https://api.inews.qq.com/newsqa/v1/automation/modules/list?modules=VaccineTopData']

    def parse(self, response):
        data = json.loads(response.text)
        url = str(response.url)
        if url == 'https://api.inews.qq.com/newsqa/v1/automation/modules/list?modules=VaccineSituationData':
            pass
            print(data['data']['VaccineSituationData'][0])
            list = data['data']['VaccineSituationData']
            for country in list:
                item = vc.VaccinationItem()
                item['name'] = country['country']
                item['total_vaccinations'] = country['total_vaccinations']
                item['total_vaccinations_per_hundred'] = country['total_vaccinations_per_hundred']
                item['vaccinations'] = country['vaccinations']
                yield item
        elif url == 'https://api.inews.qq.com/newsqa/v1/automation/modules/list?modules=VaccineTopData':
            pass
            data = data['data']['VaccineTopData']['全球']
            item = vc.VaccinationItem()
            item['name'] = '外国'
            item['total_vaccinations'] = data['total_vaccinations']
            item['total_vaccinations_per_hundred'] = data['total_vaccinations_per_hundred']
            item['vaccinations'] = None
            yield item


