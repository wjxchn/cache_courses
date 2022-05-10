# -*- coding: utf-8 -*-

# Define your item pipelines here
#
# Don't forget to add your pipeline to the ITEM_PIPELINES setting
# See: http://doc.scrapy.org/en/latest/topics/item-pipeline.html
import pymysql

class VaccinationPipeline(object):
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
        name = (
            item['name']
        )
        try:
            sql = 'select * from locations where name = %s'
            cursor = self.db_conn.cursor()
            cursor.execute(sql, name)
            id = cursor.fetchone()
            if id is not None:
                print("id: ")
                print(id[0])
                value = (
                    item['total_vaccinations'],
                    item['total_vaccinations_per_hundred'],
                    item['vaccinations'],
                    id[0]
                )
                sql = 'UPDATE covdata SET total_vaccinations = %s, total_vaccinations_per_hundred = %s, vaccinations = %s ' \
                      'WHERE location_id = %s '
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
