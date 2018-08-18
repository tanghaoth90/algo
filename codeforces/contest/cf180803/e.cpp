#include <bits/stdc++.h>
using namespace std;

const int maxn = 200005;
double sy, a, b;
double l[maxn], r[maxn];
double s[maxn];
int n;

int find_inside(double key) {
	int lo = 1, hi = n;
	while (lo < hi) {
		int mid = (lo+hi)>>1;
		if (key > l[mid])
			lo = mid+1;
		else
			hi = mid-1;
	}
	lo --;
	while (lo < n && l[lo+1] < key) lo++;
	return lo;
}

double f(double key) {
	if (key < l[1])
		return 0;
	int u = find_inside(key);
	//printf("s%lf %d\n", key, u);
	double ansu = s[u];
	if (key < r[u])
		ansu -= r[u] - key;
	return ansu;
}

int main() {
	scanf("%lf%lf%lf", &sy, &a, &b);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lf%lf", l+i, r+i);
		s[i] = s[i-1] + r[i] - l[i];
	}
	int q;
	for (scanf("%d", &q); q--; ) {
		double x, y;
		scanf("%lf%lf", &x, &y);
		double newa = x-(x-a)*y/(y-sy);
		double newb = x+(b-x)*y/(y-sy);
		printf("%.12lf\n", (f(newb) - f(newa))/y*(y-sy));
	}
	return 0;
}