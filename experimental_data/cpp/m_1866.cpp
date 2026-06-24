#include <bits/stdc++.h>

using namespace std;

const long long ma=100,dv=998244353;
long long n,pc[169],a[200069],dp[200069],sma[169],pwk;

long long pw(long long x,long long y)
{
	if(!y)
	{
		return 1;
	}
	pwk=pw(x,y/2);
	pwk=pwk*pwk%dv;
	if(y%2)
	{
		pwk=pwk*x%dv;
	}
	return pwk;
}

int main()
{
	long long i,j,k,z=0;
	
	k=pw(ma,dv-2);
	for(i=0;i<=ma-1;i++)
	{
		pc[i]=k*i%dv;
	}
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		dp[i]=(sma[a[i]]+1)*pw((1ll+dv-pc[a[i]])%dv,dv-2)%dv;
		for(j=0;j<=ma-1;j++)
		{
			sma[j]=(sma[j]+dp[i]*pc[j])%dv*pc[j]%dv;
		}
		z=(z+dp[i])%dv;
	}
	printf("%lld\n",z);
}