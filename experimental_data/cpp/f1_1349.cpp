// LUOGU_RID: 101250994
#include<bits/stdc++.h>

using namespace std;

const int N=5005,mod=998244353;

int fac[N],Inv[N],E[N][N],n;

inline int fastpow(int x, int y){

	int z=1;

	for (; y; y>>=1,x=1ll*x*x%mod)

		if (y&1) z=1ll*z*x%mod;

	return z;

}

int main(){

	scanf("%d",&n); fac[0]=Inv[0]=1;

	for (int i=1; i<=n; i++){

		E[i][0]=1; Inv[i]=fastpow(fac[i]=1ll*fac[i-1]*i%mod,mod-2);

		for (int j=1; j<i; j++) E[i][j]=(1ll*(j+1)*E[i-1][j]+1ll*(i-j)*E[i-1][j-1])%mod;

	}

	for (int i=1; i<=n; i++){

		int res=0;

		for (int j=i; j<=n; j++) res=(res+1ll*Inv[j]*E[j][i-1])%mod;

		printf("%lld ",1ll*res*fac[n]%mod);

	}

}