// LUOGU_RID: 155948463
#include<bits/stdc++.h>
using namespace std;

const int N=3005, mod=1e9+7;
int qpow(int x,int y) {int res=1; for(;y;y>>=1,x=1ll*x*x%mod) if(y&1) res=1ll*res*x%mod; return res;}

int fac[N],ifac[N],inv[N];
void init()
{
	fac[0]=1; for(int i=1;i<N;++i) fac[i]=1ll*fac[i-1]*i%mod;
	ifac[N-1]=qpow(fac[N-1],mod-2); for(int i=N-2;i>=0;--i) ifac[i]=1ll*ifac[i+1]*(i+1)%mod;
	inv[1]=1; for(int i=2;i<N;++i) inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
}
int C(int x,int y) {return x<y||y<0 ? 0:1ll*fac[x] * ifac[x-y]%mod * ifac[y]%mod;}

int n,c,K,f[N][N],ring[N][N],sum[N];
int main()
{
	init();
	scanf("%d %d %d",&n,&c,&K); K+=c;
	f[1][1]=1;
	for(int t=2;t<=n;++t)
	{
		for(int i=1;i<=n;++i) sum[i] = (sum[i-1] + f[t-1][i]) %mod;
		for(int i=1;i<=n;++i)
			f[t][i] = (sum[i-1] - (i>=c+1?sum[i-c-1]:0)) %mod;
	}
	for(int t=1;t<=n;++t)
	{
		for(int i=1;i<=n;++i)
		{
			sum[i] = (sum[i-1] + f[t][i]) %mod;
			int x = (sum[i] - (i>=c?sum[i-c]:0)) %mod;
			ring[t][i] = 1ll*x * i%mod * inv[t]%mod;
		}
	}
	
	int ans=0;
	for(int k=c;k<=K;++k)
	{
		int now=0;
		for(int i=1;i<=n;++i)
		{
			int g=__gcd(i,n), zu=n/g;
			if(k%zu) continue;
			now = (now + ring[g-k/zu][g]) %mod;
		}
		ans = (ans + 1ll*now*inv[n]) %mod;
	}
	int all=0;
	for(int k=c;k<=K;++k)
	{
		int now=0;
		for(int i=1;i<=n;++i)
		{
			int g=__gcd(i,n), zu=n/g;
			if(k%zu) continue;
			(now+=C(g,k/zu))%=mod;
		}
		all = (all + 1ll*now*inv[n]) %mod;
	}
	printf("%d\n", ((all-ans)%mod + mod) %mod);
}