#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
void read(vector<int> &a)
{
    for(int i = 0; i < a.size(); i++)
    {
        cin >> a[i];
    }
}
int main ()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    string t;
    for(int i = 0; i < n; i++)
    {
        if(i == 0)
        {
            t += s[0];
        }
        else
        {
            if(t[t.size() - 1] != s[i])
            {
                t += s[i];
            }
        }
    }
    n = t.size();
    s = t;
    vector<vector<int>> dp(n);
    for(int i = 0; i < n; i++)
    {
        dp[i].resize(n);
        dp[i].assign(n, 0);
    }
    /*for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            if(i == j)
            {
                dp[i][j] = 1;
            }
            else
            {
                int cur = dp[i][j - 1] + 1;
                for(int k = i; k < j; k++)
                {
                    if(s[k] == s[j])
                    {
                        cur = min(cur, dp[i][k] + dp[k + 1][j - 1]);
                    }
                }
                dp[i][j] = cur;
            }
        }
    }*/
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j + i - 1 < n; j++)
        {
            int v = j + i - 1;
            if(v == j)
            {
                dp[j][v] = 1;
             }
             else
             {
                 int cur = dp[j][v - 1] + 1;
                 for(int k = j; k < v; k++)
                 {
                     if(s[k] == s[v])
                     {
                         cur = min(cur, dp[j][k] + dp[k + 1][v - 1]);
                     }
                 }
                 dp[j][v] = cur;
             }
        }
    }
    cout << dp[0][n - 1];
}