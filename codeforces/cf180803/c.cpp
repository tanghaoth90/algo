#include <bits/stdc++.h>
using namespace std;

int n;
long long a[300005][2], s[300005][2];
long long l2r[300005][2], r2l[300005][2];

int getint() {
	int t;
	scanf("%d", &t);
	return t;
}

int main() {
	scanf("%d", &n);
	for (int j = 0; j < 2; j++)
		for (int i = 1; i <= n; i++) {
			a[i][j] = getint();
			s[i][j] = s[i-1][j] + a[i][j];
		}
	l2r[n][0] = l2r[n][1] = 0;
	for (int j = 0; j < 2; j++)
		for (int i = n-1; i >= 1; i--) {
			l2r[i][j] = l2r[i+1][j] + s[n][j] - s[i][j];
		}
	/*
	for (int j = 0; j < 2; j++)
		for (int i = 1; i <= n; i++)
			printf(i == n ? "%lld\n" : "%lld ", l2r[i][j]);
	*/
	r2l[n][0] = r2l[n][1] = 0;	
	for (int j = 0; j < 2; j++)
		for (int i = n-1; i >= 1; i--) {
			r2l[i][j] = r2l[i+1][j] + a[i][j] * (n-i);
		}
	long long timestamp = 0;
	int d[4][2] = {{0,1}, {1,0}, {0,-1}, {1,0}};
	int c[2] = {1,0};
	int r = 0;
	long long ans = 0, csum = 0;
	while (c[0] <= n) {
		if ((c[0] ^ c[1]) & 1) {
			long long now = csum;
			//printf("%lld\n", now);
			now += l2r[c[0]][c[1]] + timestamp * (s[n][c[1]] - s[c[0]-1][c[1]]);
			//printf("%lld %lld\n", l2r[c[0]][c[1]], now);
			now += r2l[c[0]][c[1]^1] + (timestamp+n-c[0]+1) * (s[n][c[1]^1] - s[c[0]-1][c[1]^1]);
			//printf("%d,%d %lld\n", c[0], c[1], now);
			if (now > ans)
				ans = now;
		}
		csum += (timestamp++) * a[c[0]][c[1]];
		c[0] += d[r][0];
		c[1] += d[r][1];
		r++;
		if (r == 4) r = 0;
	}
	printf("%lld\n", ans);
	return 0;
}