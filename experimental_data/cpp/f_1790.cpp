#include <bits/stdc++.h>

#define rep(a, b) for (num a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define many int t; cin >> t; while (t--)
#define yesno cout << (solve() ? "YES" : "NO") << '\n'
#define print cout << solve() << '\n'
#define call solve()

using namespace std;

using num = long long int;
using seq = vector<num>;
using par = pair<num,num>;
using Graph = vector<vector<num>>;
using WGraph = vector<vector<par>>;
template<typename T, typename U> istream& operator>>(istream& is, pair<T,U>& p) { return is >> p.first >> p.second; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& e : v) is >> e; return is; }

void solve() {
    num n, r;
    cin >> n >> r;
    seq ops(n-1);
    cin >> ops;
    for (auto& x:ops)
        --x;
    --r;
    Graph adj(n);
    rep(i, n-1) {
        num u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> colored(n, false);
    colored[r] = true;
    num dist = n;
    seq dp(n, numeric_limits<int>::max()), parent(n, -1);
    function<void(num)> dfs = [&](num node) {
        for (auto next : adj[node])
            if (next != parent[node])
                parent[next] = node, dfs(next);
    };
    dfs(0);
    r = parent[r];
    for (num i = 1; r != -1; i++, r = parent[r])
        dp[r] = i;
    for (auto x : ops) {
        dist = min(dist, dp[x]);
        colored[x] = true;
        x = parent[x];
        for (num i = 1; x != -1 && i < dist; i++, x = parent[x]) {
            dist = min(dist, dp[x] + i);
            dp[x] = min(dp[x], i);
            if (colored[x])
                dist = min(dist, dp[x]);
        }
        cout << dist << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    many call;
    return 0;
}