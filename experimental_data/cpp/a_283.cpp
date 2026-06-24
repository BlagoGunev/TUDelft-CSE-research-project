#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
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
FILE *__redirect__ = freopen("in", "r", stdin);
#  include <bits/stdc++.h>
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

#define pb push_back
#define eb pb
//emplace_back
#define mp make_pair

int INF = 1e9;
int const N = 2e5 + 16;
int const M = 1e9 + 7;

template < class t > void sc(t & x) {
  x = 0;
  int c = 0, z = 0, sign = 1;
  while (!isdigit(c = getchar()))
    z = c;
  if (z == '-')
    sign = -1;
  x = c - '0';
  while (isdigit(c = getchar()))
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

int n;
int a[N];
int b[N];

int main() {
  sc(n);
  int len = 1;
  ll sum = 0;
  while(n--) {
    int t; sc(t);
    if(t == 1) {
      int x, y; sc(x), sc(y);
      b[x] += y;
      sum += x*y;
    } else if(t == 2) {
      int x; sc(x);
      a[++len] = x;
      sum += x;
    } else {
      b[len-1] += b[len];
      sum -= a[len] + b[len];
      // zero after yourself :D
      a[len] = b[len] = 0;
      --len;
    }
    
    printf("%.6f\n", sum/double(len));
  }
}