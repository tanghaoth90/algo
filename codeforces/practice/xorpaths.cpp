#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;
ll k0;
ll a[25][25];
struct Counter {
	unordered_map<ll,ll> c;
	void clr() {
		c.clear();
	}
	void add_element(ll e) {
		if (c.count(e) == 0)
			c[e] = 1;
		else
			c[e] += 1;
	}
	int get_freq(ll e) {
		return c.count(e) == 0 ? 0 : c[e];
	}
};		
Counter cnt1, cnt2;

void dfs(int x0, int y0, int x1, int y1, ll curxor, Counter& cnt) {
	if (x0 == x1 && y0 == y1) {
		cnt.add_element(curxor^a[x0][y0]);
		return;
	}
	if (x0 + 1 <= x1)
		dfs(x0+1, y0, x1, y1, curxor^a[x0][y0], cnt);
	if (y0 + 1 <= y1)
		dfs(x0, y0+1, x1, y1, curxor^a[x0][y0], cnt);
}

int main() {
	scanf("%d%d%lld", &n, &m, &k0);
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++)
			scanf("%lld", &a[i][j]);
	int p1_steps = (n+m-2)/2;
	ll ans = 0;
	for (int x0 = 0; x0 < n; x0++) {
		int y0 = p1_steps-x0;
		if (y0 < 0) break;
		cnt1.clr();
		cnt2.clr();
		dfs(0, 0, x0, y0, 0, cnt1);
		dfs(x0, y0, n-1, m-1, 0, cnt2);
		for (auto& p: cnt1.c) {
			ll k1 = p.first;
			ll fq1 = p.second;
			ll fq2 = cnt2.get_freq(k0^k1^a[x0][y0]);
			ans += fq1 * fq2;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
