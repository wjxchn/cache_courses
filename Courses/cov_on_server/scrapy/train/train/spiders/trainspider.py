import datetime
import scrapy
import json
import train.items as ti

class TrainspiderSpider(scrapy.Spider):
    name = 'trainspider'
    allowed_domains = ['search.12306.cn',
                       'kyfw.12306.cn']
    start_urls = 'https://search.12306.cn/search/v1/train/search?keyword='
    # alpha = ['k']
    alpha = ['k', 'g', 'z', 'd', '', 't', 'c', 's']
    suffix = '&date=' + datetime.date.today().strftime('%Y%m%d')

    def start_requests(self):
        for a in self.alpha:
            # for i in range(1, 2):
            for i in range(1, 10):
                keyword = a + str(i)
                yield scrapy.Request(url=self.start_urls+keyword+self.suffix, callback=lambda response: self.parse(response))

    def parse(self, response):
        result = json.loads(response.text)
        data = result['data']
        # train = data[0]
        for train in data:
            item = ti.TrainItem()
            item['train_no'] = train['station_train_code']
            no = train['train_no']
            item['to_station'] = train['to_station']
            item['from_station'] = train['from_station']
            item['total_num'] = train['total_num']
            item['date'] = datetime.date.today().strftime('%Y-%m-%d')
            item['stops'] = '北京, 天津'
            # print(item)
            # yield item
            yield scrapy.Request(url='https://kyfw.12306.cn/otn/queryTrainInfo/query?leftTicketDTO.train_no='+no+'&leftTicketDTO.train_date='+datetime.date.today().strftime('%Y-%m-%d')+'&rand_code=', callback=lambda response1, titem = item:self.parse1(response1, titem))
        # print(result)

    def parse1(self, response, item):
        result = json.loads(response.text)
        # print(result)
        data = result['data']['data']
        pass_stations = ''
        for i in range(len(data)):
            if i == 0:
                pass
            elif i == len(data) - 1:
                pass
            else:
                pass_stations += data[i]['station_name'] + ','
        item['stops'] = pass_stations
        # print(item)
        yield item
