#include<bits/stdc++.h>

using namespace std;

#define io ios::sync_with_stdio(false);cin.tie(0),cout.tie(0)

using ll = long long;

const int MAXN = 1e4+10;

int n;

int ind[MAXN],outd[MAXN];

bool vis[MAXN];

bool can;

vector<int>G[MAXN];

int ans[MAXN];

void dfs(int x,int num)

{

	if(can)return;

	vis[x]=1;

	if(num==n+1)

	{

		ans[num]=x;

		can=1;

		return;

	}

	ans[num]=x;

	for(int i=0;i<G[x].size();i++)

	{

		int y=G[x][i];

		if(vis[y])continue;

		dfs(y,num+1);

		vis[y]=0;

	}

}

void solve() {

	cin>>n;

	can=0;

	memset(vis,0,sizeof(vis));

	memset(ind,0,sizeof(ind));

	memset(outd,0,sizeof(outd));

	for(int i=1;i<=n+1;i++)G[i].clear();

	for(int i=2;i<=n;i++)

	{

		G[i-1].push_back(i);

		ind[i]++;

		outd[i-1]++;

	}

	for(int i=1;i<=n;i++)

	{

		int x;

		cin>>x;

		if(!x)G[i].push_back(n+1),outd[i]++,ind[n+1]++;

		else G[n+1].push_back(i),ind[i]++,outd[n+1]++;

	}

		for(int i=1;i<=n+1;i++)

		{

				dfs(i,1);

				memset(vis,0,sizeof(vis));

				if(can)break;

		}

		if(!can)

		{

			cout<<-1<<'\n';

			return;

		}

			for(int i=1;i<=n+1;i++)cout<<ans[i]<<' ';

			cout<<'\n';

}

int main() {

	io;

	int t=1;

	cin>>t;

	while (t--) {

		solve();

	}

	return 0;

}