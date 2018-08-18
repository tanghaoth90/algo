#include <iostream>
using namespace std;

int main() {
	int n, pos, l, r;
	cin >> n >> pos >> l >> r;
	int ans;
	if (pos < l) {
		ans = l - pos + 1;
		if (r != n) ans += r - l + 1;
	}
	else if (pos > r) {
		ans = pos - r + 1;
		if (l != 1) ans += r - l + 1;
	}
	else {
		if (l == 1 && r == n)
			ans = 0;
		else if (l == 1)
			ans = r - pos + 1;
		else if (r == n)
			ans = pos - l + 1;
		else {
			if (pos - l <= r - pos)
				ans = pos - l + 1 + r - l + 1;
			else
				ans = r - pos + 1 + r - l + 1;
		}
	}
	cout << ans << endl;
	return 0;
}
