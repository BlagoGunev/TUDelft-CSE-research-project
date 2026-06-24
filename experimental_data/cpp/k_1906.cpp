// LUOGU_RID: 151586843
#include<bits/stdc++.h>
using namespace std;

constexpr int maxn=1<<17,mod=998244353;

int buc[maxn],dp[2][maxn],dq[2][maxn];

void fwt(int *a,int n)
{
	int i,j,k;
	for(i=1;i<n;i*=2)
	{
		for(j=0;j<n;j+=i*2)
		{
			for(k=0;k<i;k++)
			{
				int x=a[j+k],y=a[i+j+k];
				a[j+k]=(x-y+mod)%mod;
				a[i+j+k]=(x+y)%mod;
			}
		}
	}
}

void ifwt(int *a,int n)
{
	int i,j,k,inv=1;
	for(i=1;i<n;i*=2)
	{
		if(inv&1) inv+=mod;
		inv>>=1;
		for(j=0;j<n;j+=i*2)
		{
			for(k=0;k<i;k++)
			{
				int x=a[j+k],y=a[i+j+k];
				a[j+k]=(x+y)%mod;
				a[i+j+k]=(y-x+mod)%mod;
			}
		}
	}
	for(i=0;i<n;i++) a[i]=1LL*a[i]*inv%mod;
}

int main()
{
	ios::sync_with_stdio(false),cin.tie(0);
	int n,i,j,k;
	cin>>n;
	while(n--)
	{
		cin>>i;
		buc[i]++;
	}
	for(i=0;i<maxn;i++)
	{
		dp[0][i]=1;
		dp[1][i]=0;
		while(buc[i]--)
		{
			int x=(dp[0][i]*2LL+dp[1][i])%mod;
			int y=(dp[1][i]*2LL+dp[0][i])%mod;
			dp[0][i]=y;
			dp[1][i]=x;
		}
	}
	for(i=1;i<maxn;i*=2)
	{
		for(j=0;j<maxn;j+=i*2)
		{
			fwt(dp[0]+j,i);
			fwt(dp[0]+j+i,i);
			fwt(dp[1]+j,i);
			fwt(dp[1]+j+i,i);
			for(k=0;k<i;k++)
			{
				dq[0][j+k]=1LL*dp[0][j+k]*dp[0][i+j+k]%mod;
				dq[0][i+j+k]=1LL*dp[1][j+k]*dp[1][i+j+k]%mod;
				dq[1][j+k]=1LL*dp[1][j+k]*dp[0][i+j+k]%mod;
				dq[1][i+j+k]=1LL*dp[0][j+k]*dp[1][i+j+k]%mod;
			}
			for(k=0;k<i*2;k++) dp[0][j+k]=dq[0][j+k],dp[1][j+k]=dq[1][j+k];
			ifwt(dp[0]+j,i);
			ifwt(dp[0]+j+i,i);
			ifwt(dp[1]+j,i);
			ifwt(dp[1]+j+i,i);
		}
	}
	cout<<(dp[0][0]+dp[1][0])%mod<<'\n';
	return 0;
}