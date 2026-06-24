// C
#define YYF
#include <algorithm>
#include <bit>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <execution>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <string_view>
#include <vector>
// #define int long long
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define MT \
  int T;   \
  read(T); \
  while (T--)
#ifdef yyfLocal
#define dbg(...) std::cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#define logs(x) std::cerr << (x) << std::endl
#else
#define dbg(...) 42
#define logs(x) 42
#define cerr clog
#endif

using ll = long long;
using ull = unsigned long long;
using pii = std::pair<int, int>;
using tiii = std::tuple<int, int, int>;
using namespace std::string_literals;
using namespace std::string_view_literals;

void dbg_out() { std::cerr << std::endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  std::cerr << " " << H;
  dbg_out(T...);
}

void read() {}
template <typename T, typename... Targs>
void read(T& x, Targs&... args) {
  x = 0;
  bool flag = false;
  char ch = std::cin.get();
  while (!isdigit(ch)) {
    if (ch == '-') flag = true;
    ch = std::cin.get();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = std::cin.get();
  }
  if (flag) x *= -1;
  read(args...);
}

template <typename T>
void qprint(T x) {
  if (x < 0) std::cout.put('-'), x = -x;
  if (x > 9) qprint(x / 10);
  std::cout.put(x % 10 + 48);
}

template <char end = '\n', typename... Targs>
void print(const Targs&... args) {
  ((qprint(args), std::cout.put(' ')), ...);
  std::cout.put(end);
}

#ifdef YYF

void solution() {
  int n, m;
  read(n, m);
  struct Point {
    ll x, w, id;
    Point() {}
    Point(ll x, ll w, int id) : x(x), w(w), id(id) {}
  };
  std::vector<Point> a(m + 1);
  for (int i = 1; i <= m; ++i) read(a[i].x, a[i].w);
  for (int i = 1; i <= m; ++i) a[i].id = i;
  std::sort(a.begin() + 1, a.end(),
            [](const Point& lhs, const Point& rhs) { return lhs.w < rhs.w; });
  std::vector<Point> pos;
  for (int i = 1; i <= 2 * n; ++i) pos.push_back(a[i]);
  ll ans = 0;
  for (int i = 1; i <= 2 * n; ++i) ans += a[i].w;
  std::cout << ans << "\n";
  std::sort(pos.begin(), pos.end(),
            [](const Point& lhs, const Point& rhs) { return lhs.x < rhs.x; });
  for (int i = 0; i < n; ++i)
    std::cout << pos[i].id << " " << pos[int(pos.size()) - i - 1].id << "\n";
  std::cout << "\n";
}

#endif

signed main() {
#ifdef yyfLocal
  logs(std::string_view(__FILE__).substr(
      std::string_view(__FILE__).rfind("\\") + 1));
  freopen("testdata.in", "r", stdin);
  // freopen("testdata.out", "w", stdout);
#endif
#ifndef yyfLocal
  freopen("testdata.log", "w", stderr);
#endif
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  MT solution();
#ifdef yyfLocal
  std::clog << "\ntime: " << std::fixed << std::setprecision(3)
            << clock() * 1000.0 / CLOCKS_PER_SEC << "ms\n";
#endif
}