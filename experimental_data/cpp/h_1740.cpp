// LUOGU_RID: 96791763
/*

¤ï¤ó¤ï¤ó¡­¡­¤ï¤ó¤À¤Û©`¤¤¤Ã¡î

Wonderhoy!

*/

#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

typedef double DB;

char buf[1<<21],*p1=buf,*p2=buf;

#define getchar() (p1==p2 && (p2=(p1=buf)+fread(buf,1,1<<18,stdin),p1==p2)?EOF:*p1++)

int read()

{

	int x=0;

	char c=getchar();

	while(c<'0' || c>'9')	c=getchar();

	while(c>='0' && c<='9')	x=(x<<1)+(x<<3)+(c^'0'),c=getchar();

	return x;

}

void write(int x)

{

	if(x>9)	write(x/10);

	putchar(x%10+'0');

}

struct node{

	int mext; // mextail: if [...] + mext then we will use {mexq,sumq} to transform.

	int mexp,mexq;

	int sump,sumq;

	node(int M=0,int Mp=0,int Mq=0,int Sp=0,int Sq=0){mext=M,mexp=Mp,mexq=Mq,sump=Sp,sumq=Sq;}

	node operator + (node ano) const

	{

		if(mext==-1)	return ano;

		if(ano.mext==-1)	return *this;

		node ret;

		ret.mext=ano.mext;

		ret.mexp=(mext==ano.mexp?mexq:mexp),ret.mexq=(mext==ano.mexq?mexq:mexp);

		ret.sump=ano.sump+(mext==ano.mexp?sumq:sump),ret.sumq=ano.sumq+(mext==ano.mexq?sumq:sump);

		return ret;

	}

}tr[1200005];

int n;

vector<int> G[300005];

int fa[300005],siz[300005],son[300005];

void dfs1(int u)

{

	siz[u]=1;

	for(auto v:G[u])

	{

		fa[v]=u;

		dfs1(v);

		siz[u]+=siz[v];

		if(siz[son[u]]<siz[v])	son[u]=v;

	}

}

int sjc,dfn[300005],top[300005],bot[300005];

void dfs2(int u,int t)

{

	dfn[u]=++sjc;

	top[u]=t;

	bot[u]=u;

	if(son[u])	dfs2(son[u],t),bot[u]=bot[son[u]];

	for(auto v:G[u])	if(v^son[u])	dfs2(v,v);

}

int occ[300005][20];

typedef pair<int,int> P;

#define mp make_pair

P mex(int u)

{

	int p=0;

	while(occ[u][p])	++p;

	int q=p+1;

	while(occ[u][q])	++q;

	return mp(p,q);

}

#define lc(x) (x<<1)

#define rc(x) (lc(x)|1)

#define Mm int mid=(l+r)>>1

void build(int l,int r,int now)

{

	tr[now]=node(-1);

	if(l==r)	return ;

	Mm;

	build(l,mid,lc(now)),build(mid+1,r,rc(now));

}

void modify(int l,int r,int now,int p,node w)

{

	if(l==r)	return void(tr[now]=w);

	Mm;

	if(p<=mid)	modify(l,mid,lc(now),p,w);

	else	modify(mid+1,r,rc(now),p,w);

	tr[now]=tr[lc(now)]+tr[rc(now)];

}

node query(int l,int r,int now,int x,int y)

{

	if(x<=l && r<=y)	return tr[now];

	if(r<x || y<l || x>y)	return node(-1);

	Mm;

	if(x<=mid && mid<y)	return query(l,mid,lc(now),x,y)+query(mid+1,r,rc(now),x,y);

	if(x<=mid)	return query(l,mid,lc(now),x,y);

	return query(mid+1,r,rc(now),x,y);

}

int ans;

int fmex[300005];

void modify(int u)

{

	int p=fa[u];

	while(p)	ans-=query(1,n,1,dfn[top[p]],dfn[bot[p]]).sump,p=fa[top[p]];

	modify(1,n,1,dfn[u],node(0,0,1,0,1));

	p=u;

	while(p)

	{

		node w=query(1,n,1,dfn[top[p]],dfn[bot[p]]);

		ans+=w.sump;

		if(!fa[top[p]])	break;

		int mx=w.mexp;

		p=top[p];

		if(fmex[p]>=0)	--occ[fa[p]][fmex[p]];

		++occ[fa[p]][fmex[p]=mx];

		P st=mex(p=fa[p]);

		int f=st.first,g=st.second;

		modify(1,n,1,dfn[p],node(f,f,g,f,g));

	}

	fmex[u]=0;

}

int main(){

	n=read()+1;

	for(int i=2;i<=n;++i)	G[fa[i]=read()].push_back(i);

	dfs1(1),dfs2(1,1);

	build(1,n,1);

	fill(fmex+1,fmex+1+n,-1);

	modify(1);

	for(int i=2;i<=n;++i)	modify(i),write(ans),puts("");

	return 0;

}