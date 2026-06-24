#include <bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, c;
    cin >> n >> c;
    vector<vector<int>> V(n);
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    for (int i = 1; i < n; ++i) {
      int u, v;
      cin >> u >> v;
      --u;
      --v;
      V[u].push_back(v);
      V[v].push_back(u);
    }
    vector<vector<long long>> dp(n, vector<long long>(2));
    auto dfs = [&](int u, int fa, auto &&dfs) -> void {
      dp[u][1] = a[u];
      for (int v : V[u])
        if (v != fa) {
          dfs(v, u, dfs);
          dp[u][1] += max(dp[v][0], dp[v][1] - c - c);
          dp[u][0] += max(dp[v][0], dp[v][1]);
        }
    };
    dfs(0, -1, dfs);
    cout << max(dp[0][0], dp[0][1]) << "\n";
  }
  return 0;
}