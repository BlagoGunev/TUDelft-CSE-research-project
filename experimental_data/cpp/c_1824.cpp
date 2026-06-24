#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 300500, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

int sum(int a, int b) {
    a += b;
    if (a >= mod)
        a -= mod;
    return a;
}

int sub(int a, int b) {
    a -= b;
    if (a < 0)
        a += mod;
    return a;
}

int mult(int a, int b) {
    return 1ll * a * b % mod;
}

int bp(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1)
            res = mult(res, a);
        a = mult(a, a);
        b >>= 1;
    }
    return res;
}

int inv(int x) {
    return bp(x, mod - 2);
}

int f[N], rf[N];

int C(int k, int n) {
    if (0 <= k && k <= n)
        return mult(f[n], mult(rf[k], rf[n - k]));
    return 0;
}

int n, a[N];
vector<int> g[N];

set<int> st[N], ST[N];
int dp[N];

int p[N], pn;

void kek(set<int> &a, set<int> &b) {
    if (a.size() < b.size())
        a.swap(b);
    for (auto x: b)
        a.insert(x);
}


void dfs(int v, int pr) {
    bool is_leaf = true;
    for (auto to: g[v]) {
        if (to == pr)
            continue;
        a[to] ^= a[v];
        dfs(to, v);
        is_leaf = false;
    }
    if (is_leaf) {
        st[v].insert(a[v]);
        dp[v] = 0;
    } else {
        pii mx = {-1, -1};
        for (auto to: g[v]) {
            if (to == pr)
                continue;
            mx = max(mx, {st[to].size(), to});
        }
        int u = mx.s;
        dp[v] += dp[u] + 1;
        set<int> inter;
        for (auto to: g[v]) {
            if (to == pr)
                continue;
            if (to == u)
                continue;
            dp[v] += dp[to] + 1;
            for (auto x: st[to]) {
                if (st[u].find(x) == st[u].end())
                    continue;
                inter.insert(x);
            }
        }
        {
            int mx = 1;
            map<int, int> cnt;
            for (auto x: inter){
                cnt[x]++;
                mx = max(mx, cnt[x]);
            }
            for (auto to: g[v]) {
                if (to == pr)
                    continue;
                if (to == u)
                    continue;
                for (auto x: st[to]) {
                    cnt[x]++;
                    mx = max(mx, cnt[x]);
                }
            }
            dp[v] -= mx;
            if (mx == 1) {
                for (auto to: g[v]) {
                    if (to == pr)
                        continue;
                    kek(st[v], st[to]);
                }
            } else {
                for (auto it: cnt)
                    if (it.s == mx)
                        st[v].insert(it.f);
            }
        }
    }
//    cerr << v << " " << dp[v] << ": " << endl;
//    for(auto x : st[v])
//        cerr << x << " ";
//    cerr << endl;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        g[v].pb(u);
        g[u].pb(v);
    }
    dfs(0, -1);
    int ans = dp[0];
    if(st[0].find(0) == st[0].end())
        ans++;
    cout << ans << "\n";
}

int main() {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    for (int i = 1; i <= t; i++) {
//        cout << "Case #" << i << endl;
        solve();
    }
}