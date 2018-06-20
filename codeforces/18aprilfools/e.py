n = int(raw_input())
soft, hard = 0, 0
for i in range(n):
	[nm, tp] = raw_input().split()
	if tp=='soft':
		soft += 1
	else:
		hard += 1
m = max(soft, hard)
k = 1
while (k*k+1)/2<m:
	k += 1
if soft!=hard or k%2==0:
	print k
else:
	print k+1
	
