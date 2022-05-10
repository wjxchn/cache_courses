from bs4 import BeautifulSoup
# 将本地或者网站加载到对象中

if __name__ == '__main__':
    # 本地
    fp = open('./sogou.html','r',encoding='utf-8')
    soup = BeautifulSoup(fp,'lxml')
    # print(soup)

    # 打印a标签
    print(soup.a)

    print(soup.find('div'))

    print(soup.find('a',class_='g'))

    print(soup.find_all('a'))

    # 选择类选择器为g，被包含在列表中
    print(soup.select('.g'))
