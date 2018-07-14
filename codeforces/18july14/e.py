import sys
import random

def getinp():
	return int(raw_input())

def giveans(x, y):
	print x, y
	sys.stdout.flush()

def totarea(a, h):
	return sum([h[i]*(a[i+1]-a[i]) for i in range(len(h))])

def ins(x, h0, a, h):
	tot = totarea(a, h)
	# ans == 1
	ar1 = 0
	for i in range(len(h)):
		if a[i+1] > x:
			ar1 += (a[i+1]-max(x+1,a[i])) * h[i]
	ar2 = 0
	for i in range(len(h)):
		if h[i] > h0:
			ar2 += (a[i+1]-a[i]) * (h[i]-h0)
	ar3 = 0
	for i in range(len(h)):
		if a[i+1]-1 < x:
			ar3 += (a[i+1]-a[i]) * h[i]
		elif a[i] <= x <= a[i+1]:
			ar3 += (x-a[i]) * h[i] + (a[i+1]-x) * (h0-1)
		else:
			ar3 += (a[i+1]-a[i]) * min(h[i], h0-1)
	#print ar1, ar2, ar3
	return max(ar1, ar2, ar3) / (0.0+tot)

th = 0.87
n = getinp()
#giveans(n/2, n/2)
#resp = getinp()
ans = 4
a = [1,n+1]
h = [n]
yrange = (1,n)
resttry = 600
while ans != 0:
	x, h0 = 0, 0
	r = 1
	resttry -= 1
	#for xi in range(len(h)):
	t = 0
	while totarea(a,h)*(min(r,1)**resttry) > 1-(1e-10) and t < 10:
		xi = random.randint(0,len(h)-1)
		#h0 = (h[xi]+1)>>1
		#x = (a[xi]+a[xi+1]-1)>>1
		h0 = random.randint(1,h[xi])
		x = random.randint(a[xi],a[xi+1]-1)
		r = ins(x, h0, a, h)
		t += 1
	giveans(x, yrange[0]+h0-1)
	ans = getinp()
	if ans == 0:
		break
	if ans == 1:
		na = []
		nh = []
		for i in range(len(h)):
			if x >= a[i+1]:
				continue
			if a[i] <= x < a[i+1]-1:
				na.append(x+1)
				nh.append(h[i])
			elif x < a[i]:
				na.append(a[i])
				nh.append(h[i])
		na.append(a[len(h)])
		a, h = na, nh
	elif ans == 2:
		na = []
		nh = []
		yrange = (yrange[0]+h0, yrange[1])
		lasti = 0
		for i in range(len(h)):
			if h[i] > h0:
				na.append(a[i])
				nh.append(h[i]-h0)
				lasti = i
		na.append(a[lasti+1])
		a, h = na, nh
	elif ans == 3:
		na = []
		nh = []
		for i in range(len(h)):
			if a[i+1]-1 < x:
				na.append(a[i])
				nh.append(h[i])
			elif a[i] <= x <= a[i+1]-1:
				if a[i] < x:
					na.append(a[i])
					nh.append(h[i])
				na.append(x)
				nh.append(h0-1)
				#ar3 += (x-a[i]) * h[i] + (a[i+1]-x) * (h0-1)
			else:
				na.append(a[i])
				nh.append(min(h[i], h0-1))
				#ar3 += (a[i+1]-a[i]) * min(h[i], h0-1)		
		na.append(a[len(h)])
		while len(nh)>1 and nh[-1] == 0:
			na = na[:-1]
			nh = nh[:-1]
		a, h = na, nh
