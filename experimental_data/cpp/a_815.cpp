#include <cstdio>
#include <algorithm>
using namespace std;

int n,m;
int g[101][101];
int row[101],col[101];
int ans,mini;

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	    for(int j=1;j<=m;j++) scanf("%d",&g[i][j]);
	
	for(int j=2;j<=m;j++)
	{
		int cur=g[1][j]-g[1][1];
		for(int i=2;i<=n;i++)
			if (g[i][j]-g[i][1]!=cur) 
			{
				printf("-1\n");
				return 0;
			}
	}
	
	mini=1;
	for(int j=2;j<=m;j++) if (g[1][j]<g[1][mini]) mini=j;
	for(int j=1;j<=m;j++) 
	{
		row[j]=g[1][j]-g[1][mini];
		for(int i=1;i<=n;i++)
		    g[i][j]-=row[j];
	}
	
	if (n>m)
	{
		mini=1000;
		for(int i=1;i<=n;i++) mini=min(mini,g[i][1]);
		for(int j=1;j<=m;j++)
		    row[j]+=mini;
		for(int i=1;i<=n;i++) g[i][1]-=mini;
	}
	
	ans=0;
	for(int j=1;j<=m;j++) ans+=row[j];
	for(int i=1;i<=n;i++) ans+=g[i][1];
	
	printf("%d\n",ans);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=g[i][1];j++)
		    printf("row %d\n",i);
	for(int j=1;j<=m;j++)
	    for(int i=1;i<=row[j];i++)
	        printf("col %d\n",j);
	return 0;
}