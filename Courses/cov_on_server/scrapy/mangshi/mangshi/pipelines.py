# Define your item pipelines here
#
# Don't forget to add your pipeline to the ITEM_PIPELINES setting
# See: https://docs.scrapy.org/en/latest/topics/item-pipeline.html


# useful for handling different item types with a single interface
from itemadapter import ItemAdapter
import pymysql


class MangshiPipeline:
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
        return item

    # 更新数据
    def update_db(self, item):
        self.db_conn.ping(reconnect=True)
        name = (
            item['flight_no'],
            item['from_airport'],
            item['to_airport']
        )
        try:
            sql = 'select * from flights where flight_no = %s and from_airport = %s and to_airport = %s'
            cursor = self.db_conn.cursor()
            cursor.execute(sql, name)
            id = cursor.fetchone()
            # print('------------------')
            # print(id[0])
            # print('------------------')
            if id is None:
                value = (
                    item['flight_no'],
                    item['from_airport'],
                    item['to_airport'],
                    item['date'],
                    item['company'],
                    item['stop'],
                )
                sql = 'INSERT INTO flights(flight_no,from_airport,to_airport,date,company,stop) VALUES(%s,%s,%s,%s,%s,%s)'
                cursor = self.db_conn.cursor()
                cursor.execute(sql, value)
                self.db_conn.commit()
                cursor.close()
            else:
                value = (
                    item['from_airport'],
                    item['to_airport'],
                    item['date'],
                    item['company'],
                    item['stop'],
                    id[0]
                )
                sql = 'UPDATE flights SET from_airport = %s, to_airport = %s, date = %s, company = %s, stop = %s WHERE id = %s'
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