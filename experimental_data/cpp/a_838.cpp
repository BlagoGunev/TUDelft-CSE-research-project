#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int MAXN=2500;
const int INF=0x7fffffff;
int n,m;
char s[MAXN+10];
int sum[MAXN+10][MAXN+10];
int GetSum(int x1,int y1,int x2,int y2)
{
	x2=min(x2,n);y2=min(y2,m);
	return sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1];
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		scanf("%s",s+1);
		for(int j=1;j<=m;++j)
		{
			if(s[j]=='0')sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
			else sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+1;
		}
	}
	int res=INF;
	for(int k=2;k<=MAXN;++k)
	{
		int t1=0,t2;
		for(int i=1;i<=n;i+=k)
		{
			for(int j=1;j<=m;j+=k)
			{
				t2=GetSum(i,j,i+k-1,j+k-1);
				t1+=min(t2,k*k-t2);
			}
		}
		res=min(res,t1);
	}
	printf("%d",res);
	return 0;
}