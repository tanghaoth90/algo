#include <bits/stdc++.h>
using namespace std;

int n, d, k;
int par[400005], degree[400005], toextend[400005];

void returnNO() {
	puts("NO");
	exit(0);
}

int main() {
	scanf("%d%d%d", &n, &d, &k);
	if (d >= n) returnNO();
	for (int i = 1; i <= n; i++)
		degree[i] = k;
	for (int i = 2; i <= d+1; i++) {
		int j = i-1;
		par[i] = j;
		if (--degree[j] < 0 || --degree[i] < 0) returnNO();
		toextend[i] = min(i-1, d+1-i);
	}
	for (int i = d+2, j = 1; i <= n; i++) {
		while (j < i && !(degree[j] > 0 && toextend[j] > 0)) j++;
		if (j >= i || --degree[j] < 0 || --degree[i] < 0) returnNO();
		par[i] = j;
		toextend[i] = toextend[j]-1;
	}
	puts("YES");
	for (int i = 2; i <= n; i++)
		printf("%d %d\n", par[i], i);
	return 0;
}