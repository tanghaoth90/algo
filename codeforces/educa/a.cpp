#include <iostream>
using namespace std;

int main() {
	int n, k, best = 1000;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		if (k % t == 0)
			if (k / t < best)
				best = k / t;
	}
	cout << best << endl;
	return 0;
}
