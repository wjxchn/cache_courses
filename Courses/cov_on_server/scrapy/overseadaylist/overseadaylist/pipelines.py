# -*- coding: utf-8 -*-

# Define your item pipelines here
#
# Don't forget to add your pipeline to the ITEM_PIPELINES setting
# See: http://doc.scrapy.org/en/latest/topics/item-pipeline.html
import pymysql

class OverseadaylistPipeline(object):
    def open_spider(self, spider):
        db = spider.settings.get('MYSQL_DB_NAME', 'cov')
        host = spider.settings.get('MYSQL_HOST', 'localhost')
        port = spider.settings.get('MYSQL_PORT', 3306)
        user = spider.settings.get('MYSQL_USER', 'cov')
        passwd = spider.settings.get('MYSQL_PASSWORD', '123456')

        self.db_conn = pymysql.connect(host=host, port=port, db=db, user=user, passwd=passwd, charset='utf8')
        self.db_cur = self.db_conn.cursor()

    # 关闭数据库
    def close_spider(self, spider):
        self.db_conn.commit()
        self.db_conn.close()

    # 对数据进行处理
    def process_item(self, item, spider):
        self.update_db(item)
        # self.insert_db(item)
        return item

    # 更新数据
    def update_db(self, item):
        self.db_conn.ping(reconnect=True)
        date = (
            item['date'],
            item['y']
        )
        try:
            sql = 'select * from overseasdaylist where date = %s and y = %s'
            cursor = self.db_conn.cursor()
            cursor.execute(sql, date)
            id = cursor.fetchone()
            # print("id: ")
            # print(id[0])
            if id is None:
                value = (
                    item['date'],
                    item['y'],
                    item['confirm'],
                    item['confirmAdd'],
                    item['heal'],
                    item['healRate'],
                    item['dead'],
                    item['deadRate'],
                )
                sql = 'INSERT INTO overseasdaylist(date, y, confirm, confirm_add, heal, heal_rate, dead, dead_rate) values(' \
                      '%s,%s,%s,%s,%s,%s,%s,%s) '
                cursor = self.db_conn.cursor()
                cursor.execute(sql, value)
            self.db_conn.commit()
            cursor.close()
            print("Update finished")
        except:
            print("Update DB failed")
            cursor.close()
            self.db_conn.commit()
            self.db_conn.close()