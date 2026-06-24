#include <bits/stdc++.h>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
using namespace std;

void Get(int &T)
{
	char C;bool F=0;
	for(;C=getchar(),C<'0'||C>'9';)if(C=='-')F=1;
	for(T=C-'0';C=getchar(),C>='0'&&C<='9';T=T*10+C-'0');
	F&&(T=-T);
}

void Get(long long &T)
{
	char C;bool F=0;
	for(;C=getchar(),C<'0'||C>'9';)if(C=='-')F=1;
	for(T=C-'0';C=getchar(),C>='0'&&C<='9';T=T*10+C-'0');
	F&&(T=-T);
}

int N;

struct E
{
	int V,Next;
}Edge[200005];
int EdgeTop;
int Head[200005];

void Add(int U,int V)
{
	Edge[++EdgeTop]=(E){V,Head[U]};
	Head[U]=EdgeTop;
}

int Fa[200005];
int D[200005];
long long WOld[200005];
long long W[200005];

long long F[200005];
long long G[200005];

void DFS(int X)
{
	long long FMax=0,GMax=0;
	
	W[X]=WOld[X]-WOld[Fa[X]];
	
	for(int i=Head[X];i;i=Edge[i].Next)
		if(Fa[X]!=Edge[i].V)
		{
			Fa[Edge[i].V]=X;
			DFS(Edge[i].V);
			long long F0=F[Edge[i].V];
			long long G0=G[Edge[i].V];
			
			if(FMax<F0)FMax=F0;
			if(GMax<G0)GMax=G0;
		}
	
	F[X]=FMax;
	G[X]=GMax;
	
	if(X!=1)
	{
		if(W[X]>0)
			F[X]+=W[X];
		else
			G[X]-=W[X];
	}
}

void Init()
{
	Get(N);
	for(int i=1,U,V;i<N;i++)
	{
		Get(U);Get(V);
		Add(U,V);
		Add(V,U);
		D[U]++;D[V]++;
	}
	
	for(int i=1;i<=N;i++)
		Get(WOld[i]);
}

void Work()
{
	DFS(1);
}

long long Ans;

void Output()
{
	Ans=F[1]+G[1];
	
	WOld[1]+=F[1];
	WOld[1]-=G[1];
	
	Ans+=std::abs(WOld[1]);
	printf("%lld\n",Ans);
}

int main()
{
	Init();
	Work();
	Output();
	return 0;
}