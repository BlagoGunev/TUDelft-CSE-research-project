#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#define fio ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define en exit(0);
#define pb push_back
#define fi first
#define se second
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int INF = 1e9+5;
int main()
{
//    ifstream cin("in.in");
    int qq;
    cin >> qq;
    while(qq--)
    {
        int n;
        string str[2];
        cin >> n >> str[0] >> str[1];
        int dp[n+1][3];
        for(int i = 0;i<=n;i++)
            for(int j = 0;j<3;j++)
                dp[i][j]=-INF;
        dp[0][2]=0;
        for(int i = 1;i<=n;i++)
        {
            int a = (str[0][i-1]=='A'), b = (str[1][i-1]=='A');
            if(i>=2)
            {
                int pa = (str[0][i-2]=='A'), pb = (str[1][i-2]=='A');
                dp[i][0]=max(dp[i][0],dp[i-2][2]+(pa+pb+a>1));
                dp[i][1]=max(dp[i][1],dp[i-2][2]+(pa+pb+b>1));
                dp[i][2]=max({dp[i][2],dp[i-1][0]+(pb+a+b>1),dp[i-1][1]+(pa+a+b>1)});
            }
            if(i>=3)
            {
                int pa = (str[0][i-2]=='A'), pb = (str[1][i-2]=='A');
                int p2a = (str[0][i-3]=='A'), p2b = (str[1][i-3]=='A');
                dp[i][2]=max(dp[i][2],dp[i-3][2]+(p2a+pa+a>1)+(p2b+pb+b>1));
            }
            if(i>=4)
            {
                int pa = (str[0][i-2]=='A'), pb = (str[1][i-2]=='A');
                int p2a = (str[0][i-3]=='A'), p2b = (str[1][i-3]=='A');
                int p3a = (str[0][i-4]=='A'), p3b = (str[1][i-4]=='A');
                dp[i][0]=max(dp[i][0],dp[i-3][0]+(p2a+pa+a>1)+(p3b+p2b+pb>1));
                dp[i][1]=max(dp[i][1],dp[i-3][1]+(p3a+p2a+pa>1)+(p2b+pb+b>1));
            }
        }
        cout << dp[n][2] << "\n";
    }
    return 0;
}