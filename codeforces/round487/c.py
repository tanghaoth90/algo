def inc(x,y):
	if y == 48: return x+2, 0
	else: return x, y+2

[a, b, c, d] = [int(x) for x in raw_input().split()]
mat = [['a']*50 for x in range(0,8)] + [['b']*50 for x in range(8,50)]
x, y = 0, 0
for i in range(1,b):
	mat[x][y] = 'b'
	x, y = inc(x, y)
x, y = 9, 0
for i in range(1,a):
	mat[x][y] = 'a'
	x, y = inc(x, y)
for i in range(0,c):
	mat[x][y] = 'c'
	x, y = inc(x, y)
for i in range(0,d):
	mat[x][y] = 'd'
	x, y = inc(x, y)

print '50 50\n'+'\n'.join([''.join(mat[x]) for x in range(0,50)])
