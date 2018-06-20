n, m = [int(t) for t in raw_input().split()]
x = [int(t) for t in raw_input().split()]
y = set([int(t) for t in raw_input().split()])
x = filter(lambda t: t in y, x)
print ' '.join(map(lambda t: str(t), x))

