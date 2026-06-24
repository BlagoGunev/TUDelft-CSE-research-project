#include <cmath>

#include <cstdio>

#include <cstring>

#include <algorithm>



using namespace std;



typedef long long ll;

const int mod=1000000007;



int a[35],dp[35][2][35];



int main()

{

	#ifndef ONLINE_JUDGE

		freopen("input.txt","r",stdin);

		freopen("output.txt","w",stdout);

	#endif

	int n;scanf("%d",&n);++n;

	int m=0;

	while (n)

	{

		a[++m]=n&1;n>>=1;

	}

	memset(dp,0,sizeof(dp));dp[m][0][0]=1;

	for (int i=m;i;i--)

		for (int j=0;j<2;j++)

			for (int k=0;k<m;k++)

				if (dp[i][j][k])

				{

					if (j||a[i]) dp[i-1][j][k+1]=(dp[i-1][j][k+1]+dp[i][j][k])%mod;

					dp[i-1][j|a[i]][k]=(ll(dp[i][j][k])*(k==0?1:1<<(k-1))+dp[i-1][j|a[i]][k])%mod;

					if ((j||a[i])&&k) dp[i-1][j][k]=((ll(dp[i][j][k])<<(k-1))+dp[i-1][j][k])%mod;

				}

	int ans=0;

	for (int i=0;i<=m;i++) ans=(ans+dp[0][1][i])%mod;

	printf("%d\n",ans);

	return 0;

}