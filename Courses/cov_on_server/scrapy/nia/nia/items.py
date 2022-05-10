# Define here the models for your scraped items
#
# See documentation in:
# https://docs.scrapy.org/en/latest/topics/items.html

import scrapy


class NiaItem(scrapy.Item):
    # define the fields for your item here like:
    name = scrapy.Field()

    content = scrapy.Field()

    time = scrapy.Field()

    province = scrapy.Field()

    index = scrapy.Field()

    pass
