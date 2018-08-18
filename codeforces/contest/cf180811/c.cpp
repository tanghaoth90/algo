#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;
int p[3005];
int c[3005];
vector<int> v[3005];
vector<int> now;

inline int getint() {
	int tmp;
	scanf("%d", &tmp);
	return tmp;
}

int main() {
	n = getint();
	m = getint();
	for (int i = 1; i <= n; i++) {
		p[i] = getint();
		c[i] = getint();
		v[p[i]].push_back(c[i]);
	}
	for (int i = 1; i <= m; i++)
		if (v[i].size() > 0)
			sort(v[i].begin(), v[i].end());
	ll ans = ll(1000000000)*n;
	for (int atmost = 0; atmost <= n/2; atmost++) {
		ll cost = 0;
		int tick = int(v[1].size());
		now.clear();
		for (int j = 2; j <= m; j++) {
			for (int k = 0; k < max(0, int(v[j].size()-atmost)); k++) {
				cost += v[j][k];
				tick ++;
			}
			for (int k = max(0, int(v[j].size()-atmost)); k < int(v[j].size()); k++) {
				now.push_back(v[j][k]);
			}
		}
		sort(now.begin(), now.end());
		
		int i = 0;
		while (tick <= atmost) {
			tick ++;
			cost += now[i++];
		}
		ans = min(cost, ans);
	}
	printf("%lld\n", ans);
	return 0;
}
