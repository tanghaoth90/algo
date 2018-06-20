def fpa(num, pa):
	return filter(lambda item: item[0] == num or item[1] == num, pa) 

def itisok(num, pa1, pa2):
	fa1, fa2 = fpa(num, pa1), fpa(num, pa2)
	if len(fa1) == 0 or len(fa2) == 0: return False
	if len(fa1) >= 2 or len(fa2) >= 2: return True
	return fa1[0] <> fa2[0]

[n, m] = [int(t) for t in raw_input().split()]
inp1 = [int(t) for t in raw_input().split()]
inp2 = [int(t) for t in raw_input().split()]
pa1 = [(inp1[i*2], inp1[i*2+1]) for i in range(n)]
pa2 = [(inp2[i*2], inp2[i*2+1]) for i in range(m)]

pos = filter(lambda item: itisok(item, pa1, pa2), range(1,10))
print pos