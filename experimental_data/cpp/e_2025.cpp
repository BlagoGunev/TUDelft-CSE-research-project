#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll P=998244353;
ll fac[2010],f[2010],g[2010],h[2010];
ll qpow(ll x,ll y){
    ll t=1;
    while(y){
        if(y&1) t=t*x%P;
        x=x*x%P;
        y>>=1;
    }
    return t;
}
ll C(int x,int y){return fac[x]*qpow(fac[y],P-2)%P*qpow(fac[x-y],P-2)%P;}
void solve(){
    int n,m;
    cin>>n>>m;
    fac[0]=1;
    for(int i=1;i<=600;i++) fac[i]=fac[i-1]*i%P;
    ll tt=C(m,m/2)*qpow(m/2+1,P-2)%P;
    for(int i=0;i<=m/2;i++){
        for(int j=0;j<=2*m;j++) g[j]=h[j]=0;
        g[i*2]=1;
        for(int j=1;j<=m;j++){
            for(int k=0;k+1<=2*m;k++){
                h[k+1]=(h[k+1]+g[k])%P;
                if(k-1>=0) h[k-1]=(h[k-1]+g[k])%P;
            }
            for(int k=0;k<=2*m;k++){
                g[k]=h[k];
                h[k]=0;
            }
        }
        f[i]=g[0];
    }
    ll res=0;
    for(int j=0;j<=m;j++) g[j]=0;
    g[0]=1;
    for(int j=1;j<n;j++){
        for(int k=0;k<=m/2;k++){
            for(int l=0;l+k<=m/2;l++){
                h[l+k]=(h[l+k]+g[l]*f[k]%P)%P;
            }
        }
        for(int k=0;k<=m/2;k++){
            g[k]=h[k];
            h[k]=0;
        }
    }
    for(int i=0;i<=m/2;i++){
        res=(res+f[i]*g[i]%P)%P;
    }
    cout<<res;
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}