#include <bits/stdc++.h>
using namespace std;

inline int getint() {
	int x;
	scanf("%d", &x);
	return x;
}

int a[1000005], sa[1000005], qa[1000005];
int f[1000005];
const int mol = 998244353;

int mul(int x, int y) {
	return x*y%mol;
}

int plu(int x, int y) {
	return (x+y)%mol;
}

int minu(int x, int y) {
	return (x-y+mol)%mol;
}

int main() {
	int n = getint();
	sa[0] = 0;
	for (int i = 1; i <= n; i++) {
		a[i] = getint();
		sa[i] = plu(sa[i-1], a[i]);
		//qa[i] = ((((qa[i-1]*2%mol - sa[i-1])% mol + mol)%mol + sa[i]) % mol + mol) % mol;
		qa[i] = plu(minu(mul(qa[i-1], 2), sa[i-1]), sa[i]);
	}
	f[0] = 0;
	int cursum = 0;
	for (int i = 1; i <= n; i++) {
		/*
		f[i] = 0;
		int p2 = 1;
		for (int j = 0; j < i; j++) {
			f[i] += f[j]+sa[i-j]*p2;
			if (j > 0) p2 <<= 1;
		}
		*/
		f[i] = (cursum + qa[i]) % mol;
		cursum = (cursum + f[i]) % mol;
	}
	printf("%d\n", f[n]);
	//printf("%d %d %d %d\n", f[1], f[2], f[3], f[4]);
	return 0;
}
