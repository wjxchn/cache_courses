import time
import requests
from apscheduler.schedulers.blocking import BlockingScheduler

sched = BlockingScheduler()

@sched.scheduled_job('interval', seconds=3)
def my_job():
    url = 'https://www.sogou.com/'
    response = requests.get(url=url)
    page_text = response.text
    print(page_text)
    with open('./sogou.html','w',encoding = 'utf-8') as fp:
        fp.write(page_text)
    print("本次打印结束，时间如下："+time.strftime('%Y-%m-%d %H:%M:%S\n', time.localtime(time.time())))

sched.start()
