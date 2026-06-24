// 멈추지를 못해 More and more

// corner cases // in`t vs ll // clear structures // statement // doublesz // line order // 0-1-indexed // endl

#include <bits/stdc++.h>

#define trace(x) cerr << #x << " = " << x << endl

using namespace std;

const int N = 2.5e5 + 5;



struct Edge {

  int to, val;

  Edge(int a, int b): to(a), val(b) {}

};



int txor;

int px[N], vist[N], deg[N];

vector<int> gx[N];

vector<Edge> gy[N];



void apply(int u, int val) {

  if (deg[u]) {

    txor ^= px[u] ^ val;

  }

  px[u] = val;

}



void dfs(int u) {

  vist[u] = 1;

  for (auto [v, val]: gy[u]) {

    if (!vist[v]) {

      apply(v, px[u] ^ val);

      dfs(v);

    } else if ((px[u] ^ px[v]) != val) {

      cout << "No\n";

      exit(0);

    }

  }

}



int main() {

  ios_base::sync_with_stdio(0);

  cin.tie(0);



  int n, q;

  cin >> n >> q;

  vector<pair<int,int>> edges;

  for (int i = 1; i < n; ++i) {

    int u, v;

    cin >> u >> v;

    u--; v--;

    deg[u] ^= 1;

    deg[v] ^= 1;

    edges.push_back({u, v});

    gx[u].push_back(v);

    gx[v].push_back(u);

  }



  for (int i = 0; i < q; ++i) {

    int u, v, x;

    cin >> u >> v >> x;

    u--; v--;

    gy[u].push_back({v, x});

    gy[v].push_back({u, x});

  }



  vector<int> roots;

  for (int i = 0; i < n; ++i) {

    if (!vist[i]) {

      roots.push_back(i);

      dfs(i);

    }

  }



  // minimize

  memset(vist, 0, sizeof(vist));

  for (int i = 1; i < roots.size(); ++i) {

    int r = roots[i];

    apply(r, txor);

    dfs(r);

  }



  cout << "Yes\n";

  for (auto [u, v]: edges) {

    cout << (px[u] ^ px[v]) << ' ';

  }

  cout << '\n';







  return 0;

}