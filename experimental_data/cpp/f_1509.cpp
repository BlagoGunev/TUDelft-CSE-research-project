#include <bits/stdc++.h>



using namespace std;

typedef long long ll;

typedef pair<int, int> PII;



struct DSU {

    vector<int> p, sz;

    DSU(int n) : p(n), sz(n, 1) { iota(p.begin(), p.end(), 0); }



    int leader(int x) {

        if (x != p[x]) p[x] = leader(p[x]);

        return p[x];

    }



    bool merge(int x, int y) {

        x = leader(x), y = leader(y);

        if (x == y) return false;

        sz[x] += sz[y];

        p[y] = x;

        return true;

    }



    bool same(int x, int y) {

        return leader(x) == leader(y);

    }



    int size(int x) { return sz[leader(x)]; }

};



int main() {

    ios::sync_with_stdio(false);

    cin.tie(nullptr);



    int n, m;

    cin >> n >> m;

    ll rem = 1ll * n * (n - 1) / 2 - m;

    vector<array<int, 3>> e(m);

    vector<vector<int>> adj(n);

    int x = 0;

    for (int i = 0; i < m; i++) {

        int u, v, w;

        cin >> u >> v >> w;

        u--, v--;

        e[i] = {u, v, w};

        adj[u].push_back(v);

        adj[v].push_back(u);

        x ^= w;

    }

    DSU dsu(n);

    int mn = 0;

    for (int i = 0; i < n; i++) {

        if (adj[mn].size() > adj[i].size()) {

            mn = i;

        }

    }

    vector<bool> vis(n);

    for (int v : adj[mn]) {

        vis[v] = true;

    }

    for (int i = 0; i < n; i++) {

        if (vis[i]) continue;

        if (dsu.merge(mn, i)) rem--;

    }

    for (int i = 0; i < n; i++) {

        if (!vis[i]) continue;

        vector<bool> con(n);

        for (int v : adj[i]) {

            con[v] = true;

        }

        for (int j = 0; j < n; j++) {

            if (con[j] || j == i) continue;

            if (dsu.merge(i, j)) rem--;

        }

    }

    ll ans = 0;

    sort(e.begin(), e.end(), [&](array<int, 3> a, array<int, 3> b){

        return a[2] < b[2];

    });

    vector<int> type(m);

    for (int i = 0; i < m; i++) {

        auto [u, v, w] = e[i];

        if (dsu.merge(u, v)) {

            type[i] = 1;

            ans += w;

        }

    }

    DSU dsu1(n);

    for (int i = 0; i < m; i++) {

        auto [u, v, w] = e[i];

        if (!dsu1.merge(u, v)) continue;

        if (type[i]) continue;

        x = min(x, w);

    }

    if (rem == 0) {

        ans += x;

    }

    cout << ans << '\n';

    return 0;

}