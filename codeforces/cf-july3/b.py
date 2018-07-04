def neg(x):
	return '1' if x == '0' else '0'

a, b, x = [int(t) for t in raw_input().split()]
c = '0' if a >= b else '1'

while x > 0:
	x -= 1
	c += neg(c[-1])

a -= c.count('0')
b -= c.count('1')

if c[0] == '0':
	print '0'*a+c[0]+'1'*b+c[1:]
else:
	print '1'*b+c[0]+'0'*a+c[1:]


