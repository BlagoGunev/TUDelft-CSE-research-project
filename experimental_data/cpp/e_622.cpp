#include<bits/stdc++.h>

using namespace std;

const int N=500005;

int base[N],pre[2*N],vec[2*N],tot;

int n,m,a[N];

void link(int x,int y)

{

	vec[++tot]=y; pre[tot]=base[x]; base[x]=tot;

}

void dfs(int u,int fa,int deep)

{

	bool flag=1;

	for (int now=base[u];now;now=pre[now])

	{

		int v=vec[now];

		if (v==fa) continue;

		flag=0;

		dfs(v,u,deep+1);

	}

	if (flag) a[++m]=deep;

}

int main()

{

	scanf("%d",&n);

	for (int i=1;i<n;i++)

	{

		int x,y;

		scanf("%d%d",&x,&y);

		link(x,y);

		link(y,x);

	}

	int ans=0;

	for (int now=base[1];now;now=pre[now])

	{

		int v=vec[now];

		m=0;

		dfs(v,1,0);

		sort(a+1,a+m+1);

		int tmp=-1;

		for (int i=1;i<=m;i++) tmp=max(tmp+1,a[i]);

		ans=max(ans,tmp);

	}

	printf("%d\n",ans+1);

}