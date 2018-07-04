#include <bits/stdc++.h>
using namespace std;

int n;
pair<int,int> p[400005];
int ans[400005];

int main() {
	scanf("%d", &n);
	for (int i = 0 ; i < n; i ++) {
		int l, r;
		scanf("%d%d", &l, &r);
		p[i*2] = make_pair(l, 1);
		p[i*2+1] = make_pair(r, 2);
	}
	sort(p, p+n*2);
	int pre = -1;
	int tot = 0;
	for (int i = 0; i < 2*n; ) {
		int now = p[i].first;
		ans[tot] += p[i].first - pre - 1;
		int j = i;
		while (p[j].first == now && j < 2*n) j++;
		for (int k = i; k < j; k++)
			if (p[k].second == 1)
				tot += 1;
		ans[tot] += 1;
		for (int k = i; k < j; k++)
			if (p[k].second == 2)
				tot -= 1;
		pre = p[i].first;
		i = j;
	}
	for (int i = 1; i <= n; i++)
		printf(i == n ? "%d\n" : "%d ", ans[i]);
	return 0;
}
