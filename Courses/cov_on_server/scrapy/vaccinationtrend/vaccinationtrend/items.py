# -*- coding: utf-8 -*-

# Define here the models for your scraped items
#
# See documentation in:
# http://doc.scrapy.org/en/latest/topics/items.html

import scrapy


class VaccinationtrendItem(scrapy.Item):
    # define the fields for your item here like:
    date = scrapy.Field()

    y = scrapy.Field()

    total_vaccinations = scrapy.Field()

    total_vaccinations_per_hundred = scrapy.Field()
