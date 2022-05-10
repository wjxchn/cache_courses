# -*- coding: utf-8 -*-

# Define here the models for your scraped items
#
# See documentation in:
# http://doc.scrapy.org/en/latest/topics/items.html

import scrapy


class ChinadaylistItem(scrapy.Item):
    # define the fields for your item here like:
    date = scrapy.Field()

    noInfectH5 = scrapy.Field()

    deadRate = scrapy.Field()

    heal = scrapy.Field()

    nowSevere = scrapy.Field()

    suspect = scrapy.Field()

    nowConfirm = scrapy.Field()

    importedCase = scrapy.Field()

    healRate = scrapy.Field()

    dead = scrapy.Field()

    y = scrapy.Field()

    noInfect = scrapy.Field()

    localConfirm = scrapy.Field()

    localConfirmH5 = scrapy.Field()

    confirm = scrapy.Field()
    # pass
