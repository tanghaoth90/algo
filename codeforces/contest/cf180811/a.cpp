#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, h, a, b, k;

inline int getint() {
	int tmp;
	scanf("%d", &tmp);
	return tmp;
}

int main() {
	n = getint();
	h = getint();
	a = getint();
	b = getint();
	k = getint();
	for (int i = 0; i < k; i++) {
		int ta, fa, tb, fb;
		ta = getint();
		fa = getint();
		tb = getint();
		fb = getint();
		int ans = 0;
		if (ta == tb) {
			ans = abs(fa - fb);
		}
		else {
			if (fa > b) {
				ans += fa - b;
				fa = b;
			}
			else if (fa < a) {
				ans += a - fa;
				fa = a;
			}
			ans += abs(ta - tb);
			ans += abs(fa - fb);
		}
		printf("%d\n", ans);
	}
	return 0;
}
