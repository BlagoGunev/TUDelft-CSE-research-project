#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int n, m, x;
ll dp[222][222], ans = -1, a[222];

int main() {
    scanf("%d%d%d",&n,&m,&x);
    for(int i = 1; i <= n; ++i) scanf("%d",&a[i]);
    memset(dp,-1,sizeof(dp));
    dp[0][0] =  0;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= i && j <= x; ++j) {
            for(int k = i-1; k >= 0; --k) if(i-k <= m && dp[k][j-1] != -1) {
                dp[i][j] = max(dp[k][j-1] + a[i], dp[i][j]);
            }
        }
        //cout << i <<' '<< dp[i][x] << endl;
        if(n-i < m) ans = max(ans, dp[i][x]);
    }
    printf("%lld\n",ans);
}