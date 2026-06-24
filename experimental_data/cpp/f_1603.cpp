#pragma gcc optimize(3)
#include <cstdint>
#include <limits>
#include <cmath>
#include <numeric>
namespace fmath {
template <typename T> struct ring_traits {
  static T multiple(const T &a, const T &b) { return a * b; }
  static T plus(const T &a, const T &b) { return a + b; }
  static T identity_element() { return 1; }
  static T zero_element() { return 0; }
  static T oppsite(const T &a) { return -a; }
  static bool equal(const T &a, const T &b) { return a == b; }
};
template <> struct ring_traits<double> {
  static double multiple(double a, double b) { return a * b; }
  static double plus(double a, double b) { return a + b; }
  static double identity_element() { return 1.0; }
  static double zero_element() { return 0.0; }
  static double oppsite(double a) { return -a; }
  static bool equal(double a, double b) { return std::abs(a - b) <= 1e-8; }
};
template <typename T, typename traits = ring_traits<T>>
T power(T a, std::int64_t p) {
  T r = traits::identity_element();
  while (p) {
    if (p & 1)
      r = traits::multiple(r, a);
    a = traits::multiple(a, a);
    p >>= 1;
  }
  return r;
}
template <typename T> struct field_traits : public ring_traits<T> {
  static T inv(const T &a) { return ring_traits<T>::identity_element() / a; }
};
template <typename T, T mods> struct __covsys_ring_traits {
  static T multiple(const T &a, const T &b) { return a * b % mods; }
  static T plus(const T &a, const T &b) {
    return (a + b >= mods ? a + b - mods : a + b);
  }
  static T identity_element() { return 1; }
  static T zero_element() { return 0; }
  static T oppsite(const T &a) { return mods - a; }
  static bool equal(const T &a, const T &b) { return a == b; }
};
template <typename T, T mods>
struct covsys_tratis : __covsys_ring_traits<T, mods> {
  static T inv(const T &a) {
    return power<T, __covsys_ring_traits<T, mods>>(a, mods - 2);
  }
};
template <std::int64_t mods> using int64_covsys = covsys_tratis<int64_t, mods>;
using covsys_ntt = int64_covsys<998244353>;
using covsys1e9_7 = int64_covsys<1000000007>;
} // namespace fmath
#define _FMATH_DEF

#define _FMATH_DEF
#ifndef _FMATH_DEF
#include "math.hpp"
#endif
#include <vector>
namespace fmath {
  template<typename Int, typename traits>
  struct combinatoric {
    struct factorials {
      std::vector<Int> f;
      factorials(int n = 0) : f(n + 1) {
        f[0] = traits::identity_element();
        for (int i = 1; i <= n; ++i)
          f[i] = traits::multiple(f[i - 1], Int(i));
      }
      void resize(int n) {*this = factorials(n);}
      Int operator()(int n) {return f[n];}
      Int operator[](int n) {return f[n];}
    };
    struct invfactorials {
      std::vector<Int> f;
      invfactorials() = default;
      invfactorials(const factorials& fact) {
        f.resize(fact.f.size());
        f.back() = traits::inv(fact.f.back());
        for (int i = f.size() - 1; i; --i)
          f[i - 1] = traits::multiple(f[i], Int(i));
      }
      Int operator()(int n) {return f[n];}
      Int operator[](int n) {return f[n];}
    };
    struct binomals {
      factorials fact;
      invfactorials invfact;
      binomals(int n = 0) : fact(n), invfact(n) {}
      Int operator()(int n, int m) {
        if (m > n)
          return traits::zero_element();
        return traits::multiple(fact(n), traits::multiple(invfact(n - m), invfact(m)));
      }
    };
  };
  template<std::int64_t mod>
  using comb = combinatoric<std::int64_t, int64_covsys<mod>>;
  using comb1e9_7 = combinatoric<std::int64_t, covsys1e9_7>;
  using comb_ntt = combinatoric<std::int64_t, covsys_ntt>;
}
#include <iostream>
using namespace std;
constexpr int maxk = 1e7 + 4;
using inte = int64_t;
using cov = fmath::covsys_ntt;
int pow2[maxk];
int ps[maxk];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  pow2[0] = 1;
  for (int i = 1; i < maxk; ++i)
    pow2[i] = cov::multiple(pow2[i - 1], 2);
  while (T --> 0) {
    int n, k, x;
    cin >> n >> k >> x;
    if (x == 0) {
      if (n > k) {
        cout << 0 << '\n';
      } else {
        inte ans = 1;
        for (int i = 0; i < n; ++i) {
          ans = cov::multiple(ans, cov::plus(pow2[k], cov::oppsite(pow2[i])));
        }
        cout << ans << '\n';
      }
    } else {
      ps[k] = 1;
      for (int i = k - 1; i; --i) {
        ps[i] = cov::multiple(ps[i + 1], cov::plus(pow2[i], 998244352));
        ps[i + 1] = cov::multiple(ps[i + 1], pow2[i]);
      }
      inte ans = 0;
      const inte basp = fmath::power<inte, cov>(2, n);
      inte pasf = 1;
      for (int i = 0; i < k; ++i) {
        const inte cases = cov::multiple(pasf, ps[i + 1]);
        if ((k - i - 1) & 1) {
          ans = cov::plus(ans, cov::oppsite(cases));
        } else {
          ans = cov::plus(ans, cases);
        }
        pasf = cov::multiple(pasf, basp);
      }
      cout << ans << '\n';
    }
  }
  return 0;
}