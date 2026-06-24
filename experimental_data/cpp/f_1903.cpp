#include <bits/stdc++.h>
using namespace std;

struct graph {

    vector<vector<int>> adj, adj2;

    graph(int n) {
        adj = vector<vector<int>>(n);
        adj2 = vector<vector<int>>(n);
    }

    void add(int from, int to) {
        assert(0 <= from && from < (int) adj.size());
        assert(0 <= to && to < (int) adj.size());
        if (from != to) {
            adj[from].push_back(to);
            adj2[to].push_back(from);
        }
    }

    vector<int> scc() const {
        int n = adj.size();
        vector<bool> used(n);
        vector<int> order;
        function<void(int)> dfs1 = [&](int v) {
            used[v] = true;
            for (int u : adj[v]) {
                if (!used[u]) {
                    dfs1(u);
                }
            }
            order.push_back(v);
        };
        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                dfs1(i);
            }
        }
        
        vector<int> comp(n, -1);
        function<void(int,int)> dfs2 = [&](int v, int cl) {
            comp[v] = cl;
            for (int u : adj2[v]) {
                if (comp[u] == -1) {
                    dfs2(u, cl);
                }
            }
        };
        for (int i = n - 1, j = 0; i >= 0; i--) {
            int v = order[i];
            if (comp[v] == -1) {
                dfs2(v, j++);
            }
        }
        return comp;
    }
};

int n;

void get(int x, int tL, int tR, int L, int R, const function<void(int)> &f) {
    if (L <= tL && tR <= R) {
        f(x);
    } else if (tR < L || R < tL) {
    } else {
        int mid = (tL + tR) / 2;
        get(x * 2, tL, mid, L, R, f);
        get(x * 2 + 1, mid + 1, tR, L, R, f);
    }
}

void get(int L, int R, const function<void(int)> &f) {
    assert(L <= R);
    get(1, 0, n - 1, L, R, f);
}

const int NAX = 100'005;
int cid[NAX];

void add(int x, int L, int R, const function<void(int,int)> &f) {
    if (L != R) {
        f(x * 2, x);
        f(x * 2 + 1, x);
        int mid = (L + R) / 2;
        add(x * 2, L, mid, f);
        add(x * 2 + 1, mid + 1, R, f);
    } else {
        cid[L] = x;
    }
}

void add_edges(const function<void(int,int)> &f) {
    add(1, 0, n - 1, f);
}

void foo() {
    int m;
    cin >> n >> m;
    vector<pair<int,int>> edges(m);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        edges[i] = make_pair(x, y);
    }
    int b = 1;
    while (b < n) b *= 2;
    const int b2 = b * 2;
    int lo = 2, hi = n;
    while (lo <= hi) {
        const int k = (lo + hi) / 2;
        graph g(b * 4);
        function<void(int,int)> fc = [&](int x, int p) {
            g.add(x, p);
            g.add(b2 + p, b2 + x);
        };
        add_edges(fc);
        for (const auto &[x, y] : edges) {
            g.add(b2 + cid[x], cid[y]);
            g.add(b2 + cid[y], cid[x]);
        }
        for (int i = 0; i < n; i++) {
            function<void(int)> f = [&](int x) {
                g.add(cid[i], b2 + x);
            };
            get(i + 1, i + k - 1, f);
            get(i - k + 1, i - 1, f);
        }
        vector<int> scc = g.scc();
        bool ok = true;
        for (int i = 0; i < b2; i++) {
            if (scc[i] == scc[b2 + i]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            lo = k + 1;
        } else {
            hi = k - 1;
        }
    }
    cout << lo - 1 << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cases;
    cin >> cases;
    for (int t = 1; t <= cases; t++) {
        foo();
    }
}