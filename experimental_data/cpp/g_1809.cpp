// LUOGU_RID: 161974445
#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=1e6+10,mod=998244353;
inline int Add(const int &a,const int &b){
	return a+b>=mod?a+b-mod:a+b;
}
inline int Del(const int &a,const int &b){
	return a-b<0?a-b+mod:a-b;
}
inline int Mul(const int &a,const int &b){
	return 1ll*a*b%mod;
}
int qmi(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)ans=Mul(ans,a);
		a=Mul(a,a);
		b/=2;
	}
	return ans;
}
int fac[N],inv[N];
void init()
{
	fac[0]=1;
	for(int i=1;i<N;i++)fac[i]=Mul(fac[i-1],i);
	inv[N-1]=qmi(fac[N-1],mod-2);
	for(int i=N-2;i>=0;i--)inv[i]=Mul(inv[i+1],i+1);
}
int n,k;
int a[N],dp[N],sum[N];
int main()
{
    init();
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    if(a[n]-a[n-1]<=k){
        printf("0\n");
        return 0;
    }
    dp[0]=1;sum[0]=fac[n-1];
    for(int i=1,j=0;i<=n;i++)
    {
        while(j<n&&a[j+1]<a[i]-k)j++;
        dp[i]=Mul(sum[j],inv[n-j-1]);
        sum[i]=Add(sum[i-1],Mul(dp[i],fac[n-j-2]));
    }
    printf("%d",dp[n]);
    return 0;
}