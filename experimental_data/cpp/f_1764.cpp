#include <bits/stdc++.h>



#define int long long



using namespace std;



const int kMaxN = 2005;



int n, m;

int f[kMaxN][kMaxN], dis[kMaxN][kMaxN], uu[kMaxN], vv[kMaxN], w[kMaxN];

bool vis[kMaxN];

vector<int> v[kMaxN];



void solve(int u, int fa) {

  if (!v[u].size()) return;

  // cerr << u << ' ' << fa << '\n';

  int mini = 1e18, idx = 0;

  for (auto x : v[u]) {

    if (dis[u][x] < mini) {

      mini = dis[u][x];

      idx = x;

    }

  }

  ++m;

  uu[m] = u, vv[m] = idx, w[m] = dis[u][idx];

  auto diao = v[u];

  v[u].clear();

  for (auto x : diao) {

    if (x == idx || x == u) continue;

    if (dis[x][u] > dis[x][idx]) {

      v[idx].emplace_back(x);

    } else {

      v[u].emplace_back(x);

    }

  }

  solve(idx, u), solve(u, fa);

}



void dickdreamer() {

  cin >> n;

  for (int i = 1; i <= n; ++i) {

    for (int j = 1; j <= i; ++j) {

      cin >> f[i][j];

      f[j][i] = f[i][j];

    }

  }

  for (int i = 1; i <= n; ++i) {

    for (int j = 1; j <= n; ++j) {

      dis[i][j] = (f[i][i] + f[j][j] - 2ll * f[i][j]) / n;

      // cout << dis[i][j] << ' ';

    }

    // cout << '\n';

  }

  vis[1] = 1;

  for (int i = 2; i <= n; ++i) {

    v[1].emplace_back(i);

  }

  solve(1, 0);

  for (int i = 1; i <= m; ++i)

    cout << uu[i] << ' ' << vv[i] << ' ' << w[i] << '\n';

}



signed main() {

#ifdef ORZXKR

  freopen("in.txt", "r", stdin);

  freopen("out.txt", "w", stdout);

#endif

  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int T = 1;

  // cin >> T;

  while (T--) dickdreamer();

  return 0;

}