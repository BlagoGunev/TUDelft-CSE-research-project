#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#define Rep(i,a,b) for(register int i=(a),i##end=(b);i<=i##end;++i)
#define Repe(i,a,b) for(register int i=(a),i##end=(b);i>=i##end;--i)
#define For(i,a,b) for(i=(a),i<=(b);++i)
#define Forward(i,a,b) for(i=(a),i>=(b);--i)
template<typename T>inline void read(T &x)
{
	T f=1;x=0;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+(c^48);
	x*=f;
}
using namespace std;
#define Chkmax(a,b) a=a>b?a:b
#define Chkmin(a,b) a=a<b?a:b
const int MAXN=2e5+7;
inline void file()
{
	#ifndef ONLINE_LUDGE
		freopen("b.in","r",stdin);
		freopen("b.out","w",stdout);
	#endif
}
static int n,m,s[MAXN];

static long long ans[MAXN];

static int e,head[MAXN];

static struct edge
{
	int v,nxt,id,w;
}p[MAXN<<1];

inline void add(int u,int v,int id,int w)
{p[++e]=(edge){v,head[u],id,w};head[u]=e;}

inline void init()
{
	read(n);
	Rep(i,1,n)read(s[i]);
	read(m);
	static int u,v;
	Rep(i,1,m)read(u),read(v),add(u,v,i,1),add(v,u,i,-1);
}
static int vis[MAXN],fr[MAXN],fa[MAXN];

static int que[MAXN],tp;

static queue<int>G;

inline void seaq(int ss)
{
	static int u;
	static long long sm;sm=0;
	G.push(ss);que[tp=1]=ss;vis[ss]=true;
	while(!G.empty())
	{
		u=G.front();G.pop();sm+=s[u];
		for(register int v=head[u];v;v=p[v].nxt)if(!vis[p[v].v])
			fa[p[v].v]=u,fr[p[v].v]=v,G.push(p[v].v),que[++tp]=p[v].v,vis[p[v].v]=true;
	}
	if(sm!=0)puts("Impossible"),exit(0);
	Repe(i,tp,2)
	{
		u=que[i];
		s[fa[u]]+=s[u];
		ans[p[fr[u]].id]+=(long long)s[u]*-p[fr[u]].w;
	}
}
inline void solve()
{
	Rep(i,1,n)if(!vis[i])seaq(i);
	puts("Possible");
	Rep(i,1,m)printf("%I64d\n",-ans[i]);
}
int main()
{
	init();
	solve();
	return 0;
}