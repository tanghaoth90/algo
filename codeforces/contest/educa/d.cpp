#include <stdio.h>

bool graph[505][505];
bool connc[505][505];
int path[505][505];
int p[505], pl, next[505];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		next[i] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			graph[i][j] = false;
	while (m--) {
		int u, v;
		scanf("%d%d", &u, &v);
		graph[u][v] = true;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			connc[i][j] = graph[i][j];
			path[i][j] = j;
		}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (!connc[i][j] && connc[i][k] && connc[k][j]) {
					connc[i][j] = true;
					path[i][j] = path[i][k];
				}
	int s = n + 1;
	for (int i = 1; i <= n; i++)
 		if (connc[i][i]) {
			s = i;
			break;
		}
	if (s == n+1) {
		printf("YES\n");
		return 0;
	}
	pl = 0;
	int now = s;
	do {
		p[pl++] = now;
		graph[now][path[now][s]] = false;
		next[now] = path[now][s];
		now = path[now][s];
	} while (now != s);
	/*
	now = s;
	do {
		printf("%d\n", now);
		now = next[now];
	} while (now != s);
	*/
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			connc[i][j] = graph[i][j];
		}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (connc[i][k] && connc[k][j]) 
					connc[i][j] = true;
	for (int i = 1; i <= n; i++)
		if (connc[i][i]) {
			printf("NO\n");
			return 0;
		}
	for (int i = 1; i <= n; i++)
		if (next[i])
			for (int j = 1; j <= n; j++)
				if (next[j] && connc[i][j]) {
					int t = i;
					while (t != j) {
						connc[t][next[t]] = true;
						t = next[t];
					}
				}
	int t = s;
	do {
		if (!connc[t][next[t]]) {
			printf("YES\n");
			return 0;
		}
		t = next[t];
	} while (t != s);
	printf("NO\n");
	return 0;
	/*
	for (int i = 0; i < pl; i++)
		printf("%d ", p[i]);
	printf("\n");
	*/
	return 0;
}
