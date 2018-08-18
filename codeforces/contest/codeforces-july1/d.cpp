
#include <bits/stdc++.h>
using namespace std;

int n;
set<int> s;
vector<string> v;

int main() {
	scanf("%d", &n);
	long long tot = 0;
	for (int i1 = 0; i1 <= n; i1++)
		for (int i5 = 0; i5 <= n-i1; i5++)
			for (int i10 = 0; i10 <= n-i1-i5; i10++) {
				int i50 = n-i1-i5-i10;
				s.insert(i1+5*i5+10*i10+50*i50);
				printf("%d=%d*1+%d*5+%d*10+%d*50\n", i1+5*i5+10*i10+50*i50, i1, i5, i10, i50);
				tot ++;
			}
	//printf("%lld %lld\n", (long long)s.size(), tot);
	return 0;
}