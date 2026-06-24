#include<iostream>//       164

#include<cstdio>

#include<cmath>

#include<algorithm>

#include<cstring>

using namespace std;

//====================================================

struct E{int to,nxt;double d;}b[2000005];

int fst[1005],T;

void build(int f,int t,double d)

{b[++T].to=t;b[T].d=d;b[T].nxt=fst[f];fst[f]=T;}

//====================================================

struct P{int x,y;}p[1005];

double dis[1005][1005];

double D[2000005];int tot;

double f(int x){return (double)(x*x);}

int n,k;

double Max;

void init()

{

	scanf("%d%d",&n,&k);

	for(int i=1;i<=n;i++)

		scanf("%d%d",&p[i].x,&p[i].y);

	for(int i=1;i<n;i++)

	for(int j=i+1;j<=n;j++)

	{

		double x=f(p[i].x-p[j].x)+f(p[i].y-p[j].y);

		x=sqrt(x);dis[i][j]=x;Max=max(Max,x);

		D[++tot]=x;

	}

	sort(D+1,D+tot+1);D[++tot]=Max+1.0;

	tot=unique(D+1,D+tot+1)-D-1;

}

int cd[1005];

int use[1005],ans,h;

int q[1005],fro;

int vis[1005][1005];

void dfs(int x,int u)

{

	if(u>k||ans) return ;

	if(x>fro)

	{

		bool b=0;

		if(h){

			for(int i=1;i<=n;i++)

				if(use[i]) printf("%d ",i),b=1;

			if(!b) printf("1");

		}

		ans=1;

		return ;

	}

	int f=q[x];

	if(use[f]) dfs(x+1,u);

	else 

	{

		int a=u;

		for(int i=fst[f];i;i=b[i].nxt)

		{

			int v=b[i].to;

			if(!use[v])a++;use[v]++;

		}

		dfs(x+1,a);

		for(int i=fst[f];i;i=b[i].nxt)

			use[b[i].to]--;

		if(cd[f]!=1&&u+1<a)

			{use[f]=1;dfs(x+1,u+1);use[f]=0;}

	}

}

bool check(double x)

{

	memset(cd,0,sizeof(cd));

	memset(fst,0,sizeof(fst));

	memset(use,0,sizeof(use));

	T=0;fro=0;

	for(int i=1;i<n;i++)

	for(int j=i+1;j<=n;j++)

		if(dis[i][j]>=x)

		{

			build(i,j,dis[i][j]);

			build(j,i,dis[i][j]);

			if(!cd[i]) q[++fro]=i;

			if(!cd[j]) q[++fro]=j;

			cd[i]++;cd[j]++;

		}

	ans=0;dfs(1,0);

	return ans;

}

void work()

{

	init();

	int l=1,r=tot;

	while(r-l>1)

	{

		int mid=(l+r)>>1;

		if(check(D[mid]))r=mid;

		else l=mid;

	}

	h=1;bool c=check(D[r]);

}

int main()

{

	work();

}