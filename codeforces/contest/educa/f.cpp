#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

pair<int,int> weight_index[1000005];
int n;
int parent[1000005], dssize[1000005];
bool alive[1000005];
vector<int> adj[1000005];

int anc(int x) {
	return x == parent[x] ? x : (parent[x] = anc(parent[x]));
}

int getsize(int x) {
	return dssize[anc(x)];
}

void comb(int x, int y) {
	int xs = getsize(x);
	int ys = getsize(y);
	if (xs <= ys) {
		parent[anc(x)] = anc(y);
		dssize[anc(y)] = xs+ys;
	}
	else {
		parent[anc(y)] = anc(x);
		dssize[anc(x)] = xs+ys;
	}
}

long long gettotal() {
	long long ans = 0;
	int i;
	for (i = 1; i <= n; i++) {
		parent[i] = i;
		dssize[i] = 1;
		alive[i] = false;
	}
	for (i = 1; i <= n; i++) {
		int cur_a = weight_index[i].first;
		int cur_u = weight_index[i].second;
		alive[cur_u] = true;
		int presum = 1;
		long long cnt_pair = 1;
		for (int j = 0; j < adj[cur_u].size(); j++) {
			int v = adj[cur_u][j];
			if (alive[v]) {
				//cout << getsize(v) << endl;
				cnt_pair += presum * (long long)getsize(v);
				presum += getsize(v);
				comb(cur_u, v);
			}
		}
		//cout << cur_a << " " << cur_u << " " << cnt_pair << endl;
		ans += cnt_pair * cur_a;
	}
	return ans;
}

int main() {
	scanf("%d", &n);
	int i;
	for (i = 1; i <= n; i++) {
		int t;
		scanf("%d\n", &t);
		weight_index[i] = make_pair(t, i);
	}
	for (i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	sort(weight_index+1, weight_index+(1+n));
	long long ans = gettotal();
	reverse(weight_index+1, weight_index+(1+n));
	ans -= gettotal();
	cout << ans << endl;
	return 0;
}
