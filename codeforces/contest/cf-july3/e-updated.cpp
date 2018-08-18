#include <bits/stdc++.h>
using namespace std;

int n, d, k, f1, f2;
int p[400006], ext[400006];
int rest[400006];

int main() {
	scanf("%d%d%d", &n, &d, &k);
	if (d >= n) {
		puts("NO");
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		rest[i] = k;
	}
	for (int i = 2; i <= d+1; i++) {
		int j = i-1;
		p[i] = j;
		if (--rest[j] < 0 || --rest[i] < 0) {
			puts("NO");
			return 0;
		}
		ext[i] = i-1 <= d+1-i ? i-1 : d+1-i;
	}
	for (int i = d+2, j = 1; i <= n; i++) {
		while (j < i && !(rest[j] > 0 && ext[j] > 0)) j++;
		if (j >= i || --rest[j] < 0 || --rest[i] < 0) {
			puts("NO");
			return 0;
		}
		p[i] = j;
		ext[i] = ext[j]-1;
	}
	puts("YES");
	for (int i = 2; i <= n; i++)
		printf("%d %d\n", i, p[i]);
	return 0;
}