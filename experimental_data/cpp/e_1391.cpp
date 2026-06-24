#include <vector>

#include <cassert>

#include <iostream>

#include <algorithm>

#include <functional>



using namespace std;



int main() {

  ios::sync_with_stdio(false);

  cin.tie(0);

  int tt;

  cin >> tt;

  while (tt--) {

    int n, m;

    cin >> n >> m;

    vector<vector<int>> e(n);

    for (int i = 0; i < m; i++) {

      int u, v;

      cin >> u >> v;

      u--;

      v--;

      e[u].push_back(v);

      e[v].push_back(u);

    }                     

    vector<int> par(n, -1);

    vector<int> dep(n, -1);

    vector<int> f(n);

    vector<vector<int>> sisters(n);

    dep[0] = 0;

    int res = -1, x, y, w;

    function<void(int)> dfs = [&](int v) {                  

      sisters[dep[v]].push_back(v);

      f[v] = v;             

      vector<int> span;

      for (int u : e[v]) {

        if (dep[u] == -1) {

          span.push_back(u);

          dep[u] = dep[v] + 1;

          par[u] = v;

          dfs(u);

          if (dep[f[u]] > dep[f[v]]) {

            f[v] = f[u];

          }

        }

      }

      sort(span.begin(), span.end(), [&](int i, int j) {

        return dep[f[i]] > dep[f[j]];

      });

      if (!span.empty()) {

        int X = f[span[0]];

        int val = dep[X] - dep[v];

        if (val > res) {

          res = val;

          w = v, x = X, y = v;

        }

      }

      if ((int) span.size() > 1) {

        int X = f[span[0]];

        int Y = f[span[1]];

        int val = dep[X] + dep[Y] - 2 * dep[v];

        if (val > res) {

          res = val;

          w = v, x = X, y = Y;

        }

      }

    };

    dfs(0);

    if (res + 1 >= (n + 1) / 2) {

      cout << "PATH" << '\n';

      cout << res + 1 << '\n';

      int v = x;

      while (v != w) {

        cout << v + 1 << ' ';

        v = par[v];

      }                 

      vector<int> path;

      v = y;

      while (v != w) {

        path.push_back(v);

        v = par[v];

      }

      cout << w + 1;

      for (int i = (int) path.size() - 1; i >= 0; i--) {

        cout << ' ' << path[i] + 1;

      }

      cout << '\n';

    }

    else {

      cout << "PAIRING" << '\n';

      int cnt = (n + 1) / 2;

      cnt = (cnt + 1) / 2;

      cout << cnt << '\n';

      for (int i = n - 1; cnt > 0 && i >= 0; i--) {

        int k = min((int) sisters[i].size() / 2, cnt);

        for (int j = 0; j < k; j++) {

          cout << sisters[i][j << 1] + 1 << ' ' << sisters[i][j << 1 | 1] + 1 << '\n';

        }

        cnt -= k;

      }

      assert(cnt == 0);

    }

  }

  return 0;

}