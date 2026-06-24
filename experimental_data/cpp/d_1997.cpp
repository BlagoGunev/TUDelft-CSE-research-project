// Problem: D. Maximize the Root
// Contest: Codeforces - Educational Codeforces Round 168 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1997/problem/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// Author: EnucAI
#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define D(...) ((void)0)
#endif

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vi = std::vector<int>;
using pii = std::pair<int, int>;

constexpr int inf = std::numeric_limits<int>::max() / 2;
constexpr ll infll = std::numeric_limits<ll>::max() / 2;
constexpr ld eps = 1e-8l;

#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)((x).size()))
#define rep(i, j, k) for (int i = (j); i <= (k); i++)
#define per(i, j, k) for (int i = (j); i >= (k); i--)
#define fi first
#define se second
#define mp std::make_pair
#define pb push_back
#define ppb pop_back
#define eb emplace_back

template <class X, class Y> void chkmax(X &x, const Y &y) { if (x < y) x = y; }
template <class X, class Y> void chkmin(X &x, const Y &y) { if (x > y) x = y; }

constexpr int maxn = 2e5 + 5;

int n, a[maxn];
ll b[maxn];
vi g[maxn];

bool dfs(int u, ll tot) {
  b[u] -= tot;
  if (b[u] < 0 && !sz(g[u])) return false;
  if (b[u] < 0) {
    tot += -b[u];
    chkmin(tot, infll);
  }
  for (int v : g[u]) {
    if (!dfs(v, tot)) return false;
  }
  return true;
}

bool check(int x) {
  b[1] = -x;
  std::copy(a + 2, a + n + 1, b + 2);
  return dfs(1, 0);
}

void work() {
  std::cin >> n;
  rep(i, 1, n) std::cin >> a[i];
  rep(i, 1, n) g[i].clear();
  rep(i, 2, n) {
    int p;
    std::cin >> p;
    g[p].pb(i);
  }
  int l = 0, r = inf;
  while (l < r) {
    int mid = (l + r + 1) / 2;
    if (check(mid)) l = mid;
    else r = mid - 1;
  }
  std::cout << a[1] + l << '\n';
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  std::cin >> t;
  while (t--) work();
}