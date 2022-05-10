# -*- coding: utf-8 -*-
import scrapy
import json
import domesticcov.items as do

class DcovspiderSpider(scrapy.Spider):
    name = "dcovspider"
    allowed_domains = ["news.qq.com", "restapi.amap.com"]
    start_urls = ['https://view.inews.qq.com/g2/getOnsInfo?name=disease_h5']


    def parse(self, response):
        i = 1
        result = json.loads(response.text)
        # 国内
        data = json.loads(result['data'])
        time = data["lastUpdateTime"]
        print(data["chinaTotal"])
        ct = data['chinaTotal']
        print(data["chinaAdd"])
        ca = data['chinaAdd']
        # print(data["areaTree"][0]["children"][0])
        item = do.CtItem()
        item['id'] = i
        item['name'] = "中国"
        item['belong_id'] = 1
        item['type'] = 0
        item['confirm'] = ct['confirm']
        item['confirmAdd'] = ca['confirm']
        item['nowConfirm'] = ct['nowConfirm']
        item['nowConfirmAdd'] = ca['nowConfirm']
        item['dead'] = ct['dead']
        item['deadAdd'] = ca['dead']
        item['heal'] = ct['heal']
        item['healAdd'] = ca['heal']
        item['noInfect'] = ct['noInfect']
        item['noInfectAdd'] = ca['noInfect']
        item['time'] = time
        i = i + 1
        yield item
        # yield scrapy.Request(url='https://restapi.amap.com/v3/geocode/geo?address=中国&key=d05ecc16db2af3450e049076b7359134',
        #                      callback=lambda response1, titem=item: self.parse1(response1, titem))
        list = data['areaTree'][0]['children']
        for children in list:
            item = do.CtItem()
            total = children['total']
            today = children['today']
            llist = children['children']
            belong_id = i
            item['id'] = i
            item['name'] = children['name'] + "（省/直辖市/特别行政区/自治区）"
            name = item['name']
            item['belong_id'] = 1
            item['type'] = 1
            item['confirm'] = total['confirm']
            item['confirmAdd'] = today['confirm']
            item['nowConfirm'] = total['nowConfirm']
            item['heal'] = total['heal']
            item['dead'] = total['dead']
            item['nowConfirmAdd'] = None
            item['deadAdd'] = None
            item['healAdd'] = None
            item['noInfect'] = None
            item['noInfectAdd'] = None
            item['time'] = time
            i = i + 1
            # yield scrapy.Request(url='https://restapi.amap.com/v3/geocode/geo?address='+children['name']+'&key=d05ecc16db2af3450e049076b7359134', callback=lambda response1, titem=item:self.parse1(response1,titem))
            yield item
            for cchildren in llist:
                item = do.CtItem()
                item['id'] = i
                item['name'] = cchildren['name'] + "（" + name + "）"
                item['belong_id'] = belong_id
                item['type'] = 2
                item['confirm'] = cchildren['total']['confirm']
                item['confirmAdd'] = cchildren['today']['confirm']
                item['nowConfirm'] = cchildren['total']['nowConfirm']
                item['heal'] = cchildren['total']['heal']
                item['dead'] = cchildren['total']['dead']
                item['nowConfirmAdd'] = None
                item['deadAdd'] = None
                item['healAdd'] = None
                item['noInfect'] = None
                item['noInfectAdd'] = None
                item['time'] = time
                i = i + 1
                # yield scrapy.Request(url='https://restapi.amap.com/v3/geocode/geo?address=' + cchildren[
                #     'name'] + '&key=d05ecc16db2af3450e049076b7359134',callback=lambda response1, titem=item: self.parse1(response1, titem))
                yield item

    # def parse1(self, response, item):
    #     result = json.loads(response.text)
    #     data = result['geocodes'][0]
    #     locationlist = data['location'].split(',')
    #     item['latitude'] = locationlist[0]
    #     item['longitude'] = locationlist[1]
    #     # print(item)
    #     yield item


