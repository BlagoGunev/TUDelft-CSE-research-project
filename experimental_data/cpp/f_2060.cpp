#include <cstdio>
#include <vector>
using namespace std;
const int mod=998244353;
int d[100005],cnt;
int dp[105][100005];
vector<int> g[100005];
int fac[100005],inv[100005];
int powm(int a,int b)
{
    int ret=1;
    while(b)
    {
        if(b&1)
            ret=1LL*ret*a%mod;
        a=1LL*a*a%mod;
        b>>=1;
    }
    return ret;
}
int C(int n,int m)
{
    if(n<m)
        return 0;
    int ret=1;
    for(int i=0;i<m;i++)
        ret=1LL*ret*(n-i)%mod;
    return 1LL*ret*inv[m]%mod;
}
int main()
{
    int t,k,n,ans;
    fac[0]=1;
    for(int i=1;i<=100000;i++)
        fac[i]=1LL*fac[i-1]*i%mod;
    inv[100000]=powm(fac[100000],mod-2);
    for(int i=99999;i>=0;i--)
        inv[i]=1LL*inv[i+1]*(i+1)%mod;
    for(int i=1;i<=100000;i++)
        for(int j=2*i;j<=100000;j+=i)
            g[j].push_back(i);
    dp[0][1]=1;
    for(int i=1;i<=30;i++)
        for(int j=1;j<=100000;j++)
            for(int k=0;k<g[j].size();k++)
                dp[i][j]=(dp[i][j]+dp[i-1][g[j][k]])%mod;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&k,&n);
        for(int i=1;i<=k;i++)
        {
            ans=0;
            for(int j=0;j<=30&&j<=n;j++)
                ans=(ans+1LL*(C(n+1,j+1)-C(0,j)+mod)*dp[j][i]%mod)%mod;
            if(i!=k)
                printf("%d ",ans);
            else printf("%d\n",ans);
        }
        for(int i=0;i<cnt;i++)
            g[i].clear();
    }
    return 0;
}