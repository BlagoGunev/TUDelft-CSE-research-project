#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define rep(x,y) for(int x=0;x<(y);x++)
inline int in(){
  int x;
  cin >> x;
  return x;
}
const int P=1e9+7;
typedef array<int,5> Hash;
Hash base;
void set_base(){
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  rep(i,5){
    int b=uniform_int_distribution<int>(255,P-1)(rng);
    base[i]=(b%2?b:b-1);
  }
}
inline Hash add(Hash x,Hash y){
  Hash z;
  rep(i,5)z[i]=(x[i]+y[i])%P;
  return z;
}
inline Hash subt(Hash x,Hash y){
  Hash z;
  rep(i,5)z[i]=(x[i]-y[i]+P)%P;
  return z;
}
inline Hash mult(Hash x){
  Hash z;
  rep(i,5)z[i]=(x[i]*1ll*base[i])%P;
  return z;
}
inline int pwr(ll x,ll y){
  int ret=1;
  for(;y;y>>=1,x=(x*1ll*x)%P)
    if(y&1)ret=(ret*1ll*x)%P;
  return ret;
}
const int N=2e5;
int n,a[N+5];
vector<int> g[N+5];
Hash sbt[N+5],hsh[N+5];
void get_subt(int v,int p=-1){
  for(int u:g[v])if(u!=p){
    get_subt(u,v);
    sbt[v]=add(sbt[v],sbt[u]);
  }
  sbt[v]=mult(sbt[v]);
  rep(i,5)sbt[v][i]=(sbt[v][i]+1)%P;
}
void get_hash(int v,int p=-1){
  for(int u:g[v])if(u!=p){
    hsh[u]=add(mult(subt(hsh[v],mult(sbt[u]))),sbt[u]);
    get_hash(u,v);
  }
}
void solve(){
  set_base();
  n=in();
  rep(i,n-1)a[i]=in();
  rep(i,n-1){
    int x=in()-1,y=in()-1;
    g[x].pb(y),g[y].pb(x);
  }
  get_subt(0);
  hsh[0]=sbt[0];
  get_hash(0);
  Hash inp;
  rep(i,5)inp[i]=0;
  rep(i,n-1){
    rep(j,5)inp[j]=(inp[j]+pwr(base[j],a[i]))%P;
  }
  vector<int> ans;
  set<Hash> can_make;
  rep(t,N+5){
    Hash nw=inp;
    rep(j,5)nw[j]=(nw[j]+pwr(base[j],t))%P;
    can_make.insert(nw);
  }
  for(int i=0;i<n;i++)
    if(can_make.count(hsh[i]))
      ans.pb(i+1);
  cout<<int(ans.size())<<"\n";
  for(int i:ans)cout<<i<<" ";
  cout<<"\n";
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T = 1;
  // cin >> T;
  while(T--) solve();
}