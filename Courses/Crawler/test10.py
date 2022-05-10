#解析下载图片数据
# https://pic.netbian.com/4kmeinv/

import requests
from lxml import etree
import os

if __name__ == '__main__':
    if not os.path.exists('./piclibs'):
        os.mkdir('./piclibs')
    url = 'http://pic.netbian.com/4kmeinv/'
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/85.0.4183.102 Safari/537.36 Edg/85.0.564.51'
    }
    response = requests.get(url=url,headers=headers)
    response.encoding='gbk'
    response_text = response.text
    
    tree = etree.HTML(response_text)
    li_list = tree.xpath('//div[@class="slist"]/ul/li')
    for li in li_list:
        img_src = 'http://pic.netbian.com'+li.xpath('./a/img/@src')[0]
        img_name = li.xpath('./a/img/@alt')[0]+'.jpg'
        print(img_src)
        print(img_name)
        img_data = requests.get(url=img_src,headers=headers).content
        with open('./piclibs/'+img_name,'wb') as fp:
            #fp.write(img_data)
            print(type(fp))
            print(img_name,'下载成功')
