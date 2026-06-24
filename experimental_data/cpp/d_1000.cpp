#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>
#define LL long long
using namespace std;
const int mod = 998244353;
int fac[1010],ifac[1010];
int n,a[1010],dp[1010];
int qpow(int a,int n) {
    int ans=1;
    for (;n;n>>=1,a=(LL)a*a%mod) if (n&1) ans=(LL)ans*a%mod;
    return ans;
}
int choose(int n,int k) {
    if (n<0||k<0||n<k) return 0;
    return fac[n]*(LL)ifac[k]%mod*(LL)ifac[n-k]%mod;
}
int main(void) {
//    freopen("d.in","r",stdin);
    fac[0]=1;for (int i=1;i<=1000;i++) fac[i]=fac[i-1]*(LL)i%mod;
    ifac[1000]=qpow(fac[1000],mod-2);
    for (int i=999;i>=0;i--) ifac[i]=ifac[i+1]*(LL)(i+1)%mod;
//    for (int i=0;i<=10;i++) printf("%d %d %I64d\n",fac[i],ifac[i],fac[i]*(LL)ifac[i]%mod);
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=n;i++) {
        for (int j=1;j<i;j++) {
            if (a[j]>0&&j+a[j]<=i) {
                dp[i] = (dp[i] + (LL)(dp[j-1]+1)*choose(i-j-1,a[j]-1))%mod;
//                printf("i=%d,j=%d,c(%d,%d)=%d\n",i,j,a[j]-1,i-j-1,choose(i-j-1,a[j]-1));
            }
        }
        dp[i]=(dp[i]+dp[i-1])%mod;
    }
//    for (int i=1;i<=n;i++) printf("%d ",dp[i]); puts("");
//    int ans=0;
//    for (int i=1;i<=n;i++) ans=(ans+dp[i])%mod;
    printf("%d\n",dp[n]);
    return 0;
}