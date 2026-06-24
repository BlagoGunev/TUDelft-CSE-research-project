//  Nikita Golikov, 2023

#include <bits/stdc++.h>

using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

#ifdef GOLIKOV
  #include "/Users/golikovnik/contests/debug.h"
#else
  #define debug(...) ;
#endif

template <class A, class B>
bool smin(A& x, B&& y) {
  if (y < x) {
    x = y;
    return true;
  }
  return false;
}

template <class A, class B>
bool smax(A& x, B&& y) {
  if (x < y) {
    x = y;
    return true;
  }
  return false;
}

struct LCA {
  vector<vector<int>> graph;
  int root;
  int n;
  vector<int> parent, jump, depth, tin, tout, bytin;
  int timer;

  LCA(vector<vector<int>> g, int root_ = 0) : graph(move(g)), root(root_) {
    n = int(graph.size());
    if (n > 0) {
      build();
    }
  }

  template <class F>
  int up(int v, F const& f) {
    while (v != root) {
      int jv = jump[v];
      if (f(jv)) {
        v = jv;
      } else {
        int pv = parent[v];
        if (f(pv)) {
          v = pv;
        } else {
          return v;
        }
      }
    }
    return root;
  }

  int up(int v, int d) {
    int nd = depth[v] - d;
    assert(nd >= 0);
    return up(v, [&](int u) {
      return depth[u] >= nd;
    });
  }

  bool anc(int v, int u) {
    return tin[v] <= tin[u] && tout[u] <= tout[v];
  }

  int lca(int u, int v) {
    return anc(u, v) ? u : parent[up(u, [&](int x) { return !anc(x, v); })];
  }

  int operator()(int u, int v) {
    return lca(u, v);
  }

  int dist(int u, int v) {
    return depth[u] + depth[v] - 2 * depth[lca(u, v)];
  }

  //  kth vertex on path u->v
  int kth(int u, int v, int k) {
    int w = lca(u, v);
    assert(k <= depth[u] + depth[v] - 2 * depth[w]);
    if (k <= depth[u] - depth[w]) {
      return up(u, k);
    }
    k -= depth[u] - depth[w];
    return up(v, depth[v] - depth[w] - k);
  }

  void dfs(int v) {
    tin[v] = timer++;
    bytin[tin[v]] = v;
    for (int u : graph[v]) {
      if (u == parent[v]) {
        continue;
      }
      depth[u] = depth[v] + 1;
      parent[u] = v;
      int dpar = depth[v];
      int dparj = depth[jump[v]];
      int dparjj = depth[jump[jump[v]]];
      jump[u] = (dparj - dpar == dparjj - dparj ? jump[jump[v]] : v);
      dfs(u);
    }
    tout[v] = timer;
  }

  void build() {
    parent.resize(n, -1);
    jump.resize(n, -1);
    depth.resize(n, -1);
    tin.resize(n, -1);
    tout.resize(n, -1);
    bytin.resize(n);
    timer = 0;
    depth[root] = 0;
    parent[root] = jump[root] = root;
    dfs(root);
  }
};

template <class T>
struct fenwick {
  int n;
  vector<T> fenw;

  fenwick(int n_) : n(n_), fenw(n_) {}

  void upd(int at, T delta) {
    for (; at < n; at |= at + 1) fenw[at] += delta;
  }

  T pref(int r) {
    T res{};
    for (; r >= 0; r = (r & (r + 1)) - 1) res += fenw[r];
    return res;
  }

  T get(int l, int r) {
    if (l >= r) return 0;
    return pref(r - 1) - pref(l - 1);
  }

  //  max i: pref(i-1) <= sum
  int lower_bound(T sum) {
    int pw = 1 << __lg(n);
    int ans = 0;
    for (; pw > 0; pw /= 2) {
      if (ans + pw > n) {
        continue;
      }

      auto val = fenw[ans + pw - 1];
      if (sum >= val) {
        sum -= val;
        ans += pw;
      }
    }
    return ans;
  }
};

template <class T>
struct SegmentTree {
  int pw;
  int n;

  vector<T> tree;

  template <class F = function<T(int)>>
  SegmentTree(int n_, F const& f) : n(n_) {
    pw = 1;
    while (pw < n) {
      pw *= 2;
    }
    tree.resize(2 * pw);
    for (int i = 0; i < n; ++i) {
      tree[pw + i] = f(i);
    }
    for (int i = pw - 1; i > 0; --i) {
      tree[i] = tree[2 * i] + tree[2 * i + 1];
    }
  }

  T query(int ql, int qr) {
    T L{}, R{};
    for (ql += pw, qr += pw; ql < qr; ql /= 2, qr /= 2) {
      if (ql & 1) {
        L = L + tree[ql++];
      }
      if (qr & 1) {
        R = tree[--qr] + R;
      }
    }
    return L + R;
  }

  template <class F>
  void modPoint(int at, F const& f) {
    for (f(tree[at += pw]); at /= 2; ) {
      tree[at] = tree[2 * at] + tree[2 * at + 1];
    }
  }

  void setPoint(int at, T const& t) {
    modPoint(at, [&](T& x) { x = t; });
  }

  struct FindResult {
    T val{};
    int pos = -1;
  };

  template <class F = function<bool(T)>>
  FindResult findFirst(int v, int l, int r, int ql, int qr, F const& f, T pref) {
    if (ql >= r || l >= qr) {
      return {pref, -1};
    }
    if (ql <= l && r <= qr) {
      if (!f(pref + tree[v])) {
        return {pref + tree[v], -1};
      }
      if (l + 1 == r) {
        return {pref + tree[v], l};
      }
      int m = (l + r) / 2;
      if (f(pref + tree[2 * v])) {
        return findFirst(2 * v, l, m, ql, qr, f, pref);
      } else {
        return findFirst(2 * v + 1, m, r, ql, qr, f, pref + tree[2 * v]);
      }
    } else {
      int m = (l + r) / 2;
      auto res = findFirst(2 * v, l, m, ql, qr, f, pref);
      if (res.pos == -1) {
        return findFirst(2 * v + 1, m, r, ql, qr, f, res.val);
      } else {
        return res;
      }
    }
  }  

  template <class F = function<bool(T)>>
  FindResult findFirst(int ql, int qr, F const& f) {
    return findFirst(1, 0, pw, ql, qr, f, T());
  }

  template <class F = function<bool(T)>>
  FindResult findLast(int v, int l, int r, int ql, int qr, F const& f, T suff) {
    if (ql >= r || l >= qr) {
      return {suff, -1};
    }
    if (ql <= l && r <= qr) {
      if (!f(tree[v] + suff)) {
        return {tree[v] + suff, -1};
      }
      if (l + 1 == r) {
        return {tree[v] + suff, l};
      }
      int m = (l + r) / 2;
      if (f(tree[2 * v + 1] + suff)) {
        return findLast(2 * v + 1, m, r, ql, qr, f, suff);
      } else {
        return findLast(2 * v, l, m, ql, qr, f, tree[2 * v + 1] + suff);
      }
    } else {
      int m = (l + r) / 2;
      auto res = findLast(2 * v + 1, m, r, ql, qr, f, suff);
      if (res.pos == -1) {
        return findLast(2 * v, l, m, ql, qr, f, res.val);
      } else {
        return res;
      }
    }
  }

  template <class F = function<bool(T)>>
  FindResult findLast(int ql, int qr, F const& f) {
    return findLast(1, 0, pw, ql, qr, f, T());
  }

  T all() {
    return tree[1];
  }
};

LCA lca(vector<vector<int>>{});

void solveTest() {
  int n; cin >> n;
  vector<int> w(n);
  for (int i = 0; i < n; ++i) {
    cin >> w[i];
  }
  vector<vector<int>> graph(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  lca = LCA(graph);
  vector<pair<int, int>> ord(n);
  for (int i = 0; i < n; ++i) {
    ord[i] = {w[i], lca.tin[i]};
  }
  sort(ord.begin(), ord.end());
  vector<int> posVertex(n);
  for (int v = 0; v < n; ++v) {
    posVertex[lca.bytin[ord[v].second]] = v;
  }
  struct Node {
    bool ok = true;
    int firstNode = -1;
    int lastNode = -1;
    int lcaNodes = -1;

    Node operator+(Node const& other) const {
      Node res{};
      res.ok = ok && other.ok;
      res.firstNode = (firstNode >= 0 ? firstNode : other.firstNode);
      res.lastNode = (other.lastNode >= 0 ? other.lastNode : lastNode);
      if (lcaNodes < 0) {
        res.lcaNodes = other.lcaNodes;
      } else if (other.lcaNodes < 0) {
        res.lcaNodes = lcaNodes;
      } else {
        res.lcaNodes = lca(lcaNodes, other.lcaNodes);
      }
      if (lastNode >= 0 && other.firstNode >= 0) {
        res.ok = res.ok && (lca.anc(lastNode, other.firstNode));
      }
      return res;
    }
  };
  SegmentTree<Node> tree(n, [&](int t) {
    int v = lca.bytin[ord[t].second];
    return Node{true, v, v, v};
  });
  vector<int> sz(n);
  auto dfs1 = [&](auto self, int v, int p = -1) -> void {
    sz[v] = 1;
    for (int u : graph[v]) {
      if (u != p) {
        self(self, u, v);
        sz[v] += sz[u];
      }
    }
  };
  dfs1(dfs1, 0);
  vector<bool> isGood(n);
  vector<bool> active(n, true);
  auto workVertex = [&](int v) {
    int weight = w[v];
    int from = lower_bound(ord.begin(), ord.end(), make_pair(weight + 1, 0)) - ord.begin();
    auto res = tree.query(from, n);
    if (res.firstNode < 0) {
      isGood[v] = false;
      return;
    }
    int lstVal = w[res.lastNode];
    int to = lower_bound(ord.begin(), ord.end(), make_pair(lstVal, 0)) - ord.begin();
    auto res1 = tree.query(from, to);
    if (!res1.ok) {
      isGood[v] = false;
      return;
    }
    if (res1.firstNode < 0) {
      isGood[v] = true;
      return;
    }
    int nd = res1.lastNode;
    auto res2 = tree.query(to, n);
    if (res2.firstNode < 0) {
      isGood[v] = true;
      return;
    }
    isGood[v] = lca.anc(nd, res2.lcaNodes);
  };
  auto activate = [&](int v) {
    active[v] = true;
    tree.setPoint(posVertex[v], Node{true, v, v, v});
  };
  auto deactivate = [&](int v) {
    active[v] = false;
    tree.setPoint(posVertex[v], Node());
  };
  auto dfs = [&](auto self, int v, int p = -1, bool keepDeactivated = false) -> void {
    int maxChild = -1;
    for (int u : graph[v]) {
      if (u != p && (maxChild < 0 || sz[u] > sz[maxChild])) {
        maxChild = u;
      }
    }
    for (int u : graph[v]) {
      if (u != p && u != maxChild) {
        self(self, u, v, false);
      }
    }
    if (maxChild >= 0) {
      self(self, maxChild, v, true);
    }
    for (int u : graph[v]) {
      if (u != p && u != maxChild) {
        for (int t = lca.tin[u]; t < lca.tout[u]; ++t) {
          deactivate(lca.bytin[t]);
        }
      }
    }
    deactivate(v);
    workVertex(v);
    if (!keepDeactivated) {
      for (int t = lca.tin[v]; t < lca.tout[v]; ++t) {
        activate(lca.bytin[t]);
      }
    }
  };
  dfs(dfs, 0);
  vector<int> ans;
  for (int v = 0; v < n; ++v) {
    if (isGood[v]) {
      ans.push_back(v);
    }
  }
  cout << ans.size();
  for (int v : ans) {
    cout << " " << v + 1;
  }
  cout << "\n";
}

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tests_;
  cin >> tests_;
  for (int tt_ = 1; tt_ <= tests_; ++tt_) {
    solveTest();
  }

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}