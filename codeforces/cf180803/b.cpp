#include <bits/stdc++.h>
using namespace std;

int n, m, q;
string s, t;
int sm[1005];

int main() {
	cin >> n >> m >> q;
	cin >> s >> t;
	sm[0] = 0;
	for (int i = 0; i < n; i++) {
		int o = 1;
		for (int j = 0; j < m; j++)
			if (i+j >= n || s[i+j] != t[j]) {
				o = 0;
				break;
			}
		sm[i+1] = sm[i] + o;
	}
	while (q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", (r-m+1 >= l) ? sm[r-m+1]-sm[l-1] : 0);
	}
	return 0;
}