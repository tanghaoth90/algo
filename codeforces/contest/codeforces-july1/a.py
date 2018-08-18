n = int(raw_input())
a = [int(t) for t in raw_input().split()]

sa = sum(a)
f = False
for s in range(1,1<<n):
	m, c = 0, 0
	for i in range(n):
		if s & 1<<i:
			m += a[i]
			c += 1
	if m > 0 and sa-m > 0 and m <> sa-m:
		print c
		for i in range(n):
			if s & 1<<i:
				print i+1, 
		print
		f = True
		break
if not f:
	print -1