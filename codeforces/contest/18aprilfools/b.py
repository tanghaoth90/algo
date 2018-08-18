import sys
for i in range(10):
	print i
	sys.stdout.flush()
	s = raw_input().lower()
	if "even" in s or "way" in s or "die" in s or "seri" in s or "worse" in s or "terr" in s:
		print "grumpy"
		break
	elif "great" in s or "cool" in s or "bad" in s or "think" in s or "touch" in s:
		print "normal"
		break
