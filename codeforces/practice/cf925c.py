import sys

def interleave(c, b, mask):
	lb, ib, s = len(b), 0, False
	if ib<lb:
		yield b[ib]
		ib, s = 1, True
	for e in c:
		yield e
		s ^= (e&mask)>0
		if not s and ib<lb:
			yield b[ib]
			ib, s = ib+1, True
	if ib<lb: yield -1

def calprefix(b):
	cur = 0
	for e in b:
		cur ^= e
		yield cur
	
n = int(raw_input())
b = [int(t) for t in raw_input().split()]
c = []
for w in range(60,0,-1):
	low, high = 1<<(w-1), (1<<w)-1
	bx = filter(lambda x: low<=x and x<=high, b)
	c = list(interleave(c, bx, low))
	if len(c)>0 and c[-1]==-1:
		print "No"
		sys.exit(0)
print "Yes"
print " ".join(map(lambda x: str(x), c))

#ans = list(calprefix(c))
#print " ".join(map(lambda x: str(x), ans))
#c = 0
#for e in ans:
#	print c^e
#	c = e
