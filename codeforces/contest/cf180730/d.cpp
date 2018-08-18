#include <bits/stdc++.h>
using namespace std;

int p[400005];
int n, m, q;

int anc(int x) {
	return p[x] == x ? x : (p[x] = anc(p[x]));
}

int comb(int x, int y) {
	x = anc(x);
	y = anc(y);
	if (p[x] == p[y])
		return 0;
	p[y] = x;
	return 1;
}

int main() {
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < n+m; i++)
		p[i] = i;
	int ans = n+m-1;
	while (q--) {
		int x, y;
		scanf("%d%d", &x, &y);
		x --;
		y += n-1;
		ans -= (q&1) ? comb(x, y) : comb(y, x);
	}
	printf("%d\n", ans);
	return 0;
}
