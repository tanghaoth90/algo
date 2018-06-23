#include <stdio.h>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
using namespace std;

typedef pair<int,int> pii;
set<pii> nonitv;
queue<pii> dellist;
int n, q;

int main() {
	scanf("%d%d", &n, &q);
	int ans = n;
	for (int qi = 0; qi < q; qi++) {
		int ql, qr, qk;
		scanf("%d%d%d", &ql, &qr, &qk);
		ql--;
		set<pii>::iterator it = nonitv.lower_bound(make_pair(ql, ql));
		int lead = n+1;
		if (it != nonitv.begin()) {
			it--;
			if (ql >= it->second) it++;
			else lead = it->first;
		}
		while (!dellist.empty()) dellist.pop();
		while (it != nonitv.end() && it->second <= qr) {
			dellist.push(*it);
			it++;
		}
		int trail = -1;
		if (it != nonitv.end() && qr > it->first) {
			dellist.push(*it);
			trail = it->second;
		}
		while (!dellist.empty()) {
			pii v = dellist.front();
			dellist.pop();
			nonitv.erase(v);
			ans += v.second-v.first;
		}
		if (qk == 1) { // non-working
			if (lead > ql) lead = ql;
			if (trail < qr) trail = qr;
			ans -= trail - lead;
			nonitv.insert(make_pair(lead, trail));
		}
		else { // working
			if (lead < ql) {
				ans -= ql-lead;
				nonitv.insert(make_pair(lead, ql));
			}
			if (trail > qr) {
				ans -= trail-qr;
				nonitv.insert(make_pair(qr, trail));
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
