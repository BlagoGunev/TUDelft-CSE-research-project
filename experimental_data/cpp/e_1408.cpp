// Author: Tyler Wang

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstdint>
#include <cstdlib>
#include <deque>
#include <functional>
#include <initializer_list>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <optional>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>
#include <vector>

using namespace std;

template <class C>
constexpr auto ssize(const C& c)
    -> std::common_type_t<std::ptrdiff_t,
                          std::make_signed_t<decltype(c.size())>> {
  using R = std::common_type_t<std::ptrdiff_t,
                               std::make_signed_t<decltype(c.size())>>;
  return (R)c.size();
}

template <class T, std::ptrdiff_t N>
constexpr std::ptrdiff_t ssize(const T (&)[N]) noexcept {
  return N;
}

template <typename T>
constexpr std::enable_if_t<std::is_unsigned_v<T>, bool> has_single_bit(
    T x) noexcept {
  return x != 0 && (x & (x - 1)) == 0;
}

template <typename T>
constexpr std::enable_if_t<std::is_unsigned_v<T>, int> countl_zero(
    T x) noexcept {
  if constexpr (sizeof(T) <= sizeof(unsigned)) {
    return __builtin_clz(x) - (std::numeric_limits<unsigned>::digits -
                               std::numeric_limits<T>::digits);
  } else if constexpr (sizeof(T) <= sizeof(unsigned long)) {
    return __builtin_clzl(x) - (std::numeric_limits<unsigned long>::digits -
                                std::numeric_limits<T>::digits);
  } else {
    static_assert(sizeof(T) <= sizeof(unsigned long long));
    return __builtin_clzll(x) -
           (std::numeric_limits<unsigned long long>::digits -
            std::numeric_limits<T>::digits);
  }
}

template <typename T>
constexpr std::enable_if_t<std::is_unsigned_v<T>, int> countr_zero(
    T x) noexcept {
  if constexpr (sizeof(T) <= sizeof(unsigned)) {
    return __builtin_ctz(x);
  } else if constexpr (sizeof(T) <= sizeof(unsigned long)) {
    return __builtin_ctzl(x);
  } else {
    static_assert(sizeof(T) <= sizeof(unsigned long long));
    return __builtin_ctzll(x);
  }
}

template <typename T>
constexpr std::enable_if_t<std::is_unsigned_v<T>, int> popcount(T x) noexcept {
  if constexpr (sizeof(T) <= sizeof(unsigned)) {
    return __builtin_popcount(x);
  } else if constexpr (sizeof(T) <= sizeof(unsigned long long)) {
    return __builtin_popcountl(x);
  } else {
    static_assert(sizeof(T) <= sizeof(unsigned long long));
    return __builtin_popcountll(x);
  }
}

template <typename T>
constexpr std::enable_if_t<std::is_unsigned_v<T>, T> bit_width(T x) noexcept {
  return (T)(std::numeric_limits<T>::digits - countl_zero(x));
}

template <typename T>
constexpr std::enable_if_t<std::is_unsigned_v<T>, T> bit_ceil(T x) noexcept {
  return (T)(x <= 1 ? 1 : (T)1 << bit_width((T)(x - 1)));
}

template <typename T>
constexpr std::enable_if_t<std::is_unsigned_v<T>, T> bit_floor(T x) noexcept {
  return (T)(x == 0 ? 0 : (T)1 << (bit_width(x) - 1));
}

template <typename Fun>
class y_combinator_result {
 public:
  template <typename T>
  explicit y_combinator_result(T&& fun) : fun_(std::forward<T>(fun)) {}

  template <typename... Args>
  decltype(auto) operator()(Args&&... args) {
    return fun_(std::ref(*this), std::forward<Args>(args)...);
  }

 private:
  Fun fun_;
};

template <typename Fun>
decltype(auto) y_combinator(Fun&& fun) {
  return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::optional<T>& opt);

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const std::pair<T1, T2>& p);

template <typename... Ts>
std::ostream& operator<<(std::ostream& os, const std::tuple<Ts...>& t);

template <typename Container,
          std::enable_if_t<!std::is_convertible_v<Container, std::string_view>,
                           typename Container::const_iterator>* = nullptr>
std::ostream& operator<<(std::ostream& os, const Container& c);

template <typename ContainerAdaptor,
          typename ContainerAdaptor::container_type* = nullptr>
std::ostream& operator<<(std::ostream& os, const ContainerAdaptor& a);

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::optional<T>& opt) {
  return opt ? os << *opt : os << "nullopt";
}

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const std::pair<T1, T2>& p) {
  return os << '{' << p.first << ", " << p.second << '}';
}

template <typename... Ts>
std::ostream& operator<<(std::ostream& os, const std::tuple<Ts...>& t) {
  return std::apply(
      [&os](const Ts&... args) -> std::ostream& {
        os << '{';
        int i = 0;
        ((os << (i++ == 0 ? "" : ", ") << args), ...);
        return os << '}';
      },
      t);
}

template <typename Container,
          std::enable_if_t<!std::is_convertible_v<Container, std::string_view>,
                           typename Container::const_iterator>*>
std::ostream& operator<<(std::ostream& os, const Container& c) {
  os << '{';
  for (auto it = c.begin(); it != c.end(); ++it) {
    os << (it == c.begin() ? "" : ", ") << *it;
  }
  return os << '}';
}

template <typename ContainerAdaptor, typename ContainerAdaptor::container_type*>
std::ostream& operator<<(std::ostream& os, const ContainerAdaptor& a) {
  class derived : public ContainerAdaptor {
   public:
    const auto& c() const { return ContainerAdaptor::c; }
  };
  return os << static_cast<const derived&>(a).c();
}

namespace detail {

template <typename... Ts>
void print(std::ostream& os, int line, std::string_view keys,
           const Ts&... vals) {
  if constexpr (constexpr int N = sizeof...(Ts); N == 0) {
    os << "  " << line << " |" << std::endl;
  } else {
    std::array<std::string_view, N> key_list;
    int k = 0, first = 0, paren = 0;
    for (int i = 0; i < (int)keys.size(); ++i) {
      switch (keys[i]) {
        case '(':
        case '[':
        case '{':
          ++paren;
          break;
        case ')':
        case ']':
        case '}':
          --paren;
          break;
        case ',':
          if (paren == 0) {
            key_list[k++] = keys.substr(first, i - first);
            first = i;
          }
          break;
      }
    }
    assert(k == N - 1);
    key_list[k] = keys.substr(first);
    k = 0;
    os << "  " << line << " | ";
    ((os << key_list[k++] << " = " << vals), ...);
    os << std::endl;
  }
}

}  // namespace detail

#if defined(TYLER) && defined(__clang__)
#define debug(...) \
  detail::print(std::cerr, __LINE__, #__VA_ARGS__, ##__VA_ARGS__)
#elif defined(TYLER) && defined(__GNUC__)
#define debug(...) \
  detail::print(std::cerr, __LINE__, #__VA_ARGS__ __VA_OPT__(, ) __VA_ARGS__)
#else
#define debug(...) ((void)0)
#endif

// Disjoint-set data structure aka union-find data structure.
class disjoint_sets {
 public:
  disjoint_sets(int n) : count_(n), parent_or_size_(n, -1) {}

  int count() const { return count_; }

  int size() const { return (int)parent_or_size_.size(); }

  int size(int x) { return -parent_or_size_[find(x)]; }

  int find(int x) {
    if (parent_or_size_[x] < 0) {
      return x;
    }
    return parent_or_size_[x] = find(parent_or_size_[x]);
  }

  bool merge(int x, int y) {
    if ((x = find(x)) == (y = find(y))) {
      return false;
    }
    if (parent_or_size_[x] > parent_or_size_[y]) {
      std::swap(x, y);
    }
    parent_or_size_[x] += parent_or_size_[y];
    parent_or_size_[y] = x;
    --count_;
    return true;
  }

  std::vector<std::vector<int>> components() {
    std::vector<std::vector<int>> comps(count());
    std::vector<std::vector<int>*> head(size(), nullptr);
    for (int i = 0, k = 0; i < size(); ++i) {
      int p = find(i);
      if (head[p] == nullptr) {
        head[p] = &comps[k++];
        head[p]->reserve(-parent_or_size_[p]);
      }
      head[p]->push_back(i);
    }
    return comps;
  }

  friend std::ostream& operator<<(std::ostream& os, disjoint_sets ds) {
    return os << ds.components();
  }

 private:
  int count_;
  std::vector<int> parent_or_size_;
};

template <typename W>
struct edge {
  int from, to;
  W cost;

  constexpr edge() : from(-1), to(-1), cost() {}

  constexpr edge(int _from, int _to, W _cost)
      : from(_from), to(_to), cost(_cost) {}

  friend constexpr bool operator<(const edge& lhs, const edge& rhs) {
    return lhs.cost < rhs.cost;
  }

  friend std::ostream& operator<<(std::ostream& os, const edge& e) {
    return os << '{' << e.from << ", " << e.to << ", " << e.cost << '}';
  }
};

// Kruskal's minimum spanning tree algorithm. O(E log V).
template <typename W>
std::pair<W, std::vector<int>> min_span_tree(
    int n, const std::vector<edge<W>>& edges) {
  int m = (int)edges.size();
  std::vector<int> ids;
  ids.reserve(m);
  for (int i = 0; i < m; ++i) {
    ids.push_back(i);
  }
  std::sort(ids.begin(), ids.end(),
            [&edges](int lhs, int rhs) { return edges[lhs] < edges[rhs]; });
  disjoint_sets forest(n);
  W weight = 0;
  std::vector<int> keep;
  for (int i : ids) {
    if (forest.merge(edges[i].from, edges[i].to)) {
      weight += edges[i].cost;
      keep.push_back(i);
    }
  }
  return std::pair(weight, keep);
}

int main() {
  auto start_time = std::chrono::steady_clock::now();
  std::mt19937 thanos(
      (std::uint_fast32_t)start_time.time_since_epoch().count());
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.precision(24);
  int m, n;
  cin >> m >> n;
  vector<int> a(m);
  for (int i = 0; i < m; ++i) {
    cin >> a[i];
  }
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  long long sum = 0;
  vector<edge<long long>> edges;
  for (int i = 0; i < m; ++i) {
    int s;
    cin >> s;
    while (s--) {
      int j;
      cin >> j;
      --j;
      edges.emplace_back(i, m + j, -(a[i] + b[j]));
      sum += a[i] + b[j];
    }
  }
  cout << sum + min_span_tree(m + n, edges).first << '\n';
  return 0;
}