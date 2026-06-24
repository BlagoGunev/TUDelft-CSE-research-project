#include <cassert>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

using Int = long long;

template <class T1, class T2> ostream &operator<<(ostream &os, const pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << endl; }
template <class T> bool chmin(T &t, const T &f) { if (t > f) { t = f; return true; } return false; }
template <class T> bool chmax(T &t, const T &f) { if (t < f) { t = f; return true; } return false; }
#define COLOR(s) ("\x1b[" s "m")

struct Hld {
  int n, rt;
  // needs to be tree
  // vertex lists
  // modified in build(rt) (parent removed, heavy child first)
  vector<vector<int>> graph;
  vector<int> sz, par, dep;
  int zeit;
  vector<int> dis, fin, sid;
  // head vertex (minimum depth) in heavy path
  vector<int> head;

  Hld() : n(0), rt(-1), zeit(0) {}
  explicit Hld(int n_) : n(n_), rt(-1), graph(n), zeit(0) {}
  void ae(int u, int v) {
    assert(0 <= u); assert(u < n);
    assert(0 <= v); assert(v < n);
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  void dfsSz(int u) {
    sz[u] = 1;
    for (const int v : graph[u]) {
      auto it = std::find(graph[v].begin(), graph[v].end(), u);
      if (it != graph[v].end()) graph[v].erase(it);
      par[v] = u;
      dep[v] = dep[u] + 1;
      dfsSz(v);
      sz[u] += sz[v];
    }
  }
  void dfsHld(int u) {
    dis[u] = zeit++;
    const int deg = graph[u].size();
    if (deg > 0) {
      int vm = graph[u][0];
      int jm = 0;
      for (int j = 1; j < deg; ++j) {
        const int v = graph[u][j];
        if (sz[vm] < sz[v]) {
          vm = v;
          jm = j;
        }
      }
      swap(graph[u][0], graph[u][jm]);
      head[vm] = head[u];
      dfsHld(vm);
      for (int j = 1; j < deg; ++j) {
        const int v = graph[u][j];
        head[v] = v;
        dfsHld(v);
      }
    }
    fin[u] = zeit;
  }
  void build(int rt_) {
    assert(0 <= rt_); assert(rt_ < n);
    rt = rt_;
    sz.assign(n, 0);
    par.assign(n, -1);
    dep.assign(n, -1);
    dep[rt] = 0;
    dfsSz(rt);
    zeit = 0;
    dis.assign(n, -1);
    fin.assign(n, -1);
    head.assign(n, -1);
    head[rt] = rt;
    dfsHld(rt);
    assert(zeit == n);
    sid.assign(n, -1);
    for (int u = 0; u < n; ++u) sid[dis[u]] = u;
  }

  friend ostream &operator<<(ostream &os, const Hld &hld) {
    const int maxDep = *max_element(hld.dep.begin(), hld.dep.end());
    vector<string> ss(2 * maxDep + 1);
    int pos = 0, maxPos = 0;
    for (int j = 0; j < hld.n; ++j) {
      const int u = hld.sid[j];
      const int d = hld.dep[u];
      if (hld.head[u] == u) {
        if (j != 0) {
          pos = maxPos + 1;
          ss[2 * d - 1].resize(pos, '-');
          ss[2 * d - 1] += '+';
        }
      } else {
        ss[2 * d - 1].resize(pos, ' ');
        ss[2 * d - 1] += '|';
      }
      ss[2 * d].resize(pos, ' ');
      ss[2 * d] += std::to_string(u);
      if (maxPos < static_cast<int>(ss[2 * d].size())) {
        maxPos = ss[2 * d].size();
      }
    }
    for (int d = 0; d <= 2 * maxDep; ++d) os << ss[d] << '\n';
    return os;
  }

  bool contains(int u, int v) const {
    return (dis[u] <= dis[v] && dis[v] < fin[u]);
  }
  int lca(int u, int v) const {
    assert(0 <= u); assert(u < n);
    assert(0 <= v); assert(v < n);
    for (; head[u] != head[v]; ) (dis[u] > dis[v]) ? (u = par[head[u]]) : (v = par[head[v]]);
    return (dis[u] > dis[v]) ? v : u;
  }
  int jumpUp(int u, int d) const {
    assert(0 <= u); assert(u < n);
    assert(d >= 0);
    if (dep[u] < d) return -1;
    const int tar = dep[u] - d;
    for (u = head[u]; ; u = head[par[u]]) {
      if (dep[u] <= tar) return sid[dis[u] + (tar - dep[u])];
    }
  }
  int jump(int u, int v, int d) const {
    assert(0 <= u); assert(u < n);
    assert(0 <= v); assert(v < n);
    assert(d >= 0);
    const int l = lca(u, v);
    const int du = dep[u] - dep[l], dv = dep[v] - dep[l];
    if (d <= du) {
      return jumpUp(u, d);
    } else if (d <= du + dv) {
      return jumpUp(v, du + dv - d);
    } else {
      return -1;
    }
  }
  // [u, v) or [u, v]
  template <class F> void doPathUp(int u, int v, bool inclusive, F f) const {
    assert(contains(v, u));
    for (; head[u] != head[v]; u = par[head[u]]) f(dis[head[u]], dis[u] + 1);
    if (inclusive) {
      f(dis[v], dis[u] + 1);
    } else {
      if (v != u) f(dis[v] + 1, dis[u] + 1);
    }
  }
  // not path order, include lca(u, v) or not
  template <class F> void doPath(int u, int v, bool inclusive, F f) const {
    const int l = lca(u, v);
    doPathUp(u, l, false, f);
    doPathUp(v, l, inclusive, f);
  }

  // (vs, ps): compressed tree
  // vs: DFS order (sorted by dis)
  // vs[ps[x]]: the parent of vs[x]
  // ids[vs[x]] = x, not set for non-tree vertex
  vector<int> ids;
  pair<vector<int>, vector<int>> compress(vector<int> us) {
    // O(n) first time
    ids.resize(n, -1);
    std::sort(us.begin(), us.end(), [&](int u, int v) -> bool {
      return (dis[u] < dis[v]);
    });
    us.erase(std::unique(us.begin(), us.end()), us.end());
    int usLen = us.size();
    assert(usLen >= 1);
    for (int x = 1; x < usLen; ++x) us.push_back(lca(us[x - 1], us[x]));
    std::sort(us.begin(), us.end(), [&](int u, int v) -> bool {
      return (dis[u] < dis[v]);
    });
    us.erase(std::unique(us.begin(), us.end()), us.end());
    usLen = us.size();
    for (int x = 0; x < usLen; ++x) ids[us[x]] = x;
    vector<int> ps(usLen, -1);
    for (int x = 1; x < usLen; ++x) ps[x] = ids[lca(us[x - 1], us[x])];
    return make_pair(us, ps);
  }
};

////////////////////////////////////////////////////////////////////////////////


int N;
vector<int> A, B;

int main() {
  for (int numCases; ~scanf("%d", &numCases); ) { for (int caseId = 1; caseId <= numCases; ++caseId) {
    scanf("%d", &N);
    A.resize(N - 1);
    B.resize(N - 1);
    for (int i = 0; i < N - 1; ++i) {
      scanf("%d%d", &A[i], &B[i]);
      --A[i];
      --B[i];
    }
    
    Hld hld(N);
    for (int i = 0; i < N - 1; ++i) {
      hld.ae(A[i], B[i]);
    }
    hld.build(0);
    
    vector<vector<int>> uss(N);
    for (int u = 0; u < N; ++u) {
      uss[hld.dep[u]].push_back(u);
    }
    
    int ans = 0;
    for (int d = 0; d < N; ++d) {
      auto &us = uss[d];
      if (us.size()) {
        us.push_back(0);
        const auto vsps = hld.compress(us);
        const int len = vsps.first.size();
        int score = 0;
        for (int y = 1; y < len; ++y) {
          const int x = vsps.second[y];
          const int u = vsps.first[x];
          const int v = vsps.first[y];
          score += (hld.dep[v] - hld.dep[u]);
        }
// cerr<<d<<" "<<us<<": "<<score<<endl;
        chmax(ans, score);
      }
    }
    ans = N - 1 - ans;
    printf("%d\n", ans);
  }
#ifndef LOCAL
  break;
#endif
  }
  return 0;
}