#include <bits/stdc++.h>

#define int long long

#define llu unsigned long long

#define endl "\n"

#define inf 0x3f3f3f3f



using namespace std;



typedef pair<int, int> PII;



const int N = 1e6 + 7;



void solve()

{

    int n;

    cin >> n;

    vector<int> a(n + 7);

    vector<int> dp(n + 7);

    for (int i = 0; i < n; i++)

        cin >> a[i];

    for (int i = 0; i < n; i++)

    {

        dp[i] = 1;

        for (int j = max(0LL, i - 300); j < i; j++)

        {

            if ((a[j] ^ i) < (a[i] ^ j))

                dp[i] = max(dp[i], dp[j] + 1);

        }

    }

    cout << *max_element(dp.begin(), dp.begin() + n) << endl;

}



signed main()

{

    std::ios::sync_with_stdio(false);

    cin.tie(0);

    cout.tie(0);

    int T = 1;

    cin >> T;

    while (T--)

        solve();

    return 0;

}