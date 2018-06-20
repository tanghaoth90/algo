import sys

n = int(raw_input())
a = [int(x) for x in raw_input().split()]
maxnum = max(a)
s = set(a)
ans = 0, 0
for e in s:
	d = 1
	while e+d <= maxnum:
		if (e+d) in s and (e+(d<<1)) in s:
			print 3
			print e, e+d, e+(d<<1)
			sys.exit(0)
		if (e+d) in s:
			ans = e, e+d
		d <<= 1
if ans[0] == ans[1]:
	print 1
	print a[0]
else:
	print 2
	print ans[0], ans[1]