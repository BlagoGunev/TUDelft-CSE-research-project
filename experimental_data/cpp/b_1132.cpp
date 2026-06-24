#include <bits/stdc++.h>
using namespace std;
bool Dbg;

typedef double lf;
typedef long long ll;
typedef vector<ll> vll;
typedef double long llf;
typedef vector<int> vint;
typedef pair<ll, ll> pll;
typedef int unsigned uint;
typedef pair<int, int> pii;
typedef long long unsigned ull;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define mid ((l+r)>>1)
#define all(x) (x).begin(), (x).end()
#define dl1(i,b) for(int i = (b); i >= 1; --i)
#define dl0(i,b) for(int i = (b)-1; i >= 0; --i)
#define lo0(i,b) for(int i = 0, i##end = (b); i < i##end; ++i)
#define lo1(i,b) for(int i = 1, i##end = (b); i <= i##end; ++i)
#define lo(i,a,b) for(int i = (a), i##end = (b); i <= i##end; ++i)
#define dl(i,a,b) for(int i = (a), i##end = (b); i >= i##end; --i)
#define debug(...) (Dbg ? void(fprintf(stderr, __VA_ARGS__)) : void())
#define Debug(x) (Dbg ? void(cerr << #x << " = " << x << '\n') : void())
#define trav(it, a) for(__typeof((a).end())it = (a).begin(); it != (a).end(); ++it)
#define dtrav(it, a) for(__typeof((a).rend())it = (a).rbegin(); it != (a).rend(); ++it)
#define IS(x) (x == 10 || x == 13 || x == ' ')
#define inline __attribute__((always_inline))inline
#define OP operator
#define RT return *this
#define TR *this,x;return x;
#define RX x=0;t=P();while((t<'0'||t>'9')&&t!='-')t=P();f=1;\
  if(t=='-')t=P(),f=-1;x=t-'0';for(t=P();t>='0'&&t<='9';t=P())x=x*10+t-'0'
#define RU x=0;t=P();while(t<'0'||t>'9')t=P();x=t-'0';for(t=P();t>='0'&&t<='9';t=P())x=x*10+t-'0'
#define WI if(x){if(x<0)P('-'),x=-x;c=0;while(x)s[c++]=x%10+'0',x/=10;while(c--)P(s[c]);}else P('0')
#define WU if(x){c=0;while(x)s[c++]=x%10+'0',x/=10;while(c--)P(s[c]);}else P('0')
struct Cg {inline int OP()() {return getchar();}}; struct Cp {inline void OP()(int x) {putchar(x);}};
struct Fr {
  int f, t; Cg P;
  Fr &OP, (int &x) {RX; x *= f; RT;} OP int() {int x; TR;} Fr &OP, (ll &x) {RX; x *= f; RT;} OP ll() {ll x; TR;} Fr &OP, (char &x) {for (x = P(); IS(x); x = P()); RT;} OP char() {char x; TR;} Fr &OP, (string &x) {cin >> x; RT;} OP string() {string x; TR;} Fr &OP, (char *x) {char t = P(); for (; IS(t); t = P()); if (~t) {for (; !IS(t) && ~t; t = P()) * x++ = t;} *x++ = 0; RT;} Fr &OP, (lf &x) {scanf("%lf", &x); RT;} OP lf() {lf x; TR;} Fr &OP, (llf &x) {lf y; scanf("%lf", &y); x = y; RT;} OP llf() {llf x; TR;} Fr &OP, (uint &x) {RU; RT;} OP uint() {uint x; TR;} Fr &OP, (ull &x) {RU; RT;} OP ull() {ull x; TR;}
#ifdef __SIZEOF_INT128__
  Fr &OP, (__int128 &x) {RX; x *= f; RT;} OP __int128() {__int128 x; TR;}
  Fr &OP, (__float128 &x) {lf y; scanf("%lf", &y); x = y; RT;} OP __float128() {__float128 x; TR;}
#endif
} in;
struct Fw {
  int c, s[50]; Cp P;
#ifdef __SIZEOF_INT128__
  Fw &OP, (__int128 x) {WI; RT;}
  Fw &OP, (__float128 x) {printf("%.5f", (lf)(x)); RT;}
#endif
  Fw &OP, (int x) {WI; RT;} Fw &OP, (uint x) {WU; RT;} Fw &OP, (ll x) {WI; RT;} Fw &OP, (ull x) {WU; RT;} Fw &OP, (char x) {P(x); RT;}  Fw &OP, (const string &x) {cout << x; RT;} Fw &OP, (const char *x) {while (*x)P(*x++); RT;}
  Fw &OP, (const lf &x) {printf("%.5f", x); RT;} Fw &OP, (const llf &x) {printf("%.5f", lf(x)); RT;}
} out;
inline uint Rand() {static uint x = time(0) ^ (ull)(new char); x ^= (x ^= (x ^= x << 13) >> 17) << 5; return x;}
template<class T> inline T sqr(T x) {return x * x;} template<class T> inline T abs(T x) {return x >= 0 ? x : -x;}
template<class A, class B> inline A max(A a, B b) {return a > b ? a : b;} template<class A, class B> inline A min(A a, B b) {return a < b ? a : b;}
template<class A, class B> inline bool chmax(A &x, B y) {return x < y ? x = y, 1 : 0;} template<class A, class B> inline bool chmin(A &x, B y) {return x > y ? x = y, 1 : 0;}
template<class A, class B> A _gcd(A a, B b) {A t; if (a < b) swap(a, b); if (!b) return a; while ((t = a % b)) a = b, b = t; return b;}
template<class A, class B> inline ll _lcm(A a, B b) {return a / gcd(a, b) * 1ll * b;}
const int N = 1e5 + 7, P = 998244353, inft = 1e9 + 7; const lf eps = 1e-7;  const ll infl = llf(1e18) + 1;
template<class A, class B> ll mul(A a, B b, ll mod) {if (b < 0) b = -b, a = -a; ll ret; for (ret = 0; b; b >>= 1) {if (b & 1) ret = (ret + a) % mod; a = (a + a) % mod;} return (ret + mod) % mod;} template<class A, class B> A Pow1(A a, B b, int mod) {A ret; for (ret = 1; b; b >>= 1) {if (b & 1) ret = ret * 1ll * a % mod; a = a * 1ll * a % mod;} return (ret + mod) % mod;} template<class A, class B> ll Pow(A a, B b, ll mod = P) {assert(b >= 0); a %= mod; if (mod <= 2e9) return Pow1(a, b, mod); ll ret; for (ret = 1; b; b >>= 1) {if (b & 1) ret = mul(ret, a, mod); a = mul(a, a, mod);} return (ret + mod) % mod;}

namespace QvvQ {

void init() {

}
ll a[N * 3], n, m, q[N * 3], pre[N * 3];
void solve() {
  n = in;
  lo1(i, n) in, a[i];
  sort(a + 1, a + 1 + n);
  lo1(i, n) pre[i] = pre[i - 1] + a[i];
  m = in;
  lo1(i, m) in, q[i];
  // ll ans = infl;
  lo1(i, m) {
    out, pre[n] - a[n - q[i] + 1], '\n';
  }
}

}

int main() {
#ifdef QvvQ
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  Dbg = 1;
#endif
  int T = 1;
  while (T--) QvvQ::init(), QvvQ::solve();
#ifdef QvvQ
  fprintf(stderr, "\ntime:%.5fms", clock() * 1000.0 / CLOCKS_PER_SEC);
#endif
  return 0;
}