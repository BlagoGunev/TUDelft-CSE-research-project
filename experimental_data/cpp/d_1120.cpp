#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO
#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)

#ifdef FASTIO
#define scanf abacaba
#define printf abacaba
#endif

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

const int MX = 200 * 1000 + 7;
int timer = 0;

struct Edge {
    int u, v;
    int w;
    int id;

    Edge(int u, int v, int w, int id)
        : u(u)
        , v(v)
        , w(w)
        , id(id)
    {
    }
};

vector<int> g[MX];
int w[MX];

vector<Edge> e;
void dfs(int v, int p) {
    for (int i = 0; i < (int)g[v].size(); i++) {
        if (g[v][i] == p) {
            g[v].erase(g[v].begin() + i);
        }
    }

    int l = timer;
    if (g[v].empty()) {
        timer++;
    }
    for (int to : g[v]) {
        dfs(to, v);
    }
    int r = timer;
    e.emplace_back(l, r, w[v], v);
}

int p[MX], r[MX];

int getp(int v) {
    if (p[v] == -1) {
        return v;
    }
    p[v] = getp(p[v]);
    return p[v];
}

bool join(int u, int v) {
    u = getp(u);
    v = getp(v);
    if (u == v) {
        return false;
    }
    if (r[u] < r[v]) {
        swap(u, v);
    }
    r[u] += r[v];
    p[v] = u;
    return true;
}

int main() {
#ifdef FASTIO
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, 1);
    sort(e.begin(), e.end(), [&](Edge a, Edge b) {
        return a.w < b.w;
    });
    int m = timer;
    for (int i = 0; i <= m; i++) {
        p[i] = -1;
        r[i] = 1;
    }

    vector<int> can;
    ll ans = 0;
    {
        int l = 0;
        while (l < (int)e.size()) {
            int r = l;
            while (r < (int)e.size() && e[r].w == e[l].w) {
                r++;
            }
            for (int i = l; i < r; i++) {
                if (getp(e[i].u) != getp(e[i].v)) {
                    can.push_back(e[i].id);
                }
            }
            for (int i = l; i < r; i++) {
                if (join(e[i].u, e[i].v)) {
                    ans += e[i].w;
                }
            }
            l = r;
        }
    }

    sort(can.begin(), can.end());
    cout << ans << " " << can.size() << "\n";
    for (int x : can) {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}