#include <bits/stdc++.h>
#define show(x) cerr << #x << " = " << x << endl
using namespace std;
using ll = long long;
using ld = long double;
constexpr ll MOD = 1000000007LL;
template <typename T>
constexpr T INF = numeric_limits<T>::max() / 10;
template <typename Functor>
struct fix_type
{
    Functor functor;
    template <typename... Args>
    decltype(auto) operator()(Args&&... args) const& { return functor(functor, std::forward<Args>(args)...); }
};
template <typename Functor>
fix_type<typename std::decay<Functor>::type> fix(Functor&& functor) { return {std::forward<Functor>(functor)}; }

int main()
{
    ll N;
    cin >> N;
    ll inf = 0;
    ll sup = N + 1;
    while (sup - inf > 1) {
        const ll mid = (inf + sup) / 2;
        ll c = N;
        ll ans = 0;
        while (c > 0) {
            const ll eat = min(c, mid);
            ans += eat, c -= eat;
            c -= c / 10;
        }
        if (ans * 2 >= N) {
            sup = mid;
        } else {
            inf = mid;
        }
    }
    cout << sup << endl;
    return 0;
}