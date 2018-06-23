#include <string>
#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;

int n;
string s[3];
int f[3][60];
const string names[3] = {"Kuro", "Shiro", "Katie"};

void calfreq(int id, const string& t) {
	int result = 0;
	for (char ch = 'a'; ch <= 'z'; ch++)
		f[id][ch-'a'] = 0;
	for (char ch = 'A'; ch <= 'Z'; ch++)
		f[id][ch-'A'+26] = 0;
	for (int i = 0; i < t.length(); i++)
		if ('a' <= t[i] && t[i] <= 'z')
			f[id][t[i]-'a'] ++;
		else
			f[id][t[i]-'A'+26] ++;
}

int main() {
	cin >> n >> s[0] >> s[1] >> s[2];
	int bl[3], maxl = 0, good;
	for (int i = 0; i < 3; i++) {
		calfreq(i, s[i]);
		int l = s[i].length();
		int bestl = 0;
		for (int j = 0; j < 52; j++) {
			int now = f[i][j];
			int resl = 0;
			if (l - now >= n) {
				resl = now + n;
			}
			else {
				if (l == now && n == 1)
					resl = l-1;
				else
					resl = l;
				/*
				int rest = n - (l - now);
				if (rest & 1)
					resl = l-1;
				else
					resl = l;
				*/
			}
			if (resl > bestl)
				bestl = resl;
		}
		bl[i] = bestl;
		if (bestl > maxl) {
			maxl = bestl;
			good = i;
		}
	}
	int cnt = 0;
	for (int i = 0; i < 3; i++)
		if (bl[i] == maxl)
			cnt ++;
	if (cnt == 1)
		cout << names[good] << endl;
	else
		cout << "Draw\n";
	return 0;
}
