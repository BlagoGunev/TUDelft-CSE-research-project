#include<bits/stdc++.h>
using namespace std;
//#define int long long
const int maxn=5005;
bool dp[maxn];
int sz[maxn],ans;
vector<int>g[maxn];
void dfs(int u,int fa)
{
	int i,j,cnt=0,sum=0;
	vector<int>temp;
	temp.clear();
	sz[u]=1;
	for(i=0;i<(int)g[u].size();i++)
	{
		int v=g[u][i];
		if(v==fa)
		{
			continue;
		}
		dfs(v,u);
		sz[u]+=sz[v];
		sum+=sz[v];
		cnt++;
		temp.push_back(sz[v]);
	}
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	for(i=0;i<cnt;i++)
	{
		int x=temp[i];
		for(j=sum/2;j>=x;j--)
		{
			dp[j]|=dp[j-x];
		}
	}
	int o=0;
	for(j=sum/2;j>=0;j--)
	{
		if(dp[j])
		{
			o=j;
			break;
		}
	}
	ans+=o*(sum-o);
}
signed main()
{
	ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
	int n,i;
	cin>>n;
	for(i=2;i<=n;i++)
	{
		int x;
		cin>>x;
		g[x].push_back(i);
	}
	dfs(1,-1);
	cout<<ans<<endl;
	return 0;
}