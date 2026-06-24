#include<iostream>

#include<cstdio>

#include<algorithm>

#include<cmath>

#include<vector>

#include<set>

#include<cstring>

using namespace std;

inline int read()

{

	int x=0,f=1; char ch=getchar();

	while (ch<'0' || ch>'9') {if (ch=='-') f=-1; ch=getchar();}

	while (ch>='0' && ch<='9') {x=x*10+ch-'0'; ch=getchar();}

	return x*f;

}

#define INF 0x7fffffff

#define MAXN 100100

int N,M,Q,val[MAXN],Val[MAXN<<1];

struct RoadNode{int next,to;}road[MAXN<<1];

int tot=1,first[MAXN];

struct EdgeNode{int next,to;}edge[MAXN<<2];

int cnt=1,head[MAXN<<1];

inline void AddEdge(int u,int v) {cnt++; edge[cnt].next=head[u]; head[u]=cnt; edge[cnt].to=v;}

inline void InsertEdge(int u,int v) {AddEdge(u,v); AddEdge(v,u);}

multiset<int>::iterator ist;

struct BlockNode

{

	multiset<int>st; int val; 

	void insert(int x) {st.insert(x); val=*st.begin();}

	void change(int x,int y) {st.erase(*st.find(x)); st.insert(y); val=*st.begin();}

}B[MAXN<<1];

namespace Graph

{

	inline void AddRoad(int u,int v) {tot++; road[tot].next=first[u]; first[u]=tot; road[tot].to=v;}

	inline void InsertRoad(int u,int v) {AddRoad(u,v); AddRoad(v,u);}

	int dfn[MAXN],low[MAXN],dfsn,bcc,now,belong[MAXN],size[MAXN],cut[MAXN],st[MAXN],top;

	inline void Tarjan(int now)

	{

		dfn[now]=low[now]=++dfsn; st[++top]=now;

		for (int i=first[now]; i; i=road[i].next)	

			if (!dfn[road[i].to])

				{

					Tarjan(road[i].to); low[now]=min(low[now],low[road[i].to]);

					if (dfn[now]<=low[road[i].to])

						{

							bcc++; cut[now]=1; int tp=0;

							while (1) 

								{

									tp=st[top--]; belong[tp]=bcc; 

									if (cut[tp]) InsertEdge(tp+N,bcc); if (tp==road[i].to) break;

								}

							InsertEdge(now+N,bcc);

						}

				}

			else low[now]=min(low[now],dfn[road[i].to]);

	}

	void reBuild()

	{

		for (int i=1; i<=N; i++) if (!dfn[i]) Tarjan(i);

		for (int i=1; i<=N; i++)

			{

				if (i!=1) B[belong[i]].insert(val[i]);

				if (cut[i]) B[i+N].insert(INF);

			}

	}

}

namespace SegmentTree

{

	struct SegmentTreeNode{int l,r,minx;}tree[MAXN<<3];

	#define ls now<<1

	#define rs now<<1|1

	inline void Update(int now) {tree[now].minx=min(tree[ls].minx,tree[rs].minx);}

	inline void BuildTree(int now,int l,int r)

	{

		tree[now].l=l; tree[now].r=r;

		if (l==r) {tree[now].minx=Val[l]; return;}

		int mid=(l+r)>>1;

		BuildTree(ls,l,mid); BuildTree(rs,mid+1,r);

		Update(now);

	}

	inline void Change(int now,int pos,int D) 

	{

		int l=tree[now].l,r=tree[now].r;

		if (l==r) {tree[now].minx=D; return;}

		int mid=(l+r)>>1;

		if (pos<=mid) Change(ls,pos,D);

		if (pos>mid) Change(rs,pos,D);

		Update(now);

	}

	inline int Query(int now,int L,int R)

	{

		int l=tree[now].l,r=tree[now].r;

		if (L<=l && R>=r) return tree[now].minx;

		int mid=(l+r)>>1,re=INF;

		if (L<=mid) re=min(re,Query(ls,L,R));

		if (R>mid) re=min(re,Query(rs,L,R));

		return re;

	}

}

namespace TreePartition

{

	int fa[MAXN<<1],size[MAXN<<1],son[MAXN<<1],deep[MAXN<<1],pl[MAXN<<1],dfn,pre[MAXN<<1],top[MAXN<<1];

	inline void DFS_1(int now)

	{

		size[now]=1;

		for (int i=head[now]; i; i=edge[i].next)

			if (edge[i].to!=fa[now])

				{

					fa[edge[i].to]=now;

					deep[edge[i].to]=deep[now]+1;

					DFS_1(edge[i].to);

					size[now]+=size[edge[i].to];

					if (size[son[now]]<size[edge[i].to]) son[now]=edge[i].to;	

				}

	}

	inline void DFS_2(int now,int chain)

	{

		pl[now]=++dfn; pre[dfn]=now;  top[now]=chain; Val[dfn]=B[now].val;

		if (son[now]) DFS_2(son[now],chain);

		for (int i=head[now]; i; i=edge[i].next)

			if (edge[i].to!=fa[now] && edge[i].to!=son[now])

				DFS_2(edge[i].to,edge[i].to);

	}

	inline int LCA(int u,int v)

	{

    	while (top[u]!=top[v])

     	   	{

            	if (deep[top[u]]<deep[top[v]]) swap(u,v);

            	u=fa[top[u]];

        	}

    	if (deep[u]>deep[v]) swap(u,v);

    	return u;

	}

	inline int Query(int x,int y)

	{

		x=Graph::cut[x]? x+N:Graph::belong[x]; y=Graph::cut[y]? y+N:Graph::belong[y];

		int re=INF; int lca=LCA(x,y);

		if (lca<=Graph::bcc) lca=fa[lca]; re=val[lca-N];

		while (top[x]!=top[y])

			{

				if (deep[top[x]]<deep[top[y]]) swap(x,y);

				re=min(re,SegmentTree::Query(1,pl[top[x]],pl[x]));

				x=fa[top[x]];

			}

		if (deep[x]>deep[y]) swap(x,y);

		re=min(re,SegmentTree::Query(1,pl[x],pl[y]));

		return re;

	}

	inline void Change(int pos,int D) {SegmentTree::Change(1,pl[pos],D);}

}

int main()

{

	N=read(),M=read(),Q=read();

	for (int i=1; i<=N; i++) val[i]=read();

	for (int x,y,i=1; i<=M; i++) x=read(),y=read(),Graph::InsertRoad(x,y);

	Graph::reBuild();

//	for (int i=1; i<=N; i++) printf("%d %d %d %d\n",dfn[i],low[i],cut[i],belong[i]);

	TreePartition::DFS_1(N+1); TreePartition::DFS_2(N+1,N+1);

	SegmentTree::BuildTree(1,1,TreePartition::dfn);

	while (Q--)

		{

			char opt[2]; scanf("%s",opt); int x=read(),y=read();

			switch (opt[0])

				{

					case 'C': if (x!=1) {B[Graph::belong[x]].change(val[x],y); TreePartition::Change(Graph::belong[x],B[Graph::belong[x]].val);} val[x]=y; break;

					case 'A': if (x==y) printf("%d\n",val[x]); else printf("%d\n",TreePartition::Query(x,y)); break;

				}

		}

	return 0;

}