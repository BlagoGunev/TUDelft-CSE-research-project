#include<bits/stdc++.h>
using namespace std;
const int N=6e3+5;
int T,n,mod,f[N][N][2],ans[N];
int power(int a,int b){int res=1;for(;b;b>>=1){if(b&1)res=1ll*res*a%mod;a=1ll*a*a%mod;}return res;}
void slv1()
{
	for(int i=1;i<=n*2;i++)for(int j=i;j<=n*2;j++)f[i][j][0]=f[i][j][1]=0;
	for(int i=1;i<=n;i++)f[i][i+n-1][0]=1;
	int r=n;
	for(int t=n;t>=2;t--)
	{
		for(int i=1;i<=n*2-t;i++)
		{
			int j=i+t-1;
			f[i+1][j][0]=(f[i+1][j][0]+1ll*f[i][j][0]*(n-max(j-i+1,r-i+1)+1))%mod;
			if(j-i+1>=r-j+1)f[i][j-1][1]=(f[i][j-1][1]+f[i][j][0])%mod;
			f[i+1][j][0]=(f[i+1][j][0]+1ll*f[i][j][1]*(n-max(j-i+1,r-i+1)+1))%mod;
			f[i][j-1][1]=(f[i][j-1][1]+1ll*f[i][j][1]*(n-max(j-i+1,r-j+1)+1))%mod;
		}
	}
	for(int i=1;i<=n;i++)ans[i]=1ll*f[i][i][1]*(n-max(1,r-i+1)+1)%mod;
	ans[n]=(ans[n]+f[n][n][0])%mod;
	printf("%d ",(power(n,n)-ans[n]+mod)%mod);
	for(int i=n;i>=1;i--)printf("%d ",(ans[i]-ans[i-1]+mod)%mod);printf("\n");
}
int anss[N];
void solve()
{
	scanf("%d %d",&n,&mod);
	slv1();
}
int main()
{
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}