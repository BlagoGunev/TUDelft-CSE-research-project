#include<bits/stdc++.h>
/************************************************/
#define rep(i,n) for(int i=0;i<n;i++)
#define m_p make_pair
#define pb push_back
#define fr first
#define int ll
#define se second
#define rp(i,v) for(int i:v)
#define ford(i,n) for(int i=n-1;i>=0;i--)
#define forn(i,a,n) for(int i=a;i<n;i++)
#define foreach(i,c) for(__typeof(c.begin())i=(c.begin());i!=(c).end();i++)
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define sz(s) (int)(s.size())
#define all(s) s.begin(),s.end()
#define vii vector<pair<int,int> >
#define re return
//#define mod 998244353
/************************************************/
using namespace std;
int t,n,k,mod;
ll q_p(ll x,ll y){
	ll res=1;
	x%=mod;
	while(y){
		if(y%2){
			res=res*x;
			res%=mod;
		}
		y/=2;
		x=x*x;
		x%=mod;
	}
	re res;
}
void add(int &x,int y){
	x+=y;
	if(x>=mod)
	x-=mod;
} 
int dx[4]={0,-1,0,1},dy[4]={1,0,-1,0};
int dp[501][501][2];
signed main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>k>>mod;
		rep(i,k+1)
		dp[1][i][0]=dp[1][i][1]=1;
		forn(i,2,n+1){
			rep(j,k+1)
			rep(l,2)
			dp[i][j][l]=0;
			rep(l,k+1){
				rep(r,k+1-l){
					add(dp[i][l+r][0],dp[i-1][l][0]*dp[i-1][r][0]%mod);
					if(l>r)
					add(dp[i][l+r][1],dp[i-1][l][1]*dp[i-1][r][0]%mod);
					if(l<r)
					add(dp[i][l+r][1],dp[i-1][l][0]*dp[i-1][r][1]%mod);
				}
			}
			forn(j,1,k+1)
			rep(l,2) 
			add(dp[i][j][l],dp[i][j-1][l]);
//			rep(j,k+1)
//			cout<<dp[i][j][0]<<" "<<dp[i][j][1]<<"\n";
//			cout<<"\n";
		}
		cout<<dp[n][k][1]<<"\n";
	} 
	re 0;
}