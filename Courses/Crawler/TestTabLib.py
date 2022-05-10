import tablib

headers = ("name","age","weight")

data = [("alex","25","60kg"),("xiaoyuanquan","18","80kg"),("peiqi","18","60kg")]

data.append(("jiajia","22","47kg"))

data = tablib.Dataset(*data,headers=headers)

print(data.json)

with open('daochu.xls','wb')as f:
    f.write(data.xls)