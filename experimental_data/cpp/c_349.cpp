#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <unistd.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair < int, int >pii;
typedef vector < int >vi;
typedef vector < pii > vpii;
typedef pair < ll, ll > pll;
typedef vector < ll > vl;
typedef vector < pll > vpll;

#ifndef ONLINE_JUDGE
auto __redirect__ = freopen("in", "r", stdin);
#else
#  include <bits/stdc++.h>
#endif

#define lsb(x) (x&-x)
#define del(x) if(x) delete x

#define rep(i,a,b) for(int i = a; i < b; ++i)
#define repq(i,a,b) for(int i = a; i <= b; ++i)

#define rev(i,a,b) for(int i = a; i >= b; --i)
#define revn(i,a,b) for(int i = a; i > b; --i)

#define repc(i,a,cond) for(int i = a; cond; ++i)
#define revc(i,a,cond) for(int i = a; cond; --i)

#define all(x) (x.begin(),x.end())
#define rall(x) (x.rbegin(),x.rend())

int INF = 1e9;
int const N = 1e5 + 16;
int const M = 1e9 + 7;

template < class t > void sc(t & x) {
  x = 0;
  int c;
  t sign = 1;
  while ('0' > (c = getchar()))
    if (c == '-')
      sign = -1;
  x = c - '0';
  while ('0' <= (c = getchar()))
    x = (x << 1) + (x << 3) + c - '0';
  x *= sign;
}

template < class t > void put(t x) {
  static char buf[32] = { };
  if (x == 0) {
    putchar('0');
    return;
  }
  int i = 32;
  if (x < 0)
    putchar('-'), x = -x;
  do
    buf[--i] = x % 10 + '0';
  while (x /= 10);
  while (i < 32)
    putchar(buf[i++]);
}

int a[N];

int main() {
  int n;
  sc(n);
  rep(i,0,n)
    sc(a[i]);
  int mx=0;
  rep(i,0,n)
    mx = max(mx,a[i]);
  int m = n-1;
  ll cnt = 0;
  rep(i,0,n)
    cnt += mx-a[i];
  ll ans = 1e18;
  rep(i,0,n) {
    // excess = a[i] - (cnt - (mx - a[i]));
    ll excess = mx - cnt;
    ans = min(ans, (excess <= 0) ? mx : mx +(excess/m)+(excess%m!=0));
  }
  put(ans);
}