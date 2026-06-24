#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define int ll
#define ld long double
#define pb push_back
#define pf push_front
#define pii pair<int,int>
#define all(v) v.begin(),v.end()
#define F first
#define S second
#define mem(a,i) memset(a,i,sizeof(a))
#define sz(s) (int)s.size()
#define y1 yy
#define ppb pop_back
#define lb lower_bound
#define ub upper_bound
#define gcd(a,b) __gcd(a,b)
#define in insert

const int MAX=2e5+10;
const int B=224;
const int N=1e6;
const int block=450;
const int maxB=MAX/B+10;
const ll inf=1e18;
const int mod=1e6+3;
const int mod1=1e9+9;
const int logg=15;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int binpow(int a,int n){
  if(!n)return 1;
  if(n%2==1)return a*binpow(a,n-1)%mod;
  int k=binpow(a,n/2);
  return k*k%mod;
}

int n;
int a[MAX],b[MAX];

void solve(){
  cin>>n;
  int mnb1=inf,mxa1=-inf;
  int mxb2=-inf,mna2=inf;
  int sum=0;
  int ans=0;
  for(int i=1;i<=n;i++)cin>>a[i];
  for(int i=1;i<=n;i++){
    cin>>b[i];
    sum+=abs(a[i]-b[i]);
    if(a[i]==b[i]){
      mnb1=min(mnb1,b[i]);
      mxa1=max(mxa1,a[i]);
      mxb2=max(mxb2,b[i]);
      mna2=min(mna2,a[i]);
    }
    else if(a[i]<b[i]){
      mnb1=min(mnb1,b[i]);
      mxa1=max(mxa1,a[i]);
    }
    else{
      mxb2=max(mxb2,b[i]);
      mna2=min(mna2,a[i]);
    }
  }
  ans=max(ans,mxa1-mnb1);
  ans=max(ans,mxb2-mnb1);
  ans=max(ans,mxa1-mna2);
  ans=max(ans,mxb2-mna2);
  cout<<2*ans+sum<<"\n";
}

main(){
  // freopen("color.in", "r", stdin);
  // freopen("color.out", "w", stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t=1;
  cin>>t;
  while(t--){
    solve();
  }
}