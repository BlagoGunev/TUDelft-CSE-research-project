//#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
// Common file
#include <ext/pb_ds/assoc_container.hpp>
// Including tree_order_statistics_node_update
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using dd = tree<int, null_type, less_equal<>, rb_tree_tag, tree_order_statistics_node_update>;
//#pragma GCC target("avx2")

using ll = long long;
const ll nMax = 2e5 + 228, mod = 1e9 + 7;
using num = ll;
#define int long long
int ans[nMax];
vector<pair<vector<int>, int>> queries[nMax];
vector<int> g[nMax];
int h[nMax], tin[nMax], tout[nMax], timer = 0;
int lca[nMax][20];

void dfs1(int v, int p) {
    h[v] = h[p] + 1;
    lca[v][0] = p;
    for (int i = 1; i < 20; i++)
        lca[v][i] = lca[lca[v][i - 1]][i - 1];
    tin[v] = timer++;
    for (auto u: g[v]) {
        if (u == p)continue;
        dfs1(u, v);
    }
    tout[v] = timer;
}

struct segTree {
    struct node {
        int val = 0;
        int push = 0;
    };

    vector<node> t = vector<node>(nMax * 4);

    void push(int v) {
        t[v * 2].val += t[v].push;
        t[v * 2 + 1].val += t[v].push;
        t[v * 2].push += t[v].push;
        t[v * 2 + 1].push += t[v].push;
        t[v].push = 0;
    }

    void add(int v, int l, int r, int ql, int qr, int d) {
        if (ql >= r || qr <= l)return;
        if (ql <= l && r <= qr) {
            t[v].push += d;
            t[v].val += d;
            return;
        }
        push(v);
        int m = (l + r) / 2;
        add(v * 2, l, m, ql, qr, d);
        add(v * 2 + 1, m, r, ql, qr, d);
        t[v].val = max(t[v * 2].val, t[v * 2 + 1].val);
    }

    int get(int v, int l, int r, int ql, int qr) {
        if (ql >= r || qr <= l)return 0;
        if (ql <= l && r <= qr) {
            return t[v].val;
        }
        push(v);
        int m = (l + r) / 2;
        return max(get(v * 2, l, m, ql, qr), get(v * 2 + 1, m, r, ql, qr));
    }
} st;

int up(int v, int k) {
    for (int i = 0; i < 20; i++) {
        if (k & (1 << i))
            v = lca[v][i];
    }
    return v;
}

void dfs2(int v, int p) {
    st.add(1, 0, nMax, 0, timer, +1);
    st.add(1, 0, nMax, tin[v], tout[v], -2);
    //st.get(1,0,nMax,tin[3],tin[3]+1);
    for (auto u: g[v]) {
        if (u == p)continue;
        dfs2(u, v);
    }
    for (auto [as,id]: queries[v]) {
        for (auto a: as) {
            if (tin[a] <= tin[v] && tout[a] >= tout[v]) {
                //st.get(1, 0, nMax, 4, 4 + 1);
                st.add(1, 0, nMax, 0, nMax, -1e10);
                auto preA = up(v, h[v] - h[a] - 1);
                st.add(1, 0, nMax, tin[preA], tout[preA], +1e10);
            }
            else {
                st.add(1, 0, nMax, tin[a], tout[a], -1e10);
            }
        }
        ans[id] = st.get(1, 0, nMax, 0, nMax);
        //if(v==0)ans[id]++;
        for (auto a: as) {
            if (tin[a] <= tin[v] && tout[a] >= tout[v]) {
                st.add(1, 0, nMax, 0, nMax, +1e10);
                auto preA = up(v, h[v] - h[a] - 1);
                st.add(1, 0, nMax, tin[preA], tout[preA], -1e10);
            }
            else {
                st.add(1, 0, nMax, tin[a], tout[a], +1e10);
            }
        }
    }
    st.add(1, 0, nMax, 0, timer, -1);
    st.add(1, 0, nMax, tin[v], tout[v], +2);
}

void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 0; i < q; i++) {
        int x;
        int k;
        cin >> x >> k;
        x--;
        vector<int> a(k);
        for (auto&o: a) {
            cin >> o;
            o--;
        }
        queries[x].push_back({a, i});
    }
    dfs1(0, 0);
    for (int i = 0; i <= n; i++)st.add(1, 0, nMax, tin[i], tin[i] + 1, h[i]);
    dfs2(0, 0);
    for (int i = 0; i < q; i++) {
        cout << ans[i] << '\n';
    }
}

signed main() {
    //#define VANT
    //#define FILE_TEST
#ifdef VANT
#ifdef FILE_TEST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
#else
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#endif
    int q = 1;

    //cin >> q;
    cout << fixed << setprecision(14);
    while (q--) {
        solve();
        // cout << endl;
    }
    return 0;
}