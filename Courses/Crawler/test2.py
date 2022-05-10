# UA伪装 User-Agent(请求载体的身份标识) 
# 门户网站的服务器会检测对应请求的载体身份标识，
# 如果检测的请求的载体身份标识为某一款浏览器，
# 意味着当前的请求是正常的。
# 但是如果检测到身份标识不是基于某一款浏览器的，
# 则表示该请求为不正常的请求，
# 则服务器端就很有可能拒绝该次请求。

import requests

if __name__ == "__main__":
    headers={
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/85.0.4183.102 Safari/537.36 Edg/85.0.564.51'
    }
    url = "https://www.sogou.com/web"
    kw = input('enter a word:')
    param = {
        'query': kw
    }
    response = requests.get(url=url,params=param,headers=headers)

    page_text = response.text
    filename = kw+'.html'
    with open(filename,'w',encoding='utf-8') as fp:
        fp.write(page_text)
    print('保存成功')