line1 = 'X'+raw_input()
line2 = 'X'+raw_input()
m = len(line1)

f = [[-200]*16 for i in range(m)]

f[0][15] = 0
for i in range(1,m):
	for j in range(0,16): 
		block = (j & 3) << 2
		if line1[i] == 'X': block |= 2
		if line2[i] == 'X': block |= 1
		f[i][block] = max(f[i][block], f[i-1][j])
		for r in [14, 11, 7, 13]:
			if (block&r) == 0:
				f[i][block|r] = max(f[i][block|r], f[i-1][j]+1)
#for i in range(0,m):
#	print f[i]
print max(f[m-1])