#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long
#define N 14
#define M 1000
#define inf 100000000
#define rep(i,t,S) for (int t=S,i=lg2[t&-t];t;t^=t&-t,i=lg2[t&-t])
char getc(){char c=getchar();while ((c<'A'||c>'Z')&&(c<'a'||c>'z')&&(c<'0'||c>'9')) c=getchar();return c;}
int gcd(int n,int m){return m==0?n:gcd(m,n%m);}
int read()
{
    int x=0,f=1;char c=getchar();
    while (c<'0'||c>'9') {if (c=='-') f=-1;c=getchar();}
    while (c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
    return x*f;
}
int n,m,a[N][N],f[1<<N],size[1<<N],lg2[1<<N];
bool g[N][N][1<<N];
int way[N][N][1<<N][N+1];
struct data{int x,y,z;
}edge[M];
void print(int S)
{
	if (size[S]==1) return;
	for (int i=S-1&S;i;i=i-1&S)
    rep(x,u,i^S) rep(y,v,i^S)
    {
        if (g[x][y][i]&&f[i^S]+size[i]+1==f[S])
		{
			cout<<y+1<<' '<<way[x][y][i][1]+1<<endl;
			for (int t=1;t<way[x][y][i][0];t++) cout<<way[x][y][i][t]+1<<' '<<way[x][y][i][t+1]+1<<endl;
			cout<<way[x][y][i][way[x][y][i][0]]+1<<' '<<x+1<<endl;
			print(i^S);
			return;
		}
        if (x==y) break;
    }
}
int main()
{
    n=read(),m=read();
    for (int i=1;i<=m;i++)
	{
		edge[i].x=read()-1,edge[i].y=read()-1,edge[i].z=1;
		g[edge[i].x][edge[i].y][0]=g[edge[i].y][edge[i].x][0]=1;
	}
    memset(f,42,sizeof(f));for (int i=0;i<n;i++) f[1<<i]=0,lg2[1<<i]=i;
	for (int i=1;i<(1<<n);i++) size[i]=size[i^(i&-i)]+1;
    for (int i=1;i<(1<<n);i++)
    {
        rep(x,p,(1<<n)-1^i) rep(y,q,(1<<n)-1^i)
        if (x!=y||i!=(i&-i)) rep(j,o,i)
			if (g[j][y][i^(1<<j)]&&g[x][j][0])
			{
				g[x][y][i]=1;
				for (int u=0;u<=way[j][y][i^(1<<j)][0];u++) way[x][y][i][u]=way[j][y][i^(1<<j)][u];
				way[x][y][i][++way[x][y][i][0]]=j;
				break;
			}
    }
    for (int i=1;i<(1<<n);i++)
        for (int j=i-1&i;j;j=j-1&i)
            rep(x,u,i^j) rep(y,v,i^j)
            {
                if (g[x][y][j]&&f[i^j]+size[j]+1<f[i]) f[i]=f[i^j]+size[j]+1;
                if (x==y) break;
            }
    printf("%d\n",f[(1<<n)-1]);
    print((1<<n)-1);
    return 0;
}
//rep����ö���Ӽ��ڵĵ� 
//g[i][j][S]i��j�ܷ�S��һ����������