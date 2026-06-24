#include <bits/stdc++.h>
#define N 2000011
using namespace std;
int t,n,m;char ss[N];vector<vector<char>> s;
int cnt[5];
const int y[5]={1,3,0,2,4};
const int dxy[4][2]={{0,-1},{-1,0},{0,1},{1,0}};
inline int col(int I,int J)
{
	I%=5;J%=5;
	return ((J-y[I])%5+5)%5;
}
int main()
{
	scanf("%d",&t);while(t--)
	{
		scanf("%d%d",&n,&m);
		s.clear();
		s.resize(n+2,vector<char>(m+2,'.'));
		for(int i=1;i<=n;++i)
		{
			scanf("%s",ss+1);
			for(int j=1;j<=m;++j)s[i][j]=ss[j];
		}
		for(int i=0;i<5;++i)cnt[i]=0;
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=m;++j)if(s[i][j]=='#')
			{
				++cnt[col(i,j)];
				for(int _=0;_<4;++_)if(s[i][j]=='#'&&s[i+dxy[_][0]][j+dxy[_][1]]=='.')++cnt[col(i+dxy[_][0],j+dxy[_][1])];
			}
		}
		int mnx=0;
		for(int i=1;i<5;++i)if(cnt[i]<cnt[mnx])mnx=i;
		for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)if(s[i][j]=='#')
		{
			if(col(i,j)==mnx)s[i][j]='S';
			for(int _=0;_<4;++_)if(s[i][j]=='#'&&s[i+dxy[_][0]][j+dxy[_][1]]=='.'&&col(i+dxy[_][0],j+dxy[_][1])==mnx)s[i][j]='S';
		}
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=m;++j)putchar(s[i][j]);putchar(10);
		}
	}
}