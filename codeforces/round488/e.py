[n, m] = [int(t) for t in raw_input().split()]
yl = [int(t) for t in raw_input().split()]
yr = [int(t) for t in raw_input().split()]
syr = set(yr)

p = list(set(map(lambda t:t/2, filter(lambda t: t%2==0, [pl+pr for pl in yl for pr in yr]))))
lp = len(p)

for i1 in range(0,lp):
	o1 = p[i1]
	for i2 in range(o1+1,lp):
		o2 = p[i2]
		