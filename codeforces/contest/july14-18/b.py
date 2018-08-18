s = raw_input()
a = filter(lambda c: c=='0' or c=='2', s)
b = filter(lambda c: c=='1', s)
c = filter(lambda c: c=='2', s)
if len(c) == 0:
	print a+b
else:
	i = a.index('2')
	print a[:i] + b + a[i:]

