# Define here the models for your scraped items
#
# See documentation in:
# https://docs.scrapy.org/en/latest/topics/items.html

import scrapy


class MangshiItem(scrapy.Item):
    # define the fields for your item here like:
    flight_no = scrapy.Field()

    from_airport = scrapy.Field()

    to_airport = scrapy.Field()

    stop = scrapy.Field()

    company = scrapy.Field()

    date = scrapy.Field()

    pass
