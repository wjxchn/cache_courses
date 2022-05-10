# -*- coding: utf-8 -*-

# Define here the models for your scraped items
#
# See documentation in:
# http://doc.scrapy.org/en/latest/topics/items.html

import scrapy


class OverseadaylistItem(scrapy.Item):
    # define the fields for your item here like:
    date = scrapy.Field()

    y = scrapy.Field()

    confirm = scrapy.Field()

    confirmAdd = scrapy.Field()

    dead = scrapy.Field()

    heal = scrapy.Field()

    healRate = scrapy.Field()

    deadRate = scrapy.Field()
    pass
