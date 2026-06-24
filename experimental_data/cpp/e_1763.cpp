// LUOGU_RID: 101144495
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int n,c[1005],w[1005],dp[200005];

void solve()

{

	scanf("%d",&n);

	for(int i=1;i<=1000;i++) c[i]=i*(i-1)/2,w[i]=i;

	for(int i=1;i<=n;i++) dp[i]=2e9;

	for(int i=1;i<=1000;i++)

		for(int j=c[i];j<=n;j++)

			dp[j]=min(dp[j],dp[j-c[i]]+w[i]);

	printf("%lld %lld\n",dp[n],dp[n]*(dp[n]-1)/2-n);

}

int main()

{

	solve();

	return 0;

}