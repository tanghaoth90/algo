n = int(raw_input())
x = [int(t) for t in raw_input().split()]
y = [int(t) for t in raw_input().split()]
sx = sum(x)
sy = sum(y)
if sx >= sy:
    print "Yes"
else:
    print "No"
