#include <stdio.h>
#include <functional>
#include <algorithm>
using namespace std;

int c[300005];
typedef pair<int,int> pii;
pii cx[300005];
int index[300005];
int valid[300005];

bool getresult(int n, int x1, int x2, bool rev) {
	for (int i = 0; i < n-1; i++)
		valid[i] = -1;
	for (int i = 0; i < n-1; i++) {
		if (valid[i] == -1 && ((long long)c[i]*(i+1)) >= x1)
			valid[i] = i;
		if (valid[i] >= 0)
			valid[i+1] = valid[i];
	}
	for (int j = 1; j < n; j++) {
		int maxi = x2%c[j]==0 ? j-x2/c[j] : j-x2/c[j]-1;
		//printf("MJV %d %d %d\n", maxi, j, valid[maxi]);
		if (maxi >= 0 && valid[maxi]>=0) {
			printf("Yes\n");
			if (!rev) {
				printf("%d %d\n", valid[maxi]+1, j-valid[maxi]);
				for (int k = 0; k <= valid[maxi]; k++)
					printf(k < valid[maxi] ? "%d ":"%d\n", index[k]);
				for (int k = valid[maxi]+1; k <= j; k++)
					printf(k < j ? "%d ":"%d\n", index[k]);
			} else {
				printf("%d %d\n", j-valid[maxi], valid[maxi]+1);
				for (int k = valid[maxi]+1; k <= j; k++)
					printf(k < j ? "%d ":"%d\n", index[k]);
				for (int k = 0; k <= valid[maxi]; k++)
					printf(k < valid[maxi] ? "%d ":"%d\n", index[k]);
			}
			return true;
		}
	}
	return false;
}

int main() {
	int n, x1, x2;
	scanf("%d%d%d", &n, &x1, &x2);
	for (int i = 0; i < n; i++) {
		scanf("%d", c+i);
		cx[i] = make_pair(c[i], i);
	}
	sort(c, c+n, greater<int>());
	sort(cx, cx+n, greater<pii>());
	for (int i = 0; i < n; i++) 
		index[i] = cx[i].second+1;
	if (getresult(n, x1, x2, false)) return 0;
	if (getresult(n, x2, x1, true)) return 0;
	printf("No\n");
	return 0;
}
