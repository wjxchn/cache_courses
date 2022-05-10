import requests
from bs4 import BeautifulSoup
import os
if __name__ == '__main__':
    url = "https://map.bjsubway.com/"
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/85.0.4183.102 Safari/537.36 Edg/85.0.564.51'
    }
    response = requests.get(url = url,headers = headers)
    response.encoding = 'utf-8'
    response_data = response.text

    soup = BeautifulSoup(response_data,'lxml')
    li_list = soup.select('#subway_map')
    # print(li_list)
    for i in li_list:
        print(i)
        #.string表示标签中的直接的字符串，.text表示标签中的所有文字内容