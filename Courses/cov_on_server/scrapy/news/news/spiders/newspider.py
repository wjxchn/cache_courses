# -*- coding: utf-8 -*-
import scrapy
import json
import news.items as ni
import datetime


class NewspiderSpider(scrapy.Spider):
    name = "newspider"
    allowed_domains = ["voice.baidu.com"]
    start_urls = 'https://opendata.baidu.com/data/inner?tn=reserved_all_res_tn&dspName=iphone&from_sf=1&dsp=iphone&resource_id=28565&alr=1&query='
    data = [
        {'name': '国内', 'location_id': 1},

        {'name': '国外', 'location_id': 0},

        {'name': "台湾", 'location_id': 2},

        {'name': "广东", 'location_id': 4},

        {'name': "香港", 'location_id': 27},

        {'name': "云南", 'location_id': 29},

        {'name': "福建", 'location_id': 45},

        {'name': "浙江", 'location_id': 57},

        {'name': "四川", 'location_id': 71},

        {'name': "上海", 'location_id': 94},

        {'name': "北京", 'location_id': 115},

        {'name': "江苏", 'location_id': 134},

        {'name': "湖南", 'location_id': 149},

        {'name': "天津", 'location_id': 165},

        {'name': "陕西", 'location_id': 182},

        {'name': "河南", 'location_id': 197},

        {'name': "澳门", 'location_id': 218},

        {'name': "安徽", 'location_id': 220},

        {'name': "辽宁", 'location_id': 238},

        {'name': "湖北", 'location_id': 255},

        {'name': "内蒙古", 'location_id': 274},

        {'name': "广西", 'location_id': 287},

        {'name': "山西", 'location_id': 302},

        {'name': "海南", 'location_id': 315},

        {'name': "宁夏", 'location_id': 332},

        {'name': "重庆", 'location_id': 340},

        {'name': "贵州", 'location_id': 381},

        {'name': "黑龙江", 'location_id': 392},

        {'name': "吉林", 'location_id': 408},

        {'name': "甘肃", 'location_id': 420},

        {'name': "新疆", 'location_id': 434},

        {'name': "河北", 'location_id': 449},

        {'name': "山东", 'location_id': 463},

        {'name': "青海", 'location_id': 480},

        {'name': "江西", 'location_id': 483},

        {'name': "西藏", 'location_id': 497},
    ]
    suffix = '新型肺炎最新动态'

    def start_requests(self):
        for children in self.data:
            yield scrapy.FormRequest(url=self.start_urls + children['name'] + self.suffix,
                                     callback=lambda response, name=children: self.parse(response, name))

    def parse(self, response, name):
        pass
        print(name)
        result = json.loads(response.text)
        if len(result['Result']) > 0:
            result = result['Result'][0]['items_v2'][0]['aladdin_res']['DisplayData']['result'][
                'items']
            print(result[0])
            for children in result:
                item = ni.NewsItem()
                item['title'] = children['eventDescription']
                timeStamp = float(children['eventTime'])
                dateArray = datetime.datetime.fromtimestamp(timeStamp)
                time = dateArray.strftime('%Y-%m-%d %H:%M:%S')
                item['time'] = time
                item['url'] = children['eventUrl']
                item['site'] = children['siteName']
                item['location_id'] = name['location_id']
                yield item
            # print(name)
        else:
            print('暂无相关新闻')
