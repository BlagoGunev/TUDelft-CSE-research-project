/**
 * @author nhuang685
 * @date 2023-01-26 15:14:35
 */
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n, k;
  cin >> n >> k;

  vector<vector<int>> adj(n);
  vector<int> p(n, -1);
  for (int i = 1; i < n; ++i) {
    cin >> p[i];
    p[i]--;
    adj[p[i]].push_back(i);
  }

  auto good = [&](int md) -> bool {
    int ans = 0;
    auto dfs = [&](auto &self, int node) -> int {
      int d = 1;
      for (int i : adj[node]) {
        d = max(d, self(self, i) + 1);
      }
      if (d == md && node != 0 && p[node] != 0) {
        ans++;
        return 0;
      }
      return d;
    };
    dfs(dfs, 0);
    return (ans <= k);
  };

  int l = 1, r = n - 1;
  while (l < r) {
    int mid = (l + r) / 2;
    if (good(mid))
      r = mid;
    else
      l = mid + 1;
  }
  cout << l << '\n';
}

int main() {
  ios::sync_with_stdio(false);

#ifdef LOCAL
  // freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("log.txt", "w", stderr);
#else
  cin.tie(nullptr);
#endif

  int t;
  cin >> t;
  while (t--) solve();
}