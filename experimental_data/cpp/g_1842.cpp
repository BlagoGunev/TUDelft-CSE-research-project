#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7; 
ll ksm(ll x,ll p){
	ll res=1;
	for(;p;p>>=1,x=x*x%mod) if(p&1) res=res*x%mod;
	return res;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;
	ll v;
	cin>>n>>m>>v;
	ll inv_n=ksm(n,mod-2);
	vector<ll> p(n+1),a(n+1);
	for(int i=1;i<=n;i++) p[i]=i*inv_n%mod,cin>>a[i];
	vector dp=vector(2,vector<ll>(min(n,m)+2));
	dp[0][0]=1;
	for(int k=0;k<n;k++){
		int i=k&1;
		fill(dp[i^1].begin(),dp[i^1].end(),0);
		for(int j=0;j<=min(k,m);j++) if(dp[i][j]){
			ll t=dp[i][j];
			dp[i^1][j]=(dp[i^1][j]+t*((a[k+1]+v*j)%mod))%mod;
			dp[i^1][j+1]=(dp[i^1][j+1]+t*(v*p[k+1]%mod*(m-j)%mod))%mod;
		}
	}
	ll ans=accumulate(dp[n&1].begin(),dp[n&1].end(),0ll)%mod;
	cout<<ans;
}
// dp[i][j]
// i:the first i factors of each term
// j:j categories that have appeared at least once
// x_1_1, a2, x_3_3, a4, x_1_5, x_?_6