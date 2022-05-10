# -*- coding: utf-8 -*-

# Define here the models for your scraped items
#
# See documentation in:
# http://doc.scrapy.org/en/latest/topics/items.html

import scrapy


class NewsItem(scrapy.Item):
    # define the fields for your item here like:
    title = scrapy.Field()

    time = scrapy.Field()

    location_id = scrapy.Field()

    url = scrapy.Field()

    site = scrapy.Field()

    pass
