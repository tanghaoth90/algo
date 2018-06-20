import sys

n = int(raw_input())
a = [int(t) for t in raw_input().split()]
b = sorted(a)
#c = []
for x in range(n-1):
	for i in range(len(a)-1):
		if abs(a[i]-a[i+1])>=2:
			print 'NO'
			sys.exit(0)
	i = a.index(max(a))
	a = a[:i] + a[i+1:]
print 'YES'
