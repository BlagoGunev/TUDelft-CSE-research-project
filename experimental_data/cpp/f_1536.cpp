#include<bits/stdc++.h>

using namespace std;

#define int long long

#define maxn 1000005

const int mod=1e9+7;

int fac[maxn],dfac[maxn];

int power(int a,int n){

    int res=1;

    while(n){

        if(n&1) res=(res*a)%mod;

        a=(a*a)%mod;n>>=1;

    }

    return res;

}

int C(int k,int n){

    if(k>n) return 0;

    return ((fac[n]*dfac[k])%mod)*dfac[n-k]%mod;

}

signed main(){

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);cout.tie(NULL);

    fac[0]=1;

    int n;cin >> n;

    for(int i=1;i<=n;i++) fac[i]=fac[i-1]*(i)%mod;

    dfac[n]=power(fac[n],mod-2);

    for(int i=n;i>=1;i--) dfac[i-1]=dfac[i]*i%mod;

    int ans=0;

    for(int i=n;i>=1;i--){

        if(i%2==0) ans=(ans+(C(n-i,i)+C(n-i-1,i-1))*fac[i])%mod;

    }

    ans=(ans*2)%mod;

    cout << ans << '\n';

}