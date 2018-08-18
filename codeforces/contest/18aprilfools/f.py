def findfirst(s, start):
	plus, minus = s.find('+', start), s.find('-', start)
	if plus==-1: plus = len(s)
	if minus==-1: minus = len(s)
	return min(plus, minus)

s = raw_input()
while findfirst(s, 1)<len(s):
	d = findfirst(s, 1)
	d2 = findfirst(s, d+1)
	if s[:d2] == '2+2':
		s = '-46'+s[d2:]
	elif s[:d2] == '112-37':
		s = '375'+s[d2:]
	else:
		s = str(eval(s[:d2]))+s[d2:]
print s
