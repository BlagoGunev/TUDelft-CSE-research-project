#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=100010;
struct P {
	int a,s[9];
}pe[MAXN];
int n,p,kk,a[MAXN],s[MAXN][9],cnt[130],oe[130][9];
ll dp[MAXN][130];
bool cmp (P a,P b) {return a.a>b.a;}
int main () {
	scanf("%d%d%d",&n,&p,&kk);
	for (int i=1;i<=n;i++) {scanf("%d",&pe[i].a);}
	for (int i=0;i<=127;i++) {
		dp[0][i]=-1e18;
		for (int j=0;j<7;j++) {
			if (i&(1<<j)) {
				oe[i][++cnt[i]]=j+1;
			}
		}
	}
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=p;j++) {scanf("%d",&pe[i].s[j]);}
	}
	sort(pe+1,pe+n+1,cmp);
	dp[0][0]=0;
	for (int i=1;i<=n;i++) {
		int tmp=(1<<p)-1;
		for (int k=0;k<=tmp;k++) {
			dp[i][k]=dp[i-1][k]+(i-1-cnt[k]<kk?pe[i].a:0);
			for (int j=1;j<=cnt[k];j++) {
				dp[i][k]=max(dp[i][k],dp[i-1][k^(1<<(oe[k][j]-1))]+pe[i].s[oe[k][j]]);
			}
			//cout << i << "  " << k << "  " << dp[i][k] << endl;
		}
	}
	printf("%lld\n",dp[n][(1<<p)-1]);
	return 0;
}