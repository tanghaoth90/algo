#include <bits/stdc++.h>
using namespace std;

int l[400][400];
unsigned long h[400][400];
char le[100005];
string ss[400];
bool sseq[400][400];

unsigned stringhash(const char *str) {
    unsigned long hash = 5381;
    int c;
    while (c = *str++)
        hash = (hash * 91 + c) % 179426549;
    return hash;
}

int main() {
	int n;
	cin >> n;
	int all_len = 0;
	for (int i = 0; i < n; i++) {
		//scanf("%s", le);
		//ss[i] = le;
		cin >> ss[i];
		const char *lee = ss[i].c_str();
		l[i][0] = strlen(lee);
		h[i][0] = stringhash(lee);
		all_len += l[i][0];
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			sseq[i][j] = ss[i] == ss[j];
	all_len += n-1;
	for (int i = 0; i < n; i++)
		for (int j = 1; i+j < n; j++) {
			h[i][j] = (h[i][j-1] * 93 + h[i+j][0]) % 179426549;
			l[i][j] = l[i][j-1] + 1 + l[i+j][0];
		}
	int best = 0;
	for (int j = 0; j < n; j++)
		for (int i = 0; i+j < n; i++) {
			int appears = 0;
			for (int k = i+j+1; k+j < n; k++)
				if (h[i][j] == h[k][j]) {
					appears ++;
					k = k+j;
				}
			if (appears) {
				appears ++;
				//printf("%d %d %d\n", i, j, appears);
				int cur = (l[i][j]-(j+1))*appears;
				if (cur > best) best = cur;
			}
		}
	cout << all_len-best << endl;
	return 0;
}
