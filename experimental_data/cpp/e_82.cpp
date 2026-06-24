#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
#include <complex>

using namespace std;

#define x1 fiwgiunb
#define x2 viosjosk
#define y1 fnwnfwgw
#define y2 jfowjgon
#define ws osgsogsg
#define free fnibfn


#define dbg(x) cerr << #x << " = " << x << endl
#define deb(x) cerr << #x << " = " << x << endl


#define all(c) (c).begin(),(c).end()
#define pb push_back
#define sz(c) (int)(c).size()          
#define mp make_pair
#define forn(i,n) for(int i=0;i<(int)n;++i)
#define ford(i,n) for(int i=(int)n;i>=0;--i)
#define X first
#define Y second
#define bits(x) __builtin_popcount(x)



typedef long long int64;
typedef long long ll;
typedef long double ld;


const int N = 2000;
int n,h,f;
int l[N],r[N];

pair<ld,ld>p[N];

inline void add(ld l, ld r, int & sz)
{
  p[sz++]=mp(min(l,r),max(l,r));
}

ld ar(ld w)
{
  int sz=0;
  forn(i,n)
  {
    add(l[i]*(f-w)/(ld)(f-h),r[i]*(f-w)/(ld)(f-h),sz);
    add(l[i]*(f+w)/(ld)(f-h),r[i]*(f+w)/(ld)(f-h),sz);
  }
  sort(p,p+sz);  
  ld ans=0, l=-(1<<30), r=-(1<<30);
  forn(i,sz)
  {
    if (p[i].X < r)
      r=max(p[i].Y,r);
    else
    {
      ans = ans+ r - l;
      l = p[i].X;
      r = p[i].Y;
    }
  }
  ans = ans + r - l;
  return ans;
}


int main()
{
  cin >> n >> h >> f;
  forn(i,n)
    cin >> l[i] >> r[i];

  int parts = 5000;
  ld area=0;
  forn(i,parts)
  {
    ld q = h*(2*i+1)/(ld)(2*parts);
    area += ar(q) * h/(ld)parts;
  }
  printf("%.20lf\n",(double)(2*area));
  return 0;
}