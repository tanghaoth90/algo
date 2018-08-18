#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;
int n, w[maxn], h[maxn];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", w+i, h+i);
	int x = w[0];
	if (h[0] > x) x = h[0];
	for (int i = 1; i < n; i++) {
		int y = w[i] > h[i] ? w[i] : h[i];
		int z = w[i] < h[i] ? w[i] : h[i];
		if (y <= x)
			x = y;
		else if (z <= x)
			x = z;
		else {
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}