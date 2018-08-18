#include <bits/stdc++.h>
using namespace std;

double rectarea(rect) {
	return (rect[2]-rect[0])*double(rect[3]-rect[1])
}

def getinp():
	return int(raw_input())

def giveans(x, y):
	print x, y
	sys.stdout.flush()

def itsc(rect1, rect2):
	if rect1[0] >= rect2[2] or rect2[0] >= rect1[2] or rect1[1] >= rect2[3] or rect2[1] >= rect1[3]:
		return None
	return (max(rect1[0], rect2[0]), max(rect1[1], rect2[1]), min(rect1[2], rect2[2]), min(rect1[3], rect2[3]))

def cut(rects1, ans, x=0, y=0):
	if ans == 1:
		rects2 = [(x+1, 1, n+1, n+1)]
	elif ans == 2:
		rects2 = [(1, y+1, n+1, n+1)]
	elif ans == 3:
		rects2 = [(1, 1, x, n+1), (x, 1, n+1, y)]
	return filter(lambda x: x, [itsc(r1, r2) for r2 in rects2 for r1 in rects1])

def caltotarea(rects):
	return sum([rectarea(r) for r in rects])

n = getinp()
th, rects = 3.0/4, [(1,1,n+1,n+1)]
while True:
	bigrect = (rects[0][0], rects[0][1], rects[-1][2], rects[0][3])
	# print rects
	totarea = caltotarea(rects)
	# optx
	lo, hi = bigrect[0], bigrect[2]-1
	mid = lo
	while lo < hi:
		mid = (lo+hi)>>1
		if caltotarea(cut(rects, 1, x=mid)) > th*totarea:
			lo = mid+1
		else:
			hi = mid-1
	optx = mid
	# opty
	for r in rects:
		if r[0] <= optx < r[2]:
			lo, hi = r[1], r[3]-1
			break
	mid = lo
	while lo < hi:
		mid = (lo+hi)>>1
		if caltotarea(cut(rects, 2, y=mid)) > th*totarea:
			lo = mid+1
		else:
			hi = mid-1
	opty = mid
	giveans(optx, opty)
	ans = getinp()
	if ans == 0:
		break
	rects = cut(rects, ans, optx, opty)

