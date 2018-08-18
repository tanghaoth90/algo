#include <stdio.h>
#include <algorithm>
#include <set>
using namespace std;

int a[200005];
int n, K;
set<int> s;
int b[200005];

int main() {
	scanf("%d%d", &n, &K);
	int i;
	for (i = 0; i < n; i++) {
		scanf("%d", a+i);
		b[i] = a[i];
	}
	a[n] = 3000000;
	sort(a, a+n+1);
	int n0 = unique(a, a+n+1)-a-1;
	for (i = 0; i < n0; i++)
		if (!((a[i] < a[i+1]) && (a[i+1] <= a[i]+K))) {
			s.insert(a[i]);
		}
	int c = 0;
	for (i = 0; i < n; i++)
		if (s.find(b[i]) != s.end())
			c++;
	printf("%d\n", c);
	return 0;
}

