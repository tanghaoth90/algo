#include <stdio.h>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

#define ln(x) (((x)<<1)+1)
#define rn(x) (((x)<<1)+2)
#define mid(l,r) (((l)+(r))>>1)

const int maxq = 300005;
int n, q;
int ql[maxq], qr[maxq], qk[maxq];
set<int> pointset;
map<int, int> point2label;
int label2point[maxq*2];
int wd[1<<23];
int mark[1<<23];

void paint(int treenode, int segl, int segr, int paintl, int paintr, int color) {
	//printf("%d %d,%d %d,%d %d\n", treenode, segl, segr, paintl, paintr, color);
	if (segr <= segl || paintl >= segr || paintr <= segl)
		return;
	int div = mid(segl,segr);
	if (mark[treenode]) {
		if (segl < div) {
			mark[ln(treenode)] = mark[rn(treenode)] = mark[treenode];
			if (mark[treenode] == 1)
				wd[ln(treenode)] = wd[rn(treenode)] = 0;
			else {
				wd[ln(treenode)] = label2point[div] - label2point[segl];
				wd[rn(treenode)] = label2point[segr] - label2point[div];
			}
		}
		mark[treenode] = 0;
	}
	if (paintl <= segl && segr <= paintr) {
		mark[treenode] = color;
		if (color == 1)
			wd[treenode] = 0;
		else
			wd[treenode] = label2point[segr] - label2point[segl];
	}
	else {
		paint(ln(treenode), segl, div, paintl, paintr, color);
		paint(rn(treenode), div, segr, paintl, paintr, color);
		wd[treenode] = wd[ln(treenode)] + wd[rn(treenode)];
	}
	/*
	printf("%d %d,%d %d,%d %d\n", treenode, segl, segr, paintl, paintr, color);
	for (int i = 0; i < 7; i++)
		printf("%d ", wd[i]);
	printf("\n");
	for (int i = 0; i < 7; i++)
		printf("%d ", mark[i]);
	printf("\n");
	*/
}

int main() {
	scanf("%d%d", &n, &q);
	pointset.insert(0);
	pointset.insert(n);
	for (int qi = 0; qi < q; qi++) {
		scanf("%d%d%d", ql+qi, qr+qi, qk+qi);
		ql[qi]--;
		pointset.insert(ql[qi]);
		pointset.insert(qr[qi]);
	}
	int m = 0;
	for (set<int>::iterator it = pointset.begin(); it != pointset.end(); it++) {
		point2label[*it] = m;
		label2point[m] = *it;
		m++;
	}
	wd[0] = n;
	mark[0] = 2;
	for (int qi = 0; qi < q; qi++) {
		//printf("#%d\n", qi);
		paint(0, 0, m-1, point2label[ql[qi]], point2label[qr[qi]], qk[qi]);
		printf("%d\n", wd[0]);
	}
	return 0;
}
