//{{{ 
// BEGIN CUT HERE

// END CUT HERE
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

#define rep(i,n) for(int i=0;i<(n);++i)
#define FOR(i,l,h) for(int i=(l);i<=(h);++i)
#define FORD(i,h,l) for(int i=(h);i>=(l);--i)
#define SORT(vec) sort(vec.begin(), vec.end())
#define inpi(x) scanf("%d", &x)
#define inpi2(x,y) scanf("%d%d", &x,&y)
#define inpi3(x,y,z) scanf("%d%d%d", &x,&y,&z)
#define inpi4(x,y,z,w) scanf("%d%d%d%d", &x,&y,&z,&w)
#define inpl(x) scanf("%lld", &x)
#define inpl2(x,y) scanf("%lld%lld", &x,&y)
#define inpl3(x,y,z) scanf("%lld%lld%lld", &x,&y,&z)
#define inpl4(x,y,z,w) scanf("%lld%lld%lld%lld", &x,&y,&z,&w)
#define inpd(x) scanf("%lf", &x)
#define inps(x) scanf("%s", x)

typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<unsigned long long> vull;
typedef vector<string> vs;
typedef vector<double> vd;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef pair<long long,int> pli;
typedef pair<int,long long> pil;

const int mod=1000000007;
ull powmod(ull n, ull k, int m)
{
    ull ret = 1;
    while (k)
    {
        if (k&1)
            ret = ret*n%m;
        n=n*n%m;
        k>>=1;
    }
    return ret;
}

template<int MOD, int RT> struct mint {
    static const int mod = MOD;
    static constexpr mint rt() { return RT; } // primitive root for FFT
    int v; explicit operator int() const { return v; } // explicit -> don't silently convert to int
    mint():v(0) {}
    mint(ll _v) { v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD);
        if (v < 0) v += MOD; }
    bool operator==(const mint& o) const {
        return v == o.v; }
    friend bool operator!=(const mint& a, const mint& b) {
        return !(a == b); }
    friend bool operator<(const mint& a, const mint& b) {
        return a.v < b.v; }

    mint& operator+=(const mint& o) {
        if ((v += o.v) >= MOD) v -= MOD;
        return *this; }
    mint& operator-=(const mint& o) {
        if ((v -= o.v) < 0) v += MOD;
        return *this; }
    mint& operator*=(const mint& o) {
        v = int((ll)v*o.v%MOD); return *this; }
    mint& operator/=(const mint& o) { return (*this) *= inv(o); }
    friend mint fpow(mint a, ll p) {
        mint ans = 1; assert(p >= 0);
        for (; p; p /= 2, a *= a) if (p&1) ans *= a;
        return ans; }
    friend mint inv(const mint& a) { assert(a.v != 0);
        return fpow(a,MOD-2); }

    mint operator-() const { return mint(-v); }
    mint& operator++() { return *this += 1; }
    mint& operator--() { return *this -= 1; }
    friend mint operator+(mint a, const mint& b) { return a += b; }
    friend mint operator-(mint a, const mint& b) { return a -= b; }
    friend mint operator*(mint a, const mint& b) { return a *= b; }
    friend mint operator/(mint a, const mint& b) { return a /= b; }
};

using mii = mint<mod,5>; // 5 is primitive root for both common mods
using mi = mint<mod,5>; // 5 is primitive root for both common mods
//typedef double mi;
 
namespace simp {
  vector<mii> fac,ifac,invn;
  void check(int x) {
    if (fac.empty()) {
      fac={mii(1),mii(1)};
      ifac={mii(1),mii(1)};
      invn={mii(0),mii(1)};
    }
    while (fac.size()<=x) {
      int n = fac.size(), m = fac.size() * 2;
      fac.resize(m);
      ifac.resize(m);
      invn.resize(m);
      for (int i=n;i<m;i++) {
        fac[i]=fac[i-1]*mii(i);
        invn[i]=mii(mod-mod/i)*invn[mod%i];
        ifac[i]=ifac[i-1]*invn[i];
      }
    }
  }
  mii gfac(int x) {
    check(x); return fac[x];
  }
  mii jie(int x) {
    check(x); return fac[x];
  }
  mii ginv(int x) {
    check(x); return invn[x];
  }
  mii gifac(int x) {
    check(x); return ifac[x];
  }
  mii fan(int x) {
    check(x); return ifac[x];
  }
  mii binom(int n,int m) {
    if (m < 0 || m > n) return mii(0);
    return gfac(n)*gifac(m)*gifac(n - m);
  }
  mii C(int n,int m) {
      return binom(n,m);
  }
}

ll _bsmin(ll l, ll r, std::function<bool(ll)> valid)
{
    if (!valid(r))return r+1;
    while (l<r)
    {
        ll mid=(l+r)/2;
        if (valid(mid))
            r=mid;
        else
            l=mid+1;
    }
    return l;
}

int _bsmax(int l, int r, std::function<bool(int)> valid)
{
    if (!valid(l))return l-1;
    while (l<r)
    {
        int mid=(l+r+1)/2;
        if (valid(mid))
            l=mid;
        else
            r=mid-1;
    }
    return l;
}

#define bsmin(l,r,valid) _bsmin(l,r,[&](ll mid){return valid;})
#define bsmax(l,r,valid) _bsmax(l,r,[&](int mid){return valid;})

#define ttt int _t;inpi(_t);while(_t--)
//}}}

const int maxn=100010;

int a[11][maxn];

int cnt[maxn];

int lft[maxn*4], rht[maxn*4], minv[maxn*4], maxv[maxn*4], lz[maxn*4];
int initv[maxn*4];

void build(int n, int l, int r)
{
    lft[n]=l,rht[n]=r;
    if (l==r)
    {
        maxv[n]=minv[n]=initv[l];
        return;
    }
    int mid=(l+r)/2;
    build(n*2, l, mid);
    build(n*2+1, mid+1, r);
    minv[n]=min(minv[n*2], minv[n*2+1]);
    maxv[n]=max(maxv[n*2], maxv[n*2+1]);
}

void upd(int n, int k)
{
    lz[n] += k;
    minv[n] += k;
    maxv[n] += k;
}

void upd(int n, int l, int r, int k)
{
    if (lft[n]==l && rht[n]==r)
    {
        lz[n] += k;
        minv[n] += k;
        maxv[n] += k;
        return;
    }
    if (lz[n])
    {
        upd(n*2, lz[n]);
        upd(n*2+1, lz[n]);
        lz[n]=0;
    }
    int mid=(lft[n]+rht[n])/2;
    if (r<=mid)
        upd(n*2, l,r,k);
    else if (l>mid)
        upd(n*2+1, l,r,k);
    else
    {
        upd(n*2, l,mid,k);
        upd(n*2+1,mid+1,r,k);
    }
    minv[n]=min(minv[n*2], minv[n*2+1]);
    maxv[n]=max(maxv[n*2], maxv[n*2+1]);
}

int getmin(int n, int l, int r)
{
    if (lft[n]==l && rht[n]==r)
        return minv[n];
    if (lz[n])
    {
        upd(n*2, lz[n]);
        upd(n*2+1, lz[n]);
        lz[n]=0;
    }
    int mid=(lft[n]+rht[n])/2;
    if (r<=mid)
        return getmin(n*2, l,r);
    else if (l>mid)
        return getmin(n*2+1, l,r);
    else
        return min(getmin(n*2, l,mid), getmin(n*2+1,mid+1,r));
}
int getmax(int n, int l, int r)
{
    if (lft[n]==l && rht[n]==r)
        return maxv[n];
    if (lz[n])
    {
        upd(n*2, lz[n]);
        upd(n*2+1, lz[n]);
        lz[n]=0;
    }
    int mid=(lft[n]+rht[n])/2;
    if (r<=mid)
        return getmax(n*2, l,r);
    else if (l>mid)
        return getmax(n*2+1, l,r);
    else
        return max(getmax(n*2, l,mid), getmax(n*2+1,mid+1,r));
}
bool valid(int lft, int rht, int m, int k)
{
    int beg=lft-k+1;
    int ed=rht;
    ed=min(ed,m-k+1);
    beg=max(beg,1);
    int sum=0;
    FOR(i,lft,rht)
        sum+=cnt[i];
    return sum<=ed-beg+1;
}

bool valid(int m, int k, int idx)
{
    FOR(len,1,k)
    {
        FOR(beg,idx-len+1,idx)if(beg>=1&&beg+len-1<=m)
        {
            if (!valid(beg, beg+len-1, m, k))
                return false;
        }
    }
    return true;
}

int main()
{
    int n,m,k;
    inpi3(n,m,k);
    vector<pii> vec;
    FOR(i,1,n)
    {
        FOR(j,1,m)
        {
            inpi(a[i][j]);
            vec.pb(mp(a[i][j], j));
        }
    }
    SORT(vec);
    std::reverse(vec.begin(), vec.end());
    ll ans=0;
    int done=0;
    FOR(i,1,m)
        initv[i]=m-i+1;
    build(1,1,m);
    for (const auto& pr : vec)
    {
        cnt[pr.second]++;
        int idx=pr.second;
        bool ok=true;//valid(m, k, pr.second);
        if (ok)
        {
            int mxv=getmax(1,idx,m);
            int miv=(idx==1?m+1:getmin(1,1,idx-1));
            if (mxv-miv>=k-1 || mxv>=m+1 || miv<=done+1)
                ok=false;
        }
        if (ok)
        {
            ans+=pr.first;
            upd(1,idx,m,1);
            //printf("%d %d\n", pr.first, pr.second);
            done++;
            if (done>=m-k+1)
                break;
        }
        else
            cnt[pr.second]--;
    }
    printf("%lld\n", ans);
}