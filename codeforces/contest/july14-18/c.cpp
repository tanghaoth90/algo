#include <bits/stdc++.h>
using namespace std;

inline int getint() {
	int x;
	scanf("%d", &x);
	return x;
}

int main() {
	int n = getint();
	int m = getint();
	double s = 0;
	while (m--) {
		int x = getint();
		int d = getint();
		s += n*x;
		if (d > 0) {
			s += ((n-1)*(double)n/2)*(double)d;
		}
		else {
			if (n&1) {
				int nn = n>>1;
				s += (nn*(double)(nn+1))*(double)d;
			}
			else {
				int nn = n>>1;
				s += (nn*(double)(nn-1))*(double)d;
				s += nn*(double)d;
			}
		}
	}
	printf("%.10lf\n", s/n);
	return 0;
}
