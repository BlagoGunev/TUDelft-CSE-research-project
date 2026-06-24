#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = 3e5 + 5;
int n; vector<int> G[N]; ll a[N];

ll f[N][50];
inline void dfs(int u, int fa) {
  for(int i = 1; i < 50; i++) f[u][i] = a[u] * i;
  for(auto v : G[u]) {
    if(v == fa) continue;
    dfs(v, u);
    for(int i = 1; i < 50; i++) {
      ll t = 4e18;
      for(int j = 1; j < 50; j++) {
        if(j == i) continue;
        t = min(t, f[v][j]);
      }
      f[u][i] += t;
    }
  }
}

void Main() {
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
    G[i].clear();
  }
  for(int i = 1; i < n; i++) {
    int u, v; cin >> u >> v;
    G[u].push_back(v), G[v].push_back(u);
  }
  dfs(1, -1);
  ll ans = 4e18;
  for(int i = 1; i < 50; i++) {
    ans = min(ans, f[1][i]);
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  
  int T; cin >> T;
  while(T--) {
    Main();
  }
}