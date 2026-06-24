#include <bits/stdc++.h>



using namespace std;



#ifdef LOCAL

#include "algo/debug.h"

#else

#define debug(...) 42

#endif



const int md = 1'000'000'007;



inline void add(int &a, int b) {

  a += b;

  if (a >= md) a -= md;

}



inline void sub(int &a, int b) {

  a -= b;

  if (a < 0) a += md;

}



inline int mul(int a, int b) {

  return (int) ((long long) a * b % md); 

}



inline int power(int a, long long b) {

  int res = 1;

  while (b > 0) {

    if (b & 1) {

      res = mul(res, a);

    }

    a = mul(a, a);

    b >>= 1;

  }

  return res;

}



inline int inverse(int a) {

  a %= md;

  if (a < 0) a += md;

  int b = md, u = 0, v = 1;

  while (a) {

    int t = b / a;

    b -= t * a; swap(a, b);

    u -= t * v; swap(u, v);

  }

  assert(b == 1);

  if (u < 0) u += md;

  return u;

}



int main() {

  ios::sync_with_stdio(false);

  cin.tie(0);

  int tt;

  cin >> tt;

  while (tt--) {

    int n, m, s, t;

    cin >> n >> m >> s >> t;

    s -= 1;

    t -= 1;

    vector<vector<int>> g(n);

    for (int i = 0; i < m; ++i) {

      int v, u;

      cin >> v >> u;

      v -= 1;

      u -= 1;

      g[v].push_back(u);

      g[u].push_back(v);

    }

    auto Bfs = [&](int x) {

      vector<int> dist(n, -1);

      dist[x] = 0;

      vector<int> f(n);

      f[x] = 1;

      vector<int> que;

      que.push_back(x);

      for (int b = 0; b < (int) que.size(); ++b) {

        int v = que[b];

        for (int u : g[v]) {

          if (dist[u] == -1) {

            dist[u] = dist[v] + 1;

            que.push_back(u);

            f[u] = f[v];

          } else if (dist[u] == dist[v] + 1) {

            add(f[u], f[v]);

          }

        }

      }

      return pair(f, dist);

    };

    auto [fs, ds] = Bfs(s);

    auto [ft, dt] = Bfs(t);

    int ans = fs[t];

    for (int i = 0; i < n; ++i) {

      for (int j : g[i]) {

        if (ds[i] + dt[j] == ds[t] && ds[i] == ds[j]) {

          add(ans, mul(fs[i], ft[j]));

        }

      }

    }

    cout << ans << '\n';

  }

  return 0;

}