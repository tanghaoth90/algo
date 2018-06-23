#include <iostream>
using namespace std;

int main() {
	int n, s;
	cin >> n >> s;
	int h, m;
	cin >> h >> m;
	n--;
	int tm = h*60+m, tmpre;
	if (tm-1 >= s) {
		cout << "0 0\n";
		return 0;
	}
	while (n--) {
		tmpre = tm;
		cin >> h >> m;
		int tom = tmpre+1+s;
		tm = h*60+m;
		if (tm-(tom+1) >= s) {
			cout << tom/60 << " " << tom%60 << endl;
			return 0;
		}
	}
	int x = tm+1+s;
	cout << x/60 << " " << x%60 << endl;
	return 0;
}
