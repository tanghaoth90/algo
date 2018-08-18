def cbnum(n, k):
	ans = 1
	for i in range(1,k+1):
		ans = ans * n / i
		n -= 1
	return ans

def getans(cnt, flag):
	up_bound = sum(cnt)
	f = [0]*(up_bound+1)
	f[0] = 1
	for w in range(0,10):
		x = cnt[w]
		if x > 0:
			g = f
			f = [0]*(up_bound+1)
			st = 0 if flag and w == 0 else 1
			for j in range(st,x+1):
				for i in range(0,up_bound+1):
					if g[i] > 0 and i+j <= up_bound:
						f[i+j] += g[i] * cbnum(i+j, j)
			#print f
	return sum(f[1:])

n = int(raw_input())

cnt = [0]*10
while n > 0:
	cnt[n % 10] += 1
	n /= 10

ans = getans(cnt, False)
if cnt[0] > 0:
	cnt[0] -= 1
	#print ans, getans(cnt, True)
	ans -= getans(cnt, True)
print ans
#low_bound = sum( map(lambda x: 1 if x > 0 else 0, cnt) )
#for l in range(low_bound, up_bound+1):
	
