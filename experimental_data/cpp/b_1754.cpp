#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define ll __int128

typedef pair<int, int> pii;

#define gi ({ int _t; scanf("%d", &_t); _t; })
#define gl ({ long long _t; scanf("%lld", &_t); _t; })
#define gd ({ double _t; scanf("%lf", &_t); _t; })
#define gs(p) scanf("%s", p)
#define gf(...) scanf(__VA_ARGS__)

#define pi(n) printf("%d ", n)
#define pl(n) printf("%lld ", n)
#define pd(n) printf("%.3lf ", n)
#define pc(c) printf("%c", c)
#define pf(...) printf(__VA_ARGS__)
#define pn printf("\n")

#ifdef MINE
#define df(...) pf(__VA_ARGS__)
#define dbg(x) cout << #x << " = " << (x) << endl
#else
#define df(...)
#define dbg(x)
#endif

#define ms(p, v) memset(p, v, sizeof(p))
#define forn(i, n) for(int i = 1; i <= n; i++)
#define fora(i, a, b) for(int i = a; i <= b; i++)
#define forb(i, a, b) for(int i = a; i >= b; i--)

const int INF = 1e9;
const int P = 998244353;
const int N = 1e5+5;

void INF_512() {
  int n = gi, m = n / 2 * 2;
  forb (i, m / 2, 1) {
    pi(i), pi(i + m / 2);
  }
  if (n % 2)
    pi(n);
  pn;
}

int main() {
  int t = gi;
  while(t--)
    INF_512();
  return 0;
}