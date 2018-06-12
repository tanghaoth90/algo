#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, p;
string s;

int ng(char a) {return a == '0' ? '1' : '0';}
int ranfill() {
	for (int i = 0; i < n; i++)
		if (s[i] == '.')
			s[i] = '0';
}

int main() {
	cin >> n >> p;
	cin >> s;
	for (int i = 0; i < n-p; i++) {
		if (s[i] != '.' && s[i+p] != '.') {
			if (s[i] == s[i+p])
				continue;
			ranfill();
		}
		else {
			if (s[i] == '.' && s[i+p] == '.') {
				s[i] = '0'; s[i+p] = '1';
			}
			else if (s[i] == '.') s[i] = ng(s[i+p]);
			else if (s[i+p] == '.') s[i+p] = ng(s[i]);
			ranfill();
		}
		cout << s << endl;
		return 0;
	}
	cout << "No" << endl;
	return 0;
}
