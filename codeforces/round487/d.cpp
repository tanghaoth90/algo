#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, l, wmax;
int rx[100005], lx[100005];
int rxl, lxl;

int main() {
	scanf("%d%d%d", &n, &l, &wmax);
	for (int i = 0; i < n; i++) {
		int x_i, v_i;
		scanf("%d%d", &x_i, &v_i);
		if (v_i == 1)
			rx[rxl++] = x_i;
		else
			lx[lxl++] = x_i;
	}
	sort(rx, rx+rxl);
	sort(lx, lx+lxl);
	
	
		
		
	return 0;
}
