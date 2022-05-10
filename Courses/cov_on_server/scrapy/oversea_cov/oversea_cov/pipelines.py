# -*- coding: utf-8 -*-

# Define your item pipelines here
#
# Don't forget to add your pipeline to the ITEM_PIPELINES setting
# See: http://doc.scrapy.org/en/latest/topics/item-pipeline.html
import pymysql


class OverseaCovPipeline(object):
    # 打开数据库
    i = 0

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
            print("id: ")
            print(id[0])
            value = (
                item['confirm'],
                item['confirmAdd'],
                item['nowConfirm'],
                item['nowConfirmAdd'],
                item['dead'],
                item['deadAdd'],
                item['heal'],
                item['healAdd'],
                item['time'],
                id[0]
            )
            sql = 'UPDATE covdata SET confirm = %s, confirm_add = %s, now_confirm = %s, now_confirm_add = %s, ' \
                  'dead = %s, ' \
                  'dead_add = %s, heal = %s, heal_add = %s, time = %s WHERE location_id = %s'
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

    # 插入数据
    def insert_db(self, item):
        self.db_conn.ping(reconnect=True)
        value1 = (
            item['name'],
            4,
            0,
            0
        )

        try:
            sql1 = 'INSERT INTO locations(name, type, belong_id, risk) VALUES(%s,%s,%s,%s)'
            sql2 = 'INSERT INTO covdata(location_id, confirm, confirm_add, now_confirm, now_confirm_add, dead, dead_add, ' \
                   'heal, heal_add) VALUES(%s,%s,%s,%s,%s,%s,%s,%s,%s) '
            self.db_cur.execute(sql1, value1)
            id = self.db_cur.lastrowid
            print("------------------------------------------")
            print(id)
            print("------------------------------------------")
            value2 = (
                id,
                item['confirm'],
                item['confirmAdd'],
                item['nowConfirm'],
                item['nowConfirmAdd'],
                item['dead'],
                item['deadAdd'],
                item['heal'],
                item['healAdd']
            )
            self.db_cur.execute(sql2, value2)
            self.db_conn.commit()
            print("Insert finished")
        except:
            print("Insert to DB failed")
            self.db_conn.commit()
            self.db_conn.close()
