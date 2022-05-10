# -*- coding: utf-8 -*-

# Define here the models for your scraped items
#
# See documentation in:
# http://doc.scrapy.org/en/latest/topics/items.html

import scrapy


class CtItem(scrapy.Item):
    # define the fields for your item here like:
    # name = scrapy.Field()
    id = scrapy.Field()

    name = scrapy.Field()

    belong_id = scrapy.Field()

    type = scrapy.Field()

    dead = scrapy.Field()

    deadAdd = scrapy.Field()

    confirm = scrapy.Field()

    confirmAdd = scrapy.Field()

    nowConfirm = scrapy.Field()

    nowConfirmAdd = scrapy.Field()

    heal = scrapy.Field()

    healAdd = scrapy.Field()

    # importedCase = scrapy.Field()

    noInfect = scrapy.Field()

    noInfectAdd = scrapy.Field()

    time = scrapy.Field()

    latitude = scrapy.Field()

    longitude = scrapy.Field()


