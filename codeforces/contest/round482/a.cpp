#include <iostream>
using namespace std;

int main() {
	long long n;
	cin >> n;
	n+=1;
	if (n==1)
		cout << 0 << endl;
	else if (n&1)
		cout << n << endl;
	else
		cout << (n>>1) << endl;
	return 0;
}
