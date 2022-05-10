from bs4 import BeautifulSoup
import requests
import json
import os
import tablib
import pandas as pd

if __name__ == '__main__':
    url = 'https://api.inews.qq.com/newsqa/v1/automation/foreign/daily/list?country=%E5%8D%B0%E5%BA%A6&'
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/85.0.4183.121 Safari/537.36 Edg/85.0.564.63'
    }
    virus_data = requests.get(url=url,headers=headers).json()['data']
    file_name = 'IndiaVirus.json'
    fp = open(file_name,'w',encoding='utf-8')
    json.dump(virus_data,fp=fp,ensure_ascii=False)
    header_tumple = ('date', 'confirm_add', 'confirm', 'heal','dead')
    data_list = []
    # print('over')
    for item in virus_data:
        date = item['date']
        # print(date)
        confirm_add = item['confirm_add']
        confirm = item['confirm']
        heal = item['heal']
        dead = item['dead']
        tup = (date, confirm_add, confirm, heal, dead)
        data_list.append(tup)
    # print(data_list)
    excel_data = tablib.Dataset(*data_list, headers=header_tumple)
    with open('IndiaVirus.xls', 'wb') as f:
        f.write(excel_data.xls)