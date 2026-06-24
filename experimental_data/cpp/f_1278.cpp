#include<cstdio>
#include<algorithm>
using namespace std;
int S[5005][5005],A[5005],n,m,k,i,j,ans=0,inv,sum;
const int mod=998244353;
int mypow(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)ans=1LL*ans*a%mod;
		a=1ll*a*a%mod;
		b>>=1;	
	} 
	return ans;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	S[1][1]=1;
	for(i=2;i<=k;i++)for(j=1;j<=i;j++)S[i][j]=(1ll*S[i-1][j-1]+1ll*j*S[i-1][j])%mod;
	A[0]=1;
	for(i=1;i<=k;i++)A[i]=1ll*A[i-1]*(n-i+1)%mod;
	sum=inv=mypow(m,mod-2);
	for(i=1;i<=k;i++,sum=1ll*sum*inv%mod)ans=(1ll*ans+1ll*S[k][i]*sum%mod*A[i])%mod;
	printf("%d\n",ans);
	return 0;
}