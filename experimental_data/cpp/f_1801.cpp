#include<bits/stdc++.h>
#define ld   long double
#define ll   long long
#define pb   emplace_back
#define mp   make_pair
#define orz  1000000007
#define fi   first
#define se   second
#pragma GCC optmize("O2")
using namespace std;
int n,k,a[105],b[8005],m;
ld _a[105];
ld dp[105][8005];
int f[10000005],g[10000005];
void u(ld &x,ld y){if(y>x)x=y;}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)scanf("%d",a+i),_a[i]=1.0/(a[i]*1.0);
	{
		ll o=1;
		for(int i=1;i<=n;++i){
			o*=a[i];
			if(o>=k*1ll) break;
		}
		if(o<k*1ll){
			printf("0\n");
			return 0;
		}
	}
	for(int i=1;i<=k;++i)g[i]=(k-1)/i+1;
	for(int i=1;i<=k;++i){
		if(g[i]!=g[i-1]){
			b[++m]=i;
			f[i]=m;
		}
	}
	dp[0][m]=1.0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			int _b=b[j]-1;
			for(int r=min(a[i],b[j]);r>0;){
				int ans=_b/r+1;
				int l=_b/ans+1;
				u(dp[i][f[ans]],dp[i-1][j]*(ld)(a[i]/l)*_a[i]);
				r=l-1;
			}
		}
	}
	printf("%.15f\n",(double)(dp[n][1]*k));
    return 0;
}