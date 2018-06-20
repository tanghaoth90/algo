import sys

[x1, y1, x2, y2, x3, y3, x4, y4] = [int(t) for t in raw_input().split()]
[a1, b1, a2, b2, a3, b3, a4, b4] = [int(t) for t in raw_input().split()]

xl, xr = min(x1, x2, x3, x4), max(x1, x2, x3, x4)
yl, yr = min(y1, y2, y3, y4), max(y1, y2, y3, y4)
al, ar = min(a1, a2, a3, a4), max(a1, a2, a3, a4)
bl, br = min(b1, b2, b3, b4), max(b1, b2, b3, b4)
amid = (al+ar)/2
bmid = (bl+br)/2

for a in range(al, amid):
	lt = a-al
	for b in range(bmid-lt, bmid+lt+1):
		#print (a,b),  
		if xl <= a and a <= xr and yl <= b and b <= yr:
			print 'YES'
			sys.exit(0)
	#print ' '

for a in range(amid, ar+1):
	lt = ar-a
	for b in range(bmid-lt, bmid+lt+1):
		#print (a,b),  
		if xl <= a and a <= xr and yl <= b and b <= yr:
			print 'YES'
			sys.exit(0)
	#print ' '	
	
print 'NO'