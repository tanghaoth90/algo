import random

def pow_mod(a,sup,m):
	ans = 1
	while sup > 0:
		if sup & 1: ans = (ans*a) % m
		a = a**2 % m
		sup >>= 1
	return ans

def miller_rabin(n):
	if n in [2,3]: return True
	if n <= 1 or not (n & 1): return False
	d, r = n-1, 0
	while not (d&1):
		d >>= 1
		r += 1
	for wit in range(10):
		a = random.randint(2,n-2)
		w0 = pow_mod(a,d,n)
		if w0 == 1: continue
		w, flag = w0, False
		for i in range(0,r):
			if w == n-1: 
				flag = True 
				break
			w = w**2 % n
		if not flag:
			return False
		#w = [pow_mod(a,d<<i,n) for i in range(0,r)]
		#if w[0] != 1 and not w.count(n-1):
		#	return False
	return True

if __name__ == '__main__':
	#print(miller_rabin(65))
	#print(miller_rabin(7))
	print(len([i for i in range(2,1000000) if miller_rabin(i)]))
