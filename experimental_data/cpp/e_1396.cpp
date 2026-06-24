#include <cstdio>
#include <cassert>
#include <iostream>
#include <set>
using namespace std;
const int M = 100005;
#define int long long
#define pii pair<int,int>
#define mp make_pair
int read()
{
	int x=0,f=1;char c;
	while((c=getchar())<'0' || c>'9') {if(c=='-') f=-1;}
	while(c>='0' && c<='9') {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}
int n,tot,rt,f[M],cur[M],cl[M],siz[M],mx[M],fa[M],dep[M];
set<pii> s,b[M];int m,k,rs,mi,dfn[M],use[M],out[M];
struct edge
{
	int v,next;
}e[2*M];
void dfs1(int u,int fa)
{
	siz[u]=1;
	for(int i=f[u];i;i=e[i].next)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs1(v,u);
		siz[u]+=siz[v];
		mx[u]=max(mx[u],siz[v]);
	}
	mx[u]=max(mx[u],n-siz[u]);
	if(mx[u]<mx[rt] || !rt) rt=u;
}
void dfs2(int u,int p,int rt)
{
	siz[u]=1;cl[u]=rt;
	fa[u]=p;dep[u]=dep[p]+1;
	for(int i=f[u];i;i=e[i].next)
	{
		int v=e[i].v;
		if(v==p) continue;
		out[u]++;
		dfs2(v,u,rt);
		siz[u]+=siz[v];
	}
	mi+=siz[u]%2;rs+=siz[u];
	if(out[u]) b[rt].insert(mp(dep[u],u));
}
void dfs3(int u)
{
	if(!use[u]) dfn[++m]=u;
	for(int i=f[u];i;i=e[i].next)
	{
		int v=e[i].v;
		if(v==fa[u]) continue;
		dfs3(v);
	}
}
void del(int u)
{
	int x=fa[u];
	out[x]--;use[u]=1;
	if(out[x]==0) b[cl[x]].erase(mp(dep[x],x));
}
void match(int u)
{
	int t=0,p[5]={};
	for(int &i=cur[u];i && t<2;i=e[i].next)
	{
		int v=e[i].v;
		if(!use[v] && v!=fa[u]) p[++t]=v;
	}
	if(!use[u]) p[++t]=u;
	assert(t>=2);
	printf("%lld %lld\n",p[1],p[2]);
	del(p[1]);del(p[2]);
}
signed main()
{
	n=read();k=read();
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		e[++tot]=edge{v,f[u]},f[u]=tot;
		e[++tot]=edge{u,f[v]},f[v]=tot;
	}
	for(int i=1;i<=n;i++) cur[i]=f[i];
	dfs1(1,0);//find root
	for(int i=f[rt];i;i=e[i].next)
	{
		int v=e[i].v;
		dfs2(v,rt,v);//get the dep
		if(siz[v]>1) s.insert(mp(siz[v],v));
	}
	if(mi>k || rs<k || rs%2!=k%2)
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	rs=rs-k;
	while(rs)
	{
		int x=s.rbegin()->second,y=b[x].rbegin()->second;
		s.erase(mp(siz[x],x));
		if(2*dep[y]>=rs)//we can get the answer
		{
			y=b[x].lower_bound(mp(rs/2,0))->second;
			match(y);break;
		}
		rs-=2*dep[y];siz[x]-=2;
		match(y);
		if(siz[x]>1) s.insert(mp(siz[x],x));
	}
	dfs3(rt);
	assert(m%2==0);
	for(int i=1;i<=m/2;i++)
		printf("%lld %lld\n",dfn[i],dfn[i+m/2]);
}