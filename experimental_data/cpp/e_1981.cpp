#include <bits/stdc++.h>

using namespace std;

// #define int long long
typedef long long ll;
typedef long double ld;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define ar(x) array<int, x>
const int INF = (int) 2e9;
const int A = 300500;

struct segtree {
    int n = 1;
    vector<int> tree_sum, tree_min, tree_max;
    vector<int> mod;
    vector<int> sons;

    void merge(int v) {
        tree_sum[v] = tree_sum[2 * v + 1] + tree_sum[2 * v + 2];
        tree_min[v] = min(tree_min[2 * v + 1], tree_min[2 * v + 2]);
        tree_max[v] = max(tree_max[2 * v + 1], tree_max[2 * v + 2]);
    }

    void build(int v, int l, int r) {
        if (l + 1 == r) {
            tree_sum[v] = tree_min[v] = tree_max[v] = -1;
            sons[v] = 1;
            return;
        }
        int mid = (l + r) / 2;
        build(2 * v + 1, l, mid);
        build(2 * v + 2, mid, r);
        merge(v);
        sons[v] = sons[2 * v + 1] + sons[2 * v + 2];
    }

    segtree(int n_) {
        while (n <= n_) n *= 2;
        tree_sum.resize(4 * n + 5);
        tree_min.assign(4 * n + 5, INF);
        tree_max.assign(4 * n + 5, -INF);
        mod.assign(4 * n + 5, -1);
        sons.resize(4 * n + 5);
        build(0, 0, n);
    }

    void push(int v) {
        if (mod[v] == -1) return;
        tree_sum[v] = mod[v] * sons[v];
        tree_min[v] = tree_max[v] = mod[v];
        mod[2 * v + 1] = mod[v];
        mod[2 * v + 2] = mod[v];
        mod[v] = -1;
    }

    void upd(int v, int l, int r, int lq, int rq, int x) {
        push(v);
        if (l >= rq || lq >= r)return;
        if (lq <= l && r <= rq) {
            mod[v] = x;
            push(v);
            return;
        }
        int mid = (l + r) / 2;
        upd(2 * v + 1, l, mid, lq, rq, x);
        upd(2 * v + 2, mid, r, lq, rq, x);
        merge(v);
    }

    void upd(int lq, int rq, int x) {
        upd(0, 0, n, lq, rq, x);
    }

    int get(int v, int l, int r, int lq, int rq) {
        push(v);
        if (l >= rq || lq >= r)return 0;
        if (lq <= l && r <= rq) {
            return tree_max[v];
        }
        int mid = (l + r) / 2;
        int a1 = get(2 * v + 1, l, mid, lq, rq), a2 = get(2 * v + 2, mid, r, lq, rq);
        return max(a1, a2);
    }

    int get(int lq, int rq) {
        return get(0, 0, n, lq, rq);
    }
};

struct dsu {
    int n;
    vector<int> par, sz;

    dsu(int n_) {
        n = n_;
        par.resize(n);
        sz.resize(n);
        iota(all(par), 0);
        iota(all(sz), 1);
    }

    int parent(int v) {
        if (v == par[v])return v;
        return par[v] = parent(par[v]);
    }

    bool merge(int v, int u) {
        v = parent(v), u = parent(u);
        if (v == u)return false;
        if (sz[v] > sz[u])swap(v, u);
        sz[u] += sz[v];
        par[v] = u;
        return true;
    }

};

void solve() {
    int n;
    cin >> n;
    vector<ar(3) > s(n);
    vector<int> cords;
    for (int i = 0; i < n; i++) {
        cin >> s[i][0] >> s[i][1] >> s[i][2];
        cords.pb(s[i][0]);
        cords.pb(s[i][1]);
    }
    sort(all(cords));

    auto code = [&](int x) {
        return 1 + lower_bound(all(cords), x) - cords.begin();
    };

    for (int i = 0; i < n; i++) {
        s[i][0] = code(s[i][0]), s[i][1] = code(s[i][1]);
    }

    sort(all(s), [&](ar(3) i, ar(3) j) { return i[2] < j[2]; });

    vector<ar(3) > edges;

    auto tedge = [&](int i, int j) {
        if (i == -1 || j == -1)return;
        if (max(s[i][0], s[j][0]) <= min(s[i][1], s[j][1])) {
            int w = abs(s[i][2] - s[j][2]);
            edges.pb({i, j, w});
        }
    };

    segtree boss(2 * n + 5);
    for (int i = 0; i < n; i++) {
        auto [l, r, a] = s[i];
        int x = boss.get(l, l + 1), y = boss.get(r, r + 1);
        tedge(x, i);
        tedge(y, i);
        boss.upd(l, r + 1, i);
    }

    boss = segtree(2 * n + 5);
    for (int i = n - 1; i >= 0; i--) {
        auto [l, r, a] = s[i];
        int x = boss.get(l, l + 1), y = boss.get(r, r + 1);
        tedge(x, i);
        tedge(y, i);
        boss.upd(l, r + 1, i);
    }

    sort(all(edges), [&](ar(3) i, ar(3) j) { return i[2] < j[2]; });

    dsu suka(n + 5);
    ll ans = 0;
    int msedges = 0;
    for (auto [v, u, w]: edges) {
        if (suka.merge(v, u)) {
            msedges++;
            ans += (ll) w;
        }
    }
    if (msedges != n - 1)ans = -1;
    cout << ans << '\n';

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}