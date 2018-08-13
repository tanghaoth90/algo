#include <bits/stdc++.h>
using namespace std;

template <class T>
T pow_mod(T a, T sup, T m) {
	T ans = 1;
	while (sup > 0) {
		if (sup & 1) ans = (ans*a) % m;
		a = a*a % m;
		sup >>= 1;
	}
	return ans;
}

// must use T as <long long>
template <class T>
bool miller_rabin(T n) {
	if (n==2 or n==3) return true;
	if (n <= 1 or !(n & 1)) return false;
	T d = n-1;
	int r = 0;
	while (!(d&1)) {
		d >>= 1;
		r += 1;
	}
	for (int wit = 0; wit < 10; wit++) {
		T a = rand()%(n-3)+2;
		T w0 = pow_mod(a,d,n);
		if (w0 == 1) continue;
		T w = w0;
		bool flag = false;
		for (int i = 0; i < r; i++) {
			if (w == n-1) {
				flag = true; 
				break;
			}
			w = w*w % n;
		}
		if (not flag) return false;
	}
	return true;
}

int main() {
	srand(time(NULL));
	int cnt = 0;
	for (int i = 2; i < 1000000; i++)
		if (miller_rabin<long long>(i)) {
			cnt ++;
		}
	printf("%d\n", cnt);
	return 0;
}