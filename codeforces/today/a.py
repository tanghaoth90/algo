a, b, c, n = [int(t) for t in raw_input().split()]

a -= c
b -= c

if a < 0 or b < 0 or n-a-b-c <= 0:
	print -1
else:
	print n-a-b-c