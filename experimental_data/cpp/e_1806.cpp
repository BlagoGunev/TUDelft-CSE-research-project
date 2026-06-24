#pragma once
#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()
#define rep(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)
using ll = long long;
using ull = unsigned long long;
using db = double;
using ldb = long double;
using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int,int>;
using vii = vector<ii>;
using vvii = vector<vii>;
using i_ii = pair<int,ii>;
using vi_ii = vector<i_ii>;
using vvi_ii = vector<vi_ii>;
using pll = pair<ll,ll>;
using ll_ll = pll;
using vll = vector<ll>;

template <class T>
inline ostream& operator<<(ostream& o, vector<T> const& v);

template <class T, class Q>
inline ostream& operator<<(ostream& o, pair<T,Q> const& p);

template <class T>
inline ostream& operator<<(ostream& o, vector<T> const& v) {
    rep(i, 0, sz(v)-1)
        o << v[i] << ' ';
    if (!v.empty())
        o << v.back();
    return o;
}

template <class T, class Q>
inline ostream& operator<<(ostream& o, pair<T,Q> const& p) {
    return o << '(' << p.fi << ',' << p.se << ')';
}

#ifndef PI 
    #define PI acos(-1) 
#endif
#ifndef INF 
    #define INF 1e9 
#endif
#ifndef EPS
    #define EPS 1e-9
#endif
#ifndef MOD 
    #define MOD 1000000007
#endif
#ifndef MAXN
    #define MAXN (int)(2e5)
#endif

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
 
        if (hash1 != hash2) {
            return hash1 ^ hash2;             
        }
         
        // If hash1 == hash2, their XOR is zero.
          return hash1;
    }
};

vll a;
vector<int> p;
vi depth;
vi cnt_depth;
unordered_map<int, int> idx;
vector<unordered_map<ii, ll, hash_pair>> memo;

const int MAGIA = 5000;

ll dp(int x, int y) {
    if (x > y) swap(x, y);
    if (sz(memo[depth[x]]) > MAGIA) return a[x] * a[y] + dp(p[x], p[y]);
    if (memo[depth[x]].count({x,y})) return memo[depth[x]][{x,y}];
    else if (x == 0 && y == 0) { return memo[depth[x]][{x,y}] = a[0] * a[0]; }
    else return memo[depth[x]][{x,y}] = a[x] * a[y] + dp(p[x], p[y]);
}

int calcdepth(int u) {
    if (depth[u] != -1) return depth[u];
    else if (u == 0) {
        depth[u] = 0;
        if (cnt_depth.size() <= depth[u]) {
            cnt_depth.resize(depth[u] + 1);
        }
        idx[u] = cnt_depth[depth[u]]++;
        return depth[u];
    } else {
        depth[u] = 1 + calcdepth(p[u]);
        if (cnt_depth.size() <= depth[u]) {
            cnt_depth.resize(depth[u] + 1);
        }
        idx[u] = cnt_depth[depth[u]]++;
        return depth[u];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    a.resize(n); p.assign(n, 0);
    for (ll& ai : a) cin >> ai;
    rep(i, 1, n) { cin >> p[i]; --p[i]; }
    depth.assign(n, -1);
    rep(i, 0, n) {
        if (depth[i] == -1) calcdepth(i);
    }
    memo.assign(sz(cnt_depth), {});
    while (q--) {
        int x, y; cin >> x >> y; --x; --y;
        cout << dp(x, y) << '\n';
    }
    return 0;
}