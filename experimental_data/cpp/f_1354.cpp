#include<bits/stdc++.h>
#define ll long long
#define ls u<<1
#define rs u<<1|1
#define mm(x) memset(x,0,sizeof(x))
using namespace std;
int read()
{
	int a=0;int f=0;char p=getchar();
	while(!isdigit(p)){f|=p=='-';p=getchar();}
	while(isdigit(p)){a=(a<<3)+(a<<1)+(p^48);p=getchar();}
	return f?-a:a;
}
const int INF=998244353;
const int P=998244353;
const int N=2e6+5;
int T;
int n,m;
int val[N];
int a[N],b[N];
int pos[N];
int dp[80][80];
struct node
{
	int dp0,dp1;
	int happen;
	int sum;
}op[80][80];
bool cmp(int x,int y)
{
	return b[x]<b[y];
}
int t[N],top;
bool vis[N];
void dfs(int x,int y)
{
	if(x==0&&y==0)	return ;
	//cout<<"--- "<<x<<" "<<y<<" "<<op[x][y].dp0<<" "<<op[x][y].dp1<<" "<<op[x][y].happen<<endl;
	dfs(op[x][y].dp0,op[x][y].dp1);
	int now=op[x][y].happen;
	if(now>0)
	{
		vis[now]=true;
		t[++top]=now;
	}
}
void solve()
{
	n=read();	m=read();
	for(int i=1;i<=n;++i)
	{
		pos[i]=i;	vis[i]=false;
		a[i]=read();
		b[i]=read();
	}
	sort(pos+1,pos+n+1,cmp);
	memset(dp,-1,sizeof(dp));
	dp[0][0]=0;
	for(int i=0;i<n;++i)
	{
		int now=pos[i+1];
		for(int j=0;j<=m;++j)
		{
			if(dp[i][j]==-1)	continue;
			if(dp[i+1][j+1]<dp[i][j]+a[now]+b[now]*j)
			{
				dp[i+1][j+1]=dp[i][j]+a[now]+b[now]*j;
				op[i+1][j+1].dp0=i;
				op[i+1][j+1].dp1=j;
				op[i+1][j+1].happen=now;
				op[i+1][j+1].sum=op[i][j].sum+1;
			}
			if(dp[i+1][j]<dp[i][j]+b[now]*(m-1))
			{
				dp[i+1][j]=dp[i][j]+b[now]*(m-1);
				op[i+1][j].dp0=i;
				op[i+1][j].dp1=j;
				op[i+1][j].happen=-now;
				op[i+1][j].sum=op[i][j].sum+1;
			}
		}
	}
	//printf("%d\n",dp[n][m]);
	top=0;	dfs(n,m);
	printf("%d\n",m+(n-m)*2);
	for(int i=1;i<m;++i)	printf("%d ",t[i]);
	for(int i=1;i<=n;++i)	if(!vis[i])	printf("%d %d ",i,-i);
	printf("%d\n",t[m]);
}
int main()
{
	T=read();
	while(T--)	solve();
	return 0;
}