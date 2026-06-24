#include <iostream>
#include<string>
#include<cmath>
#include<map>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<set>
#include<cstdio>
#include<stack>
#include<ctime>
#include<queue>
#include<deque>
#include<bitset>
#include<random>
#include<fstream>
#include<unordered_map>
#include<unordered_set>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using uint = unsigned int;
using dbl = double;

# define all(x) x.begin(), x.end()
# define rall(x) x.rbegin(), x.rend()

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}
ll bpow(ll a, ll n) {
    return n == 0 ? 1 : n % 2 ? bpow(a, n - 1) * a : bpow(a * a, n / 2);
}
ll bpowm(ll a, ll n, ll m) {
    return n == 0 ? 1 : n % 2 ? bpowm(a, n - 1, m) * a % m : bpowm(a * a % m, n / 2, m);
}
mt19937 mt(time(0));
const int N = 2e5 + 10, K = 6e3, inf = 1e9 + 10, mod = 1e9 + 7, mod2 = 998244353, P = 503077;
const ll llinf = 1e18 + 100;
ll z, k;
bool check(ll x, ll cnt) {
    ll c = x / k;
    c = min(c, cnt);
    ll z1 = z;
    z1 -= (c * (c + 1) / 2 * k);
    z1 -= (cnt - c) * x;
    return z1 <= 0;
}

void solve() {
    ll x, y;
    cin >> x >> y >> z >> k;
    ll ans = llinf;
    ll s = 0, z1 = z;
    for (ll d = 1; d < (int)6e5; ++d) {
        s += x;
        if (d % k == 0) {
            s += y, z1 -= d;
        }
        ans = min(ans, s + (z1 + d - 1) / d * y);
    }
    for (ll cnt = 1; cnt < K; ++cnt) {
        ll l = 0, r = z + 1;
        while (r - l > 1) {
            ll m = (l + r) >> 1;
            if (check(m, cnt)) r = m;
            else
                l = m;
        }
        if(r != z + 1) ans = min(ans, cnt * y + r * x);
    }
    cout << ans;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("coloring.in", "r", stdin);
    //freopen("coloring.out", "w", stdout);

    //ld time1 = clock();

    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
        cout << '\n';
        cout.flush();
    }

    //ld time2 = clock();
    //cerr << "\n\nTIME: " << (time2 - time1) / CLOCKS_PER_SEC;
    return 0;
}