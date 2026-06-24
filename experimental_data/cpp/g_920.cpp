#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

typedef double db;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
typedef unsigned long long ull;

typedef pair < db, db > pdd;
typedef pair < db, ld > pdl;
typedef pair < ld, db > pld;
typedef pair < ld, ld > ldp;

typedef pair < ll, ll > pll;
typedef pair < int, ll > pil;
typedef pair < ll, int > pli;
typedef pair < int, int > pii;

#define F first
#define S second

#define en end()
#define bg begin()

#define rev reverse
#define mp make_pair
#define pb push_back

#define y1 y1234567890
#define um unordered_map

#define all(x) x.bg, x.en
#define sz(x) (int)x.size()

#define sqr(x) ((x) * 1ll * (x))
#define sqrd(x) ((x) * 1.0 * (x))

#define forn(i, n) for (int i = 1; i <= n; i++)

const ll inf = (ll)1e18;
const ll mod = (ll)1e9 + 7;

const db eps = (db)1e-9;
const db pi = acos(-1.0);

const int dx[] = {0, 0, 1, 0, -1};
const int dy[] = {0, 1, 0, -1, 0};

const int N = 1000500;

bool f[1 << 7];
vector < int > pr;
int n, m, lp[N], pw[1 << 7], val[1 << 7];

inline int get(int x) {
 int res = 0;
 for (int mask = 1; mask < (1 << m); mask++) {
  if (f[mask])
   res += x / val[mask];
  else
   res -= x / val[mask];
 }
 return res;
}

int main() {
 //freopen(".in", "r", stdin);
 //freopen(".out", "w", stdout);
 //freopen(".err", "w", stderr);

 //srand(time(NULL));

 //cin.tie(NULL);
 //cout.tie(NULL);
 //ios_base::sync_with_stdio(false);

 //cout << setprecision(10) << fixed;

 val[0] = 1;

 pr.reserve(7);

 for (int i = 1; i < (1 << 7); i++) {
  f[i] = ((__builtin_popcount(i)) & 1);
  if (i > 1)
   pw[i] = pw[i >> 1] + 1;
 }
 
 n = (int)1e6;

 for (int i = 2; i <= n; i += 2)
  lp[i] = 2;

 for (int i = 3; i <= 1000; i += 2)
  if (!lp[i])
   for (int j = i * i; j <= n; j += i + i)
    lp[j] = i;

 for (int i = 3; i <= n; i += 2)
  if (!lp[i])
   lp[i] = i;

 scanf("%d", &n);

 while (n--) {
  int x, p, k;
  scanf("%d %d %d", &x, &p, &k);
  pr.clear();
  while (lp[p] > 1) {
   int cur = lp[p];
   pr.pb(cur);
   while (!(p % cur))
    p /= cur;
  }
  m = sz(pr);
  for (int mask = 1; mask < (1 << m); mask++)
   val[mask] = val[mask ^ (1 << pw[mask])] * pr[pw[mask]];
  int pref = x - get(x);
  int l = x + 1, r = 6539381, ans = -1;
  while (l <= r) {
   int mid = (l + r) >> 1;
   if (mid - get(mid) - pref >= k) {
    ans = mid;
    r = mid - 1;
   }
   else
    l = mid + 1;
  }
  assert(ans != -1);
  printf("%d\n", ans);
 }
 
 //cerr << (clock() + 0.0) / CLOCKS_PER_SEC;

 return 0;
}