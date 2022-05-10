# Define here the models for your scraped items
#
# See documentation in:
# https://docs.scrapy.org/en/latest/topics/items.html

import scrapy


class TrainItem(scrapy.Item):
    # define the fields for your item here like:
    train_no = scrapy.Field()

    to_station = scrapy.Field()

    from_station = scrapy.Field()

    date = scrapy.Field()

    total_num = scrapy.Field()

    stops = scrapy.Field()


    pass
