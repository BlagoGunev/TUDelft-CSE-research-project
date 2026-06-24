#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define for1(i, n) for(int i = 1; i <= (int)(n); ++i)
#define fore(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define ford1(i, n) for(int i = (int)(n); i>=1; --i)
#define fored(i, a, b) for(int i = (int)(b); i >= (int)(a); --i)
#define sz(v) ((int)((v).size()))
#define all(v) (v).begin(), (v).end()
#define clr(v) memset(v, 0, sizeof(v))
#define clr1(v) memset(v, 0xFF, sizeof(v))
#define mp make_pair
#define pb push_back
#define fi first
#define se second

using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vpi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long i64;
typedef unsigned long long u64;
typedef long double ld;
typedef vector<ld> vld;

template<class T> bool uax(T&a, const T& b) { if( a < b ) { a = b; return true; } return false; }
template<class T> bool uin(T&a, const T& b) { if( a > b ) { a = b; return true; } return false; }

i64 get(i64 n, i64 m) {
  map<i64, i64> M;
  M[n] += 1;
  while (!M.empty()) {
    auto it = M.end();
    auto e = *(--it);
    M.erase(it);
    if (e.fi == m) return e.se;
    if (e.fi <= 1) break;
    if (e.fi & 1) {
      M[(e.fi-1)/2] += e.se * 2;
    } else {
      if (e.fi > 2)
        M[(e.fi-1)/2] += e.se;
      M[(e.fi)/2] += e.se;
    }
  }
  return 0;
}

i64 go(i64 n, i64 cx, i64 k) {
  // cerr << n << ' ' << cx << ' ' << k << '\n';
  if ((n+1)/2 == cx) {
    if (cx == 1 && n == 2 && k == 2) return 1;
    assert(k == 1);
    return (n - 1) / 2;
  }
  assert(n > 1);
  i64 p = (n - 1) / 2, q = (n) / 2;
  i64 k0 = get(p, cx*2) + get(p, cx*2-1); // care cx == 1, 2-class should be x2, but 1-class count x2
  // cerr << p << ' ' << cx << '=' << k0 << '\n';
  if (k0 >= k) return go(p, cx, k);
  return p + 1 + go(q, cx, k - k0);
}

i64 solve(i64 k, i64 n) {
  if (k <= 2) return k == 1 ? 1 : n;
  n -= 2; k -= 2;
  map<i64, i64> M, M2;
  M[n] += 1;
  i64 x;
  while (!M.empty()) {
    auto it = M.end();
    auto e = *(--it);
    M.erase(it);
    M2[e.fi] += e.se;
    if (e.fi <= 1) break;
    if (e.fi & 1) {
      M[(e.fi-1)/2] += e.se * 2;
    } else {
      if (e.fi > 2)
        M[(e.fi-1)/2] += e.se;
      M[(e.fi)/2] += e.se;
    }
  }
  for(auto it = M2.rbegin(); it != M2.rend(); ++it) {
    i64 x = it->fi;
    i64 cx = (x + 1) / 2;
    i64 cy = M2[cx*2] + M2[cx*2-1];
    if (k <= cy) {
      return 2 + go(n, cx, k);
    } else {
      M2[cx*2]=0;
      M2[cx*2-1]=0;
      k -= cy;
    }
  }
  assert(false);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed; cout.precision(15);
  cerr << fixed; cerr.precision(15);
#ifdef HOME
  freopen("input.txt", "r", stdin);
#endif
  if (0) fore(n, 1, 100) {
    cerr << "n = " << n << '\n';
    forn(i, n) cerr << "solve " << solve(1 + i, n) << '\n';
  }
  i64 k, n;
  cin >> n >> k;
  cout << solve(k, n) << '\n';

  return 0;
}