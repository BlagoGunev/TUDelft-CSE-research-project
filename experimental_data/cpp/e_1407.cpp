#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
int read()
{
	char x=getchar();int ans=0,flag=1;
	while(!isdigit(x)) if (x=='-') flag=-1,x=getchar();else x=getchar();
	while(isdigit(x)) ans=ans*10+x-'0',x=getchar();
	return ans*flag;
}
int n,m,pnt[500005],nxt[500005],head[500005],E,len[500005],dis[500005][2],col[500005];
int vis[500005][2],viss[500005];
pair<int,int> pre[500005][2];
void add_edge(int u,int v,int w)
{
	pnt[E]=v;
	nxt[E]=head[u];
	len[E]=w;
	head[u]=E++;
}
struct node
{
	int u,opt,w;
	bool operator<(node x)const
	{
		return w>x.w;
	}
};
signed main()
{
	memset(head,-1,sizeof(head));
	n=read(),m=read();
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read(),w=read();
		add_edge(v,u,w);
	}
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	dis[n][0]=dis[n][1]=0;
	vis[n][0]=vis[n][1]=1;
	priority_queue<node> Q;
	Q.push(node{n,0,0});
	viss[n]=1;
	while(!Q.empty())
	{
		node p=Q.top();
		Q.pop();
		int u=p.u,opt=p.opt;
		for (int i=head[u];i!=-1;i=nxt[i])
		{
			int v=pnt[i];
			int ww=len[i];
			
			if (dis[u][opt]+1<dis[v][ww])
			{
				dis[v][ww]=dis[u][opt]+1;
				pre[v][ww]=make_pair(u,opt);
				if (!vis[v][ww])
				{
					vis[v][ww]=1;
					if (vis[v][0]&&vis[v][1])
					{
						node tmp;
						tmp.u=v;
						if (dis[v][0]<dis[v][1]) tmp.w=dis[v][1],tmp.opt=1;
						else tmp.w=dis[v][0],tmp.opt=0;
						Q.push(tmp);
					}
				}
			}
		}
	}
	int u,w;
	for (int i=1;i<=n;i++)
	{
		if (dis[i][0]<dis[i][1]) col[i]=1;
		else col[i]=0;
	}
	if (dis[1][0]>1e9||dis[1][1]>1e9)
	{
		puts("-1");
	}
	else
	if (dis[1][0]>dis[1][1])
	{
		cout<<dis[1][0]<<endl; 
		col[1]=0;
		u=1,w=0;
	}
	else
	{
		cout<<dis[1][1]<<endl;
		col[1]=1;
		u=1,w=1;
	}
	
	for (int i=1;i<=n;i++)
		cout<<(dis[i][0]<dis[i][1])?1:0;
	return 0;
}