#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[1005], b[1005];
int mat[105][105];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d", &b[i]);
	}
	for (int p = 0; p < 31; p++) {
		int mask = 1<<p;
		int row_xsum = 0;
		for (int i = 0; i < n; i++)
			row_xsum ^= a[i] & mask;
		int col_xsum = 0;
		for (int i = 0; i < m; i++)
			col_xsum ^= b[i] & mask;
		if (row_xsum != col_xsum) {
			puts("NO");
			return 0;
		}
		int pr = -1;
		for (int i = 0; i < n; i++) {
			if (a[i] & mask) {
				if (pr == -1) {
					pr = i;
					continue;
				}
				mat[pr][0] ^= mask;
				mat[i][0] ^= mask;
				//printf("r %d %d [%d]\n", pr, i, p);
				pr = -1;
			}
		}
		int pc = -1;
		for (int i = 0; i < m; i++) {
			if (b[i] & mask) {
				if (pc == -1) {
					pc = i;
					continue;
				}
				mat[0][pc] ^= mask;
				mat[0][i] ^= mask;
				//printf("c %d %d [%d]\n", pc, i, p);
				pc = -1;
			}
		}
		if (pr != -1) {
			mat[pr][pc] ^= mask;
			//printf("x %d %d [%d]\n", pr, pc, p);
		}
	}
	puts("YES");
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			printf(j < m-1 ? "%d " : "%d\n", mat[i][j]);
	return 0;
}