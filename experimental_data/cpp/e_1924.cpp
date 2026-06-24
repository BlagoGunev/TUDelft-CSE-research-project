#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <bitset>
#include <functional>
#include <utility>
#include <cmath>
#include <string>
#include <deque>
#include <cstring>
#include <ctime>
#include <random>
#include <chrono>
#include <climits>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
//#include <windows.h>
#include <complex>
#pragma GCC optimize("fast-math")
using namespace std;
using namespace __gnu_pbds;
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define lsb(x) ((x) & (-x))
#define msb(x) ((x) == 0 ? 0 : (1 << (64 - __builtin_clzll(x) - 1)))
#define DX return cout<<ans[0],void();
#define XD return cout<<ans[1],void();
#define bleacs(x) return cout<<x<<'\n',void();
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
mt19937_64 rng(chrono :: steady_clock :: now().time_since_epoch().count());
const size_t fixed_random = rng();
clock_t start_time = clock(), end_time;
ll random_seed(ll modulo){return rng() % modulo;}
template <typename T>inline void hash_combine(size_t& seed, const T& value){seed ^= hash<T> {}(value) + 0x9e3779b9 + (seed << 6) + (seed >> 2);}
struct pair_hash{template <typename T1, typename T2>size_t operator () (const pair<T1, T2>& p) const{size_t seed = fixed_random;hash_combine(seed, p.first);hash_combine(seed, p.second);return seed;}};
struct normal_hash{template <typename T>size_t operator () (const T& p) const{size_t seed = fixed_random;hash_combine(seed, p);return seed;};};
template<typename T,typename V>istream& operator>>(istream&in,pair<T,V>&a){in>>a.first>>a.second;return in;}
template<typename T,typename V>ostream& operator<<(ostream&out,const pair<T,V>&a){out<<a.first<<' '<<a.second;return out;}
template<typename T>istream& operator>>(istream&in,vector<T> &a){for(auto &x:a)cin>>x;return in;}
template<typename T>ostream& operator<<(ostream&out,const vector<T>&a){for(T x:a)out<<x<<' ';return out;}
template<typename T,typename V,typename X,typename Z> pair<T,V>operator+(const pair<T,V> &a,const pair<X,Z>&b){return {a.first+b.first,a.second+b.second};}
template<typename T,typename V,typename X,typename Z> pair<T,V>operator-(const pair<T,V> &a,const pair<X,Z>&b){return {a.first-b.first,a.second-b.second};}
ll mod=1e9+7;
ll inf=3*1e15;
ll fastexp(ll b,ll e,ll mod=mod){
  ll rez=1;
  while(e)
  {
    if(e&1)rez=rez*b%mod;
    b=b*b%mod;
    e>>=1;
  }
  return rez;
}
class mint{
public:
  ll v;
  mint(const ll&x=0){v=x;if(v>=2*mod||v<-mod)v=v%mod;if(v<0)v+=mod;if(v>=mod)v-=mod;}
  mint operator-()const{return v==0?0:mod-v;}
  mint inv()const{return fastexp(v,mod-2);}
  friend mint operator+(const mint&a,const mint&b){return a.v+b.v;}
  friend mint operator-(const mint&a,const mint&b){return a.v+(-b);}
  friend mint operator*(const mint&a,const mint&b){return a.v*b.v;}
  friend mint operator/(const mint&a,const mint&b){return a.v*b.inv().v;}
  friend mint operator+=(mint&a,const mint&b){return a=a+b;}
  friend mint operator-=(mint&a,const mint&b){return a=a-b;}
  friend mint operator*=(mint&a,const mint&b){return a=a*b;}
  friend mint operator/=(mint&a,const mint&b){return a=a/b;}
  friend bool operator==(const mint&a,const mint&b){return a.v==b.v;}
  friend bool operator==(const mint&a,const ll&b){return a==mint(b);}
  friend bool operator==(const ll&a,const mint&b){return mint(a)==b;}
  friend istream&operator>>(istream&in,mint&a){ll x;in>>x;a=x;return in;}
  friend ostream&operator<<(ostream&out,const mint&a){out<<a.v;return out;}
};
class frac{
public:
  ll p,q;
  frac(const ll &x=0,const ll&y=1){ll d=gcd(abs(x),abs(y));p=x/d,q=y/d;if(q<0)p=-p,q=-q;}
  frac operator-()const{return frac(-p,q);}
  frac inv()const{return frac(q,p);}
  friend frac operator+(const frac &a,const frac &b){ll x,y;y=a.q/gcd(a.q,b.q)*b.q;x=y/a.q*a.p+y/b.q*b.p;return frac(x,y);}
  friend frac operator-(const frac &a,const frac &b){return a+(-b);}
  friend frac operator*(const frac&a,const frac&b){ll x,y,d;d=gcd(abs(a.p),abs(b.q));x=a.p/d;y=b.q/d;d=gcd(abs(b.p),abs(a.q));x*=b.p/d;y*=a.q/d;return frac(x,y);};
  friend frac operator/(const frac&a,const frac&b){return a*b.inv();};
  friend frac operator+=(frac&a,const frac&b){return a=a+b;}
  friend frac operator-=(frac&a,const frac&b){return a=a-b;}
  friend frac operator*=(frac&a,const frac&b){return a=a*b;}
  friend frac operator/=(frac&a,const frac&b){return a=a/b;}
  friend istream&operator>>(istream&in,frac &a){ll x,y;in>>x>>y;a={x,y};return in;}
  friend ostream&operator<<(ostream&out,const frac &a){out<<a.p<<' '<<a.q;return out;}
};
template<typename T,typename C=std::less<T>>class RMQ{
  constexpr bool isles(T a,T b,C cmp=C{})
  {
    return cmp(a,b);
  }
  vector<vector<T>>rmq;
public:
  void build(vector<T>&v)
  {
    ll lg,i,j;
    lg=log2(v.size());
    lg++;
    rmq.resize(v.size());
    for(i=0; i<v.size(); i++)
    {
      rmq[i].resize(lg);
      rmq[i][0]=v[i];
      for(j=1; (1ll<<j)<=i+1; j++)
      {
        rmq[i][j]=rmq[i-(1ll<<(j-1))][j-1];
        if(isles(rmq[i][j-1],rmq[i][j]))
          rmq[i][j]=rmq[i][j-1];
      }
    }
  }
  T ask(ll l,ll r)
  {
    ll d=0,rez;
    d=log2(r-l+1);
    rez=rmq[l+(1ll<<d)-1][d];
    if(isles(rmq[r][d],rez))
      return rmq[r][d];
    return rez;
  }
};
class arbore{
public:
  vector<vector<ll>>vec;
  vector<ll>etour,p;
  vector<pll>etimp;
  vector<ll>dotn,ntdo,depth;
  RMQ<ll> ermq;
  ll n,root,t;
  void euler(ll x){etimp[x].first=etimp[x].second=etour.size();etour.pb(ntdo[x]);for(ll y:vec[x]){if(etour[etimp[y].first]==ntdo[y])continue;euler(y);etimp[x].second=etour.size();etour.pb(ntdo[x]);}}
  void dfs_order(ll x){dotn[++t]=x;ntdo[x]=t;for(ll y:vec[x])if(ntdo[y]==0)depth[y]=depth[x]+1,dfs_order(y);}
public :
  arbore(ll x,ll r=1){n=x,root=r,vec.resize(n+1),p.resize(n+1);}
  void make_dfs_order(){
    if(!dotn.empty())return;
    dotn.resize(n+1);
    ntdo.resize(n+1);
    depth.resize(n+1);
    t=0;
    dfs_order(root);
  }
  void make_euler_tour(){//contine dfs times nu nodurile in sine
    if(!etour.empty())return;
    make_dfs_order();
    etimp.resize(n+1);
    etour.pb(0);
    euler(root);
    ermq.build(etour);
  }
  void add_edge(const ll &x,const ll &y){
    assert(1<=x&&x<=n&&1<=y&&y<=n);
    vec[x].pb(y),vec[y].pb(x);
  }
  void read_edges(istream&rid=cin){
    ll i,x,y;
    for(i=1;i<n;i++)
      rid>>x>>y,assert(1<=x&&x<=n&&1<=y&&y<=n),vec[x].pb(y),vec[y].pb(x);
  }
  void read_parents(istream&rid=cin){ll i,x;for(i=2;i<=n;i++)rid>>x,assert(1<=x&&x<=n),p[i]=x,vec[x].pb(i),vec[i].pb(x);}
  void read_kids(istream&rid=cin){ll i,x;for(i=1;i<=n;i++){cin>>x;vec[i].resize(x);for(auto&y:vec[i])rid>>y,p[y]=i;if(i!=1)vec[i].pb(p[i]);}}
  ll lca(ll x,ll y){
    make_euler_tour();
    return dotn[ermq.ask(min(etimp[x].first,etimp[y].first),max(etimp[x].second,etimp[y].second))];
  }
};
class AIB{
  vector<ll> v;
public:
  AIB(ll n)
  {
    v.resize(n+1);
  }
  void add(ll p,ll val=1)
  {
    for(; p<v.size(); p+=lsb(p))v[p]+=val;
  }
  ll ask(ll p)
  {
    ll rez=0;
    for(; p; p-=lsb(p))rez+=v[p];
    return rez;
  }
};
string pi="3141592653589793238462643383279502884197169399375105820974944";
class AINTaddminmax{
  ll n;
  vector<ll>mn,mx,lazy;
  function<bool(ll,ll)>smal=[&](ll a,ll b) {return a<b;},big=[&](ll a,ll b) {return a>b;},smaleq=[&](ll a,ll b) {return a<=b;},bigeq=[&](ll a,ll b) {return a>=b;},check;
  function<ll(ll)>mini=[&](ll p) {return mn[p];},maxi=[&](ll p) {return mx[p];},choose;
  void build(vector<ll>&a,ll st,ll dr,ll p)
  {
    lazy[p]=0;
    if(st==dr)
    {
      return mn[p]=mx[p]=a[st],void();
    }
    ll mid=(st+dr)/2;
    build(a,st,mid,p<<1);
    build(a,mid+1,dr,p<<1|1);
    mn[p]=min(mn[p<<1],mn[p<<1|1]);
    mx[p]=max(mx[p<<1],mx[p<<1|1]);
  }
  void push(ll p)
  {
    mn[p]+=lazy[p],mx[p]+=lazy[p],lazy[p<<1]+=lazy[p],lazy[p<<1|1]+=lazy[p],lazy[p]=0;
  }
  ll getvalmn(ll p)
  {
    return mn[p]+lazy[p];
  }
  ll getvalmx(ll p)
  {
    return mx[p]+lazy[p];
  }
  void add(ll st,ll dr,ll p,ll l,ll r,ll val)
  {
    if(l<=st&&dr<=r)
    {
      return lazy[p]+=val,void();
    }
    ll mid=(st+dr)/2;
    push(p);
    if(l<=mid)add(st,mid,p<<1,l,r,val);
    if(r>mid)add(mid+1,dr,p<<1|1,l,r,val);
    mx[p]=max(getvalmx(p<<1),getvalmx(p<<1|1));
    mn[p]=min(getvalmn(p<<1),getvalmn(p<<1|1));
  }
  pll ask(ll st,ll dr,ll p,ll l,ll r)
  {
    //first mn second mx
    if(l<=st&&dr<=r)
    {
      return {getvalmn(p),getvalmx(p)};
    }
    ll mid=(st+dr)/2;
    push(p);
    pll a= {1e15,-1e15},b= {1e15,-1e15};
    if(l<=mid)a=ask(st,mid,p<<1,l,r);
    if(r>mid)b=ask(mid+1,dr,p<<1|1,l,r);
    return {min(a.first,b.first),max(a.second,b.second)};
  }
  pll searchfirst(ll st,ll dr,ll p,ll l,ll r,ll val)
  {
    if(st>r||dr<l)return {-1,-1};
    ll mid=(st+dr)/2;
    if(!(check(choose(p),val)))return {-1,-1};
    if(st==dr)return {st,choose(p)};
    pll s=searchfirst(st,mid,p<<1,l,r,val);
    if(s.first!=-1)return s;
    return searchfirst(mid+1,dr,p<<1|1,l,r,val);
  }
  pll searchlast(ll st,ll dr,ll p,ll l,ll r,ll val)
  {
    if(st>r||dr<l)return {-1,-1};
    ll mid=(st+dr)/2;
    if(!(check(choose(p),val)))return {-1,-1};
    if(st==dr)return {st,choose(p)};
    pll s=searchlast(mid+1,dr,p<<1|1,l,r,val);
    if(s.first!=-1)return s;
    return searchlast(st,mid,p<<1,l,r,val);
  }
public:
  AINTaddminmax(ll x=0)
  {
    n=x,mn.resize(4*x+5),mx.resize(4*x+5),lazy.resize(4*x+5);
  }
  void build(vector<ll>&a)
  {
    build(a,1,n,1);
  }
  void add(ll l,ll r,ll val)
  {
    if(l<=r)add(1,n,1,l,r,val);
  }
  ll askmn(ll l,ll r)
  {
    if(l>r)return 1e15;
    return ask(1,n,1,l,r).first;
  }
  ll askmx(ll l,ll r)
  {
    if(l>r)return -1e15;
    return ask(1,n,1,l,r).second;
  }
  pll firsmal(ll l,ll r,ll val)
  {
    if(l>r)return {-1ll,-1ll};
    check=smal,choose=mini;
    return searchfirst(1,n,1,l,r,val);
  }
  pll firsmaleq(ll l,ll r,ll val)
  {
    if(l>r)return {-1ll,-1ll};
    check=smaleq,choose=mini;
    return searchfirst(1,n,1,l,r,val);
  }
  pll lassmal(ll l,ll r,ll val)
  {
    if(l>r)return {-1ll,-1ll};
    check=smal,choose=mini;
    return searchlast(1,n,1,l,r,val);
  }
  pll lassmaleq(ll l,ll r,ll val)
  {
    if(l>r)return {-1ll,-1ll};
    check=smaleq,choose=mini;
    return searchlast(1,n,1,l,r,val);
  }
  pll firbig(ll l,ll r,ll val)
  {
    if(l>r)return {-1ll,-1ll};
    check=big,choose=maxi;
    return searchfirst(1,n,1,l,r,val);
  }
  pll firbigeq(ll l,ll r,ll val)
  {
    if(l>r)return {-1ll,-1ll};
    check=bigeq,choose=maxi;
    return searchfirst(1,n,1,l,r,val);
  }
  pll lasbig(ll l,ll r,ll val)
  {
    if(l>r)return {-1ll,-1ll};
    check=big,choose=maxi;
    return searchlast(1,n,1,l,r,val);
  }
  pll lasbigeq(ll l,ll r,ll val)
  {
    if(l>r)return {-1ll,-1ll};
    check=bigeq,choose=maxi;
    return searchlast(1,n,1,l,r,val);
  }
};
string ans[]= {"NO\n","YES\n"};
ll maxitaxi;
vector<vector<ll>>divs;
vector<ll>fact,inv,primi;
void eratostene(bool doarprime=0){
  ll i,j;
  divs.resize(maxitaxi+1);
  for(i=1; i<=maxitaxi; i++)
  {
    if(doarprime&&divs[i].size()>1)continue;
    if(divs[i].size()==1)primi.pb(i);
    for(j=i; j<=maxitaxi; j+=i)divs[j].pb(i);
  }
}
void precalcfact(){
  ll i,j;
  fact.resize(maxitaxi+1);
  inv.resize(maxitaxi+1);
  fact[0]=inv[0]=1;
  for(i=1; i<=maxitaxi; i++)
  {
    fact[i]=fact[i-1]*i%mod;
  }
  inv[maxitaxi]=fastexp(fact[maxitaxi],mod-2);
  for(i=maxitaxi-1;i>=0;i--)
  {
    inv[i]=inv[i+1]*(i+1)%mod;
  }
}
ll comb(ll n,ll k){
  if(k<0||k>n)
    return 0ll;
  return fact[n]*inv[k]%mod*inv[n-k]%mod;
}
ll catalan(ll n)
{
  return comb(2*n,n)*fastexp(n+1,mod-2)%mod;
}
void constsetup()
{
  maxitaxi=3e5;
  mod=999999893;
  eratostene();
  precalcfact();
}
mint rez[2001][4001];
void setup()
{
  ll n=2000,m=2000,k=2000;
  vector<mint>a(n+m+1,1);
  ll st,dr,i,j;
  st=0,dr=n+m;
  for(i=0;i<=4000;i++)rez[0][i]=1;
  for(j=1;j<=k;j++)
  {
    st++;
    dr--;
    rez[j][st+j]=a[st];
    for(i=st+1;i<=dr;i++)
      a[i]+=a[i-1],rez[j][i+j]=a[i];
  }
}
void solve(ll T)
{
  mod=1e9+7;
  ll n,m,i,j,mx=-10,k,l,x,y,z,t,q,p;
  cin>>n>>m>>k;
  mint rez=0;
  for(i=1;i<=m;i++)
  {
    if(i<k){rez=0;continue;}
    if(rez==0) rez=1;
    else rez+=1/mint(i-1);
  }
  for(i=2;i<=n;i++){
    if(i*m<k){rez=0;continue;}
    mint delt=0;
    p=min(m,(k-1)/(i-1));
    q=min(m,(k-1)/(i));
    if(rez==0&&q==m-1){rez=1;continue;}
    if(p==q)
      delt=1/mint(i+q-1);
    else if(p==m){
      delt=1;
      for(j=q+2;j<=p;j++)
        delt+=1/mint(i+j-2);
    }
    else{
      y=p-q;
      for(j=1;j<=y;j++)
        delt+=1/mint(i+q-1+j);
      delt+=1/mint(i+q-1+y);
    }
    rez+=delt;
  }
  cout<<rez<<'\n';
}
int main()
{
  //freopen("IN","r",stdin);
  //freopen("OUT","w",stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll c=0;
  //constsetup();
  setup();
  ll t;cin>>t;while(t--)
  solve(++c);
  return 0;
}