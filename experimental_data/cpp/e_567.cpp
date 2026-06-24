#include <cstdio>

#include <cstring>

#include <queue>

#include <utility>

#include <vector>

#define min(a,b) ((a)<(b)?(a):(b))

#define mp std::make_pair

#define inf ((~(1LL<<63))>>2)

typedef long long i64;

struct N{int u,v;i64 l;}node[100001];

struct E{int v,nxt;i64 l;}e[300001];

typedef std::pair<i64,int> qm;

int fst[100001],ec,S,T,n,m,rem[100001],dfn[100001],ts;

i64 ps[100001],pt[100001];

bool set[100001],br[100001],vis[100001];

void ae(int u,int v,i64 l){e[ec]=E{v,fst[u],l};fst[u]=ec++;}

void dijkstra(int f)

{

	std::priority_queue<qm,std::vector<qm>,std::greater<qm>> q;qm t;

	for(int i=1;i<=n;++i){f?pt[i]=inf:ps[i]=inf;set[i]=0;}

	t.first=0;if(f)pt[T]=0,t.second=T;else ps[S]=0,t.second=S;

	q.push(t);

	while(!q.empty())

	{

		qm c=q.top();q.pop();

		int u=c.second,v;if(set[u])continue;set[u]=1;

		for(int i=fst[u];~i;i=e[i].nxt)

		{

			v=e[i].v;if(set[v])continue;

			if(f)

			{

				if(pt[v]>pt[u]+e[i^1].l&&e[i].l==inf)

				{pt[v]=pt[u]+e[i^1].l;q.push(mp(pt[v],v));}

			}

			else

			{

				if(ps[v]>ps[u]+e[i].l&&e[i].l<inf)

				{ps[v]=ps[u]+e[i].l;q.push(mp(ps[v],v));}

			}

		}

	}

}

void tarjan(int u)

{

	rem[u]=dfn[u]=++ts;

	for(int i=fst[u];~i;i=e[i].nxt)

	{

		fst[u]=e[i].nxt;

		if(vis[e[i].l])continue;vis[e[i].l]=1;

		if(!dfn[e[i].v]){tarjan(e[i].v);rem[u]=min(rem[u],rem[e[i].v]);if(dfn[u]<rem[e[i].v])br[e[i].l]=1;}

		else if(rem[u]>dfn[e[i].v])rem[u]=dfn[e[i].v];

	}

}

int main()

{

	scanf("%d%d%d%d",&n,&m,&S,&T);

	ec=0;memset(fst,0xff,sizeof(fst));

	for(int i=0;i<m;++i)

	{

		scanf("%d%d%I64d",&node[i].u,&node[i].v,&node[i].l);

		ae(node[i].u,node[i].v,node[i].l);

		ae(node[i].v,node[i].u,inf);

	}

	dijkstra(0);dijkstra(1);ts=0;i64 ref=ps[T];

	ec=0;memset(fst,0xff,sizeof(fst));

	for(int i=0;i<m;++i)

	if(ps[node[i].u]+pt[node[i].v]+node[i].l==ref)

	ae(node[i].u,node[i].v,i),ae(node[i].v,node[i].u,i);

	tarjan(S);

	for(int i=0;i<m;++i)

	if(br[i])puts("YES");else

	{

		i64 tl=ref-ps[node[i].u]-pt[node[i].v]-1;

		if(tl>0)printf("CAN %I64d\n",node[i].l-tl);else puts("NO");

	}

	return 0;

}