#include <bits/stdc++.h>
using namespace std;

#define F0R(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, b, e) for (int i = b; i < e; ++i)
#define FORE(v, a) for (auto& v : a)

using ll = long long;
using ld = long double;

template <typename T>
void chmin(T& a, const T b) { a = (a > b) ? (b) : (a); }

template <typename T>
void chmax(T& a, const T b) { a = (a < b) ? (b) : (a); }

#ifdef ONLINE_JUDGE
#pragma GCC optimize("O3")
#pragma GCC target("avx2,tune=native")
#endif

constexpr int mod = 1e9 + 7, oo = 1e9 + 7, maxn = 1e5 + 7;
constexpr ll OO = 1e18 + 1488;


void solve_test() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector <vector<ll>> arr(n, vector<ll>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    vector <vector<ll>> a(n + 1, vector<ll>(m + 1));
    ll sm = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            a[i + 1][j + 1] = s[j] - '0';
            if (a[i + 1][j + 1]) sm += arr[i][j];
            else sm -= arr[i][j];
            a[i + 1][j + 1] += a[i][j + 1] + a[i + 1][j] - a[i][j];
        }
    }
    vector <ll> cum;
    ll g = 0;
    for (int i = k; i <= n; i++) {
        for (int j = k; j <= m; j++) {
            ll sm = a[i][j] - a[i - k][j] - a[i][j - k] + a[i - k][j - k];
            g = __gcd(g, abs(k * k - 2 * sm));
        }
    }
    if ((g == 0 && sm == 0) || (g != 0 && sm % g == 0)) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tests = 1; cin >> tests;
    while (tests--) solve_test();
}