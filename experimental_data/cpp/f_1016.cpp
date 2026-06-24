#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstring>
#define N 600005
#define ll long long
using namespace std;
bool flag;
ll Max=-1e18,tpMax=-1e18,dep[N],a[N];
int n,m,sz[N],In[N];
int TOT,LA[N],NE[N<<1],EN[N<<1];
ll LE[N<<1];
void Link(int x,int y,int z)
{
	EN[++TOT]=y;LE[TOT]=z;NE[TOT]=LA[x];LA[x]=TOT;
	EN[++TOT]=x;LE[TOT]=z;NE[TOT]=LA[y];LA[y]=TOT;
}
void pre_dfs(int x,int fa)
{
	if(x==n)In[x]=x;
	int i,y;sz[x]=1;ll tp=-1e18,ttp=-1e18;
	for(i=LA[x];i;i=NE[i])
	{
		y=EN[i];if(y==fa)continue;
		dep[y]=dep[x]+LE[i];
		pre_dfs(y,x);
		sz[x]+=sz[y];
		if(In[y])In[x]=y;
		else a[x]=LE[i];
		if(a[y]&&In[y])tp=max(tp,a[y]-dep[y]);
		if(In[y])ttp=max(ttp,a[y]-dep[y]);
	}
	if(sz[x]-sz[In[x]]>2)flag=1;
	if(x==n&&sz[x]>2)flag=1;
	if(In[x])
	{
		Max=max(Max,a[x]+dep[x]+max(tpMax,tp));
		if(a[x])Max=max(Max,a[x]+dep[x]+ttp);
		for(i=LA[x];i;i=NE[i])
		{
			y=EN[i];if(y==fa)continue;
			if(In[y])tpMax=max(tpMax,a[y]-dep[y]);
		}
	}
}
int main()
{
	int i,j,k,x,y,z;ll t;
	scanf("%d%d",&n,&m);
	for(i=1;i<n;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		Link(x,y,z);
	}
	pre_dfs(1,0);
	for(i=1;i<=m;i++)
	{
		scanf("%I64d",&t);
		if(flag||t+Max>=0)printf("%I64d\n",dep[n]);
		else printf("%I64d\n",dep[n]+t+Max);
	}
}