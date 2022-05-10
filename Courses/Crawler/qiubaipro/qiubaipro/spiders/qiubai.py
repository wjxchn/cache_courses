import scrapy


class QiubaiSpider(scrapy.Spider):
    name = 'qiubai'
    #allowed_domains = ['www.qiushibaike.com']
    start_urls = ['http://www.qiushibaike.com/text/']

    def parse(self, response):
        div_list = response.xpath('//div[@id="content"]/div/div[2]/div')
        # print(div_list)
        all_data = []
        for div in div_list:
            author = div.xpath('./div[@class="author clearfix"]/a[2]/h2/text()')[0].extract()
            #class一定要打全
            #print(author)
            
            #也可用extract_first()，前面不带[0]，在列表只有一个元素时使用。
            #extract()将列表中每一个Selector对象中data对应的字符串提取
            content =  div.xpath('./a[1]/div/span//text()').extract()
            #有<br/>，所以为//，而不是/
            content = ''.join(content)
            #将列表转换为字符串
            #print(content)

            dic={
                'author': author,
                'content': content
            }
            all_data.append(dic)
        
        return all_data

#scrapy crawl qiubai -o ./qiubai.csv
#持久化存储对应的文本文件的类型只可以为json,jsonlines,jl,csv,xml,mashal,pickle

