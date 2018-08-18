
#include <bits/stdc++.h>
using namespace std;

int n, x, y;
int z, o;
char a[300005];
long long f[300005][3];

inline void refr(long long &a, long long b) {
	if (b < a) a = b;
}

int main() {
	cin >> n >> x >> y;
	cin.getline(a, 300001);
	cin.getline(a, 300001);
	char prec = '-';
	for (char* p = a; *p; p++) {
		if (*p != prec)
			if (*p == '0')
				z ++;
			else
				o ++;
		prec = *p;
	}
	if (z == 0) {
		cout << 0 << endl;
		return 0; 
	}
	long long ans = z*(long long)y;
	refr(ans, (z-1)*(long long)x+y);
	cout << ans << endl;
	return 0;
}
