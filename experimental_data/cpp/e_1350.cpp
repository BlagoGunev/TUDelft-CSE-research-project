#include<bits/stdc++.h>
using namespace std;

typedef long long lint;
typedef long double louble;

#define so(a) ((int)((a).size()))

template<typename T1,typename T2> inline T1 max(T1 a,T2 b){return a<b?b:a;}
template<typename T1,typename T2> inline T1 min(T1 a,T2 b){return a<b?a:b;}

const char lf = '\n';

namespace ae86
{
	const int bufl = 1 << 15;

	char buf[bufl],*s=buf,*t=buf;

	inline int fetch()
	{
		if(s==t){t=(s=buf)+fread(buf,1,bufl,stdin);if(s==t)return EOF;}
		return *s++;
	}

	inline lint ty()
	{
		lint a=0;int b=1,c=fetch();
		while(!isdigit(c))b^=c=='-',c=fetch();
		while(isdigit(c))a=a*10+c-48,c=fetch();
		return b?a:-a;
	}

	inline int tc()
	{
		int c=fetch();
		while(c<=32 && c!=EOF)c=fetch();
		return c;
	}
	
	template<typename T> inline int ts(T *s)
	{
		int a=0,c=fetch();
		while(c<=32 && c!=EOF)c=fetch();
		while(c>32 && c!=EOF)s[a++]=c,c=fetch();
		s[a]=0;
		return a;
	}
}
using ae86::ty;
using ae86::tc;
using ae86::ts;

const int _ = 1007;
const int go[2][4] = {{0,1,0,-1},{1,0,-1,0}};

int n,m,qn;
char val[_][_]={0};
int xtim[_][_]={0};

int main()
{
	ios::sync_with_stdio(0),cout.tie(nullptr);

	n=ty(),m=ty(),qn=ty();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			val[i][j]=tc()-48;

	memset(xtim,-1,sizeof(xtim));

	for(int i=1;i<=n;i++)
		for(int j=1;j<m;j++)
			if(val[i][j]==val[i][j+1])xtim[i][j]=xtim[i][j+1]=0;
	for(int i=1;i<n;i++)
		for(int j=1;j<=m;j++)
			if(val[i][j]==val[i+1][j])xtim[i][j]=xtim[i+1][j]=0;

	queue<pair<int,int>> q;

	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(xtim[i][j]>=0)q.emplace(i,j);
	
	while(!q.empty())
	{
		auto [x,y]=q.front();q.pop();
		for(int k=0;k<4;k++)
		{
			int xx=x+go[0][k],yy=y+go[1][k];
			if(xx<1 || xx>n || yy<1 || yy>m || xtim[xx][yy]>=0)continue;
			xtim[xx][yy]=xtim[x][y]+1,q.emplace(xx,yy);
		}
	}

	for(int qq=1;qq<=qn;qq++)
	{
		int x=ty(),y=ty();lint tim=ty();
		if(xtim[x][y]<0 || tim<xtim[x][y])cout<<(int)val[x][y]<<lf;
		else cout<<(int)(((tim-xtim[x][y])&1)^val[x][y])<<lf;
	}
	
	return 0;
}