n = int(raw_input())
a = [int(t) for t in raw_input().split()]
d = {}
ans = 0
for x in a:
	if x not in d:
		d[x] = 0
	d[x] = d[x] + 1
	ans = max(ans, d[x])
print ans