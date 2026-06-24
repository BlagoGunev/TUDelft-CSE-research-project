#include <bits/stdc++.h>
#ifdef __LOCAL__
  #include <debug_local.h>
#endif
using namespace std;
const int mxN = 5e5 + 5;
vector<int> ad[mxN];
bool ok;
pair<int, int> par[mxN];
int sz[mxN];
bool bipartite[mxN], bp[mxN];
vector<tuple<int, int, int, int, bool>> updates;
pair<int, int> find(int u) {
  if (u == par[u].first) return {u, 0};
  auto x = find(par[u].first);
  x.second ^= par[u].second;
  return x;
}
void unite(int u, int v) {
  auto [a, b] = find(u);
  auto [c, d] = find(v);
  u = a, v = c;
  if (u == v) {
    if (b == d) {
      updates.push_back({u, v, b, sz[v], bipartite[v]});
      bipartite[v] = false;
      return;
    }
    updates.push_back({u, v, b, sz[v], bipartite[v]});
    return;
  }
  if (sz[u] > sz[v]) swap(u, v);
  updates.push_back({u, v, b, sz[v], bipartite[v]});
  par[u].first = v;
  par[u].second = b ^ d ^ 1;
  bipartite[v] &= bipartite[u];
  sz[v] += sz[u];
}
void rollback() {
  auto [u, v, b, s, f] = updates.back();
  par[u] = {u, b};
  sz[v] = s;
  bipartite[v] = f;
  updates.pop_back();
}
void testCase() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> c(n + 1);
  vector<int> l[k + 1];
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
    l[c[i]].push_back(i);
  }
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    ad[u].push_back(v);
    ad[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    par[i] = {i, 0};
    sz[i] = 1;
    bipartite[i] = true;
  }
  long long ans = 1LL * k * (k - 1) / 2;
  set<int> s;
  for (int i = 1; i <= k; i++) {
    bp[i] = true;
    for (int u : l[i]) {
      for (int v : ad[u]) {
        if (c[v] == i) {
          unite(u, v);
          bp[i] &= bipartite[find(u).first];
        }
      }
    }
    if (!bp[i]) s.insert(i);
  }
  long long total = 0;
  for (int i = 1; i <= k; i++) {
    if (bp[i]) continue;
    for (int u : l[i]) {
      for (int v : ad[u]) {
        if (s.find(c[v]) != s.end()) s.erase(c[v]);
      }
    }
    if (s.find(i) != s.end()) s.erase(i);
    total += s.size();
    for (int u : l[i]) {
      for (int v : ad[u]) {
        if (!bp[c[v]]) s.insert(c[v]);
      }
    }
    s.insert(i);
  }
  ans -= total / 2;
  total = 0;
  for (int i = 1; i <= k; i++) {
    if (!bp[i]) continue;
    for (int u : l[i]) {
      for (int v : ad[u]) {
        if (s.find(c[v]) != s.end()) s.erase(c[v]);
      }
    }
    total += s.size();
    for (int u : l[i]) {
      for (int v : ad[u]) {
        if (!bp[c[v]]) s.insert(c[v]);
      }
    }
  }
  ans -= total;
  vector<pair<int, int>> edges[k + 1];
  for (int i = 1; i <= k; i++) {
    s.clear();
    for (int u : l[i]) {
      for (int v : ad[u]) {
        if (c[v] > i) {
          edges[c[v]].push_back({u, v});
          s.insert(c[v]);
        }
      }
    }
    for (int j : s) {
      bool ok = bp[i] & bp[j];
      for (auto [u, v] : edges[j]) {
        unite(u, v);
        ok &= bipartite[find(u).first];
      }
      if (!ok) ans--;
      for (auto [u, v] : edges[j]) rollback();
    }
    for (int u : l[i]) {
      for (int v : ad[u]) {
        if (c[v] > i) {
          edges[c[v]].clear();
        }
      }
    }
  }
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  testCase();
}