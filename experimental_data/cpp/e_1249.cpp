//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define rint register int
typedef long long ll;
using namespace std;
int n;
const int N=2e5+5;
int a[N],b[N];
int dp[N][2];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<n;i++)
        scanf("%d",&b[i]);
    dp[0][1]=k;
    for(int i=1;i<n;i++)
    {
        dp[i][0]=min(dp[i-1][0]+a[i],dp[i-1][1]+a[i]);
        dp[i][1]=min(dp[i-1][0]+b[i]+k,dp[i-1][1]+b[i]);
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",min(dp[i][0],dp[i][1]));
    }
    return 0;
}