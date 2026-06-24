#include<bits/stdc++.h>

#define int long long

using namespace std;

int n,a,b,lca,len,maxdep[100005],dp[100005],T;

int num[100005],f[100005],md[100005],dep[100005];

vector<int> t[100005];

void dfs0(int u,int fa,int dd)

{

	if(u==b) len=dd;

	for(int i=0;i<t[u].size();i++)

	{

		int v=t[u][i];

		if(v!=fa) dfs0(v,u,dd+1);

	}

}

void dfs1(int u,int fa)

{

	maxdep[u]=0;

	num[u]=0;

	for(int i=0;i<t[u].size();i++)

	{

		int v=t[u][i];

		if(v!=fa)

		{

			dfs1(v,u);

			maxdep[u]=max(maxdep[u],maxdep[v]+1);

			if(maxdep[v]+1>=len) num[u]++;

		}

	}

}

void dfs2(int u,int fa)

{

	if(dp[u]>=len) num[u]++;

	int x=-1;

	for(int i=0;i<t[u].size();i++)

	{

		int v=t[u][i];

		if(v!=fa)

		{

			dp[v]=max(dp[v],max(dp[u]+1,x+2));

			x=max(x,maxdep[v]);

		}

	}

	x=-1;

	for(int i=t[u].size()-1;i>=0;i--)

	{

		int v=t[u][i];

		if(v!=fa)

		{

			dp[v]=max(dp[v],x+2);

			x=max(x,maxdep[v]);

		}

	}

	for(int i=0;i<t[u].size();i++)

	{

		int v=t[u][i];

		if(v!=fa) dfs2(v,u);

	}

}

void dfs3(int u,int fa)

{

	f[u]=fa;

	md[u]=dep[u]=dep[fa]+1;

	for(int i=0;i<t[u].size();i++)

	{

		int v=t[u][i];

		if(v!=fa)

		{

			dfs3(v,u);

			md[u]=max(md[u],md[v]);

		}

	}

}

int LCA(int x,int y)

{

	while(x!=y)

	{

		if(dep[x]<dep[y]) swap(x,y);

		x=f[x];

	}

	return x;

}

void work()

{

	cin>>n>>a>>b;

	for(int i=1;i<=n;i++) t[i].clear();

	memset(dp,0,sizeof(dp));

	for(int i=1;i<n;i++)

	{

		int u,v;

		cin>>u>>v; 

		t[u].push_back(v);

		t[v].push_back(u);

	}

	dfs0(a,0,0);

	dfs1(1,0);

	dfs2(1,0);

	int x=-1;

	for(int i=1;i<=n;i++)

	{

		if(num[i]>=3) x=i;

	}

	if(x==-1)

	{

		cout<<"NO\n";

		return;

	}

	dfs3(x,0);

	lca=LCA(a,b);

	if(lca==a||lca==b)

	{

		cout<<"YES\n";

		return;

	}

	int depx=dep[a],depy=dep[b];

	for(int i=1;i<=2*n+5;i++)

	{

		x=md[a]-depx;

		x=dep[b]-(depy-x);

		while(x--) b=f[b];

		depy=dep[b];

		depx=md[a];

		if(depy<=dep[lca])

		{

			cout<<"YES\n";

			return;

		}

		swap(a,b);

		swap(depx,depy);

	}

	cout<<"NO\n";

}

signed main()

{

	ios::sync_with_stdio(0);

	cin>>T;

	while(T--) work();

}