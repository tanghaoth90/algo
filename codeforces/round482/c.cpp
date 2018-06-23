#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[300005];
int n, x, y;
int pre[300005];
bool vis[300005];
queue<int> myqueue;

void bfsxy(int x, int y, int& x_forb, int& y_forb) {
	for (int i = 1; i <= n; i++)
		pre[i] = 0;
	while (!myqueue.empty()) myqueue.pop();
	myqueue.push(x);
	pre[x] = -1;
	while (!myqueue.empty() && pre[y] == 0) {
		int now = myqueue.front();
		myqueue.pop();
		for (int v : adj[now]) {
			if (!pre[v]) {
				pre[v] = now;
				myqueue.push(v);
			}
		}
	}
	y_forb = pre[y];
	x_forb = y;
	while (pre[x_forb] != x)
		x_forb = pre[x_forb];
}

long long bfs_use_forb(int x, int xf) {
	for (int i = 1; i <= n; i++)
		vis[i] = false;
	while (!myqueue.empty()) myqueue.pop();
	myqueue.push(x);
	vis[x] = true;
	int result = 0;
	while (!myqueue.empty()) {
		int now = myqueue.front();
		myqueue.pop();
		result ++;
		for (int v : adj[now])
			if (!vis[v] && v != xf) {
				vis[v] = true;
				myqueue.push(v);
			}
	}
	return result;
}

int main() {
	scanf("%d%d%d", &n, &x, &y);
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	long long ans = n * (long long)(n-1);
	int xf, yf;
	bfsxy(x, y, xf, yf);
	ans -= bfs_use_forb(x, xf) * bfs_use_forb(y, yf);
	cout << ans << endl;
	return 0;
}
