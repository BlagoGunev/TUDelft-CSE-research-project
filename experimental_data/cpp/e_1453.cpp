// code by a weak man named YJJ
#include <bits/stdc++.h>
#define filesolution freopen("data.in", "r", stdin), freopen("solution.out", "w", stdout)
#define filebrute freopen("data.in", "r", stdin), freopen("brute.out", "w", stdout)
#define filemakedata freopen("data.in", "w", stdout);
#define file(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
using namespace std;

template <typename T> void read(T &x) {
  x = 0; int f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + (ch ^ 48);
    ch = getchar();
  }
  return x *= f, void();
}
template <typename T> void ckmax(T &a, T b) { a = b > a ? b : a; }
template <typename T> void ckmin(T &a, T b) { a = b < a ? b : a; }

///////////////////////////////////////////////////

const int N = 2e5 + 5;

int T, n, ans, f[N];
vector<int> g[N];

void dfs(int u, int fath) {
  if (g[u].size() - (fath != 0) == 0) return f[u] = 0, void();
  for (auto v : g[u]) if (v != fath) dfs(v, u);
  if (u == 1) {
    int pos = 0;
    for (auto v : g[u]) if (v != fath) {
      if (pos == 0 || f[v] > f[pos]) pos = v;
    }
    f[u] = f[pos] + 1;
    for (auto v : g[u]) if (v != fath) {
      if (v == pos) ckmax(ans, f[v] + 1);
      else ckmax(ans, f[v] + 2);
    }
    return ;
  }
  int pos = 0;
  for (auto v : g[u]) if (v != fath) {
    if (pos == 0 || f[v] < f[pos]) pos = v;
  }
  f[u] = f[pos] + 1;
  for (auto v : g[u]) if (v != fath) {
    if (v == pos) ckmax(ans, f[v] + 1);
    else ckmax(ans, f[v] + 2);
  }
}

int main() {
  for (read(T); T; T--) {
    read(n);
    for (int i = 1; i <= n; i++) g[i].clear();
    for (int i = 1, u, v; i < n; i++) {
      read(u), read(v);
      g[u].push_back(v);
      g[v].push_back(u);
    }
    ans = 0, dfs(1, 0); 
    printf("%d\n", ans);
  }
  return 0;
}