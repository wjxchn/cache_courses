# -*- coding: utf-8 -*-

# Define here the models for your scraped items
#
# See documentation in:
# http://doc.scrapy.org/en/latest/topics/items.html

import scrapy


class ProvincedaylistItem(scrapy.Item):
    # define the fields for your item here like:
    date = scrapy.Field()

    name = scrapy.Field()

    y = scrapy.Field()

    confirm = scrapy.Field()

    confirmAdd = scrapy.Field()

    heal = scrapy.Field()

    healAdd = scrapy.Field()

    dead = scrapy.Field()

    deadAdd = scrapy.Field()