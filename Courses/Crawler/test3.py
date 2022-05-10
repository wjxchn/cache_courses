import requests
import json

if __name__ == "__main__":
    post_url = 'https://fanyi.baidu.com/sug'
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/85.0.4183.102 Safari/537.36 Edg/85.0.564.51'
    }
    word = input('enter a word:')
    data = {
        'kw':word
    }
    response = requests.post(url=post_url,data=data,headers=headers)
    # 如果确认返回的数据是json类型的，才可以用json()
    # 返回的是字典对象
    dic_obj = response.json()
    # print(dic_obj)
    filename = word+'.json'
    fp=open(filename,'w',encoding='utf-8')
    json.dump(dic_obj,fp=fp,ensure_ascii=False)
    print('over')