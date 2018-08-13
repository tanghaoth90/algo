n = int(raw_input())
a = [int(t) for t in raw_input().split()]

a.sort()
s = sum(a)

if s*2 >= 9*n:
	print 0
else:
	for i in range(0,n):
		s += 5-a[i]
		if s*2 >= 9*n:
			print i+1
			break