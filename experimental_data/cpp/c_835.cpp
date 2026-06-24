#include<bits/stdc++.h>
using namespace std;
const int maxn = 109;

int cnt[20][maxn][maxn];
int n,q,c;

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int main()
{
	n=read();q=read();c=read()+1;
	for(int i=1;i<=n;i++)
	{
		int x=read(),y=read(),z=read();
		cnt[z][x][y]++;
	}
	for(int k=0;k<c;k++)
		for(int i=1;i<=100;i++)
			for(int j=1;j<=100;j++)
			{
				cnt[k][i][j]=cnt[k][i-1][j]+cnt[k][i][j-1]-cnt[k][i-1][j-1]+cnt[k][i][j];
			}
	while(q--)
	{
		int t=read(),x1=read(),y1=read(),x2=read(),y2=read(),ans=0;
		for(int i=0;i<c;i++)
		{
			int tot=cnt[i][x2][y2]-cnt[i][x1-1][y2]-cnt[i][x2][y1-1]+cnt[i][x1-1][y1-1];
			ans+=tot*((i+t)%c);
		}
		printf("%d\n",ans);
	}
	return 0;
}