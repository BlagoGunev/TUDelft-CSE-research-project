#include<stdio.h>

#include<cstring>

#include<algorithm>

using namespace std;

#define N 1005

#define M 10005

#define ll long long

int n,m,i,j,v,k,S,T,cnt;

int head[N],U[M],V[M];

ll L,dis[N],ret[N],len[M],ans;

bool vis[N];

struct ff{int to,nxt;ll len;}e[2*M];

void add(int u,int v,int len){

	e[++cnt]=(ff){v,head[u],len};

	head[u]=cnt;

}

int main()

{

	scanf("%d%d%I64d%d%d",&n,&m,&L,&S,&T);

	cnt=1;

	for(i=1;i<=m;i++){

		scanf("%d%d%I64d",&U[i],&V[i],&len[i]);

		add(U[i],V[i],len[i]),add(V[i],U[i],len[i]);

	}

	memset(ret,60,sizeof(ret));

	memset(vis,0,sizeof(vis));

	ret[T]=0;

	for(i=1;i<=n;i++){

		k=-1;

		for(j=0;j<n;j++)

			if(!vis[j]&&(k==-1||ret[j]<ret[k]))k=j;

		vis[k]=1;

		for(j=head[k];j;j=e[j].nxt){

			int v=e[j].to;

			if(e[j].len&&ret[k]+e[j].len<ret[v])ret[v]=ret[k]+e[j].len;

		}

	}if(ret[S]<L){puts("NO");return 0;}

	memset(dis,60,sizeof(dis));

	memset(vis,0,sizeof(vis));

	dis[S]=0;

	for(i=1;i<=n;i++){

		k=-1;

		for(j=0;j<n;j++)

			if(!vis[j]&&(k==-1||dis[j]<dis[k]))k=j;

		vis[k]=1;

		for(j=head[k];j;j=e[j].nxt){

			int v=e[j].to;

			if(!e[j].len){

				if(ret[v]<ret[n])e[j].len=L-ret[v]-dis[k];

					else e[j].len=1;

				if(e[j].len<=0)e[j].len=1;

				e[j^1].len=len[j/2]=e[j].len;

			}

			if(dis[k]+e[j].len<dis[v])dis[v]=dis[k]+e[j].len;

		}

	}if(dis[T]!=L){puts("NO");return 0;}

	puts("YES");

	for(i=1;i<=m;i++)

		printf("%d %d %I64d\n",U[i],V[i],len[i]);

	return 0;

}