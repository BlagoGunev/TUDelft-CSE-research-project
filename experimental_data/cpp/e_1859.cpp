#include <bits/stdc++.h>
#define int long long

using namespace std;

const int oo = INT_MAX;
const int nmax = 3000;

int n,k;
int a[nmax + 5], b[nmax + 5];

int dp[nmax + 5][nmax + 5][2][2], sdp[nmax + 5][nmax + 5];

int get_max(int i, int j)
{
    return max(max(dp[i][j][0][0],dp[i][j][1][1]),max(dp[i][j][0][1],dp[i][j][1][0]));
}

void solve_test()
{
    cin>>n>>k;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=k && j<=i; j++)
        {
            ///incep segment nou
            dp[i][j][0][0] = sdp[i - 1][j - 1] + b[i] - a[i] + a[i] - b[i];
            dp[i][j][0][1] = sdp[i - 1][j - 1] + b[i] - a[i] - a[i] + b[i];
            dp[i][j][1][0] = sdp[i - 1][j - 1] - b[i] + a[i] + a[i] - b[i];
            dp[i][j][1][1] = sdp[i - 1][j - 1] - b[i] + a[i] - a[i] + b[i];

            ///continui segment vechi
            if(i > 1 && j > 1)
            {
                dp[i][j][0][0] = max(dp[i][j][0][0], dp[i - 1][j - 1][0][0] + a[i - 1] - a[i] + b[i - 1] - b[i]);
                dp[i][j][0][1] = max(dp[i][j][0][1], dp[i - 1][j - 1][0][1] + a[i - 1] - a[i] - b[i - 1] + b[i]);
                dp[i][j][1][0] = max(dp[i][j][1][0], dp[i - 1][j - 1][1][0] - a[i - 1] + a[i] + b[i - 1] - b[i]);
                dp[i][j][1][1] = max(dp[i][j][1][1], dp[i - 1][j - 1][1][1] - a[i - 1] + a[i] - b[i - 1] + b[i]);
            }

            sdp[i][j] = max(sdp[i - 1][j], get_max(i,j));
        }
    }

    cout<<sdp[n][k]<<'\n';
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int test=1; test<=t; test++)
    {
        solve_test();
    }
    return 0;
}