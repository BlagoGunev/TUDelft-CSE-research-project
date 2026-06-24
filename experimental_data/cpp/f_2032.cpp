/*
  ! 前途似海，来日方长。
  ! Created: 2024/11/01 18:55:18
*/
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
// #define int long long
#define mp(x, y) make_pair(x, y)
#define eb(...) emplace_back(__VA_ARGS__)
#define fro(i, x, y) for (int i = (x); i <= (y); i++)
#define pre(i, x, y) for (int i = (x); i >= (y); i--)
inline void JYFILE19();

using i64 = long long;
using pii = pair<int, int>;

bool ST;
const int N = 1e6 + 10;
const int mod = 998244353;

int n, m;
int a[N], s[N], pw[N];

inline void add(int&x, int y) {
  if ((x += y) >= mod) x -= mod;
}
inline void del(int&x, int y) {
  if ((x -= y) < 0) x += mod;
}

inline void solve() {
  cin >> n;
  fro(i, 1, n) cin >> a[i];
  s[1] = a[1];
  pw[0] = 1;
  fro(i, 1, n) pw[i] = pw[i - 1] * 2 % mod;
  fro(i, 2, n) s[i] = a[i] ^ s[i - 1];
  int all = 0;
  map<int, int> mp;
  map<int, int> pm;
  int ns = 0;
  all = mp[0] = 1;
  fro(i, 1, n) {
    if (a[i] == 1) {
      if (i & 1) {
        add(pm[s[i]], pw[i - 1]);
        if (i == n) ns = pw[i - 1];
      } else {
        add(all, pw[i - 1]);
        add(mp[s[i]], pw[i - 1]);
      }
    } else {
      fro(j, i, n) {
        int num = 0;
        add(num, pm[s[j]]);
        add(num, all);
        del(num, mp[s[j]]);
        ns = (ns + 1ll * num * pw[max(0, n - j - 1)]) % mod;
      }
      break;
    }
  }
  cout << ns << "\n";
}

signed main() {
  JYFILE19();
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}

bool ED;
inline void JYFILE19() {
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);
  srand(random_device{}());
  ios::sync_with_stdio(0), cin.tie(0);
  double MIB = fabs((&ED - &ST) / 1048576.), LIM = 32;
  cerr << "MEMORY: " << MIB << endl, assert(MIB <= LIM);
}