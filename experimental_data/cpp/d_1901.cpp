#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define R cin>>
#define ln cout<<'\n'
#define ll long long
#define in(a) insert(a)
#define pb(a) push_back(a)
#define pd(a) printf("%.12f\n",a)
#define mem(a) memset(a,0,sizeof(a))
#define all(c) (c).begin(),(c).end()
#define iter(c) __typeof((c).begin())
#define rrep(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define rep(i,n) REP(i,0,n)
#define tr(it,c) for(iter(c) it=(c).begin();it!=(c).end();it++)
ll check(ll n,ll m,ll x,ll y){return x>=0&&x<n&&y>=0&&y<m;}void pr(){ln;}
template<class A,class...B>void pr(const A &a,const B&...b){cout<<a<<(sizeof...(b)?" ":"");pr(b...);}
template<class A>void PR(A a,ll n){rep(i,n)cout<<(i?" ":"")<<a[i];ln;}
const ll MAX=1e9+7,MAXL=1LL<<61,dx[8]={-1,0,1,0,-1,-1,1,1},dy[8]={0,1,0,-1,-1,1,1,-1};
typedef pair<ll,ll> P;

int N=1<<19;
class StarrySkyTree{
public:
  ll Ma[1555555],A[1555555];
  void init(){memset(Ma,0,sizeof(Ma)),memset(A,0,sizeof(A));}
  void add(int a,int b,ll x,int k=0,int l=0,int r=N) {
    if(r<=a||b<=l) return;
    if(a<=l&&r<=b){
      A[k]+=x;
      while(k){
        k=(k-1)/2;
        Ma[k]=max(Ma[k*2+1]+A[k*2+1],Ma[k*2+2]+A[k*2+2]);
      }
      return;
    }
    add(a,b,x,k*2+1,l,(l+r)/2);
    add(a,b,x,k*2+2,(l+r)/2,r);
  }
  ll getMax(int a,int b,int k=0,int l=0,int r=N) {
    if(r<=a||b<=l)return -MAXL;if(a<=l&&r<=b)return Ma[k]+A[k];
    ll left=getMax(a,b,k*2+1,l,(l+r)/2),right=getMax(a,b,k*2+2,(l+r)/2,r);
    return max(left,right)+A[k];
  }
};

StarrySkyTree t,t2;

void Main() {
  ll n;
  R n;
  ll a[n];
  rep(i,n) R a[i];
  t.init();t2.init();
  rep(i,n) t.add(i,i+1,a[i]),t2.add(i,i+1,a[i]);
  REP(i,1,n) t.add(i,n,1),t2.add(i,n,1);
  ll ans=MAXL;
  rep(i,n) {
    ans=min(ans,max(t.getMax(0,n),t2.getMax(0,n)));
    t.add(i,n,-1);
    t.add(i,i+1,n-i);
    t2.add(i+1,i+2,-(i+1));
    t2.add(0,i+1,1);
  }
  pr(ans);
}

int main(){ios::sync_with_stdio(0);cin.tie(0);Main();return 0;}