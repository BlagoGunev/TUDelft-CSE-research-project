#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
vector<int> e[200010];
bool vis[200010];
int fa[200010];
int siz[200010];
void dfs(int u,int fat)
{
	fa[u]=fat,siz[u]=(!vis[u]);
	for(int v:e[u])
	{
		if(v!=fat) dfs(v,u),siz[u]+=siz[v];
	}
}
signed main()
{
	ios::sync_with_stdio(false),cin.tie(0);
	int t; cin>>t; while(t--)
	{
		cin>>n;
		for(int i=1; i<=n; ++i) e[i].clear();
		for(int i=1; i<=n-1; ++i)
		{
			int u,v; cin>>u>>v;
			e[u].push_back(v),e[v].push_back(u);
		}
		int cnt=0;
		for(int i=1; i<=n; ++i) cnt+=(e[i].size()==1);
		int ans=cnt*(n-cnt);
		for(int i=1; i<=n; ++i)
		{
			vis[i]=(e[i].size()==1);
			for(int j:e[i]) vis[i]|=(e[j].size()==1);
		}
		dfs(1,0);
		for(int i=1; i<=n; ++i)
		{
			if(e[i].size()==1) continue;
			for(int j:e[i])
			{
				if(!vis[j]) continue;
				if(fa[i]==j) ans+=siz[1]-siz[i];
				else ans+=siz[j];
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}