
from bs4 import BeautifulSoup
xmL = open'map.xml', 'r', encoding= 'utf8').read()
soup = BeautifulSoup(xml, "lxml")
'''print(soup)'''
cnt=0
for node in soup. find_all' node ):
    for tag in node('tag'):
        if tag['k']== 'public_transport' and tag['v'] == 'stop_position':
            cnt += 1 
            print (cnt)