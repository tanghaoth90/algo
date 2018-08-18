#include <stdio.h>
#include <algorithm>
using namespace std;

int a[500005];
int c[500005];

int n, k, d;

int getsum(int x) {
	if (x == -1) return 0;
	int result = 0;
	while (x > 0) {
		result += c[x];
		x -= (x&(-x));
	}
	return result+1;
}

int add(int x) {
	while (x <= n) {
		c[x]++;
		x += (x&(-x));
	}
}

int main() {
	scanf("%d%d%d", &n, &k, &d);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a+i);
		c[i] = 0;
	}
	sort(a+1, a+1+n);
	for (int i = 1, j = 1; i <= n; i++) {
		while (j<i && a[j]<a[i]-d) {
			j++;
		}
		//printf("j %d\n", j);
		if (i-j+1 >= k && getsum(i-k)-getsum(j-2) > 0) {
			add(i);
			//printf("%d\n", i);
		}
		//puts("");
	}
	puts((getsum(n)-getsum(n-1)>0)?"YES":"NO");
	return 0;
}	
