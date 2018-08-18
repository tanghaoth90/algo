#include <bits/stdc++.h>
using namespace std;

int n, k;
int p[100005], c[100005];
int r[100005];
long long ans[100005];
int best10[15];

bool cmp(int a, int b) {
	return p[a] < p[b];
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", p+i);
	for (int i = 0; i < n; i++) {
		scanf("%d", c+i);
		ans[i] = c[i];
	}
	for (int i = 0; i < n; i++)
		r[i] = i;
	sort(r, r+n, cmp);
	c[n] = 0;
	for (int i = 0; i < k; i++)
		best10[i] = 0;
	for (int x = 0; x < n; x++) {
		int i = r[x];
		for (int j = 0; j < k; j++)
			ans[i] += best10[j];
		for (int j = 0; j < k; j++)
			if (best10[j] < c[i]) {
				for (int w = k-1; w >= j+1; w--)
					best10[w] = best10[w-1];
				best10[j] = c[i];
				break;
			}
		//for (int w = 0; w < k; w++)
		//	printf("%d ", best10[w]);
		//puts("");
	}
	for (int i = 0; i < n; i++)
		printf("%lld ", ans[i]);
	puts("");
	return 0;
}