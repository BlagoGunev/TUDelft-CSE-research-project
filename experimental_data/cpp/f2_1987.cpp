//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 810
using namespace std;
ll n,a[N],f[N][N],dp[N][N];
ll dfs(ll l,ll r)
{
	if(l>r)
	{
		return 0;
	}
	if(f[l][r]!=INF)
	{
		return f[l][r];
	}
	if(abs(a[l]-(l+1))&1)
	{
		return INF;
	}
	if(a[l]>l+1)
	{
		return INF;
	}
	if((r-l+1)&1)
	{
		return INF;
	}
	ll i;
	f[l][r]=INF-1;
	for(i=l+1;i<=r;i+=2)
	{
		if(dfs(l+1,i-1)<=l+1-a[l])
		{
			f[l][r]=min(f[l][r],max(0ll,dfs(i+1,r)-(i-l+1)));
		}
	}
	f[l][r]=max(f[l][r],l+1-a[l]);
	return f[l][r];
}
int main(){
	ll T,i,j,k;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		for(i=0;i<n;i++)
		{
			for(j=i;j<n;j++)
			{
				f[i][j]=INF;
			}
		}
		for(i=0;i<=n;i++)
		{
			for(j=0;j<=n;j++)
			{
				dp[i][j]=0;
			}
		}
		dp[0][0]=1;
		for(i=0;i<n;i++)
		{
			for(j=0;j<=n;j++)
			{
				if(!dp[i][j])
				{
					continue;
				}
				dp[i+1][j]=1;
				for(k=i;k<n;k++)
				{
					if(dfs(i,k)<=j)
					{
						dp[k+1][j+k-i+1]=1;
					}
				}
			}
		}
		for(i=n;i>0;i--)
		{
			if(dp[n][i])
			{
				break;
			}
		}
		printf("%lld\n",i/2);
	}
	return 0;
}