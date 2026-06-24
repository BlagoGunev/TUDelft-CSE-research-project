#include<bits/stdc++.h>

using namespace std;

const int maxn=2005,mod=998244353;

int n,m,T,ans,flg;

int fac[maxn],inv[maxn],nfac[maxn],f[maxn],lst[maxn],g[maxn];

int main(){

	fac[0]=fac[1]=nfac[0]=nfac[1]=inv[1]=1;

	for(int i=2;i<maxn;i++)

		fac[i]=1ll*fac[i-1]*i%mod,inv[i]=mod-1ll*(mod/i)*inv[mod%i]%mod,nfac[i]=1ll*nfac[i-1]*inv[i]%mod;

	scanf("%d%d",&n,&m);

	for(int t=n;t>=0;t--){//t=min(t1,t2,t3,t4)

		for(int i=0;i<=4*n;i++)

			f[i]=0;

		f[0]=1;

		for(int c=0;c<4;c++){

			for(int i=t;i<=n;i++)

				for(int j=i;j<=4*n;j++)

					g[j]=(g[j]+1ll*f[j-i]*nfac[i]%mod*nfac[n-i])%mod;

			for(int i=0;i<=4*n;i++)

				f[i]=g[i],g[i]=0;

		}

		for(int i=1;i<=4*n;i++){

			int r=min(i-1,m);

			ans=(ans+1ll*fac[r]*fac[4*n-r-1]%mod*(n-t)%mod*(f[r]-lst[i]+mod))%mod;

			lst[i]=f[r];

		}

	}

	ans=1ll*ans*fac[n]%mod*fac[n]%mod*fac[n]%mod*fac[n]%mod*nfac[4*n]%mod;

	printf("%d\n",ans);

	return 0;

}