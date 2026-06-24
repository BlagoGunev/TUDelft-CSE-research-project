#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define ff first
#define ss second
#define mp make_pair
#define pi pair<int,int>
using namespace std;
const int N=1000005;
const int inf=1e9+7;
typedef long long ll;
typedef long double lb;
inline void read(int &x){x=0; char ch=getchar();while(ch<'0') ch=getchar();while(ch>='0'){x=x*10+ch-48; ch=getchar();}}
//------------------------------------------head---------------------------------------------------//
int n,m,top,clk;
int head[N],nxt[N],to[N],w[N],e;
pair<int,int> g[N];
int dfn[N],low[N];
int stk[N],vis[N];
int mx,rt;
inline void dfs(int u=1,int par=0)
{
	vis[u]=1;stk[top]=u; top++;
	clk++; dfn[u]=low[u]=clk;
	for(int i=head[u];i+1;i=nxt[i])
	{
		int v=to[i],id=w[i];
		if(v==par) continue;
		if(!vis[v])
		{
			dfs(v,u);
			g[id]=mp(v,u);
		}
		else g[id]=mp(u,v);
		low[u]=min(low[u],low[v]);
	}
	if(low[u]==dfn[u])
	{
		int cnt=0;
		while(top-1>=0 && stk[top-1]!=u) cnt++, top--;
		cnt++; top--;
		if(cnt>mx) mx=cnt, rt=u;
	}
}
inline void init(){memset(head,-1,sizeof(head)); e=0;}
inline void add_edge(int x,int y,int z)
{
	to[e]=y; nxt[e]=head[x]; w[e]=z; head[x]=e++;
}
int main()
{
	read(n); read(m); init();
	rep(i,1,m)
	{
		int x,y; read(x); read(y);
		g[i]=make_pair(x,y);
		add_edge(x,y,i); add_edge(y,x,i);
	}
	dfs();
	printf("%d\n",mx);
	memset(vis,0,sizeof(vis));dfs(rt);
	rep(i,1,m) printf("%d %d\n",g[i].first,g[i].second);
	return 0;
}