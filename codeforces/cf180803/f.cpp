#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> e[300005];
vector<long long> w[300005];
long long p[300005], l[300005];
int pr[300005];
bool isd[300005];
int q[300005];
int dl[300005];
int dll;
set<int> sr;
long long mx1[300005];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i < n; i++) {
		int u, v, w0;
		scanf("%d%d%d", &u, &v, &w0);
		e[u].push_back(v);
		e[v].push_back(u);
		w[u].push_back(w0);
		w[v].push_back(w0);
	}
	{
		int q1, q2;
		q[q1 = q2 = 1] = 1;
		pr[1] = -1;
		while (q1 <= q2) {
			int u = q[q1++];
			int i = 0;
			for (int v : e[u]) {
				if (!pr[v]) {
					pr[v] = u;
					l[v] = l[u] + w[u][i];
					q[++q2] = v;
				}
				i++;
			}
		}
		int x = n;
		while (x != -1) {		
			dl[dll++] = x;
			isd[x] = true;
			x = pr[x];	
		}
		for (int i = n; i >= 1; i--)
			if (!isd[q[i]]) {
				x = q[i];
				if (l[x] > p[x])
					p[x] = l[x];
				int y = pr[x];
				if (p[y] == 0)
					p[y] = p[x];
				else
					p[y] = l[n]*10;
			}
		for (int i = 1; i <= n; i++)
			if (isd[i]) {
				p[i] -= l[i];
				if (p[i] < 0) p[i] = 0;
				//printf("%d %lld\n", i, p[i]);
			}
	}
	/*
		for (int i = 1; i <= n; i++)
			printf(i == n ? "%lld\n" : "%lld ", l[i]);
		for (int i = 1; i <= n; i++)
			printf(i == n ? "%lld\n" : "%lld ", p[i]);
	*/
	mx1[dll] = -l[n]*10;
	long long best = -l[n]*10;
	for (int x = dll-1; x >= 0; x--) {
		int j = dl[x];
		if (x < dll-1) {
			int y = x+1;
			if (p[dl[y]] == 0 && p[j] == 0)
				y++;
			if (p[j] - l[j] + mx1[y] > best)
				best = p[j] - l[j] + mx1[y];
		}
		mx1[x] = p[j] + l[j] > mx1[x+1] ? p[j] + l[j] : mx1[x+1];
		//printf("%d %lld\n", j, mx1);
	}
	//printf("%lld\n", best);


	while (m--) {
		int a;
		scanf("%d", &a);
		if (best + a < 0) {
			printf("%lld\n", best+a+l[n]);
		}
		else {
			printf("%lld\n", l[n]);
		}
	}



	return 0;
}