#include <bits/stdc++.h>
using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

const int MAXN = 500228;
const int LG = 20;

int p[MAXN];
int revp[MAXN];

int tin[MAXN];
int tout[MAXN];

int par[MAXN][LG];
int h[MAXN];

int get_par(int v, int x) {
    for (int i = LG -1 ; i >= 0; --i) {
        if (x & (1 << i)) {
            v = par[v][i];
        }
    }

    return v;
}

int lca(int u, int v) {
    int d = h[u] - h[v];
    if (d > 0) {
        u = get_par(u, d);
    } else {
        v = get_par(v, -d);
    }

    if (u == v) {
        return u;
    }

    for (int i = LG - 1; i >= 0; --i) {
        if (par[v][i] != par[u][i]) {
            v = par[v][i], u = par[u][i];
        }
    }

    return par[v][0];
}

bool is_par(int par, int ch) {
    return tin[par] <= tin[ch] && tout[ch] <= tout[par];
}

struct State {
    int a, b, l;

    State(int v = -1)
        : a(v), b(v), l(v)
    {
        
    }

    State(int a, int b, int l)
        : a(a), b(b), l(l)
    {
    }

    bool bad() const {
        return a == -1;
    }

    friend State operator + (const State& l, const State& r) {
        if (l.bad() || r.bad()) {
            return {};
        }

        int nl = lca(l.l, r.l);

        int deep = l.a;
        for (int x: {l.b, r.a, r.b}) {
            if (h[x] > h[deep]) {
                deep = x;
            }
        }

        if (deep == nl) {
            return { nl };
        }

        vector<int> bad;
        for (int x: {l.a, l.b, r.a, r.b}) {
            if (!is_par(x, deep)) {
                bad.push_back(x);
            }
        }

        if (bad.empty()) {
            return { deep, nl, nl };
        }

        int v = bad[0];
        for (int u: bad) {
            if (h[u] > h[v]) {
                v = u;
            }
        }

        if (lca(v, deep) != nl) {
            return {};
        }

        for (int u: bad) {
            if (!is_par(u, v)) {
                return {};
            }
        }

        return { deep, v, nl };
    }
};


State rmq[4 * MAXN];
int initid[MAXN];
vector<int> e[MAXN];

void updrmq(int v) {
    rmq[v] = rmq[v * 2] + rmq[v * 2 + 1];
}

void build(int v, int l, int r) {
    if (l + 1 == r) {
        initid[l] = v;
        rmq[v] = State{ revp[l] };
        return;
    }

    int md = (l + r) / 2;
    build(v * 2, l, md);
    build(v * 2 + 1, md, r);
    updrmq(v);
}

void modify(int x) {
    if (x == 0) {
        return;
    }

    int v = initid[x];
    rmq[v] = State{ revp[x] };
    while (v > 1) {
        updrmq(v /= 2);
    }
}

int dfst = 0;

void dfs(int x) {
    tin[x] = dfst++;
    for (int v: e[x]) {
        dfs(v);
    }

    tout[x] = dfst++;
}

int main() {
#ifdef BZ
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        revp[p[i]] = i;
    }

    fill(par[1], par[1] + LG, 1);

    for (int i = 2; i <= n; ++i) {
        int x;
        cin >> x;
        par[i][0] = x;
        e[x].push_back(i);
        h[i] = h[x] + 1;
        for (int j = 0; j + 1 < LG; ++j) {
            par[i][j + 1] = par[par[i][j]][j];
        }
    }

    bool np = e[1].size() > 2;
    for (int i = 2; i <= n; ++i) {
        np |= e[i].size() > 1;
    }

    dfs(1);

    build(1, 1, n);

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int t;
        cin >> t;
        if (t == 1) {
            int v, u;
            cin >> v >> u;
            swap(p[v], p[u]);
            revp[p[v]] = v;
            revp[p[u]] = u;
            modify(p[v]);
            modify(p[u]);
        } else {
            if (!np) {
                cout << n << "\n";
                continue;
            }

            State s{ revp[0] };

            int l = 1, r = n, v = 1;
            while (l + 1 != r) {
                int m = (l + r) / 2;
                v *= 2;
                State ns = s + rmq[v];
                if (ns.bad()) {
                    r = m;
                } else {
                    l = m;
                    ++v;
                    s = ns;
                }
            }

            cout << l << "\n";
        }
    }
}