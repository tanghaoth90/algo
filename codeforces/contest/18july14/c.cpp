#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;
int n, a[maxn];
bool b[maxn];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", a+i);
	sort(a, a+n);
	int ans = 0;
	for (int i = 0, j = 0; i < n && j < n; i++) {
		while (j < n && a[j] <= a[i]) j++;
		if (j >= n) break;
		a[i] = a[j++];
		ans ++;
	}
	printf("%d\n", ans);
	return 0;
}