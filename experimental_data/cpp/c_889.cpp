#include<bits/stdc++.h>
#define mo 1000000007
using namespace std;
long long fac[1000100],nifac[1000100],f[1000100],sum[1000100];
long long getmi(int a,int x)
{
	long long ans=1;
	while (x)
	{
		if (x&1) ans=ans*a%mo;
		a=(long long)a*a%mo;
		x>>=1;
	}
	return ans;
}
int main(void)
{
	int n,k; scanf("%d%d",&n,&k);
	fac[0]=1; for (int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mo;
	nifac[n]=getmi(fac[n],mo-2);
	for (int i=n-1;i>=0;i--) nifac[i]=nifac[i+1]*(i+1)%mo;
	f[1]=sum[1]=1;long long ans=fac[n-1];
	for (int i=2;i<=n;i++)
	{
		f[i]=(sum[i-1]-sum[max(0,i-k-1)]+mo)*fac[i-2]%mo;//cout<<i<<' '<<f[i]<<endl;
		sum[i]=(sum[i-1]+f[i]*nifac[i-1])%mo;
		ans=(ans+f[i]*fac[n-1]%mo*nifac[i-1])%mo;
	}
	printf("%I64d\n",(fac[n]-ans+mo)%mo);
	return 0;
}