#include<bits/stdc++.h>
#define N 500020
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n;
int w[N];
int head[N],pos;
struct edge{int to,next,c;}e[N<<1];
void add(int a,int b,int c)
{pos++;e[pos].c=c,e[pos].to=b,e[pos].next=head[a],head[a]=pos;}
void insert(int a,int b,int c){add(a,b,c);add(b,a,c);}
long long ans,f[N],g[N];
void dfs(int u,int fa)
{
	f[u]=w[u];ans=max(ans,1ll*w[u]);
	for(int i=head[u];i;i=e[i].next)
	{
		int v=e[i].to;
		if(v==fa)continue;
		dfs(v,u);
		ans=max(f[u]+g[v]+w[v]-e[i].c,ans);
		f[u]=max(f[u],f[v]-e[i].c+w[u]);
		g[u]=max(g[u],g[v]+w[v]-e[i].c); 
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)w[i]=read();
	for(int i=2;i<=n;i++)
	{
		int u=read(),v=read(),c=read();
		insert(u,v,c);
	}
	dfs(1,0);
	printf("%lld\n",ans);
}