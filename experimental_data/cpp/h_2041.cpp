#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define sz(x) ((int)x.size())
using namespace std;
const int N=1000005,P=998244353;
int n,k,dp[N],g[N],fac[N],inv[N];
void Inc(int&x,int y){
    if((x+=y)>=P) x-=P;
}
void Dec(int&x,int y){
    if((x-=y)<0) x+=P;
}
int C(int x,int y){
    return 1ll*fac[x]*inv[y]%P*inv[x-y]%P;
}
int bp(int x,int y){
    int r=1;
    for(;y;y=y>>1,x=1ll*x*x%P) if(y&1) r=1ll*r*x%P;
    return r;
}
int main(){
    scanf("%d%d",&n,&k),dp[0]=g[0]=1;
    fac[0]=inv[0]=1;
    rep(i,1,n) fac[i]=1ll*fac[i-1]*i%P,inv[i]=bp(fac[i],P-2);
    int as=0;
    rep(i,1,n){
        dp[i]=g[i-1];
        if(i-k>=0) Dec(dp[i],g[i-k]);
        Inc(g[i],dp[i]),Inc(g[i],g[i-1]);
    }
    n--;
    rep(i,0,n){
        if(i==0) Inc(as,1ll*C(n,i)*dp[i]%P);
        else Inc(as,2ll*C(n,i)%P*dp[i]%P);
    }
    printf("%d\n",as);
}