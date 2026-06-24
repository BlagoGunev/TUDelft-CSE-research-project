#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<queue>
#include<cassert>
using namespace std;
const double PI = acos(-1.0);
const int N = 100002;
#define fi first
#define se second
#define mp make_pair
long long s1, s2, dp[N][2];
long long mmax;
int main()
{
    ios::sync_with_stdio(false);
    //freopen("data.txt", "r", stdin);
    int n;
    cin >> n;
    for(int i = 1; i < n; ++i)
    {
        int x;
        cin >> x;
        if(x & 1)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + x - 1;
            dp[i][1] = max(dp[i - 1][1], s1) + x;
            if(x > 1)
                s1 += x - 1;
            else
            {
                s1 = 0;
                dp[i][0] = dp[i][1];
            }
        }
        else
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + x;
            dp[i][1] = max(dp[i - 1][1], s1) + x - 1;
            s1 += x;
        }
        dp[i][0] = max(dp[i][0], dp[i][1]);
       // cout << s1 <<' ' << dp[i][0] << ' ' << dp[i][1] << endl;
        mmax = max(mmax, dp[i][0]);
    }
    cout << mmax << endl;
    return 0;
}