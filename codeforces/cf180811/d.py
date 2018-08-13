import sys

def printans(i):
    print("! %d"%i, flush=True)
    sys.exit(0)

def fullgetdiff(i, m):
    print("? %d"%i, flush=True)
    ai = int(input())
    print("? %d"%(i+m), flush=True)
    aim = int(input())
    return ai-aim

n = int(input())
if n//2%2: 
    printans(-1)
getdiff = lambda i: fullgetdiff(i, n//2)
d1 = getdiff(1)
if d1==0:
    printans(1)
lo, hi = 2, n//2
while lo <= hi:
    mid = (lo+hi)//2
    dmid = getdiff(mid)
    if dmid == 0:
        printans(mid)
    if d1*dmid > 0:
        lo = mid+1
    else:
        hi = mid-1

