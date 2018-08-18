#include <stdio.h>
#include <algorithm>
using namespace std;

int n, m, cl, ce, v;
int stair[100005];
int elev[100005];

int dif(int a, int b) {
	return a>=b ? a-b : b-a;
}

int edif(int a, int b) {
	int d = dif(a,b);
	return d%v ? d/v+1 : d/v;
}

int main() {
	scanf("%d%d%d%d%d", &n, &m, &cl, &ce, &v);
	for (int i = 0; i < cl; i++)
		scanf("%d", stair+i);
	for (int i = 0; i < ce; i++)
		scanf("%d", elev+i);
	sort(stair, stair+cl);
	sort(elev, elev+ce);
	int q;
	scanf("%d", &q);
	while (q--) {
		int x1, y1, x2, y2;
		int ans = (n+m)<<1;
		int cost;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		int tmp = x1; x1 = y1; y1 = tmp;
		tmp = x2; x2 = y2; y2 = tmp;
		int near = lower_bound(stair, stair+cl, x1)-stair;
		if (near < cl) {
			cost = dif(stair[near],x1)+dif(y1,y2)+dif(stair[near],x2);
			if (cost < ans) ans = cost;
		}
		if (!(near < cl && stair[near] == x1)) { 
			near--;
			if (near >= 0) {
				cost = dif(stair[near],x1)+dif(y1,y2)+dif(stair[near],x2);
				if (cost < ans) ans = cost;
			}
		}
		near = lower_bound(elev, elev+ce, x1)-elev;
		if (near < ce) {
			cost = dif(elev[near],x1)+edif(y1,y2)+dif(elev[near],x2);
			if (cost < ans) ans = cost;
		}
		if (!(near < ce && elev[near] == x1)) { 
			near--;
			if (near >= 0) {
				cost = dif(elev[near],x1)+edif(y1,y2)+dif(elev[near],x2);
				if (cost < ans) ans = cost;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
