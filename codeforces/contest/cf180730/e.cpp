#include <bits/stdc++.h>
using namespace std;

int n;
int a[5005];
int f[8][2505], g[8][2505];
int ans[2505];

int main(){
	scanf("%d", &n);
	for (int j = 0; j <= ((n+1)>>1); j++) {
		for (int s = 0; s < 4; s++)
			f[j][s] = 1<<30;
	}
	for (int s = 0; s < 4; s++)
		f[0][s] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= ((n+1)>>1); j++)
			for (int s = 0; s < 4; s++) {
				g[j][s] = f[j][s];
				f[j][s] = 1<<30;
			}
		for (int j = 0; j <= ((i+1)>>1); j++)
			for (int s = 0; s < 4; s++) {





			}
	}
	for (int j = 1; j <= ((n+1)>>1); j++) {
		ans[j] = 1<<30;
		


	}

	return 0;
}
