#include <bits/stdc++.h>



class graph {

  private:

    std::vector<std::vector<int>> adj;

    std::vector<int> dfn, low;

    std::stack<int> sta;

    int n, DFN = 0;



    void dfs (int u) {

      dfn[u] = low[u] = ++DFN;

      sta.push(u);



      for (auto v : adj[u]) {

        if (!dfn[v]) {

          dfs(v);

          low[u] = std::min(low[u], low[v]);



          if (low[v] >= dfn[u]) {

            ++m;



            std::map<int, int> mp;

            mp[u] = 1;

            int top;

            do {

              top = sta.top();

              sta.pop();

              squ[m].emplace_back(top);

              for (auto v : adj[top]) {

                edge[m] += mp[v];

              }

              mp[top] = 1;

            } while (top != v);



            squ[m].emplace_back(u);

          }

        } else {

          low[u] = std::min(low[u], dfn[v]);

        }

      }

    }



  public:

    int m;

    std::vector<std::vector<int>> squ;

    std::vector<int> edge;

    graph (int n) : n(n), m(n), adj(n + 1), dfn(n + 1), low(n + 1), squ(n * 2 + 1), edge(n * 2 + 1) {}



    void add_edge (int x, int y) {

      adj[x].emplace_back(y);

      adj[y].emplace_back(x);

    }



    void run () {

      dfs(1);

    }

};



class Tree {

  private:

    std::vector<std::vector<int>> adj;

    std::vector<int> sum, siz, hson, top, par, dep;

    int n, m, DFN = 0;



    void dfs (int u, int fa) {

      if (fa) {

        adj[u].erase(find(adj[u].begin(), adj[u].end(), fa));

      }



      dfn[u] = ++DFN;

      sum[u] = sum[fa] + (val[u]);

      dep[u] = dep[fa] + 1;

      par[u] = fa;

      siz[u] = 1;



      for (auto v : adj[u]) {

        if (v ^ fa) {

          dfs(v, u);

          siz[u] += siz[v];

          if (siz[v] > siz[hson[u]]) {

            hson[u] = v;

          }

        }

      }

    }



    void dfs1 (int u, int Top) {

      top[u] = Top;

      if (hson[u]) {

        dfs1(hson[u], Top);

      }



      for (auto v : adj[u]) {

        if (v ^ hson[u]) {

          dfs1(v, v);

        }

      }

    }



    int LCA (int x, int y) {

      while (top[x] != top[y]) {

        if (dep[top[x]] < dep[top[y]]) {

          std::swap(x, y);

        }



        x = par[top[x]];

      }



      return dep[x] < dep[y] ? x : y;

    }



  public:

    std::vector<int> dfn, val;

    Tree (int n, int m) : n(n), m(m), adj(m + 1), sum(m + 1), dep(m + 1), siz(m + 1), hson(m + 1), top(m + 1), dfn(m + 1), par(m + 1), val(m + 1) {}



    void add_edge (int x, int y) {

      adj[x].emplace_back(y);

      adj[y].emplace_back(x);

    }



    void init () {

      dfs(m, 0);

      dfs1(m, m);

    }



    int dis (int u, int v) {

      int lca = LCA(u, v);

      return sum[u] + sum[v] - sum[lca] - sum[par[lca]];;

    }



    int lca (int u, int v) {

      return LCA(u, v);

    }

};



signed main() {

  std::ios::sync_with_stdio(false);

  std::cin.tie(nullptr);



  int n, m;

  std::cin >> n >> m;



  graph M(n);

  for (int i = 1; i <= m; ++i) {

    int x, y;

    std::cin >> x >> y;

    M.add_edge(x, y);

  }



  M.run();



  Tree T(n, M.m);

  for (int i = n + 1; i <= M.m; ++i) { 

    for (int j : M.squ[i]) {

      T.add_edge(i, j);

    }

  }



  for (int i = n + 1; i <= M.m; ++i) {

    T.val[i] = M.edge[i] == 1 ? 0 : M.edge[i];

  }



  T.init();



  int q;

  std::cin >> q;



  while (q--) {

    int x, y;

    std::cin >> x >> y;

    std::cout << T.dis(x, y) << '\n';

  }

}