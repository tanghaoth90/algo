#include <iostream>
using namespace std;

int ca[10]; // count a
int db[20]; // digit b

int choose_best_digit(int d, bool aless) {
	if (aless) d = 9;
	while (ca[d] == 0) d--;
	return d;
}

bool check_rest(int l, int excl) {
	long long mina = 0;
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < ca[i]-(excl==i); j++)
			mina = mina*10+i;
	long long restb = 0;
	for (int i = l-1; i >= 0; i--)
		restb = restb*10+db[i];
	return mina <= restb;
}

int main() {
	long long a, b;
	cin >> a >> b;
	for (int i = 0; i < 10; i++)
		ca[i] = 0;
	int la = 0;
	while (a > 0) {
		ca[a % 10]++;
		a /= 10;
		la ++;
	}
	for (int i = 0; i < 20; i++)
		db[i] = 0;
	int j = 0;
	while (b > 0) {
		db[j++] = b % 10;
		b /= 10;
	}
	bool already_less = la < j;
	while (la > 0) {
		la --;
		int d = choose_best_digit(db[la], already_less);
		if (!already_less)
			if (d < db[la]) already_less = true;
			else {
				if (!check_rest(la, d)) {
					d = choose_best_digit(d-1, already_less);
					already_less = true;
				}
			}
		ca[d]--;
		cout << d;
	}
	cout << endl;
	return 0;
}
