#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,popcnt")
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace __gnu_pbds;
using namespace std;
 
#define ll long long
#define ld long double
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define mp make_pair
#define F first
#define S second
#define eb emplace_back
#define pb push_back
#define random mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())

inline void solve() {
    ll n, p, k;
    cin >> n >> p >> k;
    ll N[k + 1], D[k + 1], P[k + 1];
    const ll MOD = 998244353;
    N[0] = 1, D[0] = 1, P[0] = 1;
    for (ll i = 1; i <= k; ++i) {
        P[i] = (P[i - 1] * p) % MOD;
    }
    cout << "1 ";
    auto binexp = [&](ll x_, ll y_) {
        ll res = 1;
        x_ %= MOD;
        while (y_) {
            if (y_ & 1LL) res = (res * x_) % MOD;
            x_ = (x_ * x_) % MOD;
            y_ >>= 1LL;
        }
        return res;
    };
    ll pn = binexp(p, n);
    for (ll i = 1; i <= k; ++i) {
        N[i] = (((N[i - 1] * ((pn - P[i - 1] + MOD) % MOD)) % MOD) * ((pn - P[i - 1] + MOD) % MOD)) % MOD;
        D[i] = (D[i - 1] * ((P[i] - 1 + MOD) % MOD)) % MOD;
        ll multiplier = binexp(binexp(p, (i * (i - 1)) / 2LL), MOD - 2);
        cout << (((N[i] * multiplier) % MOD) * binexp(D[i], MOD - 2)) % MOD << " ";
    }
    cout << '\n';
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tests = 1;
    // cin >> tests;
    for (int _ = 0; _ < tests; ++_) {
        solve();
    }
}