#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
#define ll long long
#define MAX 1000100
inline int read()
{
	int x=0;bool t=false;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')t=true,ch=getchar();
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
	return t?-x:x;
}
int a[MAX],n,m;
int ans,f[2][10][10];
void cmax(int &x,int y){x=max(x,y);}
int main()
{
	n=read();m=read();
	for(int i=1;i<=n;++i)a[read()]+=1;
	for(int i=1;i<=m;++i)
		if(a[i]>6)
		{
			int d=(a[i]-6)/3;
			a[i]-=d*3;ans+=d;
		}
	memset(f,-63,sizeof(f));
	f[0][a[1]][a[2]]=ans;int nw=1,pw=0;
	for(int i=3;i<=m;++i,nw^=1,pw^=1)
	{
		memset(f[nw],-63,sizeof(f[nw]));
		for(int j=a[i-2];~j;--j)
			for(int k=a[i-1];~k;--k)
				if(f[pw][j][k]>=0)
					for(int l=0;l<=a[i]&&l<=j&&l<=k;++l)
						cmax(f[nw][k-l][a[i]-l],f[pw][j][k]+l+(j-l)/3);
	}
	for(int i=0;i<=a[m-1];++i)
		for(int j=0;j<=a[m];++j)
			ans=max(ans,f[pw][i][j]+i/3+j/3);
	printf("%d\n",ans);
	return 0;
}