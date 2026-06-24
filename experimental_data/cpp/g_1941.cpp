// An AC a day keeps the doctor away.
#pragma GCC optimize("Ofast")
// #include <bits/extc++.h>
#include <bits/stdc++.h>
using namespace std;

/* namespace pbds = __gnu_pbds; */
/* template <typename T> */
/* using rbt = pbds::tree<T, pbds::null_type, less<>, */
/*       pbds::rb_tree_tag, */
/*       pbds::tree_order_statistics_node_update>; */

/*{{{*/
#define all(x) begin(x), end(x)
#ifdef CKISEKI
#include <experimental/iterator>
#define safe cerr<<__PRETTY_FUNCTION__<<" line "<<__LINE__<<" safe\n"
#define debug(a...) debug_(#a, a)
#define orange(a...) orange_(#a, a)
void debug_(auto s, auto ...a) {
  cerr << "\e[1;32m(" << s << ") = (";
  int f = 0;
  (..., (cerr << (f++ ? ", " : "") << a));
  cerr << ")\e[0m\n";
}
void orange_(auto s, auto L, auto R) {
  cerr << "\e[1;33m[ " << s << " ] = [ ";
  using namespace experimental;
  copy(L, R, make_ostream_joiner(cerr, ", "));
  cerr << " ]\e[0m\n";
}
#else
#define safe ((void)0)
#define debug(...) safe
#define orange(...) safe
#endif

template <typename T, T MOD> class Modular {
  public:
    constexpr Modular() : v() {}
    template <typename U> Modular(const U &u) { v = (0 <= u && u < MOD ? u : (u%MOD+MOD)%MOD); }
    template <typename U> explicit operator U() const { return U(v); }
    T operator()() const { return v; }
#define REFOP(type, expr...) Modular &operator type (const Modular &rhs) { return expr, *this; }
    REFOP(+=, v += rhs.v - MOD, v += MOD & (v >> width)) ; REFOP(-=, v -= rhs.v, v += MOD & (v >> width))
    // fits for MOD^2 <= 9e18
    REFOP(*=, v = static_cast<T>(1LL * v * rhs.v % MOD)) ; REFOP(/=, *this *= inverse(rhs.v))
#define VALOP(op) friend Modular operator op (Modular a, const Modular &b) { return a op##= b; }
    VALOP(+) ; VALOP(-) ; VALOP(*) ; VALOP(/)
    Modular operator-() const { return 0 - *this; }
    friend bool operator == (const Modular &lhs, const Modular &rhs) { return lhs.v == rhs.v; }
    friend bool operator != (const Modular &lhs, const Modular &rhs) { return lhs.v != rhs.v; }
    friend std::istream & operator>>(std::istream &I, Modular &m) { T x; I >> x, m = x; return I; }
    friend std::ostream & operator<<(std::ostream &O, const Modular &m) { return O << m.v; }
  private:
    constexpr static int width = sizeof(T) * 8 - 1;
    T v;
    static T inverse(T a) {
      // copy from tourist's template
      T u = 0, v = 1, m = MOD;
      while (a != 0) {
        T t = m / a;
        m -= t * a; std::swap(a, m);
        u -= t * v; std::swap(u, v);
      }
      assert(m == 1);
      return u;
    }
};

using lld = int64_t;
using llf = long double;
template <typename T> using max_heap = std::priority_queue<T,vector<T>,less<T> >;
template <typename T> using min_heap = std::priority_queue<T,vector<T>,greater<T> >;
template <typename V, typename T> int get_pos(const V &v, T x) { return lower_bound(all(v),x) - begin(v); }
template <typename V> void sort_uni(V &v) { sort(all(v)), v.erase(unique(all(v)),end(v)); }
template <typename T> bool chmin(T &x, const T &v) { return v < x ? (x=v, true) : false; }
template <typename T> bool chmax(T &x, const T &v) { return x < v ? (x=v, true) : false; }
constexpr inline lld cdiv(lld x, lld m) { return x/m + (x%m ? (x<0) ^ (m>0) : 0); } // ceiling divide
constexpr inline lld modpow(lld e,lld p,lld m) { lld r=1; for(e%=m;p;p>>=1,e=e*e%m) if(p&1) r=r*e%m; return r; }/*}}}*/

constexpr llf eps = 1e-9;
constexpr lld maxn = 200025, INF = 1e18, mod = 998244353, K = 14699, inf = 1e9;
using Mint = Modular<int, mod>;
Mint modpow(Mint e, uint64_t p) { Mint r = 1; while (p) (p&1) && (r *= e), e *= e, p >>= 1; return r; } // 0^0 = 1

const auto dummy = [] { return cin.tie(nullptr)->sync_with_stdio(false); }();

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> cs;
  vector<array<int, 3>> e(m);
  for (auto &[u, v, c] : e) {
    cin >> u >> v >> c;
    --u, --v;
    cs.push_back(c);
  }
  sort(all(cs));

  vector<int> dis(n + m, -1);
  vector<vector<pair<int,int>>> g(n + m);

  for (auto &[u, v, c] : e) {
    c = get_pos(cs, c) + n;
    g[u].emplace_back(c, 0);
    g[v].emplace_back(c, 0);
    g[c].emplace_back(u, 1);
    g[c].emplace_back(v, 1);
  }

  int S, T;
  cin >> S >> T;
  --S, --T;
  min_heap<pair<int,int>> pq;
  pq.emplace(dis[S] = 0, S);
  while (!pq.empty()) {
    auto [d, i] = pq.top(); pq.pop();
    for (auto [j, c] : g[i])
      if (dis[j] == -1 || dis[j] > dis[i] + c)
        pq.emplace(dis[j] = dis[i] + c, j);
  }
  cout << dis[T] << '\n';
}

signed main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}