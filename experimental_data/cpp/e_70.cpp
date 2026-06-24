#include<iostream>

#include<string.h>

#include<stdio.h>

#include<algorithm>

using namespace std;

const int M=185;

int dp[M][M],cost[M],d[M][M],best[M],k;

struct Edge{

	int to,nxt;

}G[M<<1];

int head[M],tot_edge,n;

inline void add_edge(int from,int to){

	G[tot_edge]=(Edge){to,head[from]};

	head[from]=tot_edge++;

	G[tot_edge]=(Edge){from,head[to]};

	head[to]=tot_edge++;

}

inline void Min(int &a,int b){

	if(a==-1||a>b)a=b;

}

inline void predfs(int v,int f,int *dis){

	for(int i=head[v];~i;i=G[i].nxt){

		int to=G[i].to;

		if(to==f)continue;

		dis[to]=dis[v]+1;

		predfs(to,v,dis);

	}

}

inline void dfs(int v,int f=0){

	for(int j=1;j<=n;++j)

		dp[v][j]=cost[d[v][j]];

	for(int i=head[v];~i;i=G[i].nxt){

		int to=G[i].to;

		if(to==f)continue;

		dfs(to,v);

		for(int j=1;j<=n;++j)

			dp[v][j]+=min(dp[to][j],dp[to][best[to]]+k);

	}

	dp[v][0]=1<<30;

	for(int j=1;j<=n;++j)

		if(dp[v][j]<dp[v][best[v]])best[v]=j;

}

int att[M];

inline void rdfs(int v,int j,int f=0){

	att[v]=j;

	for(int i=head[v];~i;i=G[i].nxt){

		int to=G[i].to;

		if(to==f)continue;

		rdfs(to,(dp[to][j]>dp[to][best[to]]+k)?best[to]:j,v);

	}

}

int main(){

	memset(head,-1,sizeof(head));

	tot_edge=0;

	cin>>n>>k;

	for(int i=1;i<n;++i)cin>>cost[i];

	for(int i=1,a,b;i<n;++i)cin>>a>>b,add_edge(a,b);

	for(int i=1;i<=n;++i)

		predfs(i,i,d[i]);

	dfs(1);

	cout<<dp[1][best[1]]+k<<endl;

	rdfs(1,best[1]);

	for(int i=1;i<=n;++i)

		printf("%d%c",att[i]," \n"[i==n]);

	return 0;

}