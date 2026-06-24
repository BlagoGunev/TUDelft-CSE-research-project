// LUOGU_RID: 92349700
#include<iostream>

#include<cstdio>

#include<cstring>

#include<cmath>

#include<vector>

#include<algorithm>

using namespace std;

typedef long long ll;

const int N=1000+5,M=1e6+5;

int n,tot,a[N],b[M],matched[N];

bool vis[N];

ll ans;

vector<int> e[M];

bool found(int u)

{	for(int i=0;i<(int)e[u].size();i++)

	{	int v=e[u][i];

		if(vis[v])continue;

		vis[v]=1;

		if(!matched[v]||found(matched[v])){matched[v]=u;return 1;}

	}

	return 0;

}

void match()

{	int res=0;

	for(int i=1;i<=tot&&res<=n;i++)

	{	if(!found(i))continue;

		res++,ans+=(ll)b[i];

		memset(vis,0,sizeof(vis));

	}

}

int main()

{	//freopen("1.in","r",stdin);

	scanf("%d",&n);

	for(int i=1;i<=n;i++)

	{	scanf("%d",&a[i]);

		for(int j=1;j<=n;j++)b[++tot]=j*a[i];

	}

	sort(b+1,b+1+tot);

	tot=unique(b+1,b+1+tot)-b-1;

	for(int i=1;i<=n;i++)

		for(int j=1;j<=n;j++)

		{	int p=lower_bound(b+1,b+1+tot,a[i]*j)-b;

			e[p].push_back(i);

		}

	match();

	printf("%lld\n",ans);

	return 0;

}