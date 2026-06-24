#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
inline int getnum()
{
	int ans=0,fh=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')fh*=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')ans=ans*10+ch-'0',ch=getchar();
	return fh*ans;
}
int m,n;
int t[51000][10];
int f[51000][10];
int main(int argc, char *argv[])
{
	m=getnum();n=getnum();
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
		t[i][j]=getnum();
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			f[i][j]=max(f[i-1][j],f[i][j-1])+t[i][j];
	for(int i=1;i<m;i++)
		printf("%d ",f[i][n]);
	printf("%d\n",f[m][n]);
	return 0;
}