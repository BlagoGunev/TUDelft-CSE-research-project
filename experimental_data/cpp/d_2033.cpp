#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define endl '\n'
#define int long long
#define foor(i, n) for (int i = 0; i < n; i++)

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        foor(i, n) cin >> v[i];

        vector<int> dp(n, 0);
        int pre = 0;
        map<int, int> mp;
        mp[0] = -1;

        foor(i, n)
        {
            pre += v[i];
            if (i > 0)
                dp[i] = dp[i - 1];

            if (mp.find(pre) != mp.end())
            {
                if (mp[pre] == -1)
                {
                    dp[i] = max(dp[i], 1LL + 0);
                }
                else
                    dp[i] = max(dp[i], 1 + dp[mp[pre]]);
            }

            mp[pre] = i;
        }

        cout << dp[n - 1] << endl;
    }
}