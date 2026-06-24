#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

void solve() {
  int n, x;
  cin >> n >> x;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];

  vector<vector<int>> g(n + 1);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector<int> fa(n + 1);
  auto dfs = [&](auto &&self, int now) -> void {
    for (auto &u : g[now]) {
      if (u == fa[now]) continue;
      fa[u] = now;
      self(self, u);
    }
  };
  dfs(dfs, x);

  const ll inf = 1e18;
  ll ans = inf;
  for (int i = 0; i < n; i++) {
    auto check = [&](int mid) {
      vector<int> du(n + 1);
      for (int i = 1; i <= n; i++) du[fa[i]]++;

      vector<ll> b(n + 1);
      queue<int> q;
      for (int i = 1; i <= n; i++)
        if (du[i] == 0) q.push(i);

      while (q.front() != 0) {
        int now = q.front();
        q.pop();

        b[now] += mid + (now <= i);
        b[now] -= a[now];
        if (b[now] > 0) {
          b[now] = -(b[now] % 2);
        }

        b[fa[now]] += b[now];
        du[fa[now]]--;
        if (du[fa[now]] == 0) q.push(fa[now]);
      }

      return b[0] >= 0 && b[0] % 2 == 0;
    };

    int l, r;
    l = 1, r = 2e9 + 9;
    while (l < r) {
      int mid = l + r >> 1;
      if (mid % 2 == 0) mid--;
      if (check(mid)) {
        r = mid;
      } else {
        l = mid + 2;
      }
    }
    ans = min(ans, 1ll * l * n + i);

    l = 0, r = 2e9 + 10;
    while (l < r) {
      int mid = l + r >> 1;
      if (mid % 2 == 1) mid--;
      if (check(mid)) {
        r = mid;
      } else {
        l = mid + 2;
      }
    }
    ans = min(ans, 1ll * l * n + i);
  }
  cout << ans << "\n";
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(10);

  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}