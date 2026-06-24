#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
#define maxn 201000

struct node
{
	int x,y;bool bk;
}e[maxn*4];
int fa[maxn],d[maxn];
int ffind(int x)
{
	if (fa[x]!=x) fa[x]=ffind(fa[x]);
	return fa[x];
}
int main()
{
	int n,m,i,x,y,cnt,mx,id;
	memset(d,0,sizeof(d));
	scanf("%d%d",&n,&m);
	for (i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		d[x]++;d[y]++;
		e[i].x=x;e[i].y=y;//ins(x,y);
		e[i].bk=false;
	}
	mx=0;id=-1;cnt=0;
	for (i=1;i<=n;i++)
	{
		if (d[i]>mx) mx=d[i],id=i;
		fa[i]=i;
	}
	for (i=1;i<=m;i++)
	 if (e[i].x==id || e[i].y==id)
	 {
		 int fx=ffind(e[i].x);
		 int fy=ffind(e[i].y);
		 fa[fx]=fy;cnt++;
		 e[i].bk=true;
	 }
	if (cnt!=n-1)
	{
		for (i=1;i<=m;i++) if (!e[i].bk)
		{
			int fx=ffind(e[i].x);
			int fy=ffind(e[i].y);
			if (fx==fy) continue;
			fa[fx]=fy;cnt++;
			e[i].bk=true;
			if (cnt==n-1) break;
		}
	}
	for (i=1;i<=m;i++)
	 if (e[i].bk) printf("%d %d\n",e[i].x,e[i].y);
	return 0;
}