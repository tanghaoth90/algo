#include <bits/stdc++.h>
using namespace std;

inline int getint() {
	int x;
	scanf("%d", &x);
	return x;
}

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a%b);
}

pair<int,int> ans[100005];

int main() {
	int n = getint();
	int m = getint();
	if (m < n-1) {
		printf("Impossible\n");
		return 0;
	}
	int ansl = 0;
	for (int d = 1; d < n && ansl < m; d++)
		for (int i = 1; i+d <= n && ansl < m; i++)
			if (gcd(i, i+d) == 1) {
				ans[ansl++] = make_pair(i, i+d);
			}
	if (ansl < m) {
		printf("Impossible\n");
		return 0;
	}
	printf("Possible\n");
	for (int ti = 0; ti < ansl; ti++)
		printf("%d %d\n", ans[ti].first, ans[ti].second);
	return 0;
}
