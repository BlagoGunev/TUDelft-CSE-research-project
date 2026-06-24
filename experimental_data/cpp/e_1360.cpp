#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using vi = vector<int>;
using pi = pair<int, int>;

#define FAST_IO                     \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL)

bool is_prime(ll x) {
  if (x <= 1) return 0;
  for (ll y = 2; y * y <= x; ++y)
    if (x % y == 0) return 0;
  return 1;
}

using std::gcd;  // Computes the greatest common divisor of the integers m and
                 // n.
using std::lcm;  // Computes the least common multiple of the integers m and n.

int popcnt(uint x) { return __builtin_popcount(x); }
int popcnt(int x) { return __builtin_popcount(x); }
int popcnt(ull x) { return __builtin_popcountll(x); }
int popcnt(ll x) { return __builtin_popcountll(x); }
int bsr(uint x) { return 31 - __builtin_clz(x); }
int bsr(ull x) { return 63 - __builtin_clzll(x); }
int ctz(int x) { return __builtin_ctz(x); }
int ctz(ll x) { return __builtin_ctzll(x); }
int ctz(ull x) { return __builtin_ctzll(x); }

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

#define all(x) x.begin(), x.end()
#define len(x) ll(x.size())

#define SUM(v) accumulate(all(v), 0LL)
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))

#define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))
#define UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end())

ll ceil(ll x, ll y) {
  assert(y >= 1);
  return (x > 0 ? (x + y - 1) / y : x / y);
}

ll floor(ll x, ll y) {
  assert(y >= 1);
  return (x > 0 ? x / y : (x - y + 1) / y);
}

ll mod(ll x, ll y) { return x - y * floor(x, y); }

struct UnionFind {
  int n;
  int n_comp;
  std::vector<int> size, par;
  UnionFind(int n) : n(n), n_comp(n), size(n, 1), par(n) {
    std::iota(par.begin(), par.end(), 0);
  }
  int find(int x) {
    assert(0 <= x && x < n);
    while (par[x] != x) {
      x = par[x] = par[par[x]];
    }
    return x;
  }

  int operator[](int x) { return find(x); }

  bool merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) {
      return false;
    }
    n_comp--;
    if (size[x] < size[y]) std::swap(x, y);
    size[x] += size[y];
    size[y] = 0;
    par[y] = x;
    return true;
  }

  std::vector<int> find_all() {
    std::vector<int> A(n);
    for (int i = 0; i < n; ++i) A[i] = find(i);
    return A;
  }

  void reset() {
    n_comp = n;
    size.assign(n, 1);
    std::iota(par.begin(), par.end(), 0);
  }
};

template <typename T>
std::istream& operator>>(std::istream& is, vc<T>& a) {
  for (auto& e : a) is >> e;
  return is;
}

/**************************** debug utils begin *******************************/

#ifdef OJ_DEBUG
#define LOG std::cerr << "line: " << __LINE__ << ", "
#else
struct NonFunctioningLogger {
 public:
  template <typename T>
  NonFunctioningLogger& operator<<(const T& obj) {
    return *this;
  }
};
NonFunctioningLogger LOG;
#endif  // OJ_DEBUG

#define DEFINE_CONTAINER_PRINTER(CONTAINER_TYPE)                   \
  template <typename T>                                            \
  ostream& operator<<(ostream& ostr, const CONTAINER_TYPE<T>& a) { \
    ostr << "{";                                                   \
    for (auto it = a.begin(); it != a.end(); it++) {               \
      if (it != a.begin()) ostr << ", ";                           \
      ostr << *it;                                                 \
    }                                                              \
    ostr << "}";                                                   \
    return ostr;                                                   \
  }

DEFINE_CONTAINER_PRINTER(std::vector)
DEFINE_CONTAINER_PRINTER(std::deque)
DEFINE_CONTAINER_PRINTER(std::list)
DEFINE_CONTAINER_PRINTER(std::set)
DEFINE_CONTAINER_PRINTER(std::unordered_set)

template <typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& A) {
  os << "(" << A.first << ", " << A.second << ")";
  return os;
}

template <typename T, typename Y>
auto operator<<(std::ostream& os, const std::vector<std::pair<T, Y>>& a)
    -> std::ostream& {
  os << "{";
  int i;
  for (i = 0; i < a.size() - 1; i++) {
    os << "(" << a[i].first << ", " << a[i].second << "), ";
  }
  if (i < a.size()) {
    os << a[i];
  }
  os << "}";
  return os;
}

template <class T, class S>
inline bool chmin(T& a, const S& b) {
  return (a > b ? a = b, 1 : 0);
}

/**************************** debug utils end *******************************/

void dfs(const vc<string>& a, vvc<bool>& f, int& cnt_valid, int i, int j) {
  int n = a.size();
  if (i < 0 || i >= n || j < 0 || j >= n || a[i][j] == '0' || f[i][j]) return;
  f[i][j] = true;
  cnt_valid++;

  vc<int> dx = {-1, 0};
  vc<int> dy = {0, -1};
  for (int k = 0; k < 2; k++) {
    dfs(a, f, cnt_valid, i + dx[k], j + dy[k]);
  }
}

void solve() {
  int n;
  cin >> n;
  vc<string> a(n);
  cin >> a;
  LOG << "n = " << n << ", a = " << a << "\n";
  vvc<bool> f(n, vc<bool>(n, false));
  int cnt_valid{0}, cnt_total{0};

  for (int k = 0; k < n; k++) {
    dfs(a, f, cnt_valid, n - 1, k);
    dfs(a, f, cnt_valid, k, n - 1);
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cnt_total += (a[i][j] == '1');
    }
  }
  LOG << "cnt_valid = " << cnt_valid << ", cnt_total = " << cnt_total << "\n";
  LOG << "f = " << f << "\n";
  cnt_valid == cnt_total ? cout << "YES\n" : cout << "NO\n";
}

int main() {
  FAST_IO;
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}