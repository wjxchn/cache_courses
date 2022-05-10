import time

import scrapy
import json
import mangshi.items as mi

class MangshispiderSpider(scrapy.Spider):
    name = 'mangshispider'
    allowed_domains = ['flights.ctrip.com']
    start_urls = ['https://flights.ctrip.com/schedule/lum..html']
    total = 0

    headers = {
        'content-type': 'application/json;charset=UTF-8',
        'accept': 'application/json',
        'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_12_0) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/72.0.3626.121 Safari/537.36'
    }

    def parse(self, response):
        list = scrapy.Selector(text=response.text).xpath('/html/body/li/div[3]/div[2]/div[2]/div/ul[1]/li')
        for slist in list:
            sslist = slist.xpath('./div/a')
            for airline in sslist:
                href = airline.xpath('./@href').extract()[0]
                line = href[10:17]
                codelist = line.split('.')
                from_code = codelist[0]
                to_code = codelist[1]
                print(from_code)
                print(to_code)
                url = 'https://flights.ctrip.com/schedule/getScheduleByCityPair'
                formdata = {"departureCityCode": from_code.upper(),
                            "arriveCityCode": to_code.upper()}
                yield scrapy.Request(url=url, method='POST', body=json.dumps(formdata), headers=self.headers,
                                     callback=self.parse2)

    def parse2(self, response):
        result = json.loads(response.text)
        url = str(response.url)
        from_code = result['departureCityCode']
        to_code = result['arriveCityCode']
        totalPage = result['totalPage']
        curPage = result['curPage']
        if curPage == 1:
            self.total += result['totalCount']
        flightlist = result['scheduleVOList']
        for flight in flightlist:
            item = mi.MangshiItem()
            item['flight_no'] = flight['flightNo']
            item['from_airport'] = flight['departPortName']
            item['to_airport'] = flight['arrivePortName']
            item['stop'] = flight['stopCityName']
            item['company'] = flight['airlineCompanyName']
            item['date'] = time.strftime("%Y-%m-%d", time.localtime())
            # print(item)
            print('total: ' + str(self.total))
            yield(item)
        if curPage < totalPage:
            formdata = {"departureCityCode": from_code,
                        "arriveCityCode": to_code,
                        "pageNo": curPage + 1}
            yield scrapy.Request(url=url, method='POST', body=json.dumps(formdata), headers=self.headers,
                                 callback=self.parse2)
