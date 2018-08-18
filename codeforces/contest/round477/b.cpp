#include <stdio.h>
#include <functional>
#include <algorithm>
using namespace std;

int curS;
int s[1000005];

int main() {
	int n, A, B;
	scanf("%d%d%d", &n, &A, &B);
	curS = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", s+i);
		curS += s[i];
	}
	sort(s+1, s+n);
	int j = n;
	while (s[0]*A/curS < B) {
		curS -= s[--j];
	}
	printf("%d\n", n-j);
	return 0;
}
