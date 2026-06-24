#ifndef disastah
#pragma GCC optimize("Ofast,unroll-loops")
#endif
#include "bits/stdc++.h"
std::mt19937 rnd(503);

using namespace std;
using ll = long long;
using ld = long double;

const int N = 2e5 + 5;
const int B = 420;
const int INF = 2e9 + 7;
const ll LL_INF = 4e18 + 7;

int n;
int a[N];
vector<int> g[N];

int tin[N], tout[N], timer = 0, h[N];
int bup[N][20], s[N][20][20];

void dfs(int v, int p = 0) {
    bup[v][0] = p;
    tin[v] = timer++;
    for (auto u : g[v]) {
        if (u != p) {
            h[u] = h[v] + 1;
            dfs(u, v);
        }
    }
    tout[v] = timer++;
}

void add(int* ss, int x) {
    for (int b = 19; b >= 0; --b) {
        if ((x >> b) & 1) {
            if (ss[b] != 0) {
                x ^= ss[b];
            } else {
                ss[b] = x;
                break;
            }
        }
    }
}

void merge(int* s, int* s1, int* s2) {
    for (int b = 0; b < 20; ++b) {
        s[b] = s1[b];
    }
    for (int b = 19; b >= 0; --b) {
        if (s2[b] != 0) {
            add(s, s2[b]);
        }
    }
}

void merge2(int* s, int* s1) {
    for (int b = 19; b >= 0; --b) {
        if (s1[b] != 0) {
            add(s, s1[b]);
        }
    }
}

void build() {
    for (int v = 0; v < n; ++v) {
        add(s[v][0], a[v]);
    }
    for (int k = 1; k < 20; ++k) {
        for (int v = 0; v < n; ++v) {
            bup[v][k] = bup[bup[v][k - 1]][k - 1];
            merge(s[v][k], s[v][k - 1], s[bup[v][k - 1]][k - 1]);
        }
    }
}

int lca(int a, int b) {
    int d = 19;
    while (tin[a] > tin[b] || tout[a] < tout[b]) {
        while (d && tin[bup[a][d]] <= tin[b] && tout[bup[a][d]] >= tout[b]) {
            --d;
        }
        a = bup[a][d];
    }
    return a;
}

int ss[20];

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0);
    build();
    int q;
    cin >> q;
    while (q--) {
        int x, y, k;
        cin >> x >> y >> k;
        --x, --y;
        int z = lca(x, y);
        fill(ss, ss + 20, 0);
        int hzx = h[x] - h[z], hzy = h[y] - h[z];
        for (int b = 0; b < 20; ++b) {
            if ((hzx >> b) & 1) {
                merge2(ss, s[x][b]);
                x = bup[x][b];
            }
        }
        for (int b = 0; b < 20; ++b) {
            if ((hzy >> b) & 1) {
                merge2(ss, s[y][b]);
                y = bup[y][b];
            }
        }
        add(ss, a[z]);
        for (int b = 19; b >= 0; --b) {
            if ((k >> b) & 1) {
                k ^= ss[b];
            }
        }
        cout << (k == 0 ? "YES\n" : "NO\n");
    }
}

void clean() {
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
        clean();
        cout << "\n";
    }
}