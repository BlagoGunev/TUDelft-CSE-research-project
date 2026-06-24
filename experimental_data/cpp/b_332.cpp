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
typedef pair < ll, ll >pll;
typedef vector < ll >vl;
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
int const N = 2e5 + 16;
int const M = 1e9 + 7;

int n, k;
int law[N];
ll p[N];

void sc(int &x) {
  int c;
  while(!isdigit(c = getchar()));
  x = c-'0';
  while(isdigit(c = getchar()))
    x = (x << 1)+(x << 3)+c-'0';
}

int main() {
  //scanf("%d%d",&n,&k);
  sc(n), sc(k);
  repq(i,1,n) sc(law[i]);//scanf("%d",law+i);
  repq(i,1,k)
    p[1] += law[i];
  repq(i,2,n-k+1)
    p[i] = p[i-1] - law[i-1] + law[i-1+k];
  
  int r = n - k + 1;
  int l = r - k;
  int a = l;
  int b = r;
  ll sum = p[a] + p[b];
  while(--l) {
    if(p[l+k] >= p[r])
      r = l + k;
    ll new_sum = p[l] + p[r];
    if(new_sum >= sum)
      a = l, b = r, sum = new_sum;
  }
  printf("%d %d\n", a, b);
}