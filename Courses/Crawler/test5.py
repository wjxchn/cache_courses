# 爬取图片数据
import requests
import json

if __name__ == '__main__':
    # content返回的是二进制形式的图片数据
    # text返回字符串的数据
    url = "https://pic.qiushibaike.com/system/pictures/12359/123591588/medium/TUW7J10T8LN5P5DD.jpg"
    response_data = requests.get(url=url).content
    with open('./xiushi.jpg','wb') as fp:
        fp.write(response_data)