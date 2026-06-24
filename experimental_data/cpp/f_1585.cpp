#include<bits/stdc++.h>
using namespace std;

#define db(val) "["#val" = "<<(val)<<"] "
#define FOR(i,l,r) for(int i=(l);i<=(r);i++)
#define FOD(i,l,r) for(int i=(l);i>=(r);i--)
#define F0R(i,l,r) for(int i=(l);i<(r);i++)

using ll=long long;

const int mod=998244353,N=2e5+5;

int L[N],a[N],dp[N][2],sum[N][2];
int n;

void solve(){
   cin>>n;
   FOR(i,1,n)cin>>a[i];
   dp[0][0]=sum[0][0]=1;
   FOR(i,1,n){
      L[i]=i-1;
      while(L[i]>0&&a[L[i]]>=a[i])L[i]=L[L[i]];
      if(L[i]>0){
         dp[i][0]=(dp[L[i]][0]+1ll*(sum[i-1][1]-sum[L[i]-1][1]+mod)*a[i])%mod;
         dp[i][1]=(dp[L[i]][1]+1ll*(sum[i-1][0]-sum[L[i]-1][0]+mod)*a[i])%mod;
      }else{
         dp[i][0]=1ll*sum[i-1][1]*a[i]%mod;
         dp[i][1]=1ll*sum[i-1][0]*a[i]%mod;
      }
      sum[i][0]=sum[i-1][0]+dp[i][0];
      if(sum[i][0]>=mod)sum[i][0]-=mod;
      sum[i][1]=sum[i-1][1]+dp[i][1];
      if(sum[i][1]>=mod)sum[i][1]-=mod;
   }
   cout<<(dp[n][n&1]-dp[n][n&1^1]+mod)%mod;
}

int32_t main(){
   cin.tie(0)->ios::sync_with_stdio(0);

   int tt=1;
//   cin>>tt;
   while(tt--){
      solve();
      cout<<'\n';
   }

   return 0;
}