#Piyush Vashisht
#2017303
#prob-IPMIDM_2
import math
N=int(input())#input the no. of points
a=[]
b=[]
for i in range(N):
	x,y=input().split()
	a.append([x, y])
	# print(a)
for j in range(N):
	for k in range(j+1,N):
		d=(int(a[j][0])-int(a[k][0]))**2 + (int(a[j][1])-int(a[k][1]))**2
		c=math.sqrt(d)
		b.append(c)
# print(p)
p=(max(b))
print(round(p,2))