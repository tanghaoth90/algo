#include <bits/stdc++.h>
using namespace std;

int a[32];

int getint() {
	int t;
	scanf("%d", &t);
	return t;
}

int getshift(int t) {
	int s = -1;
	while (t) {
		t >>= 1;
		s++;
	}
	return s;
}

int main() {
	int n = getint();
	int q = getint();
	for (int i = 0; i < n; i++) {
		int x = 0, t = getint();
		a[getshift(t)] ++;
	}
	while (q--) {
		int ans = 0, t = getint();
		for (int i = 30; i >= 0; i--) {
			if (t >= (1<<i) ) {
				int c = t / (1<<i);
				if (c > a[i]) c = a[i];
				ans += c;
				t -= c << i;
			}
		}
		printf("%d\n", t>0?-1:ans);
	}
	return 0;
}