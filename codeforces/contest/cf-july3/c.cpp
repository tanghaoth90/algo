#include <bits/stdc++.h>
using namespace std;

int a[5005], s[5005];

int getint() {
	int t;
	scanf("%d", &t);
	return t;
}

void upd(double &a, double b) {
	if (b > a) a = b;
}

int main(){
	int n, k;
	n = getint();
	k = getint();
	for (int i = 1; i <= n; i++) {
		a[i] = getint();
		s[i] = a[i] + s[i-1];
	}
	double ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = i+k-1; j <= n; j++)
			upd(ans, (s[j]-s[i-1])/(j-i+1.0));
	printf("%.8lf\n" , ans);
	return 0;
}