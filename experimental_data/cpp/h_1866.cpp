#include<bits/stdc++.h>
using namespace std;
const int N=1919810,mod=998244353;
typedef long long ll;
typedef unsigned long long ull;

typedef pair<ll,ll> PII;

ll n,m,k;

ll jc[N],ny[N];

ll ksm(ll num,ll p){
    ll sum=1,item=num;
    while(p){
        if(p%2) sum=sum*item%mod;
        item=item*item%mod;
        p/=2;
    }
    return sum;
}

ll c(ll a,ll b){
    if(a>b) return 0;
    return jc[b]*ny[a]%mod*ny[b-a]%mod;
}
ll P(ll a,ll b){
    return jc[b]*ny[b-a]%mod;
}

ll catalan(ll x){
    return c(x,x+x)*ksm(x+1,mod-2)%mod;
}

int main(){
    cin>>n>>k;
    jc[0]=1;
    for(ll i=1;i<N;i++) jc[i]=jc[i-1]*i%mod;
    ny[N-1]=ksm(jc[N-1],mod-2);
    for(ll i=N-1;i>0;i--) ny[i-1]=ny[i]*i%mod;
    //cout<<ny[0]<<endl;
    ll ans=0;
    
    for(int i=1;i<=min(n,k);i++){
        ll res=((ksm(i+1,k-i+1)%mod-ksm(i,k-i+1)%mod)%mod+mod)%mod;
        res=res*jc[i]%mod;
        res=res*P(i,n)%mod;
        //res=res*jc[n]%mod;
        //res=res*ny[n-i]%mod;
        ans=(ans+res)%mod;
    }
    ans++;
    cout<<ans%mod<<endl;
}