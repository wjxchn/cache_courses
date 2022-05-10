# Define your item pipelines here
#
# Don't forget to add your pipeline to the ITEM_PIPELINES setting
# See: https://docs.scrapy.org/en/latest/topics/item-pipeline.html


# useful for handling different item types with a single interface
from itemadapter import ItemAdapter
import pymysql

class NiaPipeline:
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
        if item['index'] == 0:
            self.update_db1(item)
        else :
            pass
            self.update_db2(item)
        return item

    # 更新数据
    def update_db1(self, item):
        self.db_conn.ping(reconnect=True)
        name = (
            item['name']
        )
        try:
            sql = 'select * from nialist where name = %s'
            cursor = self.db_conn.cursor()
            cursor.execute(sql, name)
            id = cursor.fetchone()
            print("id: ")
            if id is None:
                value = (
                    item['name'],
                    item['content'],
                    item['time']
                )
                sql = 'INSERT INTO nialist(name, content, time) VALUES(%s,%s,%s)'
                cursor = self.db_conn.cursor()
                cursor.execute(sql, value)
                self.db_conn.commit()
                cursor.close()
            else:
                value = (
                    item['content'],
                    item['time'],
                    id[0]
                )
                sql = 'UPDATE nialist SET content = %s, time = %s WHERE id = %s'
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

    # 更新数据
    def update_db2(self, item):
        self.db_conn.ping(reconnect=True)
        name = (
            item['name']
        )
        try:
            sql = 'select * from nialist where name = %s'
            cursor = self.db_conn.cursor()
            cursor.execute(sql, name)
            id = cursor.fetchone()
            print("id: ")
            if id is None:
                value = (
                    item['name'],
                    item['content'],
                    item['province'],
                    item['time']
                )
                sql = 'INSERT INTO nialist(name, content, province, time) VALUES(%s,%s,%s,%s)'
                cursor = self.db_conn.cursor()
                cursor.execute(sql, value)
                self.db_conn.commit()
                cursor.close()
            else:
                value = (
                    item['content'],
                    item['time'],
                    id[0]
                )
                sql = 'UPDATE nialist SET content = %s, time = %s WHERE id = %s'
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


