import random

def pow_mod(a,sup,m):
	ans = 1
	while sup > 0:
		if sup & 1: ans = (ans*a) % m
		a = a**2 % m
		sup >>= 1
	return ans

def gcd(a, b):
	while b:
		a, b = b, a%b
	return a

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

def pollard_rho(n):
	#if miller_rabin(n) or n <= 1: return n
	if n <= 1: return n
	x, x_fixed, cycle_size, factor = 2, 2, 2, 1
	while factor == 1:
		cnt = 1
		while cnt <= cycle_size and factor <= 1:
			x = (x*x+1)%n
			factor = gcd(abs(x-x_fixed), n)
			cnt += 1
		cycle_size *= 2
		x_fixed = x
	return factor

if __name__ == '__main__':
	print(pollard_rho(10403))
	primes = [i for i in range(2,1000000) if miller_rabin(i)]
	print("len of primes=%d"%len(primes))
	print(pollard_rho(primes[-1]*primes[-2]))
	for i in range(1,7):
		print(i, 2**(2**i)+1, end=" ", flush=True)
		print(pollard_rho(2**(2**i)+1), flush=True)
