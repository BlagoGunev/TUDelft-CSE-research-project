#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll          long long
#define pb          push_back
#define	endl		'\n'
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define rep(i,a,b)	for(ll int i=a;i<b;i++)
#define repr(i,a,b) for(ll int i=a;i>b;i--) 
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define ordered_set tree<ll int, null_type,less<ll int>, rb_tree_tag,tree_order_statistics_node_update> 
ll int dp[201][202];
vector <ll int> adj[201];
ll int w[201];
ll int n,k;
void solve(ll int v,ll int prev=-1)
{
	dp[v][0]=w[v];
	rep(i,1,k+1) dp[v][i]=0;
	for (auto u: adj[v])
	{
		if (u==prev) continue;
		solve(u,v);
		dp[v][0]=dp[v][0]+dp[u][k];
		ll int dp1[k+1];
		rep(i,0,k+1) dp1[i]=0;
		rep(i,1,k+1)
		{
			rep(j,0,k+1)
			{
				if ((i+j+1)>k)
				{
					ll int u1=min(i,j+1);
					dp1[u1]=max(dp1[u1],dp[v][i]+dp[u][j]);
				}
			}
		}
		rep(i,1,k+1)
		{
			dp[v][i]=dp1[i];
		}
	}
}
int main()
{
	cin >> n >> k;
	rep(i,1,n+1) cin >> w[i];
	rep(i,0,n-1)
	{
		ll int a,b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	solve(1);
	ll int max2=0;
	rep(i,0,k+1)
	{
		max2=max(max2,dp[1][i]);
	}
	cout << max2 << endl;
}