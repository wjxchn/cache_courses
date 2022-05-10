import requests
from bs4 import BeautifulSoup
import os
if __name__ == '__main__':
    if not os.path.exists('./sanguo'):
        os.mkdir('./sanguo')
    url = "https://www.shicimingju.com/book/sanguoyanyi.html"
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/85.0.4183.102 Safari/537.36 Edg/85.0.564.51'
    }
    response = requests.get(url = url,headers = headers)
    response_data = response.text

    soup = BeautifulSoup(response_data,'lxml')
    li_list = soup.select('.book-mulu > ul > li')
    # print(li_list)
    for i in li_list:
        # print(i.a.string)
        #.string表示标签中的直接的字符串，.text表示标签中的所有文字内容
        detail_url = 'http://www.shicimingju.com'+i.a['href']
        # print(detail_url)
        detail_text = requests.get(url=detail_url,headers = headers).text
        detail_soup = BeautifulSoup(detail_text,'lxml')
        detail_list = detail_soup.select('.chapter_content > p')
        for j in detail_list:
            # print(j.string)
            with open('./sanguo/'+i.a.string+'.txt','a',encoding='utf-8') as fp:
                fp.write(j.string)
    print('下载三国演义内容成功')
