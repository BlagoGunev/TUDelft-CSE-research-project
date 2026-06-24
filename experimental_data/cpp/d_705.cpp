#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long double   ld;
typedef long long     ll;
typedef pair<int,int> pii;
typedef vector<int>   vi;
typedef vector<pii>   vpii;
typedef pair<ll,ll>   pll;
typedef vector<ll>    vl;
typedef vector<pll>   vpll;

#define gc getchar
#define lsb(x) (x&-x)
#define blt(x) __builtin_##x
#define clz blt(clz)
#define ctz blt(ctz)
#define ones blt(popcount)
#define del(x) if(x) delete x

#define rep(i,a,b) for(int i = a; i < b; ++i)
#define repq(i,a,b) for(int i = a; i <= b; ++i)

#define rev(i,a,b) for(int i = a; i >= b; --i)
#define revn(i,a,b) for(int i = a; i > b; --i)

#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define double ld

int INF = 1e9;
double eps = numeric_limits<double>::epsilon();
double PI = acos(-1);
int const N = 1e6 + 16;
int const M = 1e9 + 7;

template<class t> void sc(t&x) {
  int c;//,z=0;
  while(!isdigit(c=gc()));// z = c;
  x = (c-'0');
  while(isdigit(c=gc()))
    x = (x<<1) + (x<<3) + (c-'0');
  //if(z=='-') x = -x;
}

template<class t> void print(t x){
  static char buf[32] = {};
  int i = 32;
  if(x == 0) {
    puts("0");return;
  } else if(x < 0)
    putchar('-'),x=-x;
  while(x) {
    t y = x/10;
    buf[--i] = x-(y<<1)-(y<<3)+'0';
    x = y;
  }
  puts(buf+i);
}

int n, s, e;
int prv[5120], nxt[5120];
ll a[5120],b[5120],c[5120],d[5120],x[5120];

inline ll cost(int i, int j) {
  if(i < j)
    return x[j]-x[i] + d[i] + a[j];
  return x[i]-x[j] + c[i] + b[j];
}

int main() {
  scanf("%d%d%d",&n,&s,&e);
  repq(i,1,n) scanf("%lld",x+i);
  repq(i,1,n) scanf("%lld",a+i);
  repq(i,1,n) scanf("%lld",b+i);
  repq(i,1,n) scanf("%lld",c+i);
  repq(i,1,n) scanf("%lld",d+i);

  nxt[s] = e; 
  prv[e] = s;
  prv[s] = nxt[e] = -1;

  ll tot = cost(s,e);

  repq(i,1,n) {
    if(s == i || i == e) continue;

    int p = s;
    ll c = tot+cost(s,i)+cost(i,nxt[s])-cost(s,nxt[s]);

    for(int j = s; j != e; j = nxt[j]) {
      int l = j, r = nxt[j];

      ll cur = tot+cost(l,i)+cost(i,r)-cost(l,r);

      if(cur < c)
        p = l, c = cur;
    }

    prv[i] = p;
    nxt[i] = nxt[p];
    prv[nxt[i]] = i;
    nxt[prv[i]] = i;
    
    tot = c;
  }

  // ll tot = 0;
  // for(;s != e; s = nxt[s]) {
  //   printf("%d -> ", s, cost(s, nxt[s]));
  //   tot += cost(s, nxt[s]);
  // }

  printf("%lld\n", tot);
}