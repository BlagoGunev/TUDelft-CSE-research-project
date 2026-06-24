// Author: XZC(L_Wave)
// Language: Cpp/G++14
// Problem: F. Digital Patterns
// Contest: Codeforces - Codeforces Round 924 (Div. 2)
// URL: https://codeforces.com/contest/1928/problem/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Create Time: not 2024-02-11 21:34:21, but 1926-08-17 11:45:14
// ABRACADABRA!!!
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("Ofast","inline")
#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a), i##ABRACADABRA = (b); i <= i##ABRACADABRA; i++)
#define drep(i, a, b) for (int i = (a), i##ABRACADABRA = (b); i >= i##ABRACADABRA; i--)
using namespace std;
using ll = long long;
constexpr int N=300010;

#define S0(t) (1ll)
#define S1(t) (t)
#define S2(t) (1ll*t*(t+1)/2)
#define S3(t) (1ll*t*(t+1)*(1-t)/6)
// inline ll S0(ll t){return 1;}
// inline ll S1(ll t){return t;} // *1
// inline ll S2(ll t){return t*(t+1)/2;} // *n
// inline ll S3(ll t){return t*(t+1)*(1-t)/6;} // *1

struct segtree{
  int L[N<<2],R[N<<2];
  ll s[N<<2][4];
  void up(int p){
    rep(i,0,3)s[p][i]=s[p<<1][i]+s[p<<1|1][i];
  }
  void bld(int p,int l,int r){
    L[p]=l,R[p]=r;
    if (l==r)return ;
    int mid=(l+r)>>1;
    bld(p<<1,l,mid);
    bld(p<<1|1,mid+1,r);
  }
  void add(int p,int o,int x){
    if (L[p]==R[p]){
      s[p][0]+=x*S0(L[p]);
      s[p][1]+=x*S1(L[p]);
      s[p][2]+=x*S2(L[p]);
      s[p][3]+=x*S3(L[p]);
      return ;
    }
    int mid=(L[p]+R[p])>>1;
    if (o<=mid)add(p<<1,o,x);
    else add(p<<1|1,o,x);
    up(p);
  }
  ll ask(int p,int l,int r,int q){
    if (l<=L[p]&&R[p]<=r)return s[p][q];
    if (L[p]>r||R[p]<l)return 0;
    return ask(p<<1,l,r,q)+ask(p<<1|1,l,r,q);
  }
} A,B;

int n,m,q;
ll a[N],b[N],res;
set<int>as,bs;
void chg_a(int o,ll x){
  // assert(o>=1);
  // cout<<"chg_a "<<o<<' '<<x<<'\n';
  res+=x*(S1(o)*B.ask(1,1,o,2)+S0(o)*B.ask(1,1,o,3));
  res+=x*(S2(o)*B.ask(1,o+1,m,1)+S3(o)*B.ask(1,o+1,m,0));
  A.add(1,o,x);
}
void chg_b(int o,ll x){
  // assert(o>=1);
  // cout<<"chg_b "<<o<<' '<<x<<'\n';
  res+=x*(S1(o)*A.ask(1,1,o,2)+S0(o)*A.ask(1,1,o,3));
  res+=x*(S2(o)*A.ask(1,o+1,n,1)+S3(o)*A.ask(1,o+1,n,0));
  B.add(1,o,x);
}
void icut_a(int o){
  if (o==n+1||o==1)return ;
  // cout<<"icut_a "<<o<<'\n';
  ll pre=*--as.lower_bound(o),nxt=*as.upper_bound(o);
  as.insert(o);
  chg_a(nxt-pre,-1);
  chg_a(nxt-o,1);
  chg_a(o-pre,1);
}
void icut_b(int o){
  if (o==m+1||o==1)return ;
 // cout<<"icut_b "<<o<<'\n';
  ll pre=*--bs.lower_bound(o),nxt=*bs.upper_bound(o);
  bs.insert(o);
  chg_b(nxt-pre,-1);
  chg_b(nxt-o,1);
  chg_b(o-pre,1);
}
void dcut_a(int o){
  if (o==n+1||o==1)return ;
  // cout<<"dcut_a "<<o<<'\n';
  as.erase(o);
  ll pre=*--as.lower_bound(o),nxt=*as.upper_bound(o);
  chg_a(nxt-pre,1);
  chg_a(nxt-o,-1);
  chg_a(o-pre,-1);
}
void dcut_b(int o){
  if (o==m+1||o==1)return ;
  // cout<<"dcut_b "<<o<<'\n';
  bs.erase(o);
  ll pre=*--bs.lower_bound(o),nxt=*bs.upper_bound(o);
  chg_b(nxt-pre,1);
  chg_b(nxt-o,-1);
  chg_b(o-pre,-1);
}
void add_a(int o,ll x){
  // cout<<"add_a "<<o<<' '<<x<<'\n';
  if (!a[o])dcut_a(o);
  a[o]+=x;
  if (!a[o])icut_a(o);
}
void add_b(int o,ll x){
  // cout<<"add_b "<<o<<' '<<x<<'\n';
  if (!b[o])dcut_b(o);
  b[o]+=x;
  if (!b[o])icut_b(o);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0),cout.tie(0);
  cin>>n>>m>>q;
  rep(i,1,n)cin>>a[i];
  rep(i,1,m)cin>>b[i];
  drep(i,n+1,1)a[i]-=a[i-1];
  drep(i,m+1,1)b[i]-=b[i-1];
  A.bld(1,1,n);
  B.bld(1,1,m);
  chg_a(n,1);
  chg_b(m,1);
  // 割点 x 时，是 x-1][x 这样的关系
  // [l,r)
  as.insert(1);
  as.insert(n+1);
  bs.insert(1);
  bs.insert(m+1);
  // cout<<"$$$$ CHECK res="<<res<<'\n';
  rep(i,1,n)if (!a[i])icut_a(i);
  rep(i,1,m)if (!b[i])icut_b(i);
  cout<<res<<'\n';
  while (q--){
    int o,l,r;
    ll x;
    cin>>o>>l>>r>>x;
    if (o==1)add_a(l,x),add_a(r+1,-x);
    else add_b(l,x),add_b(r+1,-x);
    cout<<res<<'\n';
  }
  return 0;
}