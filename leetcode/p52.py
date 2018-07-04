class Solution(object):
	def totalNQueens(self, n):
		states, prestates = [(0, 0, 0)], []
		mask = (1<<n)-1
		for i in range(n): #range((n-1)>>1):
			prestates, states = states, []
			for t in prestates:
				for j in range(n):
					row = 1<<j
					if not(t[0]&row) and not((t[1]>>1)&row) and not((t[2]<<1)&row):
						states.append((t[0]|row, (t[1]>>1)|row, (t[2]<<1)&mask|row))
		return len(states)

print Solution().totalNQueens(13)