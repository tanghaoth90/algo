#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
int p[1005];
bool vis[1005];

inline int getint() {
	int tmp;
	scanf("%d", &tmp);
	return tmp;
}

int main() {
	n = getint();
	for (int i = 1; i <= n; i++)
		p[i] = getint();
	for (int a = 1; a <= n; a++) {
		for (int i = 1; i <= n; i++)
			vis[i] = false;
		int j = a;
		while (!vis[j]) {
			vis[j] = true;
			j = p[j];
		}
		printf(a == 1 ? "%d" : " %d", j);
	}
	puts("");
	return 0;
}
