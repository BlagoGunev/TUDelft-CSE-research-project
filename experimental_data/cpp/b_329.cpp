#include<cstdio>
#include<cstring>
const int N = 1005;
char g[N][N];
int dp[N][N],q[N*N][2];
int c[4][2]={1,0,0,1,-1,0,0,-1};
int main()
{
	int n,m,i,j;
	scanf("%d%d",&m,&n);
	for(i=0;i<m;i++)
	{
		scanf("%s",g[i]);
	}
	int sx,sy,ex,ey;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(g[i][j]=='E')
			{
				sx=i;
				sy=j;
			}
			else if(g[i][j]=='S')
			{
				ex=i;
				ey=j;
			}
		}
	}
	memset(dp,-1,sizeof(dp));
	int t=0,w=1;
	q[0][0]=sx;
	q[0][1]=sy;
	dp[sx][sy]=0;
	while(t<w)
	{
		int nx=q[t][0],ny=q[t][1];
		t++;
		for(i=0;i<4;i++)
		{
			int tx=nx+c[i][0];
			int ty=ny+c[i][1];
			if(tx>=0&&ty>=0&&tx<m&&ty<n&&g[tx][ty]!='T'&&dp[tx][ty]==-1)
			{
				dp[tx][ty]=dp[nx][ny]+1;
				q[w][0]=tx;
				q[w][1]=ty;
				w++;
			}
		}
	}
	int dep=dp[ex][ey],r=0;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(g[i][j]>='0'&&g[i][j]<='9'&&dp[i][j]!=-1&&dp[i][j]<=dep)r+=g[i][j]-'0';
		}
	}
	printf("%d\n",r);
	return 0;
}