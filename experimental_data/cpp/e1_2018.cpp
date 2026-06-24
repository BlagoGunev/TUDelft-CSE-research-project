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
const int N = 5e5 + 5;
const int LG = 20;

int dsu[N];

int root(int v) {
    return v == dsu[v] ? v : dsu[v] = root(dsu[v]);
}

void unite(int u, int v) {
    u = root(u);
    v = root(v);
    if (v == u) return;
    dsu[v] = u;
}

int val[N];

void solve() {
    int n;
    cin >> n;
    vi L(n), R(n);
    rep(i, n) cin >> L[i];
    rep(i, n) cin >> R[i];
    auto xx = R;
    sort(all(xx));
    xx.resize(unique(all(xx)) - xx.begin());
    int sz = xx.size();
    vector<vi> who(sz + 1);
    rep(i, n) {
        int l = L[i], r = R[i];
        l = lower_bound(all(xx), l) - xx.begin();
        r = lower_bound(all(xx), r) - xx.begin();
        l++;
        r++;
        who[r].push_back(l);
    }
    int ans = 0;
    for (int one = 1; one <= n; ++one) {
        for(int i = 0; i <= sz; ++i) dsu[i] = i;
        for(int i = 0; i <= sz; ++i) val[i] = 0;
        int l = 1;
        val[l - 1] = n + 2;
        int cnt = 0;
        for (int r = l; r <= sz; r++) {
            for (auto &j: who[r]) {
                if (j < l) continue;
                val[r]++;
                int pos = root(j - 1);
                val[pos]--;
                if (val[pos] == 0) {
                    unite(pos - 1, pos);
                }
            }
            int cost = n + 2 - val[l - 1];
            if (cost >= one) {
                cnt++;
                l = r + 1;
                val[l - 1] = n + 2;
            } else if (!val[r]) {
                unite(r - 1, r);
            }
        }
        if (!cnt) break;
        ckmax(ans, cnt * one);
    }
    cout << ans << '\n';
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