#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<int> v;
vector<vector<int>> S;
int n;

template<class Node>
struct SegTree {
  int n, b, e; vector<Node> T;
  SegTree(int n) : n(n), T(2 * n) {}
  template<class CB>
  void Walk(int l, int r, CB&& cb) {
    auto dfs = [&](auto& self, int x, int b, int e) {
      int m = (b + e) / 2, y = x + 1, z = x + 2 * (m - b);
      if (m == b) y = z = 0;
      T[x].push(T[y], T[z]);
      if (b >= r || e <= l) return;
      this->b = b; this->e = e;
      if (b >= l && e <= r && !cb(T[x])) 
        return T[x].push(T[y], T[z]);
      self(self, y, b, m);
      self(self, z, m, e);
      T[x].pull(T[y], T[z]);
    };
    dfs(dfs, 1, 0, n);
  };
};

struct Node {
  int max1 = -1e9, lazy = 0;
  void pull(Node& a, Node& b) {
    max1 = max(a.max1, b.max1);
    // if (a.max1 > b.max1) {
    //   max1 = a.max1;
    //   max2 = max(a.max2, b.max1);
    // } else {
    //   max1 = b.max1;
    //   max2 = max(b.max2, a.max1);
    // }
  }
  void push(Node& l, Node& r) {
    if (lazy == 0) return;
    l.lazy += lazy; r.lazy += lazy;
    max1 += lazy; // max2 += lazy;
    lazy = 0;
  }
};

// struct SegTree {
//   struct Node {
//     int max1 = -INF, max2 = -INF;
//   };
//   Node f(Node a, Node b) {
//     if (a.max1 > b.max1) {
//       return Node{a.max1, max(a.max2, b.max1)};
//     } else {
//       return Node{b.max1, max(b.max2, a.max1)};
//     }
//   }
//   vector<Node> T; int n;
//   SegTree(int n) : T(2 * n), n(n) {}
  
//   void Update(int b, int e, int delta) {
//     upd(1, 0, n, b, e, delta);
//   }
//   Node Query(int b, int e) {
//     Node r1, r2;
//     for (b += n, e += n; b < e; b /= 2, e /= 2) {
//       if (b % 2) r1 = f(r1, T[b++]);
//       if (e % 2) r2 = f(T[--e], r2);
//     }
//     return f(r1, r2);
//   }
// };
// SegTree ST(0);

SegTree<Node> ST(0);
vector<int> lf, rt;
long long ans = 1;
vector<int> buff;

void DFS(int node, int& timer) {
  lf[node] = timer++;
  for (auto son : graph[node]) {
    DFS(son, timer);
  }
  rt[node] = timer;
  auto& s = S[v[node]];
  while (s.size() > 0 && lf[s.back()] >= lf[node]) {
    ST.Walk(lf[s.back()], rt[s.back()], [&](Node& x) {
      x.lazy -= 1;
      return 0;
    });
    s.pop_back();
  }
  ST.Walk(lf[node], rt[node], [&](Node& x) {
    x.lazy += 1;
    return 0;
  });
  s.push_back(node);
  buff.clear();
  for (auto son : graph[node]) {
    Node res; 
    ST.Walk(lf[son], rt[son], [&](Node& x) {
      res.pull(res, x);
      return 0;
    });
    buff.push_back(res.max1);
  }
  if (buff.size()) {
    sort(buff.begin(), buff.end());
    ans = max(ans, 1LL * buff.back());
  }
  // cerr << "node=" << node + 1 << ": ";
  // for (auto x : buff) cerr << x << " "; cerr << endl;
  if (buff.size() >= 2) {
    ans = max(ans, 1LL * buff[buff.size() - 2] * buff[buff.size() - 1]);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    cin >> n;
    graph.assign(n, {});
    v.assign(n, -1);
    S.assign(n, {});
    lf.assign(n, -1);
    rt.assign(n, -1);
    ST = {n};
    ST.Walk(0, n, [&](Node& x) {
      if (ST.e - ST.b == 1) {
        x.max1 = 0;
        return 0;
      }
      return 1;
    });
    // for (auto x : ST.T) cerr << x.max1 << " " << x.max2 << " | "; cerr << endl;
    for (int i = 1; i < n; ++i) {
      int par; cin >> par; graph[par - 1].push_back(i);
    }
    for (int i = 0; i < n; ++i) {
      cin >> v[i]; --v[i];
    }
    ans = 1;
    int timer = 0;
    DFS(0, timer);
    cout << ans << '\n';
  }

  return 0;
}