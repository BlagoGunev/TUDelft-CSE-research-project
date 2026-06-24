#include <bits/stdc++.h>
using namespace std;
int a[200005];
int dp[200005][64];
int base=1e9+7;
int main()
{ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int t;
cin>>t;
while(t--)
{
int n,k;cin>>n>>k;
for(int i=1;i<=n;i++)
cin>>a[i];
for(int i=1;i<=n;i++)for(int j=0;j<=64;j++)dp[i][j]=0;
for(int i=1;i<=n;i++)dp[i][a[i]]=1;
for(int i=1;i<=n;i++)
{
for(int j=0;j<=63;j++)dp[i][j]=(dp[i][j]+dp[i-1][j])%base;
for(int j=0;j<=63;j++)dp[i][(j&a[i])]=(dp[i][(j&a[i])]+dp[i-1][j])%base;;
}
int ans=0;
for(int i=0;i<=63;i++)if(__builtin_popcount(i)==k)ans=(ans+dp[n][i])%base;
cout<<ans<<'\n';
}
}