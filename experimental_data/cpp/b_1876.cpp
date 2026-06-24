#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int a[100005],id[100005],f[100005];
vector <int> v[100005];
long long fac[100005],ifac[100005],mod=998244353;
long long qpow(long long a,long long b){
    long long ans=1;
    while(b){
        if(b&1) ans=ans*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return ans;
}
long long c(int n,int m){
    if(m>n) return 0;
    return fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
int main() {
    int T = 1, kase = 0;
    //cin >> T;
    while (T--) {
        int n;
        scanf("%d",&n);
        ifac[0]=fac[0]=1;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),id[i]=i,fac[i]=fac[i-1]*i%mod,ifac[i]=qpow(fac[i],mod-2);
        sort(id+1,id+n+1,[&](int x,int y){
            return a[x]>a[y];
        });
        for(int i=1;i<=n;i++)
            for(int j=i;j<=n;j+=i)
                v[j].push_back(i);
        int rest=n;
        long long ans=0;
        for(int i=1;i<=n;i++){
            int cnt=0;
            for(auto t:v[id[i]]){
                if(!f[t]) f[t]=1,cnt++,rest--;
            }
            ans+=1LL*a[id[i]]*(qpow(2,cnt)-1)%mod*qpow(2,rest)%mod,ans%=mod;
        }
        printf("%lld\n",ans);
    }
    return 0;
}