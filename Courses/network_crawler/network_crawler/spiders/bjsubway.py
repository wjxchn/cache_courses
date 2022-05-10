import scrapy


class BjsubwaySpider(scrapy.Spider):
    name = 'bjsubway'
    allowed_domains = ['map.bjsubway.com']
    start_urls = ['https://map.bjsubway.com/']

    def parse(self, response):
        is_busy_list = response.xpath('body/div[@id="app"]/div[@class="container-fluid"]/div[@class="row"]/div/div')
        # print(is_busy_list)
        is_busy_list_in = is_busy_list.xpath('div[@id="subway_map"]')
        print(is_busy_list_in.extract())
        svg_url = "https://map.bjsubway.com/vendor/svg/svg.js"
        
