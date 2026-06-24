#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back
#define fo(i, n) for(ll i = 1; i <= n; ++i)

const int N = 100500;
const int mod = 1e9 + 7;
const int INF = 2e9;

int n, q;
int u, v;
int k, m , r;
int a[N];
vector<int> g[N];
vector<int> vertexes;
int done[N];
int Up[N];
int dp[N][301];
vector<int> order;
ll f[N], rf[N];
inline ll bin(ll x, ll k) {
    ll res = 1;
    while(k) {
        if(k & 1) res = res * x % mod;
        x = x * x % mod;
        k >>= 1;
    }
    return res;
}
inline void add(int &x, int y) {
    x += y;
    if(x >= mod) x -= mod;
}

inline void dfs(int v, int p = 0) {
    if(done[v]) {
        Up[v] = vertexes.size();
        vertexes.pb(v);
        order.pb(v);
    }
    for(int to : g[v])
        if(to != p) dfs(to, v);
    if(done[v]) vertexes.pop_back();
}
int tin[N], tout[N] = {mod}, timer;
int up[N][21];
int h[N];

inline int upper(int a, int b) {
    return tin[a] <= tin[b] && tout[b] <= tout[a];
}

inline int lca(int a, int b) {
    if(upper(a, b)) return a;
    if(upper(b, a)) return b;
    for(int i = 20; i >= 0; --i) {
        if(!upper(up[a][i], b)) a = up[a][i];
    }
    return up[a][0];
}

inline void dfs_start(int v, int p = 0) {
    tin[v] = ++timer;
    up[v][0] = p;
    h[v] = h[p] + 1;
    for(int i = 1; i <= 20; ++i)
        up[v][i] = up[up[v][i-1]][i-1];
    for(int to : g[v]) {
        if(to == p) continue;
        dfs_start(to, v);
    }
    tout[v] = ++timer;
}

inline int dist(int a, int b) {
    int c = lca(a,b);
    return h[a] + h[b] - 2 * h[c];
}
int d[N];

inline bool cmp(int i, int j) {
    return d[i] < d[j];
}

inline void solve() {
    cin >> k >> m >> r;
    fo(i, k) cin >> a[i];
    if(k >= 200) {
        fo(i, k) done[a[i]] = 1;
        vertexes.clear();
        order.clear();
        dfs(r);
        fo(i, k) done[a[i]] = 0;
    } else {
        for(int i = 1; i <= k; ++i)
            d[a[i]] = dist(a[i], r);
        sort(a + 1, a + k + 1, cmp);
        order.clear();
        for(int i = 1; i <= k; ++i) {
            order.pb(a[i]);
            Up[a[i]] = 0;
            for(int j = 1; j < i; ++j) {
                if(dist(a[i], a[j]) + d[a[j]] == d[a[i]])
                    Up[a[i]]++;
            }
        }
    }
    for(int i = 0; i <= k; ++i)
        for(int j = 0; j <= m; ++j)
            dp[i][j] = 0;
    dp[0][0] = 1;
    for (int i = 1; i <= k; ++i) {
        int v = order[i - 1];
        for(int j = 0; j <= m; ++j) {
            if(j + 1 <= m)
                add(dp[i][j + 1], dp[i-1][j]);
            int g = max(0, j - Up[v]);
            if(j) add(dp[i][j], 1ll * g * dp[i-1][j] % mod);
        }
    }
    int ans = 0;
    for(int i = 1; i <= m; ++i) {
        add(ans, dp[k][i]);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    f[0] = rf[0] = 1;
    fo(i, n) f[i] = f[i-1] * i % mod;
    rf[n] = bin(f[n], mod - 2);
    for(int i = n-1; i >= 1; --i) rf[i] =rf[i+1] * (i +1) % mod;
    fo(i, n - 1) {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs_start(1);
    fo(i, q) solve();
    return 0;
}