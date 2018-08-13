#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

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

template <class T>
T gcd(T a, T b) {
	while (b) {
		T r = a%b;
		a = b;
		b = r;
	}
	return a;
}

template <class T>
T myabs(T a) {
	return a>=0?a:-a;
}

template <class T>
T pollard_rho(T n) {
	if (miller_rabin<T>(n) || n <= 1) return n;
	if (n <= 1) return n;
	T x = 2, x_fixed = 2, cycle_size = 2, factor = 1;
	while (factor == 1) {
		T cnt = 1;
		while (cnt <= cycle_size && factor <= 1) {
			x = (x*x+1)%n;
			factor = gcd(myabs(x-x_fixed), n);
			cnt ++;
		}
		cycle_size *= 2;
		x_fixed = x;
	}
	return factor;
}

std::ostream&
operator<<( std::ostream& dest, __uint128_t value );

int main() {
	srand(time(NULL));
	int cnt = 0, a = 0, b = 0;
	for (int i = 2; i < 1000000; i++)
		if (miller_rabin<ll>(i)) {
			cnt ++;
			b = a;
			a = i;
		}

	printf("%d\n", cnt);
	printf("%lld\n", pollard_rho<ll>(10403));
	printf("%d*%d %lld\n", a, b, pollard_rho<ll>(a*(ll)b));
	__uint128_t fermat = 3;
	for (int i = 1; i <= 6; i++) {
		// fermat == 2^(2^i)+1
		fermat = (fermat-1)*(fermat-1)+1;
		cout << i << " " << fermat << " ";
		cout << pollard_rho(fermat) << endl;
	}
	return 0;
}

// copied from https://stackoverflow.com/questions/25114597/how-to-print-int128-in-g
std::ostream&
operator<<( std::ostream& dest, __uint128_t value )
{
    std::ostream::sentry s( dest );
    if ( s ) {
        //__uint128_t tmp = value < 0 ? -value : value;
        __uint128_t tmp = value;
        char buffer[ 128 ];
        char* d = std::end( buffer );
        do
        {
            -- d;
            *d = "0123456789"[ tmp % 10 ];
            tmp /= 10;
        } while ( tmp != 0 );
        if ( value < 0 ) {
            -- d;
            *d = '-';
        }
        int len = std::end( buffer ) - d;
        if ( dest.rdbuf()->sputn( d, len ) != len ) {
            dest.setstate( std::ios_base::badbit );
        }
    }
    return dest;
}