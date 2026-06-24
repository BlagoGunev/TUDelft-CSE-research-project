#include<bits/stdc++.h>

#define ll long long

using namespace std;

const int N=2010,p=998244353;

int t,n,m,k,S[N][N];

int qpow(int x,int y=p-2){

	int m=1;

	for(;y;y>>=1,x=1ll*x*x%p)if(y&1)m=1ll*m*x%p;

	return m;

}

signed main(){

	S[0][0]=1;

	for(int i=1;i<N;i++){

		for(int j=1;j<N;j++)S[i][j]=(1ll*S[i-1][j]*j%p+S[i-1][j-1])%p;

	}

	scanf("%d",&t);

	for(;t--;){

		scanf("%d%d%d",&n,&m,&k);

		int q=1ll*((m+1)/2)*qpow(m)%p;

		int ans=0,mul=1;

		for(int i=1;i<=k;i++){

			mul=1ll*mul*q%p*(n-i+1)%p;

			ans=(ans+1ll*S[k][i]*mul%p)%p;

		}

		printf("%lld\n",1ll*ans*qpow(m,n)%p);

	}

}