#include <bits/stdc++.h>
using namespace std;

int c[100005], a[100005];
int n, x;

int main() {
	scanf("%d%d", &n, &x);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		c[a[i]] ++;
		if (c[a[i]] >= 2) {
			puts("0");
			return 0;
		}
	}
	for (int i = 0; i < n; i++) {
		int t0 = a[i];
		int t1 = a[i] & x;
		c[t0]--;
		c[t1]++;
		if (c[t1] >= 2) {
			puts("1");
			return 0;
		}
		c[t0]++;
		c[t1]--;
	}
	for (int i = 0; i < n; i++) {
		int t0 = a[i];
		int t1 = a[i] & x;
		c[t0]--;
		c[t1]++;
	}
	for (int i = 0; i < 100005; i++) {
		if (c[i] >= 2) {
			puts("2");
			return 0;
		}
	}
	puts("-1");
	return 0;
}
