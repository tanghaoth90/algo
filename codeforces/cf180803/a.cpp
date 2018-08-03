#include <bits/stdc++.h>
using namespace std;

int n, m, a;

int main() {
	scanf("%d%d", &n, &m);
	int now = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a);
		int c = a / m;
		a %= m;
		now += a;
		if (now >= m) {
			c++;
			now -= m;
		}
		printf(i == n ? "%d\n" : "%d ", c);
	}
	return 0;
}