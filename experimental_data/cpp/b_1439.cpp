#include <bits/stdc++.h>
#ifdef __LOCAL__
  #include <debug_local.h>
#endif
using namespace std;
const int mxN = 1e5 + 5;
int deg[mxN], mark[mxN];
vector<int> ad[mxN];
void testCase() {
  int n, m, k;
  cin >> n >> m >> k;
  while (m--) {
    int u, v;
    cin >> u >> v;
    deg[u]++, deg[v]++;
    ad[u].push_back(v);
    ad[v].push_back(u);
  }
  auto clear = [&]() {
    for (int i = 0; i <= n; i++) {
      deg[i] = mark[i] = 0;
      ad[i].clear();
    }
    return 0;
  };
  if (k > 500) {
    cout << "-1\n";
    clear();
    return;
  }
  for (int i = 1; i <= n; i++) sort(ad[i].begin(), ad[i].end());
  auto has = [&](int u, int v) {
    auto it = lower_bound(ad[u].begin(), ad[u].end(), v);
    return (it != ad[u].end() && *it == v);
  };
  set<pair<int, int>> s;
  for (int i = 1; i <= n; i++) s.insert({deg[i], i});
  while (!s.empty()) {
    auto [dd, u] = *s.begin();
    if (dd < k - 1) {
      s.erase(s.begin());
      for (int v : ad[u]) {
        if (!mark[v]) {
          s.erase({deg[v], v});
          deg[v]--;
          s.insert({deg[v], v});
        }
      }
      mark[u] = 1;
      continue;
    }
    if (dd >= k) {
      cout << "1 " << s.size() << "\n";
      for (auto [_, i] : s) cout << i << " ";
      cout << "\n";
      clear();
      return;
    }
    vector<int> a = {u};
    for (int v : ad[u]) if (!mark[v]) a.push_back(v);
    bool ok = true;
    for (int i = 0; i < k; i++) {
      for (int j = 0; j < i; j++) {
        ok &= has(a[i], a[j]);
      }
    }
    if (ok) {
      cout << "2\n";
      for (int i : a) cout << i << " ";
      cout << "\n";
      clear();
      return;
    }
    s.erase(s.begin());
    for (int v : ad[u]) {
      if (!mark[v]) {
        s.erase({deg[v], v});
        deg[v]--;
        s.insert({deg[v], v});
      }
    }
    mark[u] = 1;
  }
  cout << "-1\n";
  clear();
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    testCase();
  }
}