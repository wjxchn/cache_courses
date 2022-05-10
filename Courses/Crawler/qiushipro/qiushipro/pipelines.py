# Define your item pipelines here
#
# Don't forget to add your pipeline to the ITEM_PIPELINES setting
# See: https://docs.scrapy.org/en/latest/topics/item-pipeline.html
import pymysql


# useful for handling different item types with a single interface
from itemadapter import ItemAdapter


class QiushiproPipeline:
    fp = open('./qiubai.txt','a',encoding='utf-8')

    def process_spider(self,spider):
        print('开始爬虫......')
        self.fp = open('./qiubai.txt','a',encoding='utf-8')

    def process_item(self, item, spider):
        author = item['author']
        content = item['content']
        self.fp.write(author+':'+content+'\n')
        
        return item #即将传递给下一个即将被执行的管道类
    
    def close_spider(self,spider):
        print('结束爬虫')
        self.fp.close()

# 需要在ITEM_PIPELINES设置
class mysqlPipeLine(object):
    connection = None
    cursor = None

    def open_spider(self,spider):
        self.connection = pymysql.Connect(host='127.0.0.1',port=3306,user='root',password='Wjxteam123',db='qiushimysql',charset='utf-8')

    def process_item(self,item,spider):
        self.cursor = self.connection.cursor()
        try:
            self.cursor.execute('insert into qiubai values("%s","%s)'%(item["author"],item["content"]))
            self.connection.commit()
        except Exception as e:
            print(e)
            self.conn.rollback()
        return item
    
    def close_spider(self,spider):
        self.cursor.close()
        self.connection.close()