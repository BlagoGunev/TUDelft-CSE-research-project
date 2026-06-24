#include <cstdio>
#include <algorithm>
using namespace std;

const int N=5002,INF=1000000000;
int n,a[N],l[N],r[N],dp[N][2505][2];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        l[i]=max(0,a[i]-a[i-1]+1);
        r[i]=max(0,a[i]-a[i+1]+1);
    }
    dp[0][0][1]=dp[1][0][1]=dp[1][1][0]=dp[1][1][1]=INF;
    for(int i=2;i<=n+1;i++){
        for(int j=0;j<=i/2;j++){
            dp[i][j][0]=min(dp[i-1][j][0],dp[i-1][j][1]);
            if(j>0)dp[i][j][1]=min(dp[i-2][j-1][0]+r[i-2]+l[i],dp[i-2][j-1][1]-l[i-2]+max(r[i-2],l[i-2])+l[i]);
            else dp[i][j][1]=INF;
            //printf("i=%d j=%d dp=%d,%d\n",i,j,dp[i][j][0],dp[i][j][1]);
        }
        dp[i][i/2+1][0]=dp[i][i/2+1][1]=INF;
    }
    for(int i=1;i<=(n+1)/2;i++)printf("%d ",min(dp[n+1][i][0],dp[n+1][i][1]));
}