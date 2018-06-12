#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string s;

int main() {
	cin >> s;
	int l = s.length();
	for (int i = 1; i < l-1; i++) {
		char c = s[i];
		if (c == 'A' || c == 'B' || c == 'C') {
			if (s[i-1] != c && s[i-1] != s[i+1] && s[i+1] != c && s[i-1] != '.' && s[i+1] != '.') {
				puts("Yes");
				return 0;
			}
		}
	}
	puts("No");
	return 0;
}
