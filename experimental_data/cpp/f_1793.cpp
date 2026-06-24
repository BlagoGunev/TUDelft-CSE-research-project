//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast,unroll-loops,fast-math")
//#pragma GCC target("avx,avx2,bmi,bmi2,popcnt,lzcnt,tune=native")

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 1e9 + 100, MOD = 1e9 + 7, MAXN = 3e5;
const ld EPS = 1e-6;

//random_device rd;
//mt19937 rnd(rd());
//
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
//ll rnd(ll n) { uniform_ll_distribution <ll> uid(0, n - 1); return uid(rng); }
//ld rndd() { return ld(rand()) / RAND_MAX; }

#ifdef local
#define debug(x) cerr << (#x) << ": " << x << endl;
#else
#define debug(x)
#endif

#define pow2(x) ((x)*(x))
#define mod(x, m) ((((x) % (m)) + (m)) % (m))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))

vector<ll> tree(4 * MAXN, -1);
vector<ll> a(MAXN);
vector<ll> dp(MAXN, INF);
vector<ll> dptree(4 * MAXN, INF);

void upddp(ll v, ll l, ll r, ll pos, ll val) {
    if (l + 1 == r) {
        dptree[v] = val;
    } else {
        ll m = (l + r) / 2;
        if (pos < m) {
            upddp(2 * v + 1, l, m, pos, val);
        } else {
            upddp(2 * v + 2, m, r, pos, val);
        }
        dptree[v] = min(dptree[2 * v + 1], dptree[2 * v + 2]);
    }
}

ll getdp(ll v, ll l, ll r, ll ql, ll qr) {
    if (r <= ql || l >= qr) {
        return INF;
    } else if (ql <= l && r <= qr) {
        return dptree[v];
    } else {
        ll m = (l + r) / 2;
        return min(getdp(2 * v + 1, l, m, ql, qr), getdp(2 * v + 2, m, r, ql, qr));
    }
}

void upd(ll pos, ll val) { // arr[pos] := newval
    pos += MAXN;
    tree[pos] = val;
    pos >>= 1;
    while (pos > 0) {
        tree[pos] = max(tree[pos << 1], tree[(pos << 1) | 1]);
        pos >>= 1;
    }
}

ll get(ll l, ll r) { // [l, r)
    l += MAXN;
    r += MAXN;
    ll ans = -1;
    while (l < r) {
        if (l & 1) {
            ans = max(ans, tree[l++]);
        }
        if (r & 1) {
            ans = max(ans, tree[--r]);
        }
        l >>= 1;
        r >>= 1;
    }
    return ans;
}

void solve() {
    ll n, q;
    cin >> n >> q;
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<pair<ll, ll>> zap[n];
    vector<ll> ans(q);
    for (ll i = 0; i < q; ++i) {
        ll l, r;
        cin >> l >> r;
        l--, r--;
        zap[r].push_back({l, i});
    }
    vector<ll> leftmin(n), leftmax(n);
    vector<ll> vec;
    for (ll i = 0; i < n; ++i) {
        while (!vec.empty() && a[vec.back()] > a[i]) {
            vec.pop_back();
        }
        if (vec.empty()) leftmin[i] = -1;
        else leftmin[i] = vec.back();
        vec.push_back(i);
    }
    vec.clear();
    for (ll i = 0; i < n; ++i) {
        while (!vec.empty() && a[vec.back()] < a[i]) {
            vec.pop_back();
        }
        if (vec.empty()) leftmax[i] = -1;
        else leftmax[i] = vec.back();
        vec.push_back(i);
    }

    for (ll i = 0; i < n; ++i) {
        ll ind = leftmax[i];
        while (ind != -1 && ind != i) {
            if (dp[ind] > a[ind] - a[i]) {
                dp[ind] = a[ind] - a[i];
                upddp(0, 0, MAXN, ind, dp[ind]);
            }
            ind = get(a[i], a[i] + (a[ind] - a[i]) / 2 + 1);
        }
        ind = leftmin[i];
        while (ind != -1 && ind != i) {
            if (dp[ind] > a[i] - a[ind]) {
                dp[ind] = a[i] - a[ind];
                upddp(0, 0, MAXN, ind, dp[ind]);
            }
            ind = get(a[i] - (a[i] - a[ind]) / 2, a[i]);
        }
        for (auto e : zap[i]) {
            ans[e.second] = getdp(0, 0, MAXN, e.first, i);
        }
        upd(a[i], i);
    }
    for (ll i = 0; i < q; ++i) {
        cout << ans[i] << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("ALO.in", "r", stdin);
    //freopen("ALO.out", "w", stdout);

    ll test = 1;
//    cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}