from lxml import etree
import requests

if __name__ == '__main__':
    url = 'https://bj.58.com/ershoufang'
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/85.0.4183.102 Safari/537.36 Edg/85.0.564.51'
    }
    page_text = requests.get(url=url,headers=headers).text
    tree = etree.HTML(page_text)
    li_list = tree.xpath('//ul[@class="house-list-wrap"]/li')
    for li in li_list:
        # xpath 返回的是列表，下面语句中的.表示li
        title = li.xpath('./div[2]/h2/a/text()')[0]
        print(title)
