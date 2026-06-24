#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
 
using namespace std;

#ifndef ONLINE_JUDGE
#define DEBUG
#endif

#define oo 0x3F3F3F3F
#ifdef DEBUG
#define cvar(x) cerr << "[" << #x << ": " << x << "]"
#define evar(x) cvar (x) << endl
template<class T> void DISP (const char *s, T x, int n) {cerr << "[" << s << ": "; for (int i = 0; i < n; ++i) cerr << x[i] << " "; cerr << "]" << endl;}
#define disp(x,n) DISP (#x " to " #n, x, n)
#else
#define cvar(...) ({})
#define evar(...) ({})
#define disp(...) ({})
#endif
#ifdef WIN32
#define fmt64 "%I64d"
#else
#define fmt64 "%lld"
#endif
#define foreach(i, x) for (__typeof__((x).begin ()) i = (x).begin (); i != (x).end (); ++i)
#define MKP make_pair
#define Px first
#define Py second
#define PB push_back

typedef unsigned int uint;
typedef long long int64;
typedef unsigned long long uint64;
typedef vector<int> VI;
typedef map<int, int> MII;
typedef set<int> SI;

int64 fpm (int64 b, int64 e, int64 m) { int64 t = 1; for (; e; e >>= 1, b = b * b % m) e & 1 ? t = t * b % m : 0; return t; }
template<class T> inline bool chkmin (T &a, T b) {return a < b ? a = b, true : false;}
template<class T> inline bool chkmax (T &a, T b) {return a > b ? a = b, true : false;}
template<class T> inline T sqr (T x) {return x * x;}

template<class edge> struct Graph
{
  vector<vector<edge> > adj;
  Graph (int n) {adj.clear (); adj.resize (n + 5);}
  void adde (int s, edge e){adj[s].push_back (e);}
  typename vector<edge>::iterator operator [] (int t) {return adj[t].begin ();}
};

const int maxn = 220000;

int a[maxn], b[maxn], Q[maxn], ans[maxn];

int count (int n, int *a)
{
  int ret = 0;
  for (int i = 1; i <= n; ++i)
    ret += a[i] == 1 && a[i - 1] == 0;
  return ret;
}

int main ()
{
  freopen ("input.txt" , "r", stdin);
  freopen ("output.txt", "w", stdout);
  ios_base::sync_with_stdio (false);

  int n, m, k;
  
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> a[i];
  cin >> m;
  for (int j = 1; j <= m; ++j)
    cin >> b[j];
  int A = count (n, a), B = count (m, b);

  bool swaped = false;
  if (B < A || (B == A && a[1] == 0 && b[1] == 1))
    {
      for (int i = 1; i <= n || i <= m; ++i)
        swap (a[i], b[i]);
      swap (n, m);
      swaped = true;
      // cerr << "swaped" << endl;
    }

  // insert A to B
  k = 0;
  for (int i = 1, j = 1; j <= m + 1; ++j)
    {
      for (; i <= n && (j > m || a[i] == b[j]); ++i)
        cout << (swaped ? i + m : i) << " ", Q[++k] = a[i];
      if (j <= m)
        cout << (swaped ? j : (j + n)) << " ", Q[++k] = b[j];
    }
  cout << endl;

  n += m, k = 0;
  for (int i = 1; i <= n; )
    {
      for (; i <= n && !Q[i]; ++i);
      if (i > n) break;
      if (i != 1) ans[++k] = i - 1;
      for (; i <= n && Q[i]; ++i);
      ans[++k] = i - 1;
    }

  cout << k << endl;
  for (int i = 1; i <= k; ++i)
    cout << ans[i] << " ";
  cout << endl;
  return 0; 
}