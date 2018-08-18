d = {}
for i in range(0,int(raw_input())):
	l, r = 0, 0
	for x in raw_input():
		if x == '(': l += 1
		elif l > 0: l -= 1
		else: r += 1
	if l > 0 and r > 0: continue
	else:
		if l-r not in d: d[l-r] = 0
		d[l-r] += 1
ans = 0
for s in d:
	if s <= 0: ans += d[s] * (d[-s] if (-s) in d else 0)
print ans



