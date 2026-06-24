#include<bits/stdc++.h>
#define N 200010
#define ll long long
using namespace std;
ll a[N],sum[N],dp[53][N],f[53][N],Max[53][N];
int main() {
	int n,k,p;
	scanf("%d%d%d",&n,&k,&p);
	for(int i=1; i<=n; i++) {
		scanf("%lld",&a[i]);
		sum[i]=sum[i-1]+a[i];
		sum[i]%=p;
	}
	for(int i=1; i<=k; i++) {
		for(int j=1; j<=n; j++) {
//			for(int t=0;t<j;t++){
//				dp[i][j]=max(dp[i][j],dp[i-1][t]+(sum[j]-sum[t])%p);
			dp[i][j]=max(dp[i][j],f[i-1][j-1]+sum[j]);
			if(dp[i][j]<Max[i-1][j-1])dp[i][j]+=p;
//			}
			Max[i][j]=max(Max[i][j-1],dp[i][j]);
			f[i][j]=dp[i][j]-sum[j];
			f[i][j]=max(f[i][j],f[i][j-1]);
//			cout<<dp[i][j]<<" ";
		}
//		cout<<endl;
	}
	printf("%lld\n",dp[k][n]);
	return 0;
}