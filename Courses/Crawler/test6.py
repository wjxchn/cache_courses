import requests
import re
import os

if __name__ == '__main__':
    if not os.path.exists('./qiutulibs'):
        os.mkdir('./qiutulibs')
    url="https://www.qiushibaike.com/imgrank/page/%d/"

    for page_num in range(1,14):
        new_url = format(url%page_num)
        headers = {
            'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/85.0.4183.102 Safari/537.36 Edg/85.0.564.51'
        }
        page_text = requests.get(url=new_url,headers=headers).text

        ex = '<div class="thumb">.*?<img src="(.*?)" alt.*?</div>'
        img_src_list = re.findall(ex,page_text,re.S)
        # print(img_src_list)
        for src in img_src_list:
            src = 'https:'+src
            img_data = requests.get(url=src,headers=headers).content
            img_name = src.split('/')[-1]
            img_path = './qiutulibs/'+img_name
            with open(img_path,'wb') as fp:
                fp.write(img_data)
                print(img_name,'下载成功')
