#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long > pll;
typedef vector<pair<ll,ll>> vpll;
#define f first
#define s second
#define pb push_back
#define nl "\n"
#define mod 998244353

vector<vector<pii>> adj;
map<int,vector<int>> dp;
map<int,int> dn;


int add(int a,int b){
  return ((a%mod)+(b%mod))%mod;
}
int mul(int a,int b){
  return ((a%mod)*(b%mod))%mod;
}
int sub(int a,int b){
  return ((a%mod)-(b%mod)+mod)%mod;

}

vector<int> dfs(int i){
  if(dn[i])return dp[i];

  vector<int> v0;
  vector<int> v1;
  int curr=0;
  for(auto [e,w]:adj[i]){
    if(w==0){v0.push_back(1); v1.push_back(0);}
    else {v0.push_back(0); v1.push_back(1);}
    auto nv=dfs(e);
    curr=add(curr,nv[0]);
    v0.push_back(nv[1]);
    v1.push_back(nv[2]);
  }

// if(i==1){
//   for(auto j:v0)cout<<j<<" ";
//   cout<<endl;
//   for(auto j:v1)cout<<j<<" ";
//   cout<<endl;
// }
  int t0=0;
  for(auto j:v0)t0=add(t0,j);
  int t1=0;
  for(auto j:v1)t1=add(t1,j);
  int c0=t0;
  for(int i=0;i<v0.size();i++){
    t0=sub(t0,v0[i]);
    curr=add(curr,mul(t0,v1[i]));
  }

  dp[i]={curr,c0,t1};
  // cout<<i<<" "<<curr<<" "<<t0<<" "<<t1<<endl;
  dn[i]=1;
  return dp[i];
}


void solve()
{
  int n;
  cin>>n;
  adj.assign(n+1,vector<pair<int,int>>()) ;
  for(int i=1;i<=n;i++){
    int co;
    cin>>co;
    while(co--){
      int e, w;
      cin>>e>>w;
      adj[i].push_back({e,w});
    }
  }

  dfs(1);

  cout<<dp[1][0]<<endl;


}



signed main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  ll test=1;
// cin>>test;
  while(test--)
  {
    solve();
  }
  return 0;
}