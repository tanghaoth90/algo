import random, time

def myqsort(a):
	if len(a)<=1: return a
	return myqsort(filter(lambda x:x<a[0], a)) + filter(lambda x:x==a[0], a) + myqsort(filter(lambda x:x>a[0], a))

def inplaceqsort(a, l, r):
	if l >= r: return
	pivot = a[l]
	i, j = l, r
	while i<j:
		while i<j and a[j]>=pivot: j-=1
		a[i] = a[j]
		while i<j and a[i]<=pivot: i+=1
		a[j] = a[i]
	a[i] = pivot
	inplaceqsort(a, l, i-1)
	inplaceqsort(a, i+1, r)

n = 500000
a0 = [random.randint(0,1000000) for i in range(0,n)]

c = [x for x in a0]
t0 = time.clock()
inplaceqsort(c, 0, len(c)-1)
print time.clock()-t0

a = [x for x in a0]
t0 = time.clock()
b = myqsort(a)
print time.clock()-t0

a = [x for x in a0]
t0 = time.clock()
a.sort()
print time.clock()-t0
print a == b
print a == c

a = [x for x in a0]
t0 = time.clock()
sorted(a)
print time.clock()-t0
