#line 1 "library/my_template.hpp"
#if defined(LOCAL)
#include <my_template_compiled.hpp>
#else

// https://codeforces.com/blog/entry/96344
#pragma GCC optimize("Ofast,unroll-loops")
// いまの CF だとこれ入れると動かない？
// #pragma GCC target("avx2,popcnt")

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using u32 = unsigned int;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;
using f128 = __float128;

template <class T>
constexpr T infty = 0;
template <>
constexpr int infty<int> = 1'000'000'000;
template <>
constexpr ll infty<ll> = ll(infty<int>) * infty<int> * 2;
template <>
constexpr u32 infty<u32> = infty<int>;
template <>
constexpr u64 infty<u64> = infty<ll>;
template <>
constexpr i128 infty<i128> = i128(infty<ll>) * infty<ll>;
template <>
constexpr double infty<double> = infty<ll>;
template <>
constexpr long double infty<long double> = infty<ll>;

using pi = pair<ll, ll>;
using vi = vector<ll>;
template <class T>
using vc = vector<T>;
template <class T>
using vvc = vector<vc<T>>;
template <class T>
using vvvc = vector<vvc<T>>;
template <class T>
using vvvvc = vector<vvvc<T>>;
template <class T>
using vvvvvc = vector<vvvvc<T>>;
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;

#define vv(type, name, h, ...) \
  vector<vector<type>> name(h, vector<type>(__VA_ARGS__))
#define vvv(type, name, h, w, ...)   \
  vector<vector<vector<type>>> name( \
      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))
#define vvvv(type, name, a, b, c, ...)       \
  vector<vector<vector<vector<type>>>> name( \
      a, vector<vector<vector<type>>>(       \
             b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))

// https://trap.jp/post/1224/
#define FOR1(a) for (ll _ = 0; _ < ll(a); ++_)
#define FOR2(i, a) for (ll i = 0; i < ll(a); ++i)
#define FOR3(i, a, b) for (ll i = a; i < ll(b); ++i)
#define FOR4(i, a, b, c) for (ll i = a; i < ll(b); i += (c))
#define FOR1_R(a) for (ll i = (a)-1; i >= ll(0); --i)
#define FOR2_R(i, a) for (ll i = (a)-1; i >= ll(0); --i)
#define FOR3_R(i, a, b) for (ll i = (b)-1; i >= ll(a); --i)
#define overload4(a, b, c, d, e, ...) e
#define overload3(a, b, c, d, ...) d
#define FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)
#define FOR_R(...) overload3(__VA_ARGS__, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)

#define FOR_subset(t, s) \
  for (ll t = (s); t >= 0; t = (t == 0 ? -1 : (t - 1) & (s)))
#define all(x) x.begin(), x.end()
#define len(x) ll(x.size())
#define elif else if

#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second

#define stoi stoll

int popcnt(int x) { return __builtin_popcount(x); }
int popcnt(u32 x) { return __builtin_popcount(x); }
int popcnt(ll x) { return __builtin_popcountll(x); }
int popcnt(u64 x) { return __builtin_popcountll(x); }
int popcnt_mod_2(int x) { return __builtin_parity(x); }
int popcnt_mod_2(u32 x) { return __builtin_parity(x); }
int popcnt_mod_2(ll x) { return __builtin_parityll(x); }
int popcnt_mod_2(u64 x) { return __builtin_parityll(x); }
// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)
int topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }
int topbit(u32 x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }
int topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }
int topbit(u64 x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }
// (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)
int lowbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x)); }
int lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x)); }
int lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }
int lowbit(u64 x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }

template <typename T>
T floor(T a, T b) {
  return a / b - (a % b && (a ^ b) < 0);
}
template <typename T>
T ceil(T x, T y) {
  return floor(x + y - 1, y);
}
template <typename T>
T bmod(T x, T y) {
  return x - y * floor(x, y);
}
template <typename T>
pair<T, T> divmod(T x, T y) {
  T q = floor(x, y);
  return {q, x - q * y};
}

template <typename T, typename U>
T SUM(const vector<U> &A) {
  T sm = 0;
  for (auto &&a: A) sm += a;
  return sm;
}

#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))
#define UNIQUE(x) \
  sort(all(x)), x.erase(unique(all(x)), x.end()), x.shrink_to_fit()

template <typename T>
T POP(deque<T> &que) {
  T a = que.front();
  que.pop_front();
  return a;
}
template <typename T>
T POP(pq<T> &que) {
  T a = que.top();
  que.pop();
  return a;
}
template <typename T>
T POP(pqg<T> &que) {
  T a = que.top();
  que.pop();
  return a;
}
template <typename T>
T POP(vc<T> &que) {
  T a = que.back();
  que.pop_back();
  return a;
}

template <typename F>
ll binary_search(F check, ll ok, ll ng, bool check_ok = true) {
  if (check_ok) assert(check(ok));
  while (abs(ok - ng) > 1) {
    auto x = (ng + ok) / 2;
    (check(x) ? ok : ng) = x;
  }
  return ok;
}
template <typename F>
double binary_search_real(F check, double ok, double ng, int iter = 100) {
  FOR(iter) {
    double x = (ok + ng) / 2;
    (check(x) ? ok : ng) = x;
  }
  return (ok + ng) / 2;
}

template <class T, class S>
inline bool chmax(T &a, const S &b) {
  return (a < b ? a = b, 1 : 0);
}
template <class T, class S>
inline bool chmin(T &a, const S &b) {
  return (a > b ? a = b, 1 : 0);
}

// ? は -1
vc<int> s_to_vi(const string &S, char first_char) {
  vc<int> A(S.size());
  FOR(i, S.size()) { A[i] = (S[i] != '?' ? S[i] - first_char : -1); }
  return A;
}

template <typename T, typename U>
vector<T> cumsum(vector<U> &A, int off = 1) {
  int N = A.size();
  vector<T> B(N + 1);
  FOR(i, N) { B[i + 1] = B[i] + A[i]; }
  if (off == 0) B.erase(B.begin());
  return B;
}

// stable sort
template <typename T>
vector<int> argsort(const vector<T> &A) {
  vector<int> ids(len(A));
  iota(all(ids), 0);
  sort(all(ids),
       [&](int i, int j) { return (A[i] == A[j] ? i < j : A[i] < A[j]); });
  return ids;
}

// A[I[0]], A[I[1]], ...
template <typename T>
vc<T> rearrange(const vc<T> &A, const vc<int> &I) {
  vc<T> B(len(I));
  FOR(i, len(I)) B[i] = A[I[i]];
  return B;
}
#endif
#line 1 "library/other/io.hpp"
#define FASTIO
#include <unistd.h>

// https://judge.yosupo.jp/submission/21623
namespace fastio {
static constexpr uint32_t SZ = 1 << 17;
char ibuf[SZ];
char obuf[SZ];
char out[100];
// pointer of ibuf, obuf
uint32_t pil = 0, pir = 0, por = 0;

struct Pre {
  char num[10000][4];
  constexpr Pre() : num() {
    for (int i = 0; i < 10000; i++) {
      int n = i;
      for (int j = 3; j >= 0; j--) {
        num[i][j] = n % 10 | '0';
        n /= 10;
      }
    }
  }
} constexpr pre;

inline void load() {
  memcpy(ibuf, ibuf + pil, pir - pil);
  pir = pir - pil + fread(ibuf + pir - pil, 1, SZ - pir + pil, stdin);
  pil = 0;
  if (pir < SZ) ibuf[pir++] = '\n';
}

inline void flush() {
  fwrite(obuf, 1, por, stdout);
  por = 0;
}

void rd(char &c) {
  do {
    if (pil + 1 > pir) load();
    c = ibuf[pil++];
  } while (isspace(c));
}

void rd(string &x) {
  x.clear();
  char c;
  do {
    if (pil + 1 > pir) load();
    c = ibuf[pil++];
  } while (isspace(c));
  do {
    x += c;
    if (pil == pir) load();
    c = ibuf[pil++];
  } while (!isspace(c));
}

template <typename T>
void rd_real(T &x) {
  string s;
  rd(s);
  x = stod(s);
}

template <typename T>
void rd_integer(T &x) {
  if (pil + 100 > pir) load();
  char c;
  do
    c = ibuf[pil++];
  while (c < '-');
  bool minus = 0;
  if constexpr (is_signed<T>::value || is_same_v<T, i128>) {
    if (c == '-') { minus = 1, c = ibuf[pil++]; }
  }
  x = 0;
  while ('0' <= c) { x = x * 10 + (c & 15), c = ibuf[pil++]; }
  if constexpr (is_signed<T>::value || is_same_v<T, i128>) {
    if (minus) x = -x;
  }
}

void rd(int &x) { rd_integer(x); }
void rd(ll &x) { rd_integer(x); }
void rd(i128 &x) { rd_integer(x); }
void rd(u32 &x) { rd_integer(x); }
void rd(u64 &x) { rd_integer(x); }
void rd(u128 &x) { rd_integer(x); }
void rd(double &x) { rd_real(x); }
void rd(long double &x) { rd_real(x); }
void rd(f128 &x) { rd_real(x); }

template <class T, class U>
void rd(pair<T, U> &p) {
  return rd(p.first), rd(p.second);
}
template <size_t N = 0, typename T>
void rd_tuple(T &t) {
  if constexpr (N < std::tuple_size<T>::value) {
    auto &x = std::get<N>(t);
    rd(x);
    rd_tuple<N + 1>(t);
  }
}
template <class... T>
void rd(tuple<T...> &tpl) {
  rd_tuple(tpl);
}

template <size_t N = 0, typename T>
void rd(array<T, N> &x) {
  for (auto &d: x) rd(d);
}
template <class T>
void rd(vc<T> &x) {
  for (auto &d: x) rd(d);
}

void read() {}
template <class H, class... T>
void read(H &h, T &... t) {
  rd(h), read(t...);
}

void wt(const char c) {
  if (por == SZ) flush();
  obuf[por++] = c;
}
void wt(const string s) {
  for (char c: s) wt(c);
}
void wt(const char *s) {
  size_t len = strlen(s);
  for (size_t i = 0; i < len; i++) wt(s[i]);
}

template <typename T>
void wt_integer(T x) {
  if (por > SZ - 100) flush();
  if (x < 0) { obuf[por++] = '-', x = -x; }
  int outi;
  for (outi = 96; x >= 10000; outi -= 4) {
    memcpy(out + outi, pre.num[x % 10000], 4);
    x /= 10000;
  }
  if (x >= 1000) {
    memcpy(obuf + por, pre.num[x], 4);
    por += 4;
  } else if (x >= 100) {
    memcpy(obuf + por, pre.num[x] + 1, 3);
    por += 3;
  } else if (x >= 10) {
    int q = (x * 103) >> 10;
    obuf[por] = q | '0';
    obuf[por + 1] = (x - q * 10) | '0';
    por += 2;
  } else
    obuf[por++] = x | '0';
  memcpy(obuf + por, out + outi + 4, 96 - outi);
  por += 96 - outi;
}

template <typename T>
void wt_real(T x) {
  ostringstream oss;
  oss << fixed << setprecision(15) << double(x);
  string s = oss.str();
  wt(s);
}

void wt(int x) { wt_integer(x); }
void wt(ll x) { wt_integer(x); }
void wt(i128 x) { wt_integer(x); }
void wt(u32 x) { wt_integer(x); }
void wt(u64 x) { wt_integer(x); }
void wt(u128 x) { wt_integer(x); }
void wt(double x) { wt_real(x); }
void wt(long double x) { wt_real(x); }
void wt(f128 x) { wt_real(x); }

template <class T, class U>
void wt(const pair<T, U> val) {
  wt(val.first);
  wt(' ');
  wt(val.second);
}
template <size_t N = 0, typename T>
void wt_tuple(const T t) {
  if constexpr (N < std::tuple_size<T>::value) {
    if constexpr (N > 0) { wt(' '); }
    const auto x = std::get<N>(t);
    wt(x);
    wt_tuple<N + 1>(t);
  }
}
template <class... T>
void wt(tuple<T...> tpl) {
  wt_tuple(tpl);
}
template <class T, size_t S>
void wt(const array<T, S> val) {
  auto n = val.size();
  for (size_t i = 0; i < n; i++) {
    if (i) wt(' ');
    wt(val[i]);
  }
}
template <class T>
void wt(const vector<T> val) {
  auto n = val.size();
  for (size_t i = 0; i < n; i++) {
    if (i) wt(' ');
    wt(val[i]);
  }
}

void print() { wt('\n'); }
template <class Head, class... Tail>
void print(Head &&head, Tail &&... tail) {
  wt(head);
  if (sizeof...(Tail)) wt(' ');
  print(forward<Tail>(tail)...);
}

// gcc expansion. called automaticall after main.
void __attribute__((destructor)) _d() { flush(); }
} // namespace fastio
using fastio::read;
using fastio::print;
using fastio::flush;

#define INT(...)   \
  int __VA_ARGS__; \
  read(__VA_ARGS__)
#define LL(...)   \
  ll __VA_ARGS__; \
  read(__VA_ARGS__)
#define U32(...)   \
  u32 __VA_ARGS__; \
  read(__VA_ARGS__)
#define U64(...)   \
  u64 __VA_ARGS__; \
  read(__VA_ARGS__)
#define STR(...)      \
  string __VA_ARGS__; \
  read(__VA_ARGS__)
#define CHAR(...)   \
  char __VA_ARGS__; \
  read(__VA_ARGS__)
#define DBL(...)      \
  double __VA_ARGS__; \
  read(__VA_ARGS__)

#define VEC(type, name, size) \
  vector<type> name(size);    \
  read(name)
#define VV(type, name, h, w)                     \
  vector<vector<type>> name(h, vector<type>(w)); \
  read(name)

void YES(bool t = 1) { print(t ? "YES" : "NO"); }
void NO(bool t = 1) { YES(!t); }
void Yes(bool t = 1) { print(t ? "Yes" : "No"); }
void No(bool t = 1) { Yes(!t); }
void yes(bool t = 1) { print(t ? "yes" : "no"); }
void no(bool t = 1) { yes(!t); }
#line 3 "main.cpp"

#line 2 "library/graph/tree.hpp"

#line 2 "library/graph/base.hpp"

template <typename T>
struct Edge {
  int frm, to;
  T cost;
  int id;
};

template <typename T = int, bool directed = false>
struct Graph {
  static constexpr bool is_directed = directed;
  int N, M;
  using cost_type = T;
  using edge_type = Edge<T>;
  vector<edge_type> edges;
  vector<int> indptr;
  vector<edge_type> csr_edges;
  vc<int> vc_deg, vc_indeg, vc_outdeg;
  bool prepared;

  class OutgoingEdges {
  public:
    OutgoingEdges(const Graph* G, int l, int r) : G(G), l(l), r(r) {}

    const edge_type* begin() const {
      if (l == r) { return 0; }
      return &G->csr_edges[l];
    }

    const edge_type* end() const {
      if (l == r) { return 0; }
      return &G->csr_edges[r];
    }

  private:
    const Graph* G;
    int l, r;
  };

  bool is_prepared() { return prepared; }

  Graph() : N(0), M(0), prepared(0) {}
  Graph(int N) : N(N), M(0), prepared(0) {}

  void build(int n) {
    N = n, M = 0;
    prepared = 0;
    edges.clear();
    indptr.clear();
    csr_edges.clear();
    vc_deg.clear();
    vc_indeg.clear();
    vc_outdeg.clear();
  }

  void add(int frm, int to, T cost = 1, int i = -1) {
    assert(!prepared);
    assert(0 <= frm && 0 <= to && to < N);
    if (i == -1) i = M;
    auto e = edge_type({frm, to, cost, i});
    edges.eb(e);
    ++M;
  }

#ifdef FASTIO
  // wt, off
  void read_tree(bool wt = false, int off = 1) { read_graph(N - 1, wt, off); }

  void read_graph(int M, bool wt = false, int off = 1) {
    for (int m = 0; m < M; ++m) {
      INT(a, b);
      a -= off, b -= off;
      if (!wt) {
        add(a, b);
      } else {
        T c;
        read(c);
        add(a, b, c);
      }
    }
    build();
  }
#endif

  void build() {
    assert(!prepared);
    prepared = true;
    indptr.assign(N + 1, 0);
    for (auto&& e: edges) {
      indptr[e.frm + 1]++;
      if (!directed) indptr[e.to + 1]++;
    }
    for (int v = 0; v < N; ++v) { indptr[v + 1] += indptr[v]; }
    auto counter = indptr;
    csr_edges.resize(indptr.back() + 1);
    for (auto&& e: edges) {
      csr_edges[counter[e.frm]++] = e;
      if (!directed)
        csr_edges[counter[e.to]++] = edge_type({e.to, e.frm, e.cost, e.id});
    }
  }

  OutgoingEdges operator[](int v) const {
    assert(prepared);
    return {this, indptr[v], indptr[v + 1]};
  }

  vc<int> deg_array() {
    if (vc_deg.empty()) calc_deg();
    return vc_deg;
  }

  pair<vc<int>, vc<int>> deg_array_inout() {
    if (vc_indeg.empty()) calc_deg_inout();
    return {vc_indeg, vc_outdeg};
  }

  int deg(int v) {
    if (vc_deg.empty()) calc_deg();
    return vc_deg[v];
  }

  int in_deg(int v) {
    if (vc_indeg.empty()) calc_deg_inout();
    return vc_indeg[v];
  }

  int out_deg(int v) {
    if (vc_outdeg.empty()) calc_deg_inout();
    return vc_outdeg[v];
  }

#ifdef FASTIO
  void debug() {
    print("Graph");
    if (!prepared) {
      print("frm to cost id");
      for (auto&& e: edges) print(e.frm, e.to, e.cost, e.id);
    } else {
      print("indptr", indptr);
      print("frm to cost id");
      FOR(v, N) for (auto&& e: (*this)[v]) print(e.frm, e.to, e.cost, e.id);
    }
  }
#endif

  vc<int> new_idx;
  vc<bool> used_e;

  // G における頂点 V[i] が、新しいグラフで i になるようにする
  // {G, es}
  Graph<T, directed> rearrange(vc<int> V, bool keep_eid = 0) {
    if (len(new_idx) != N) new_idx.assign(N, -1);
    int n = len(V);
    FOR(i, n) new_idx[V[i]] = i;
    Graph<T, directed> G(n);
    vc<int> history;
    FOR(i, n) {
      for (auto&& e: (*this)[V[i]]) {
        if (len(used_e) <= e.id) used_e.resize(e.id + 1);
        if (used_e[e.id]) continue;
        int a = e.frm, b = e.to;
        if (new_idx[a] != -1 && new_idx[b] != -1) {
          history.eb(e.id);
          used_e[e.id] = 1;
          int eid = (keep_eid ? e.id : -1);
          G.add(new_idx[a], new_idx[b], e.cost, eid);
        }
      }
    }
    FOR(i, n) new_idx[V[i]] = -1;
    for (auto&& eid: history) used_e[eid] = 0;
    G.build();
    return G;
  }

private:
  void calc_deg() {
    assert(vc_deg.empty());
    vc_deg.resize(N);
    for (auto&& e: edges) vc_deg[e.frm]++, vc_deg[e.to]++;
  }

  void calc_deg_inout() {
    assert(vc_indeg.empty());
    vc_indeg.resize(N);
    vc_outdeg.resize(N);
    for (auto&& e: edges) { vc_indeg[e.to]++, vc_outdeg[e.frm]++; }
  }
};
#line 4 "library/graph/tree.hpp"

// HLD euler tour をとっていろいろ。
template <typename GT>
struct Tree {
  using Graph_type = GT;
  GT &G;
  using WT = typename GT::cost_type;
  int N;
  vector<int> LID, RID, head, V, parent, VtoE;
  vc<int> depth;
  vc<WT> depth_weighted;

  Tree(GT &G, int r = 0, bool hld = 1) : G(G) { build(r, hld); }

  void build(int r = 0, bool hld = 1) {
    if (r == -1) return; // build を遅延したいとき
    N = G.N;
    LID.assign(N, -1), RID.assign(N, -1), head.assign(N, r);
    V.assign(N, -1), parent.assign(N, -1), VtoE.assign(N, -1);
    depth.assign(N, -1), depth_weighted.assign(N, 0);
    assert(G.is_prepared());
    int t1 = 0;
    dfs_sz(r, -1, hld);
    dfs_hld(r, t1);
  }

  void dfs_sz(int v, int p, bool hld) {
    auto &sz = RID;
    parent[v] = p;
    depth[v] = (p == -1 ? 0 : depth[p] + 1);
    sz[v] = 1;
    int l = G.indptr[v], r = G.indptr[v + 1];
    auto &csr = G.csr_edges;
    // 使う辺があれば先頭にする
    for (int i = r - 2; i >= l; --i) {
      if (hld && depth[csr[i + 1].to] == -1) swap(csr[i], csr[i + 1]);
    }
    int hld_sz = 0;
    for (int i = l; i < r; ++i) {
      auto e = csr[i];
      if (depth[e.to] != -1) continue;
      depth_weighted[e.to] = depth_weighted[v] + e.cost;
      VtoE[e.to] = e.id;
      dfs_sz(e.to, v, hld);
      sz[v] += sz[e.to];
      if (hld && chmax(hld_sz, sz[e.to]) && l < i) { swap(csr[l], csr[i]); }
    }
  }

  void dfs_hld(int v, int &times) {
    LID[v] = times++;
    RID[v] += LID[v];
    V[LID[v]] = v;
    bool heavy = true;
    for (auto &&e: G[v]) {
      if (depth[e.to] <= depth[v]) continue;
      head[e.to] = (heavy ? head[v] : e.to);
      heavy = false;
      dfs_hld(e.to, times);
    }
  }

  vc<int> heavy_path_at(int v) {
    vc<int> P = {v};
    while (1) {
      int a = P.back();
      for (auto &&e: G[a]) {
        if (e.to != parent[a] && head[e.to] == v) {
          P.eb(e.to);
          break;
        }
      }
      if (P.back() == a) break;
    }
    return P;
  }

  int heavy_child(int v) {
    int k = LID[v] + 1;
    if (k == N) return -1;
    int w = V[k];
    return (parent[w] == v ? w : -1);
  }

  int e_to_v(int eid) {
    auto e = G.edges[eid];
    return (parent[e.frm] == e.to ? e.frm : e.to);
  }
  int v_to_e(int v) { return VtoE[v]; }

  int ELID(int v) { return 2 * LID[v] - depth[v]; }
  int ERID(int v) { return 2 * RID[v] - depth[v] - 1; }

  // 目標地点へ進む個数が k
  int LA(int v, int k) {
    assert(k <= depth[v]);
    while (1) {
      int u = head[v];
      if (LID[v] - k >= LID[u]) return V[LID[v] - k];
      k -= LID[v] - LID[u] + 1;
      v = parent[u];
    }
  }
  int la(int u, int v) { return LA(u, v); }

  int LCA(int u, int v) {
    for (;; v = parent[head[v]]) {
      if (LID[u] > LID[v]) swap(u, v);
      if (head[u] == head[v]) return u;
    }
  }
  // root を根とした場合の lca
  int LCA_root(int u, int v, int root) {
    return LCA(u, v) ^ LCA(u, root) ^ LCA(v, root);
  }
  int lca(int u, int v) { return LCA(u, v); }
  int lca_root(int u, int v, int root) { return LCA_root(u, v, root); }

  int subtree_size(int v, int root = -1) {
    if (root == -1) return RID[v] - LID[v];
    if (v == root) return N;
    int x = jump(v, root, 1);
    if (in_subtree(v, x)) return RID[v] - LID[v];
    return N - RID[x] + LID[x];
  }

  int dist(int a, int b) {
    int c = LCA(a, b);
    return depth[a] + depth[b] - 2 * depth[c];
  }

  WT dist_weighted(int a, int b) {
    int c = LCA(a, b);
    return depth_weighted[a] + depth_weighted[b] - WT(2) * depth_weighted[c];
  }

  // a is in b
  bool in_subtree(int a, int b) { return LID[b] <= LID[a] && LID[a] < RID[b]; }

  int jump(int a, int b, ll k) {
    if (k == 1) {
      if (a == b) return -1;
      return (in_subtree(b, a) ? LA(b, depth[b] - depth[a] - 1) : parent[a]);
    }
    int c = LCA(a, b);
    int d_ac = depth[a] - depth[c];
    int d_bc = depth[b] - depth[c];
    if (k > d_ac + d_bc) return -1;
    if (k <= d_ac) return LA(a, k);
    return LA(b, d_ac + d_bc - k);
  }

  vc<int> collect_child(int v) {
    vc<int> res;
    for (auto &&e: G[v])
      if (e.to != parent[v]) res.eb(e.to);
    return res;
  }

  vc<int> collect_light(int v) {
    vc<int> res;
    bool skip = true;
    for (auto &&e: G[v])
      if (e.to != parent[v]) {
        if (!skip) res.eb(e.to);
        skip = false;
      }
    return res;
  }

  vc<pair<int, int>> get_path_decomposition(int u, int v, bool edge) {
    // [始点, 終点] の"閉"区間列。
    vc<pair<int, int>> up, down;
    while (1) {
      if (head[u] == head[v]) break;
      if (LID[u] < LID[v]) {
        down.eb(LID[head[v]], LID[v]);
        v = parent[head[v]];
      } else {
        up.eb(LID[u], LID[head[u]]);
        u = parent[head[u]];
      }
    }
    if (LID[u] < LID[v]) down.eb(LID[u] + edge, LID[v]);
    elif (LID[v] + edge <= LID[u]) up.eb(LID[u], LID[v] + edge);
    reverse(all(down));
    up.insert(up.end(), all(down));
    return up;
  }

  vc<int> restore_path(int u, int v) {
    vc<int> P;
    for (auto &&[a, b]: get_path_decomposition(u, v, 0)) {
      if (a <= b) {
        FOR(i, a, b + 1) P.eb(V[i]);
      } else {
        FOR_R(i, b, a + 1) P.eb(V[i]);
      }
    }
    return P;
  }
};
#line 1 "library/ds/bit_vector.hpp"
struct Bit_Vector {
  vc<pair<u32, u32>> dat;
  Bit_Vector(int n) { dat.assign((n + 63) >> 5, {0, 0}); }

  void set(int i) { dat[i >> 5].fi |= u32(1) << (i & 31); }

  void build() {
    FOR(i, len(dat) - 1) dat[i + 1].se = dat[i].se + popcnt(dat[i].fi);
  }

  // [0, k) 内の 1 の個数
  int rank(int k, bool f = 1) {
    auto [a, b] = dat[k >> 5];
    int ret = b + popcnt(a & ((u32(1) << (k & 31)) - 1));
    return (f ? ret : k - ret);
  }
};
#line 2 "library/alg/monoid/add.hpp"

template <typename E>
struct Monoid_Add {
  using X = E;
  using value_type = X;
  static constexpr X op(const X &x, const X &y) noexcept { return x + y; }
  static constexpr X inverse(const X &x) noexcept { return -x; }
  static constexpr X power(const X &x, ll n) noexcept { return X(n) * x; }
  static constexpr X unit() { return X(0); }
  static constexpr bool commute = true;
};
#line 3 "library/ds/wavelet_matrix/wavelet_matrix.hpp"

// 座圧するかどうかを COMPRESS で指定する
// xor 的な使い方をする場合には、コンストラクタで log を渡すこと
template <typename T, bool COMPRESS, typename Monoid = Monoid_Add<T>>
struct Wavelet_Matrix {
  using MX = Monoid;
  using X = typename MX::value_type;
  static_assert(MX::commute);
  int N, lg;
  vector<int> mid;
  vector<Bit_Vector> bv;
  vc<T> key;
  bool set_log;
  vvc<X> cumsum;

  Wavelet_Matrix() {}

  // 和を使わないなら、SUM_data は空でよい
  Wavelet_Matrix(vc<T> A, vc<X> SUM_data = {}, int log = -1) {
    build(A, SUM_data, log);
  }

  void build(vc<T> A, vc<X> SUM_data = {}, int log = -1) {
    N = len(A), lg = log, set_log = (log != -1);
    if (N == 0) {
      lg = 0;
      return;
    }
    bool MAKE_SUM = !(SUM_data.empty());
    vc<X>& S = SUM_data;
    if (COMPRESS) {
      assert(!set_log);
      key.reserve(N);
      vc<int> I = argsort(A);
      for (auto&& i: I) {
        if (key.empty() || key.back() != A[i]) key.eb(A[i]);
        A[i] = len(key) - 1;
      }
      key.shrink_to_fit();
    }
    if (lg == -1) lg = __lg(max<ll>(MAX(A), 1)) + 1;
    mid.resize(lg);
    bv.assign(lg, Bit_Vector(N));
    if (MAKE_SUM) cumsum.assign(1 + lg, vc<X>(N + 1, MX::unit()));
    S.resize(N);
    vc<T> A0(N), A1(N);
    vc<X> S0(N), S1(N);
    FOR_R(d, -1, lg) {
      int p0 = 0, p1 = 0;
      if (MAKE_SUM) {
        FOR(i, N) { cumsum[d + 1][i + 1] = MX::op(cumsum[d + 1][i], S[i]); }
      }
      if (d == -1) break;
      FOR(i, N) {
        bool f = (A[i] >> d & 1);
        if (!f) {
          if (MAKE_SUM) S0[p0] = S[i];
          A0[p0++] = A[i];
        }
        if (f) {
          if (MAKE_SUM) S1[p1] = S[i];
          bv[d].set(i), A1[p1++] = A[i];
        }
      }
      mid[d] = p0;
      bv[d].build();
      swap(A, A0), swap(S, S0);
      FOR(i, p1) A[p0 + i] = A1[i], S[p0 + i] = S1[i];
    }
  }

  // xor した結果で [a, b) に収まるものを数える
  int count(int L, int R, T a, T b, T xor_val = 0) {
    return prefix_count(L, R, b, xor_val) - prefix_count(L, R, a, xor_val);
  }

  int count(vc<pair<int, int>> segments, T a, T b, T xor_val = 0) {
    int res = 0;
    for (auto&& [L, R]: segments) res += count(L, R, a, b, xor_val);
    return res;
  }

  // xor した結果で、[L, R) の中で k>=0 番目と prefix sum
  pair<T, X> kth_value_and_sum(int L, int R, int k, T xor_val = 0) {
    assert(0 <= k && k <= R - L);
    if (L == R) return {infty<T>, MX::unit()};
    if (k == R - L) { return {infty<T>, sum_all(L, R)}; }
    if (xor_val != 0) assert(set_log);
    assert(!cumsum.empty());
    int cnt = 0;
    X sm = MX::unit();
    T ret = 0;
    for (int d = lg - 1; d >= 0; --d) {
      bool f = (xor_val >> d) & 1;
      int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);
      int c = (f ? (R - L) - (r0 - l0) : (r0 - l0));
      if (cnt + c > k) {
        if (!f) L = l0, R = r0;
        if (f) L += mid[d] - l0, R += mid[d] - r0;
      } else {
        X s = (f ? get(d, L + mid[d] - l0, R + mid[d] - r0) : get(d, l0, r0));
        cnt += c, ret |= T(1) << d, sm = MX::op(sm, s);
        if (!f) L += mid[d] - l0, R += mid[d] - r0;
        if (f) L = l0, R = r0;
      }
    }
    sm = MX::op(sm, get(0, L, L + k - cnt));
    if (COMPRESS) ret = key[ret];
    return {ret, sm};
  }

  // xor した結果で、[L, R) の中で k>=0 番目と prefix sum
  pair<T, X> kth_value_and_sum(vc<pair<int, int>> segments, int k,
                               T xor_val = 0) {
    assert(!cumsum.empty());
    if (xor_val != 0) assert(set_log);
    int total_len = 0;
    for (auto&& [L, R]: segments) total_len += R - L;
    assert(0 <= k && k <= total_len);
    if (k == total_len) { return {infty<T>, sum_all(segments)}; }
    int cnt = 0;
    X sm = MX::unit();
    T ret = 0;
    for (int d = lg - 1; d >= 0; --d) {
      bool f = (xor_val >> d) & 1;
      int c = 0;
      for (auto&& [L, R]: segments) {
        int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);
        c += (f ? (R - L) - (r0 - l0) : (r0 - l0));
      }
      if (cnt + c > k) {
        for (auto&& [L, R]: segments) {
          int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);
          if (!f) L = l0, R = r0;
          if (f) L += mid[d] - l0, R += mid[d] - r0;
        }
      } else {
        cnt += c, ret |= T(1) << d;
        for (auto&& [L, R]: segments) {
          int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);
          X s = (f ? get(d, L + mid[d] - l0, R + mid[d] - r0) : get(d, l0, r0));
          sm = MX::op(sm, s);
          if (!f) L += mid[d] - l0, R += mid[d] - r0;
          if (f) L = l0, R = r0;
        }
      }
    }
    for (auto&& [L, R]: segments) {
      int t = min(R - L, k - cnt);
      sm = MX::op(sm, get(0, L, L + t));
      cnt += t;
    }
    if (COMPRESS) ret = key[ret];
    return {ret, sm};
  }

  // xor した結果で、[L, R) の中で k>=0 番目
  T kth(int L, int R, int k, T xor_val = 0) {
    if (xor_val != 0) assert(set_log);
    assert(0 <= k && k < R - L);
    int cnt = 0;
    T ret = 0;
    for (int d = lg - 1; d >= 0; --d) {
      bool f = (xor_val >> d) & 1;
      int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);
      int c = (f ? (R - L) - (r0 - l0) : (r0 - l0));
      if (cnt + c > k) {
        if (!f) L = l0, R = r0;
        if (f) L += mid[d] - l0, R += mid[d] - r0;
      } else {
        cnt += c, ret |= T(1) << d;
        if (!f) L += mid[d] - l0, R += mid[d] - r0;
        if (f) L = l0, R = r0;
      }
    }
    if (COMPRESS) ret = key[ret];
    return ret;
  }

  T kth(vc<pair<int, int>> segments, int k, T xor_val = 0) {
    int total_len = 0;
    for (auto&& [L, R]: segments) total_len += R - L;
    assert(0 <= k && k < total_len);
    int cnt = 0;
    T ret = 0;
    for (int d = lg - 1; d >= 0; --d) {
      bool f = (xor_val >> d) & 1;
      int c = 0;
      for (auto&& [L, R]: segments) {
        int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);
        c += (f ? (R - L) - (r0 - l0) : (r0 - l0));
      }
      if (cnt + c > k) {
        for (auto&& [L, R]: segments) {
          int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);
          if (!f) L = l0, R = r0;
          if (f) L += mid[d] - l0, R += mid[d] - r0;
        }
      } else {
        cnt += c, ret |= T(1) << d;
        for (auto&& [L, R]: segments) {
          int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);
          if (!f) L += mid[d] - l0, R += mid[d] - r0;
          if (f) L = l0, R = r0;
        }
      }
    }
    if (COMPRESS) ret = key[ret];
    return ret;
  }

  // xor した結果で、[L, R) の中で中央値。
  // LOWER = true：下側中央値、false：上側中央値
  T median(bool UPPER, int L, int R, T xor_val = 0) {
    int n = R - L;
    int k = (UPPER ? n / 2 : (n - 1) / 2);
    return kth(L, R, k, xor_val);
  }

  T median(bool UPPER, vc<pair<int, int>> segments, T xor_val = 0) {
    int n = 0;
    for (auto&& [L, R]: segments) n += R - L;
    int k = (UPPER ? n / 2 : (n - 1) / 2);
    return kth(segments, k, xor_val);
  }

  // xor した結果で [k1, k2) 番目であるところの SUM_data の和
  X sum(int L, int R, int k1, int k2, T xor_val = 0) {
    assert(0 <= k1 && k1 <= k2 && k2 <= R - L);
    if (k1 == k2) return MX::unit();
    X add = prefix_sum(L, R, k2, xor_val);
    X sub = prefix_sum(L, R, k1, xor_val);
    return MX::op(add, MX::inverse(sub));
  }

  X sum_all(int L, int R) { return get(lg, L, R); }

  X sum_all(vc<pair<int, int>> segments) {
    X sm = MX::unit();
    for (auto&& [L, R]: segments) { sm = MX::op(sm, get(lg, L, R)); }
    return sm;
  }

  // check(cnt, prefix sum) が true となるような最大の (cnt, sum)
  template <typename F>
  pair<int, X> max_right(F check, int L, int R, T xor_val = 0) {
    assert(check(0, MX::unit()));
    if (xor_val != 0) assert(set_log);
    if (L == R) return {R - L, MX::unit()};
    if (check(R - L, get(lg, L, R))) return {R - L, get(lg, L, R)};
    int cnt = 0;
    X sm = MX::unit();
    for (int d = lg - 1; d >= 0; --d) {
      bool f = (xor_val >> d) & 1;
      int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);
      int c = (f ? (R - L) - (r0 - l0) : (r0 - l0));
      X s = (f ? get(d, L + mid[d] - l0, R + mid[d] - r0) : get(d, l0, r0));
      if (check(cnt + c, MX::op(sm, s))) {
        cnt += c, sm = MX::op(sm, s);
        if (f) L = l0, R = r0;
        if (!f) L += mid[d] - l0, R += mid[d] - r0;
      } else {
        if (!f) L = l0, R = r0;
        if (f) L += mid[d] - l0, R += mid[d] - r0;
      }
    }
    int k = binary_search(
        [&](int k) -> bool {
          return check(cnt + k, MX::op(sm, get(0, L, L + k)));
        },
        0, R - L);
    cnt += k;
    sm = MX::op(sm, get(0, L, L + k));
    return {cnt, sm};
  }

  pair<int, X> prefix_count_and_sum(int L, int R, T x, T xor_val = 0) {
    if (xor_val != 0) assert(set_log);
    x = (COMPRESS ? LB(key, x) : x);
    X sm = MX::unit();
    if (x == 0) return {0, MX::unit()};
    if (x >= (1 << lg)) return {R - L, get(lg, L, R)};
    int cnt = 0;
    FOR_R(d, lg) {
      bool add = (x >> d) & 1;
      bool f = ((xor_val) >> d) & 1;
      int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);
      int kf = (f ? (R - L) - (r0 - l0) : (r0 - l0));
      if (add) {
        X s = (f ? get(d, L + mid[d] - l0, R + mid[d] - r0) : get(d, l0, r0));
        sm = MX::op(sm, s);
        cnt += kf;
        if (f) { L = l0, R = r0; }
        if (!f) { L += mid[d] - l0, R += mid[d] - r0; }
      } else {
        if (!f) L = l0, R = r0;
        if (f) L += mid[d] - l0, R += mid[d] - r0;
      }
    }
    return {cnt, sm};
  }

private:
  inline X get(int d, int L, int R) {
    assert(!cumsum.empty());
    return MX::op(MX::inverse(cumsum[d][L]), cumsum[d][R]);
  }

  // xor した結果で [0, x) に収まるものを数える
  int prefix_count(int L, int R, T x, T xor_val = 0) {
    if (xor_val != 0) assert(set_log);
    x = (COMPRESS ? LB(key, x) : x);
    if (x == 0) return 0;
    if (x >= (1 << lg)) return R - L;
    int cnt = 0;
    FOR_R(d, lg) {
      bool add = (x >> d) & 1;
      bool f = ((xor_val) >> d) & 1;
      int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);
      int kf = (f ? (R - L) - (r0 - l0) : (r0 - l0));
      if (add) {
        cnt += kf;
        if (f) { L = l0, R = r0; }
        if (!f) { L += mid[d] - l0, R += mid[d] - r0; }
      } else {
        if (!f) L = l0, R = r0;
        if (f) L += mid[d] - l0, R += mid[d] - r0;
      }
    }
    return cnt;
  }

  // xor した結果で [0, k) 番目のものの和
  X prefix_sum(int L, int R, int k, T xor_val = 0) {
    return kth_value_and_sum(L, R, k, xor_val).se;
  }

  // xor した結果で [0, k) 番目のものの和
  X prefix_sum(vc<pair<int, int>> segments, int k, T xor_val = 0) {
    return kth_value_and_sum(segments, k, xor_val).se;
  }
};
#line 2 "library/random/base.hpp"

u64 RNG_64() {
  static uint64_t x_
      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(
                     chrono::high_resolution_clock::now().time_since_epoch())
                     .count())
        * 10150724397891781847ULL;
  x_ ^= x_ << 7;
  return x_ ^= x_ >> 9;
}

u64 RNG(u64 lim) { return RNG_64() % lim; }

ll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }
#line 2 "library/mod/modint_common.hpp"

struct has_mod_impl {
  template <class T>
  static auto check(T &&x) -> decltype(x.get_mod(), std::true_type{});
  template <class T>
  static auto check(...) -> std::false_type;
};

template <class T>
class has_mod : public decltype(has_mod_impl::check<T>(std::declval<T>())) {};

template <typename mint>
mint inv(int n) {
  static const int mod = mint::get_mod();
  static vector<mint> dat = {0, 1};
  assert(0 <= n);
  if (n >= mod) n %= mod;
  while (len(dat) <= n) {
    int k = len(dat);
    int q = (mod + k - 1) / k;
    dat.eb(dat[k * q - mod] * mint::raw(q));
  }
  return dat[n];
}

template <typename mint>
mint fact(int n) {
  static const int mod = mint::get_mod();
  assert(0 <= n && n < mod);
  static vector<mint> dat = {1, 1};
  while (len(dat) <= n) dat.eb(dat[len(dat) - 1] * mint::raw(len(dat)));
  return dat[n];
}

template <typename mint>
mint fact_inv(int n) {
  static vector<mint> dat = {1, 1};
  if (n < 0) return mint(0);
  while (len(dat) <= n) dat.eb(dat[len(dat) - 1] * inv<mint>(len(dat)));
  return dat[n];
}

template <class mint, class... Ts>
mint fact_invs(Ts... xs) {
  return (mint(1) * ... * fact_inv<mint>(xs));
}

template <typename mint, class Head, class... Tail>
mint multinomial(Head &&head, Tail &&... tail) {
  return fact<mint>(head) * fact_invs<mint>(std::forward<Tail>(tail)...);
}

template <typename mint>
mint C_dense(int n, int k) {
  static vvc<mint> C;
  static int H = 0, W = 0;
  auto calc = [&](int i, int j) -> mint {
    if (i == 0) return (j == 0 ? mint(1) : mint(0));
    return C[i - 1][j] + (j ? C[i - 1][j - 1] : 0);
  };
  if (W <= k) {
    FOR(i, H) {
      C[i].resize(k + 1);
      FOR(j, W, k + 1) { C[i][j] = calc(i, j); }
    }
    W = k + 1;
  }
  if (H <= n) {
    C.resize(n + 1);
    FOR(i, H, n + 1) {
      C[i].resize(W);
      FOR(j, W) { C[i][j] = calc(i, j); }
    }
    H = n + 1;
  }
  return C[n][k];
}

template <typename mint, bool large = false, bool dense = false>
mint C(ll n, ll k) {
  assert(n >= 0);
  if (k < 0 || n < k) return 0;
  if constexpr (dense) return C_dense<mint>(n, k);
  if constexpr (!large) return multinomial<mint>(n, k, n - k);
  k = min(k, n - k);
  mint x(1);
  FOR(i, k) x *= mint(n - i);
  return x * fact_inv<mint>(k);
}

template <typename mint, bool large = false>
mint C_inv(ll n, ll k) {
  assert(n >= 0);
  assert(0 <= k && k <= n);
  if (!large) return fact_inv<mint>(n) * fact<mint>(k) * fact<mint>(n - k);
  return mint(1) / C<mint, 1>(n, k);
}

// [x^d](1-x)^{-n}
template <typename mint, bool large = false, bool dense = false>
mint C_negative(ll n, ll d) {
  assert(n >= 0);
  if (d < 0) return mint(0);
  if (n == 0) { return (d == 0 ? mint(1) : mint(0)); }
  return C<mint, large, dense>(n + d - 1, d);
}
#line 3 "library/mod/modint.hpp"

template <int mod>
struct modint {
  static constexpr u32 umod = u32(mod);
  static_assert(umod < u32(1) << 31);
  u32 val;

  static modint raw(u32 v) {
    modint x;
    x.val = v;
    return x;
  }
  constexpr modint() : val(0) {}
  constexpr modint(u32 x) : val(x % umod) {}
  constexpr modint(u64 x) : val(x % umod) {}
  constexpr modint(u128 x) : val(x % umod) {}
  constexpr modint(int x) : val((x %= mod) < 0 ? x + mod : x){};
  constexpr modint(ll x) : val((x %= mod) < 0 ? x + mod : x){};
  constexpr modint(i128 x) : val((x %= mod) < 0 ? x + mod : x){};
  bool operator<(const modint &other) const { return val < other.val; }
  modint &operator+=(const modint &p) {
    if ((val += p.val) >= umod) val -= umod;
    return *this;
  }
  modint &operator-=(const modint &p) {
    if ((val += umod - p.val) >= umod) val -= umod;
    return *this;
  }
  modint &operator*=(const modint &p) {
    val = u64(val) * p.val % umod;
    return *this;
  }
  modint &operator/=(const modint &p) {
    *this *= p.inverse();
    return *this;
  }
  modint operator-() const { return modint::raw(val ? mod - val : u32(0)); }
  modint operator+(const modint &p) const { return modint(*this) += p; }
  modint operator-(const modint &p) const { return modint(*this) -= p; }
  modint operator*(const modint &p) const { return modint(*this) *= p; }
  modint operator/(const modint &p) const { return modint(*this) /= p; }
  bool operator==(const modint &p) const { return val == p.val; }
  bool operator!=(const modint &p) const { return val != p.val; }
  modint inverse() const {
    int a = val, b = mod, u = 1, v = 0, t;
    while (b > 0) {
      t = a / b;
      swap(a -= t * b, b), swap(u -= t * v, v);
    }
    return modint(u);
  }
  modint pow(ll n) const {
    assert(n >= 0);
    modint ret(1), mul(val);
    while (n > 0) {
      if (n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }
  static constexpr int get_mod() { return mod; }
  // (n, r), r は 1 の 2^n 乗根
  static constexpr pair<int, int> ntt_info() {
    if (mod == 120586241) return {20, 74066978};
    if (mod == 167772161) return {25, 17};
    if (mod == 469762049) return {26, 30};
    if (mod == 754974721) return {24, 362};
    if (mod == 880803841) return {23, 211};
    if (mod == 943718401) return {22, 663003469};
    if (mod == 998244353) return {23, 31};
    if (mod == 1045430273) return {20, 363};
    if (mod == 1051721729) return {20, 330};
    if (mod == 1053818881) return {20, 2789};
    return {-1, -1};
  }
  static constexpr bool can_ntt() { return ntt_info().fi != -1; }
};

#ifdef FASTIO
template <int mod>
void rd(modint<mod> &x) {
  fastio::rd(x.val);
  x.val %= mod;
  // assert(0 <= x.val && x.val < mod);
}
template <int mod>
void wt(modint<mod> x) {
  fastio::wt(x.val);
}
#endif

using modint107 = modint<1000000007>;
using modint998 = modint<998244353>;
#line 9 "main.cpp"

using mint = modint107;

void solve() {
  LL(N);
  VEC(int, A, N);
  ll mx = MAX(A);
  Graph<int, 0> G(N);
  G.read_tree();
  Tree<decltype(G)> tree(G);

  vc<mint> wt(mx + 1);
  FOR(i, mx + 1) wt[i] = RNG(mint::get_mod());

#if defined(LOCAL)
  wt = {1, 10, 100, 1000, 10000, 100000};
#endif

  vc<int> X(N + N);
  vc<mint> wtX(N + N);

  FOR(v, N) {
    int L = tree.ELID(v);
    int R = tree.ERID(v);
    X[L] = A[v], X[R] = A[v];
    wtX[L] = wt[A[v]];
    wtX[R] = -wt[A[v]];
  }

  Wavelet_Matrix<int, 0, Monoid_Add<mint>> WM(X, wtX);

  auto get = [&](vc<pair<int, int>> S, int x) -> mint {
    // [0,x) の hash
    mint res = 0;
    for (auto& [a, b]: S) {
      auto [cnt, sm] = WM.prefix_count_and_sum(a, b, x);
      res += sm;
    }
    return res;
  };

  LL(Q);
  FOR(Q) {
    LL(a1, b1, a2, b2, k);
    --a1, --b1, --a2, --b2;
    ll c1 = tree.lca(a1, b1), c2 = tree.lca(a2, b2);
    vc<pair<int, int>> S1, S2;
    {
      int a = tree.ELID(c1) + 1, b = tree.ELID(a1) + 1;
      int c = tree.ELID(c1), d = tree.ELID(b1) + 1;
      S1.eb(a, b);
      S1.eb(c, d);
    }
    {
      int a = tree.ELID(c2) + 1, b = tree.ELID(a2) + 1;
      int c = tree.ELID(c2), d = tree.ELID(b2) + 1;
      S2.eb(a, b);
      S2.eb(c, d);
    }

    ll x = 0;
    mint now1 = 0;
    mint now2 = 0;

    vc<mint> ANS;
    FOR(k) {
      // [0,x] の hash が now であることが分かっている
      // (x,y] の hash が 0 でないような c を見つけたい
      ll y = binary_search(
          [&](ll y) -> bool {
            return get(S1, y + 1) - now1 != get(S2, y + 1) - now2;
          },
          mx + 1, x, 0);
      if (y == mx + 1) { break; }
      ANS.eb(y);
      x = y;
      now1 = get(S1, x + 1);
      now2 = get(S2, x + 1);
    }
    print(len(ANS), ANS);
  }
}

signed main() {
  solve();
  return 0;
}