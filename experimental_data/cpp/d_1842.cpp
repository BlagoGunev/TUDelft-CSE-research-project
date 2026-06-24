#include <bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 1000;

struct edge{
    int u, w;
};

int used[maxn];

vector < vector <edge> > g(maxn, vector <edge> ());

const int inf = 1e18;

void dfs(int v) {
    used[v] = 1;
    for (auto [u, w] : g[v]) {
        if (!used[u]) dfs(u);
    }
}

void solve() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int v, u, w; cin >> v >> u >> w;
        v--;  u--;
        g[v].push_back({u, w});
        g[u].push_back({v, w});
    }
    dfs(0);
    if (!used[n - 1]) {
        cout << "inf\n";
        return;
    }
    int t = 0;
    set <pair <int, int> > q;
    vector <int> mi(n, inf);
    q.insert({0, n - 1});
    vector < vector <int> > ans;
    vector <int> d;
    vector <int> use(n, 1);
    while (!q.empty()) {
        auto [w, v] = *q.begin();
        q.erase(q.begin());
        if (w - t > 0) {
            ans.push_back(use);
            d.push_back(w - t);
        }
        t = w;
        use[v] = 0;
        if (v == 0) break;
        for (auto [u, ww] : g[v]) {
            if (use[u] && mi[u] > ww + t) {
                q.erase({mi[u], u});
                mi[u] = ww + t;
                q.insert({mi[u], u});
            }
        }
    }
    cout << t << " ";
    int k = ans.size();
    cout << k << "\n";
    for (int i = 0; i < k; ++i) {
        for (auto el : ans[i]) {
            cout << el;
        }
        cout << ' ' << d[i] << "\n";
    }
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);
    }
    int t; t = 1;
    while (t--) {
        solve();
    }
    return 0;
}