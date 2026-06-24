#line 1 "/home/maomao90/Documents/IO/Codeforces/2066/B/B.cpp"

// Hallelujah, praise the one who set me free
// Hallelujah, death has lost its grip on me
// You have broken every chain, There's salvation in your name
// Jesus Christ, my living hope
#include <bits/stdc++.h>
using namespace std;

#define REP(i, s, e) for (int i = (s); i < (e); i++)
#define RREP(i, s, e) for (int i = (s); i >= (e); i--)
template <class T> inline bool mnto(T &a, T b) { return b < a ? a = b, 1 : 0; }
template <class T> inline bool mxto(T &a, T b) { return a < b ? a = b, 1 : 0; }

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define FI first
#define SE second
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> iii;
#define ALL(_a) _a.begin(), _a.end()
#define SZ(_a) (int)_a.size()
#define pb push_back
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<iii> viii;

#ifndef DEBUG
#define cerr                                                                   \
  if (0)                                                                       \
  cerr
#endif

const int INF = 1000000005;
const ll LINF = 1000000000000000005ll;
const int MAXN = 500005;

int t;
int n;
int a[MAXN];
int mn[MAXN], occ[MAXN];

int main() {
#ifndef DEBUG
  ios::sync_with_stdio(0), cin.tie(0);
#endif
  cin >> t;
  while (t--) {
    cin >> n;
    REP(i, 0, n + 1) { occ[i] = 0; }
    REP(i, 1, n + 1) { cin >> a[i]; }
    vi b;
    bool first = 1;
    REP(i, 1, n + 1) {
      if (a[i] || first) {
        b.pb(a[i]);
      }
      if (!a[i]) {
        first = 0;
      }
    }
    REP(i, 0, SZ(b)) {
      mn[i] = b[i];
      if (i) {
        mnto(mn[i], mn[i - 1]);
      }
    }
    bool good = 1;
    int mex = 0;
    RREP(i, SZ(b) - 1, 1) {
      if (b[i] <= n) {
        occ[b[i]]++;
      }
      while (occ[mex]) {
        mex++;
      }
      good &= mn[i - 1] >= mex;
    }
    if (good) {
      cout << SZ(b) << '\n';
    } else {
      cout << SZ(b) - 1 << '\n';
    }
  }
  return 0;
}