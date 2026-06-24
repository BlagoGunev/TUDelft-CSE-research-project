#include <bits/stdc++.h>
#define all(a) begin(a), end(a)
#define sz(a) (int) (a).size()
#define int long long
#define forn(i, n) for (int i = 0; i < n; i++)
using namespace std;

// why so standard :(

const int RED = 1;
const int WHITE = 0;
const int WITH_MAX = 1;
const int WITHOUT_MAX = 0;

int mx = 0;
vector<int> a;

struct node{
    int a[2][2][2];
    node (int idx = -1, bool state = false) {
        forn(i, 2) forn(j, 2) forn(k, 2) a[i][j][k] = -(1LL << 60);
        if (idx != -1) {
            a[WHITE][WHITE][WITHOUT_MAX] = 0;
            if (state) a[RED][RED][::a[idx] == mx] = 1;
        }
    }
};

void chmax(int& x, int y) { x = max(x, y); }
node operator+ (const node& a, const node& b) {
    node c(-1, 0);
    forn(i1, 2) forn(j1, 2) forn(k1, 2)
        forn(i2, 2) forn(j2, 2) forn(k2, 2) {
        if (j1 && i2) continue;
        chmax(c.a[i1][j2][k1 || k2], a.a[i1][j1][k1] + b.a[i2][j2][k2]);
    }
    return c;
}

const int N = 2e5 + 11;
node T[N << 2];

void build(int v, int l, int r) {
    if (l == r) T[v] = node(l, 0);
    else {
        int m = (l + r) / 2;
        build(v * 2 + 1, l, m);
        build(v * 2 + 2, m + 1, r);
        T[v] = T[v * 2 + 1] + T[v * 2 + 2];
    }
}

void update(int qi, int qv, int v, int l, int r) {
    // if (v == 0) printf("ADD %lld %lld\n", qi, qv);
    if (l == r) T[v] = node(qi, qv);
    else {
        int m = (l + r) / 2;
        if (qi <= m) update(qi, qv, v * 2 + 1, l, m);
        else update(qi, qv, v * 2 + 2, m + 1, r);
        T[v] = T[v * 2 + 1] + T[v * 2 + 2];
    }
}

int query() {
    int ans = 0;
    forn(i, 2) forn(j, 2)
        ans = max(ans, mx + T[0].a[i][j][1]);
    return ans;
}

void solve() {
    int n; cin >> n;
    a = vector<int>(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    mx = *max_element(all(a));
    vector<pair<int, int>> V;
    for (int i = 0; i < n; i++) {
        V.push_back({a[i], i});
    }
    sort(all(V), [](auto x, auto y) { return x > y; });
    int ans = 0;

    build(0, 0, n - 1);
    for (auto [val, idx] : V) {
        update(idx, 1, 0, 0, n - 1);
        int res = query() + val;
        ans = max(ans, res);
    }
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}