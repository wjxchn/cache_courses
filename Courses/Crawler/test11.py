import requests
from lxml import etree

if __name__ == '__main__':
    url = 'https://www.aqistudy.cn/historydata/'
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/85.0.4183.102 Safari/537.36 Edg/85.0.564.51'
    }
    page_text = requests.get(url=url,headers=headers).text

    tree = etree.HTML(page_text)
    hot_li_list = tree.xpath('//div[@class="bottom"]/ul/li')
    all_city_names = []
    for li in hot_li_list:
        hot_city_name = li.xpath('./a/text()')[0]
        all_city_names.append(hot_city_name)

    city_names_list = tree.xpath('//div[@class="bottom"]/ul/div[2]/li')
    for nli in city_names_list:
        city_name = nli.xpath('./a/text()')[0]
        all_city_names.append(city_name)

    print(all_city_names)
    print(len(all_city_names))

    # tree.xpath('//div[@class="bottom"]/ul/li | //div[@class="bottom"]/ul/div[2]/li')