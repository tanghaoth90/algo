n, k = [int(t) for t in raw_input().split()]
a = [0] + [int(t) for t in raw_input().split()]
s = [0] * (n+1)
for i in range(1,n+1):
	s[i] = s[i-1] + a[i]

ans = 0
for i in range(1,n+1):
	for j in range(i+k-1,n+1):
		ans = max(ans, (s[j]-s[i-1])/(j-i+1.0))

print ans
