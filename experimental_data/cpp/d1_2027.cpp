#if __INCLUDE_LEVEL__ == 0

#include __BASE_FILE__

void Solve() {
  int n, m;
  IN(n, m);
  vector<int64_t> a(n);
  IN(a);
  vector<int64_t> b(m);
  IN(b);

  vector<int64_t> pref(n + 1);
  for (int i : Rep(0, n)) {
    pref[i + 1] = pref[i] + a[i];
  }

  vector f(n + 1, vector<int64_t>(m + 1, INF64));
  f[0][0] = 0;
  for (int i : Rep(0, n)) {
    for (int j : Rep(0, m)) {
      SetMin(f[i][j + 1], f[i][j]);
      int ni = int(ranges::upper_bound(pref, pref[i] + b[j]) - pref.begin()) - 1;
      if (i < ni) {
        SetMin(f[ni][j], f[i][j] + (m - j - 1));
      }
    }
  }
  int64_t ans = ranges::min(f[n]);
  if (ans == INF64) {
    ans = -1;
  }
  OUT(ans);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  IN(t);
  while (t--) {
    Solve();
  }
}

#elif __INCLUDE_LEVEL__ == 1

#include <bits/stdc++.h>

template <class T> concept Range = std::ranges::range<T> && !std::convertible_to<T, std::string_view>;
template <class T> concept Tuple = std::__is_tuple_like<T>::value && !Range<T>;

namespace std {

istream& operator>>(istream& is, Range auto&& r) {
  for (auto&& e : r) is >> e;
  return is;
}
istream& operator>>(istream& is, Tuple auto&& t) {
  apply([&](auto&... xs) { (is >> ... >> xs); }, t);
  return is;
}

ostream& operator<<(ostream& os, Range auto&& r) {
  auto sep = "";
  for (auto&& e : r) os << exchange(sep, " ") << e;
  return os;
}
ostream& operator<<(ostream& os, Tuple auto&& t) {
  auto sep = "";
  apply([&](auto&... xs) { ((os << exchange(sep, " ") << xs), ...); }, t);
  return os;
}

}  // namespace std

using namespace std;

#define LAMBDA2(x, y, ...) ([&](auto&& x, auto&& y) -> decltype(auto) { return __VA_ARGS__; })
#define Rep(...) [](int l, int r) { return views::iota(min(l, r), r); }(__VA_ARGS__)
#define SetMin(...) LAMBDA2(x, y, y < x && (x = y, 1))(__VA_ARGS__)
#define INF64 (INT64_MAX / 2)
#define IN(...) (cin >> forward_as_tuple(__VA_ARGS__))
#define OUT(...) (cout << forward_as_tuple(__VA_ARGS__) << '\n')

#endif  // __INCLUDE_LEVEL__ == 1