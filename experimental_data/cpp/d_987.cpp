#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,s,k,a[100010],head[100010],dis[110][100010];
int q[100010],h,t,size;
int nw[110];
struct edg{
	int to,next;
}e[200010];
void add(int x,int y)
{
	size++;e[size].to=y;e[size].next=head[x];head[x]=size;
}
void bfs(int T)
{
	while (h<t)
	{
		int x=q[++h];
		for (int i=head[x];i;i=e[i].next)
		{
			int y=e[i].to;
			if (dis[T][y]>1e9) dis[T][y]=dis[T][x]+1,q[++t]=y;
		}
	}
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&s,&k);memset(dis,63,sizeof(dis));
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int x,y,i=1;i<=m;i++) scanf("%d%d",&x,&y),add(x,y),add(y,x);
	for (int T=1;T<=s;T++)
	{
		h=t=0;
		for (int i=1;i<=n;i++)
			if (a[i]==T) dis[T][i]=0,q[++t]=i;
		bfs(T); 
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=s;j++)
			nw[j]=dis[j][i];
		sort(nw+1,nw+1+s);
		int ans=0;
		for (int j=1;j<=k;j++) ans+=nw[j];
		printf("%d ",ans);
	}
}