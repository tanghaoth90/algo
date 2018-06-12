import sys

num_of_seqs = int(raw_input())
d = {}
for seq_id in range(1,num_of_seqs+1):
	l = int(raw_input())
	a = [int(x) for x in raw_input().split()]
	s = sum(a)
	b = [s-x for x in a]
	for i in range(0,l):
		if (b[i] in d) and (d[b[i]][0] != seq_id):
			print "YES"
			print seq_id, i+1
			print d[b[i]][0], d[b[i]][1]+1
			sys.exit(0)
		d[b[i]] = (seq_id, i)
print "NO"