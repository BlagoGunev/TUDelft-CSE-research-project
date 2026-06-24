// Such a destiny was not desired.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = 10000 + 5;
int n, m, k;
int c[N];

struct Edge {int u, v, w;} e[N];
struct DUS {
  int f[N];
  inline void init() {iota(f + 1, f + n * 2 + 1, 1);}
  inline int find(int x) {while(x != f[x]) x = f[x] = f[f[x]]; return x;}
  inline void merge(int x, int y) {
    x = find(x), y = find(y);
    f[y] = x;
  }
} D;

int tot, w[N];
vector<int> G[N];

int siz[N];
vector<ll> f[N];
// ll f[N][N / 2], g[N / 2];
ll g[N / 2];
void dfs(int u) {
  siz[u] = (u <= n ? 1 : 0);
  // memset(f[u], 0x3f, sizeof(f[u]));
  f[u] = {0};
  for(auto v : G[u]) {
    dfs(v);
    fill(g, g + siz[u] + siz[v] + 1, 1e18);
    for(int i = 0; i <= siz[u]; i++) {
      for(int j = 1; j <= siz[v]; j++) {
        g[i + j] = min(g[i + j], f[u][i] + f[v][j]);
      }
      g[i] = min(g[i], f[u][i] + 1ll * w[u] * c[v]);
    }
    siz[u] += siz[v];
    f[u].resize(siz[u] + 1);
    for(int i = 0; i <= siz[u]; i++) f[u][i] = g[i];
    c[u] += c[v];
  }
  if(u <= n) f[u] = {0, 0};
}

void Main() {
  cin >> n >> m >> k;
  fill(c + 1, c + n * 2 + 1, 0);
  D.init();
  for(int i = 1; i <= k; i++) {
    int u; cin >> u;
    c[u] = 1;
  }
  for(int i = 1; i <= m; i++) {
    auto &[u, v, w] = e[i];
    cin >> u >> v >> w;
  }
  sort(e + 1, e + m + 1, [](Edge A, Edge B) {
    return A.w < B.w;
  });
  for(int i = 1; i <= tot; i++) G[i].clear();
  tot = n;
  for(int i = 1; i <= m; i++) {
    auto [u, v, val] = e[i];
    if(D.find(u) != D.find(v)) {
      tot++;
      assert(tot < 2 * n);
      w[tot] = val;
      G[tot].push_back(D.find(u)), G[tot].push_back(D.find(v));
      D.merge(tot, u), D.merge(tot, v);
    }
  }
  dfs(tot);
  for(int i = 1; i <= n; i++) {
    cout << f[tot][i] << " \n"[i == n];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  
  int T; cin >> T;
  while(T--) {
    Main();
  }
}