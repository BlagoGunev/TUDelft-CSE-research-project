#pragma GCC optimize("Ofast")

#include "bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define each(x, a) for (auto &x : a)
#define ar array
#define vec vector
#define range(i, n) rep(i, n)

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pair<int, int>>;
using vvi = vector<vi>;

int Bit(int mask, int b) { return (mask >> b) & 1; }

template<class T>
bool ckmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool ckmax(T &a, const T &b) {
    if (b > a) {
        a = b;
        return true;
    }
    return false;
}

// [l, r)
template<typename T, typename F>
T FindFirstTrue(T l, T r, const F &predicat) {
    --l;
    while (r - l > 1) {
        T mid = l + (r - l) / 2;
        if (predicat(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    return r;
}


template<typename T, typename F>
T FindLastFalse(T l, T r, const F &predicat) {
    return FindFirstTrue(l, r, predicat) - 1;
}

const ll INF = 2e18;
const int INFi = 1e9;
const int N = 2e5 + 5;
const int LG = 20;

bool ask(const string &t) {
    cout << "? " << t << endl;
    int x;
    cin >> x;
    if (x == -1) exit(0);
    return x;
}

void answer(const string &t) {
    cout << "! " << t << endl;
}

void solve() {
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    int s = *max_element(all(a));
    vl dp(s + 1);
    vl cnt(s + 1), cnt_g(s + 1);
    rep(i, n) cnt[a[i]]++;

    vl can(s + 1);

    vector<int> mu(s + 1, 1);
    mu[0] = 0;
    for (int i = 2; i <= s; ++i) {
        if (!mu[i]) continue;
        for(int j = i * 2; j <= s; j += i) mu[j] -= mu[i];
        mu[i] = -mu[i];
    }

    ll g = a[0];
    rep(i, n) g = gcd(g, a[i]);
    vector<vi> divs(s + 1);
    for (int i = s; i >= 1; --i) if (mu[i] != 0) for (int j = i; j <= s; j += i) divs[j].push_back(i);

    for (int i = s; i >= 1; --i) {
        for (int j = i; j <= s; j += i) cnt_g[i] += cnt[j];
        if (cnt[i]) {
            dp[i] = i - g;
        } else {
            dp[i] = INF;
        }

        for (int j = i * 2; j <= s; j += i) {
            ll ans = 0;
            for (auto &d: divs[j / i]) ans += mu[d] * cnt_g[d * i];
            if (ans) {
                dp[i] = min(dp[i], i + dp[j] - g);
            }
        }
    }

    cout << dp[g] + g * n << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(12) << fixed;
    int t = 1;
    cin >> t;
    rep(i, t) {
        solve();
    }
    return 0;
}