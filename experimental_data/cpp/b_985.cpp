#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int a[2333][2333],s[2333][2333];
int main()
{
	int n,m;
	scanf("%d%d\n",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			a[i][j]=getchar()-'0';
			s[i][j]=s[i-1][j]+a[i][j];
		}
		getchar();
	}
	for(int i=1;i<=n;i++)
	{
		int gg=0;
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]==1&&s[n][j]==1)gg=1;
		}
		if(!gg)
		{
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}