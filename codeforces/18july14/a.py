s = raw_input()
vowels = set('aouie')
f = True
for i in range(len(s)):
	if s[i] not in vowels and s[i] != 'n':
		if i == len(s)-1 or s[i+1] not in vowels:
			f = False
			break
if f:
	print "YES"
else:
	print "NO"
