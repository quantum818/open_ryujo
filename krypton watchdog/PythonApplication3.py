import re
import requests
import time
import socket

from bs4 import BeautifulSoup
def gettime(ind):
    localtime=time.localtime(time.time())
    l1=(int(localtime[0])-ind[0])*365
    l2=(int(localtime[1])-ind[1])*30
    l3=int(localtime[2])-ind[2]
    return l1+l2+l3
url='https://blog.2333332.xyz/'
socket.setdefaulttimeout(20)
time.sleep(10)
strhtml=requests.get(url)
soup=BeautifulSoup(strhtml.text,'lxml')
findata=soup.h1.a
getop=re.search('href="/',str(findata)).span()
print('博客网址：'+url)
findatastr=str(findata)
top=getop[1]
final=getop[1]+11
data=findatastr[top:final]
gettitle = re.findall(r'>(.*?)<', findatastr)
posttime=(int(data[0:4]),int(data[6:7]),int(data[9:10]))
print('最新文章：'+str(gettitle))
print('更新时间：'+findatastr[top:final])
timede=gettime(posttime)
print('该博主距现在已有大约 '+str(timede)+' 未更新新的文章')


