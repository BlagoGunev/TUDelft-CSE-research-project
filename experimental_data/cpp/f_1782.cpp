#include<iostream>
#include<cstdio>
using namespace std;
const int mod=998244353;
int n,p,dp[501][501][2],sum[501][501][2],c[501][501];
inline void init()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
}
inline int read()
{
    int x;
    cin>>x;
    return x;
}
inline int pw(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1)
            res=1ll*res*a%mod;
        b>>=1;
        a=1ll*a*a%mod;
    }
    return res;
}
inline int Mod(int x)
{
    return x>=mod? x-mod:x;
}
int main()
{
    init();
    n=read(),p=1ll*read()*pw(10000,mod-2)%mod;
    c[0][0]=dp[0][0][0]=1;
    for(int i=1;i<=n;++i)
    {
        c[i][0]=1;
        for(int j=1;j<=i;++j)
            c[i][j]=Mod(c[i-1][j]+c[i-1][j-1]);
    }
    for(int i=0;i<=n;++i)
        sum[0][i][0]=1;
    for(int i=1;i<=n;++i)
        for(int j=0;j<=n;++j)
        {
            for(int k=1;k<i;++k)
                dp[i][j][1]=Mod(dp[i][j][1]+1ll*c[i][k]*Mod(1ll*sum[k][j][0]*Mod(sum[i-k][j][0]+sum[i-k][j][1])%mod-(j? 1ll*sum[k][j-1][0]*Mod(sum[i-k][j-1][0]+sum[i-k][j-1][1])%mod:0)+mod)%mod);
            dp[i][j][0]=Mod(dp[i][j][0]+1ll*p*Mod(dp[i-1][j+1][0]+dp[i-1][j+1][1])%mod);
            if(!j)
            {
                dp[i][j][0]=Mod(dp[i][j][0]+1ll*p*Mod(dp[i-1][j][0]+dp[i-1][j][1])%mod);
                sum[i][j][0]=dp[i][j][0];
                sum[i][j][1]=dp[i][j][1];
            }
            else
            {
                dp[i][j][0]=Mod(dp[i][j][0]+1ll*Mod(1-p+mod)*Mod(dp[i-1][j-1][0]+dp[i-1][j-1][1])%mod);
                sum[i][j][0]=Mod(sum[i][j-1][0]+dp[i][j][0]);
                sum[i][j][1]=Mod(sum[i][j-1][1]+dp[i][j][1]);
            }
        }
    int ans=Mod(dp[n][0][0]+dp[n][0][1]);
    for(int i=1;i<=n;++i)
        ans=1ll*ans*pw(i+i-1,mod-2)%mod;
    cout<<ans<<'\n';
    cout.flush();
    return 0;
}