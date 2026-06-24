#include<bits/stdc++.h>
using namespace std;
const int maxn=555+50;
typedef long long ll;
const int inf=1e9;
const ll mod=1e9+7;

ll p[maxn],inv[maxn];
ll dp[maxn];
ll ksm(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1)res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
ll cal(int x,int y){
    if(x<y)return 0;
    return p[x]*inv[y]%mod*inv[x-y]%mod;
}
int main(){
    std::ios::sync_with_stdio(false);
    p[0]=1;
    inv[0]=1;
    for(int i=1;i<=300;i++)p[i]=p[i-1]*i%mod,inv[i]=ksm(p[i],mod-2);

    int n;ll k;
    cin>>n>>k;
    for(int i=0;i<=n;i++){
        dp[i]=ksm(((ksm(k,i)-ksm(k-1,i))+mod)%mod,n)%mod;
    }
    ll ans=0;
    for(int i=0;i<=n;i++){
        ll x=cal(n,i)*ksm(ksm(k-1,n),i)%mod*dp[n-i]%mod;
        if(i&1){
            ans-=x;
            ans+=mod;
            ans%=mod;
        }
        else ans=(ans+x)%mod;
    }
    cout<<ans<<endl;
    return 0;
}