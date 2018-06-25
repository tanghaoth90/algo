import sys

def my2pow(k):
	if k==0:
		return 1
	elif k==1:
		return 2
	elif k%2==0:
		return pow(my2pow(k/2),2)%(pow(10,9)+7)
	else:
		return pow(my2pow(k/2),2)*2%(pow(10,9)+7)

[x, k] = [int(t) for t in raw_input().split()]
if x==0:
	print 0
else:
	print (my2pow(k)*(2*x-1)+1)%(pow(10,9)+7)

