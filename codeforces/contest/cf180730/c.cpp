#include <bits/stdc++.h>
using namespace std;

int a[200005];
int n;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < (n<<1); i++)
		scanf("%d", &a[i]);
	sort(a, a+(n<<1));
	long long ans = ((long long)1)<<62;
	for (int i = 0; i+n-1 < (n<<1); i++) {
		long long dx = a[i+n-1]-a[i], dy;
		if (i == 0) {
			dy = a[2*n-1]-a[n];
		}
		else if (i == n) {
			dy = a[n-1]-a[0];
		}
		else
			dy = a[2*n-1]-a[0];
		if (dx * dy < ans)
			ans = dx * dy;
	}
	printf("%lld\n", ans);
	return 0;
}
