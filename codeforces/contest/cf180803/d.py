import operator

def readints():
	return [int(t) for t in raw_input().split()]

[n, m], a, b = readints(), readints(), readints()
axor, bxor = reduce(operator.xor, a, 0), reduce(operator.xor, b, 0)
if axor != bxor:
	print "NO"
else:
	print "YES"
	ans = [[0]*m for i in xrange(n)]
	ans[0][:] = b[:]
	a[0] ^= bxor
	for i in xrange(n):
		ans[i][0] ^= a[i]
		print " ".join([str(t) for t in ans[i]])
