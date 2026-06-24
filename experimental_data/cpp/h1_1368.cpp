#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,q;
char str[100005];
int L[100005],R[100005],U[100005],D[100005];
ll dp[100005][2];
int main(){
    scanf("%d%d%d",&n,&m,&q);
    scanf("%s",str+1);for(int i=1;i<=n;i++)L[i]=(str[i]=='R');
    scanf("%s",str+1);for(int i=1;i<=n;i++)R[i]=(str[i]=='R');
    scanf("%s",str+1);for(int i=1;i<=m;i++)U[i]=(str[i]=='R');
    scanf("%s",str+1);for(int i=1;i<=m;i++)D[i]=(str[i]=='R');
    dp[0][0]=dp[0][1]=0;
    for(int i=1;i<=m;i++)dp[0][0]+=U[i],dp[0][1]+=(!U[i]);
    for(int i=1;i<=n;i++){
        dp[i][0]=min(dp[i-1][0],dp[i-1][1]+m)+L[i]+R[i];
        dp[i][1]=min(dp[i-1][1],dp[i-1][0]+m)+(!L[i])+(!R[i]);
    }
    for(int i=1;i<=m;i++)dp[n][0]+=D[i],dp[n][1]+=(!D[i]);
    ll ans=min(dp[n][0],dp[n][1]);
    dp[0][0]=dp[0][1]=0;
    for(int i=1;i<=n;i++)dp[0][0]+=L[i],dp[0][1]+=(!L[i]);
    for(int i=1;i<=m;i++){
        dp[i][0]=min(dp[i-1][0],dp[i-1][1]+n)+U[i]+D[i];
        dp[i][1]=min(dp[i-1][1],dp[i-1][0]+n)+(!U[i])+(!D[i]);
    }
    for(int i=1;i<=n;i++)dp[m][0]+=R[i],dp[m][1]+=(!R[i]);
    printf("%lld\n",min(ans,min(dp[m][0],dp[m][1])));
    return 0;
}//