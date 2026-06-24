#include <cstdlib>
#include <csignal>
#include <csetjmp>
#include <cstdarg>
#include <typeinfo>
#include <typeindex>
#include <type_traits>
#include <bitset>
#include <functional>
#include <utility>
#include <ctime>
#include <chrono>
#include <cstddef>
#include <initializer_list>
#include <tuple>
#include <any>
#include <optional>
#include <variant>
#include <new>
#include <memory>
#include <scoped_allocator>
#include <climits>
#include <cfloat>
#include <cstdint>
#include <cinttypes>
#include <limits>
#include <exception>
#include <stdexcept>
#include <cassert>
#include <system_error>
#include <cerrno>
#include <cctype>
#include <cwctype>
#include <cstring>
#include <cwchar>
#include <string>
#include <string_view>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <iterator>
#include <algorithm>
#include <cmath>
#include <complex>
#include <random>
#include <numeric>
#include <iosfwd>
#include <ios>
#include <istream>
#include <ostream>
#include <iostream>
#include <fstream>
#include <sstream>
#include <strstream>
#include <iomanip>
#include <streambuf>
#include <cstdio>
#include <locale>
#include <clocale>
#include <codecvt>
#include <regex>
#include <atomic>
#include <thread>
#include <mutex>
#include <shared_mutex>
#include <future>
#include <condition_variable>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define nfor(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i, l, r) for (int i = int(l); i < int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(x, y) make_pair((x), (y))
#define x first
#define y second

using namespace std;

typedef long long li;
typedef long double ld;
typedef pair<int, int> pti;

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

template<typename A, typename B> inline ostream& operator<< (ostream& out, const pair<A, B>& p) { return out << "(" << p.x << ", " << p.y << ")"; }
template<typename T> inline ostream& operator<< (ostream& out, const vector<T>& a) { out << "["; forn(i, sz(a)) { if (i) out << ','; out << ' ' << a[i]; } return out << " ]"; }
template<typename T> inline ostream& operator<< (ostream& out, const set<T>& a) { return out << vector<T>(all(a)); }
template<typename X, typename Y> inline ostream& operator<< (ostream& out, const map<X, Y>& a) { return out << vector<pair<X, Y>>(all(a)); }
template<typename T> inline ostream& operator<< (ostream& out, const pair<T*, int>& a) { return out << vector<T>(a.x, a.x + a.y); }

inline ld gett() { return ld(clock()) / CLOCKS_PER_SEC; }

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

#ifdef SU1
//#define GEN
#ifndef GEN
#define LOG
#endif
#endif

const int N = 555;

vector<pair<pti, int>> in;

bool read() {
  int n;
  if (!(cin >> n)) return false;
  in.resize(n);
  forn(i, n) assert(!!(cin >> in[i].x.x >> in[i].x.y >> in[i].y));
  return true;
}

li z[N][N];

void solve() {
  vector<pair<int, pti>> a;
  forn(i, sz(in)) {
    a.pb(mp(in[i].x.y, mp(in[i].x.x, in[i].y)));
  }

  sort(all(a), greater<pair<int, pti>>());

  forn(i, N) forn(j, N) z[i][j] = -INF64;

  forn(i, N) z[0][i] = 0;

  li ans = 0;
  forn(c, sz(a) + 1)
    forn(i, sz(a) + 1) {
      ans = max(ans, z[c][i]);
      if (i == sz(a)) continue;

      z[c][i + 1] = max(z[c][i + 1], z[c][i]);
      z[c + 1][i + 1] = max(z[c + 1][i + 1], z[c][i] + a[i].y.x - a[i].x * 1ll * c);

      li cost = a[i].y.x - a[i].x * 1ll * a[i].y.y;
      if (cost >= 0) {
        z[c][i + 1] = max(z[c][i + 1], z[c][i] + cost);
      }
    }

  cout << ans << endl;
}

int main() {
#ifdef SU1
  assert(freopen("input.txt", "rt", stdin));
  //assert(freopen("output.txt", "wt", stdout));
#endif

  cout << setprecision(10) << fixed;
  cerr << setprecision(5) << fixed;

  while (read()) {
    ld stime = gett();
    solve();
#ifdef SU1
    cerr << "Time: " << gett() - stime << endl;
#endif
    //break;
  }

  return 0;
}