#include <iostream>
#include <algorithm>

using namespace std;

long long n, m, a, b;

int main() {
	cin >> n >> m >> a >> b;
	long long d = n % m;
	if (d == 0)
		cout << 0 << endl;
	else {
		long long f1 = d * b, f2 = (m-d) * a;
		cout << (f1<=f2 ? f1:f2) << endl;
	}
	return 0;
}

