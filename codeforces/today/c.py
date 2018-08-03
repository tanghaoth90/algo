def ok(n, k):
	a, n0 = 0, n
	while n > 0:
		if n <= k:
			n, a = 0, a+n
			break
		n, a = n-k, a+k
		n -= n / 10	
	#print k, a
	return 2*a >= n0

n = int(raw_input())

lo, hi = 1, n
while lo <= hi:
	mid = (lo+hi)>>1
	if ok(n, mid): hi = mid-1
	else: lo = mid+1
hi = max(1,hi)
if ok(n,hi):
	print hi
else:
	print hi+1
