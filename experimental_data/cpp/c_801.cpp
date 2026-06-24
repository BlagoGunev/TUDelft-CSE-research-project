#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define eps 1e-6
#define MN 100005
#define INF 0x3FFFFFFF
using namespace std;
/*struct node
{
	int now,step,pos;
	friend bool operator<(node a,node b)
	{
		return a.now>b.now ||
			   a.now==b.now && a.step>b.step;
	}
};
struct edge{int nex,to,w;}e[MN];*/
int n;
double m,tot,cs[MN],w[MN];
double L,R,mid,lf,lt;//m,ans,sum;
//int hr[MN];
//int to[MN],del[MN];
//priority_queue <node> q;
//bool u[MN];
//char c[MN];
//int hr[MN],nex[MN],to[MN],dep[MN],q[MN],fa[MN],hd,tl,pin,inf;
//bool u[MN];

//inline void ins(int x,int y,int z) {e[++pin]=(edge){hr[x],y,z}; hr[x]=pin;}
//inline void ins(int x,int y) {++pin; nex[pin]=hr[x]; to[pin]=y; hr[x]=pin;}
inline int read()
{
	int n=0,f=1; char c=getchar();
	while (c<'0' || c>'9') {if(c=='-')f=-1; c=getchar();}
	while (c>='0' && c<='9') {n=n*10+c-'0'; c=getchar();}
	return n*f;
} 
/*
void bfs()
{
	register int i,x;
	memset(dep,127/3,sizeof(dep));
	inf=dep[0]; hd=1; tl=0;
	for (i=1;i<=m;++i) if (dep[a[i]]==inf) q[++tl]=a[i],dep[a[i]]=0;
	while (hd<=tl)
	{
		x=q[hd++];
		for (int i=hr[x];i;i=nex[i])
		{
			if (to[i]==fa[x]) continue;
			if (dep[to[i]]!=inf) {++ans; u[i]=true; continue;}
			dep[to[i]]=dep[x]+1; q[++tl]=to[i]; fa[to[i]]=x;
		}
	}
}*/

//bool cmp(int x,int y) {return c[x]<c[y] || c[x]==c[y] && x<y;}
/*
void dfs(int x)
{
	for (int i=hr[x];i;i=e[i].nex)
	{
		ans[e[i].to]=ans[x]+e[i].w;
		dfs(e[i].to);
	}
}*/

int main()
{
	register int i,j;
	n=read(); m=read();
	for (i=1;i<=n;++i) {tot+=cs[i]=read(); w[i]=read();}
	if (tot<=m+eps) return 0*printf("-1");
	L=0; R=100000000000;
//	printf("%.1lf %.1lf\n",L,R);
	while (R-L>eps)
	{
		mid=(L+R)/2; lf=m;
		for (i=1;i<=n;++i)
			if (mid*cs[i]>w[i])
			{
				lt=cs[i]-w[i]/mid;
				if (lt>lf+eps) break;
				lf-=lt;
			}
		if (i>n) L=mid; else R=mid;
	}
	printf("%.9lf",L);
}