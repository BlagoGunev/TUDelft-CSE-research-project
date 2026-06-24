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

////////////////////////////////////////////////////////////////////////////////
struct ModInt {
  static unsigned M;
  unsigned x;
  ModInt() : x(0U) {}
  ModInt(unsigned x_) : x(x_ % M) {}
  ModInt(unsigned long long x_) : x(x_ % M) {}
  ModInt(int x_) : x(((x_ %= static_cast<int>(M)) < 0) ? (x_ + static_cast<int>(M)) : x_) {}
  ModInt(long long x_) : x(((x_ %= static_cast<long long>(M)) < 0) ? (x_ + static_cast<long long>(M)) : x_) {}
  ModInt &operator+=(const ModInt &a) { x = ((x += a.x) >= M) ? (x - M) : x; return *this; }
  ModInt &operator-=(const ModInt &a) { x = ((x -= a.x) >= M) ? (x + M) : x; return *this; }
  ModInt &operator*=(const ModInt &a) { x = (static_cast<unsigned long long>(x) * a.x) % M; return *this; }
  ModInt &operator/=(const ModInt &a) { return (*this *= a.inv()); }
  ModInt pow(long long e) const {
    if (e < 0) return inv().pow(-e);
    ModInt a = *this, b = 1U; for (; e; e >>= 1) { if (e & 1) b *= a; a *= a; } return b;
  }
  ModInt inv() const {
    unsigned a = M, b = x; int y = 0, z = 1;
    for (; b; ) { const unsigned q = a / b; const unsigned c = a - q * b; a = b; b = c; const int w = y - static_cast<int>(q) * z; y = z; z = w; }
    assert(a == 1U); return ModInt(y);
  }
  ModInt operator+() const { return *this; }
  ModInt operator-() const { ModInt a; a.x = x ? (M - x) : 0U; return a; }
  ModInt operator+(const ModInt &a) const { return (ModInt(*this) += a); }
  ModInt operator-(const ModInt &a) const { return (ModInt(*this) -= a); }
  ModInt operator*(const ModInt &a) const { return (ModInt(*this) *= a); }
  ModInt operator/(const ModInt &a) const { return (ModInt(*this) /= a); }
  template <class T> friend ModInt operator+(T a, const ModInt &b) { return (ModInt(a) += b); }
  template <class T> friend ModInt operator-(T a, const ModInt &b) { return (ModInt(a) -= b); }
  template <class T> friend ModInt operator*(T a, const ModInt &b) { return (ModInt(a) *= b); }
  template <class T> friend ModInt operator/(T a, const ModInt &b) { return (ModInt(a) /= b); }
  explicit operator bool() const { return x; }
  bool operator==(const ModInt &a) const { return (x == a.x); }
  bool operator!=(const ModInt &a) const { return (x != a.x); }
  friend std::ostream &operator<<(std::ostream &os, const ModInt &a) { return os << a.x; }
};
unsigned ModInt::M;
////////////////////////////////////////////////////////////////////////////////

using Mint = ModInt;


int N, K, P;

namespace brute {
Mint dp[410][410][410];
Mint run() {
  memset(dp, 0, sizeof(dp));
  dp[0][0][0] = 1;
  for (int i = 0; i < N; ++i) {
    for (int a = 0; a <= K; ++a) for (int b = 0; b <= a; ++b) if (dp[i][a][b]) {
      for (int k = b; k <= K; ++k) {
        dp[i + 1][k][max(k - a, 0)] += dp[i][a][b];
      }
    }
  }
  Mint ans = 0;
  for (int a = 0; a <= K; ++a) {
    ans += dp[N][a][0];
  }
  return ans;
}
}  // brute

namespace slow {
Mint dp[410][410][410];
Mint run() {
  for (int i = 0; i <= N; ++i) {
    for (int a = 0; a <= K; ++a) for (int b = 0; b <= K; ++b) {
      dp[i][a][b] = 0;
    }
  }
  dp[0][0][0] = 1;
  for (int i = 0; i < N; ++i) {
    for (int a = 0; a <= K; ++a) {
      for (int b = 1; b <= a; ++b) dp[i][a][b] += dp[i][a][b - 1];
      for (int k = 0; k <= K; ++k) {
        dp[i + 1][k][max(k - a, 0)] += dp[i][a][min(a, k)];
      }
    }
  }
  Mint ans = 0;
  for (int a = 0; a <= K; ++a) {
    ans += dp[N][a][0];
  }
  return ans;
}
}  // slow

int main() {
  for (int numCases; ~scanf("%d", &numCases); ) { for (int caseId = 1; caseId <= numCases; ++caseId) {
    scanf("%d%d%d", &N, &K, &P);
    Mint::M = P;
    const Mint ans = slow::run();
    printf("%u\n", ans.x);
  }
#ifndef LOCAL
  break;
#endif
  }
  return 0;
}