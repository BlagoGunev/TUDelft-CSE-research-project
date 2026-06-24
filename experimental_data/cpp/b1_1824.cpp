#include<bits/stdc++.h>
#define int long long
#define sz(a) (int)a.size()

using namespace std;

const int M = 1e9 + 7;

int powa(int a, int n) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        int x = powa(a, n / 2);
        return (x * x) % M;
    }
    return (a * powa(a, n - 1)) % M;
}

int divv(int a, int b) {
    return (a * powa(b, M - 2)) % M;
}

vector<vector<int>> g;
vector<int> sz;
int vs = 0, n;

void dfs(int v, int p) {
    for (int i : g[v]) {
        if (i == p) continue;
        dfs(i, v);
        sz[v] += sz[i];
    }
}

void dfs2(int v, int p) {
    if (v != 0) {
        vs += sz[v] * (n - sz[v]);
        vs %= M;
    }
    for (int i : g[v]) {
        if (i == p) continue;
        dfs2(i, v);
    }
}

void solve() {
    int k;
    cin >> n >> k;
    g.resize(n);
    sz.resize(n, 1);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    if (k % 2 == 1) {
        cout << 1 << '\n';
        return;
    }
    dfs(0, 0);
    dfs2(0, 0);
    int pths = n * (n - 1) / 2;
    pths %= M;
    vs += pths;
    vs %= M;
    cout << divv(vs, pths) << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}