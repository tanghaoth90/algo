n, B = [int(t) for t in raw_input().split()]
a = [int(t) for t in raw_input().split()]
md = [-1 if t%2==0 else 1 for t in a]
md = [sum(md[:i+1]) for i in range(len(md))]

ans = 0
f = [[B+1]*(n+1) for i in range(n+1)]
f[0][0] = 0
for i in range(n-1):
	if md[i] == 0:
		for j in range(n):
			for k in range(i):
				if f[k][j]+abs(a[i+1]-a[i])<f[i+1][j+1]:
					f[i+1][j+1] = f[k][j]+abs(a[i+1]-a[i])
					ans = max(ans, j+1)
print ans

