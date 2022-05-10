import scrapy
#scrapy startproject scrapytest
#cd scrapytest
#scrapy genspider first www.xxx.com
#scrapy crawl first [--nolog]
#设置文件中 LOG_LEVEL = 'ERROR' 只输出错误日志

class FirstSpider(scrapy.Spider):
    # name为唯一属性
    name = 'first'
    # 允许的域名 用来限定start_urls列表中那些urls可以进行请求发送
    allowed_domains = ['www.baidu.com','www.sogou.com']
    # 起始的url列表：该列表中存放的url会被scrapy自动发送
    start_urls = ['https://www.baidu.com/','https://www.sogou.com']

    #用作于数据解析 response参数表示的就是请求成功之后对应的响应对象
    #两次url,两个响应对象，parse执行次数由start_urls列表决定
    def parse(self, response):
        print(response)
