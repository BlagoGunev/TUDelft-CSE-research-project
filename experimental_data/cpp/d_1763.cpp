#include<bits/stdc++.h>



using namespace std;

typedef long long ll;



int mod = 1e9 + 7;



// long loooooooooooooooong;

void solve(ll kkkk, ll tttt)

{

    int n, a, b, x, y; cin >> n >> a >> b >> x >> y; a--, b--, x--, y--;



    vector<vector<int>> dp(n, vector<int>(n, 0));





    for (int i = 1; i < n - 1; i++)

    {

        if (n - 1 == x && i == a || n - 1 == y && i == b)

        {

            dp[i][i] = 1;

            continue;

        }

        if (i == a || i == b) continue;

        dp[i][i] = 1;

    }



    for (int num = n - 2; num >= 0; num--)

    {

        for (int i = 0; i < n; i++)

        {

            int len = n - num;

            if (num == x && i != a || num == y && i != b)

                continue;

            if (i == a && num != x || i == b && num != y)

                continue;



            int beg = i - len + 1;

            int en = i + len - 1;



            if (beg >= 0)

            {

                dp[beg][i] += dp[beg][i - 1];

                dp[beg][i] %= mod;

            }

            if (en < n)

            {

                dp[i][en] += dp[i + 1][en];

                dp[i][en] %= mod;

            }

        }

    }

    cout << dp[0][n - 1] << endl;

}



void fast() { ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); }



int main()

{

    fast();



//    int t = 0, i = 0;



    int t; cin >> t;

    for (int i = 1; i <= t; i++)



    solve(t, i);

    return 0;

}