#include <bits/stdc++.h>
#define MOD 998244353
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
inline int pw(int a,int b) {
    int as=1;
    while(b) {
        if(b&1) as=1ll*as*a%MOD;
        a=1ll*a*a%MOD;b>>=1;
    }
    return as;
}
inline int ni(int a) {
    return pw(a,MOD-2);
}
int N,M,a[444],b[444],c[444],xx[2];long long dp[(1<<20)+5];
signed main(void) {
    scanf("%d %d",&N,&M);
    //N=20;M=420;
    for(int i=1;i<=M;i++) {
        a[i]=rand()%2;
        b[i]=rand()%N+1;
        c[i]=rand()%N+1;
        scanf("%d %d %d",&a[i],&b[i],&c[i]);
    }
    dp[0]=1;
    for(int i=0;i<(1<<N)-1;i++) {
        dp[i]%=MOD;
        if(!dp[i]) continue;
        memset(xx,0,sizeof(xx));
        for(int j=1;j<=M;j++) {
            if((i&((1<<c[j]-1)|(1<<b[j]-1)))||b[j]==c[j]) xx[a[j]]|=((1<<c[j])|(1<<b[j]));
        }
        for(int j=1;j<=N;j++) {
            if((i>>j-1)&1) continue;
            dp[i|(1<<j-1)]=(dp[i|(1<<j-1)]+(2ll-((xx[0]>>j)&1)-((xx[1]>>j)&1))*dp[i]);
        }
    }
    int tp=dp[(1<<N)-1]%MOD;
    for(int i=1;i<=N;i++) tp=1ll*tp*ni(2)%MOD;
    for(int i=1;i<=N;i++) tp=1ll*tp*ni(i)%MOD;
    printf("%d",tp);
}