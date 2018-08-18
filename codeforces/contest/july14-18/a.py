n, m = [int(t) for t in raw_input().split()]
c = [int(t) for t in raw_input().split()]
a = [int(t) for t in raw_input().split()]
i, ans = 0, 0
for aj in a:
	while i < n and aj < c[i]:
		i += 1
	if i >= n:
		break
	ans += 1
	i += 1
print ans
	
