#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m,p;
		scanf("%d%d%d",&n,&m,&p);
		vector<int>fa(n+1),w(n+1);
		vector<long long>dp1(n+1);
		vector<vector<long long>>dp(n+1);
		for(int i=1,s;i<=p;i++)scanf("%d",&s),++w[s];
		vector<pair<int,pair<int,int>>>e;
		for(int i=1,u,v,w;i<=m;i++)scanf("%d%d%d",&u,&v,&w),e.push_back({w,{u,v}});
		sort(e.begin(),e.end());
		for(int i=1;i<=n;i++)fa[i]=i;
		function<int(int)>find=[&](int i){return fa[i]==i?i:fa[i]=find(fa[i]);};
		for(int i=0;i<m;i++)
		{
			int u=e[i].second.first,v=e[i].second.second,l=e[i].first;
			u=find(u),v=find(v);
			if(u!=v)
			{
				if(dp[u].size()>dp[v].size())swap(u,v);
				if(dp1[v]+1ll*w[u]*l<dp1[u]+1ll*w[v]*l)
					dp[u].push_back(1ll*w[u]*l-dp1[u]);
				else dp[v].push_back(1ll*w[v]*l-dp1[v]);
				for(long long x:dp[u])dp[v].push_back(x);
				dp1[v]=min(dp1[v]+1ll*w[u]*l,dp1[u]+1ll*w[v]*l);
				w[v]+=w[u];
				fa[u]=v;
//				vector<long long>tmp(w[u]+w[v]+1,1e18);
//				for(int j=0;j<=w[u];j++)
//					for(int k=0;k<=w[v];k++)
//					{
//						if(j==0&&k)tmp[j+k]=min(tmp[j+k],dp[v][k]+1ll*w[u]*l);
//						else if(k==0&&j)tmp[j+k]=min(tmp[j+k],dp[u][j]+1ll*w[v]*l);
//						else tmp[j+k]=min(tmp[j+k],dp[u][j]+dp[v][k]);
//					}
//				dp[v].swap(tmp);
//				w[v]+=w[u];
//				fa[u]=v;
			}
		}
		dp[find(1)].resize(n,0);
		sort(dp[find(1)].begin(),dp[find(1)].end(),[&](long long i,long long j){return i>j;});
		for(int i=0;i<n;i++)printf("%lld ",dp1[find(1)]),dp1[find(1)]-=dp[find(1)][i];
		puts("");
	}
	return 0;
}