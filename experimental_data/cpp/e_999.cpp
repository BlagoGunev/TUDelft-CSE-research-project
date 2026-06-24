#include<iostream> 
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int read()
{
	int x=0,f=1;char c=getchar();
	while (c<'0'||c>'9') {if (c=='-') f=-1;c=getchar();}
	while (c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x*f;
}
#define N 5010
int n,m,s,p[N],dfn[N],low[N],stk[N],degree[N],set[N],t=0,cnt=0,ans,top=0;
bool flag[N];
struct data{int to,nxt;
}edge[N];
void addedge(int x,int y){t++;edge[t].to=y,edge[t].nxt=p[x],p[x]=t;}
void tarjan(int k)
{
	dfn[k]=low[k]=++cnt;
	stk[++top]=k;flag[k]=1;
	for (int i=p[k];i;i=edge[i].nxt)
	if (dfn[edge[i].to]) 
	{
		if (flag[edge[i].to]) low[k]=min(low[k],dfn[edge[i].to]);
	}
	else tarjan(edge[i].to),low[k]=min(low[k],low[edge[i].to]);
	if (dfn[k]==low[k])
	{
		t++;
		while (stk[top]!=k)
		{
			set[stk[top]]=t;
			flag[stk[top]]=0;
			top--;
		}
		set[k]=t;flag[k]=0;top--;
	}
}
int main()
{
	n=read(),m=read(),s=read();
	for (int i=1;i<=m;i++)
	{
		int x=read(),y=read();
		addedge(x,y);
	}
	t=0;
	for (int i=1;i<=n;i++) if (!dfn[i]) tarjan(i);
	for (int i=1;i<=n;i++)
		for (int j=p[i];j;j=edge[j].nxt)
		if (set[i]!=set[edge[j].to]) degree[set[edge[j].to]]++;
	for (int i=1;i<=t;i++) if (!degree[i]&&set[s]!=i) ans++;
	cout<<ans;
	return 0;
}