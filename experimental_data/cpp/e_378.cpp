#include <bits/stdc++.h>

#define pb push_back

#define mp make_pair

using namespace std;

typedef long long ll;

typedef pair <int,int> pii;



int a[110],n,m,dp[(1 << 20)];

vector < pair <char , int> > q;



int32_t main()

{

    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n;

    for (int i = 0 ; i < n ; i++)

        cin >> a[i];

    sort(a, a+n, greater <int> ());

    cin >> m;

    for (int i = 0 ; i < m ; i++)

    {

        char ch;

        int team;

        cin >> ch >> team;

        q.pb(mp(ch , team));

    }

    

    n = min(n , m);

    for (int mask = 0 ; mask < (1 << n) ; mask++)

    {

        int ind = n - (__builtin_popcount(mask)); //query e chandome

        char ch = q[ind].first;

        int team = q[ind].second;



        if (team == 1)

        {

            dp[mask] = -2e9;

            for (int i = 0 ; i < n ; i++)

            {

                if (mask & (1 << i))

                {

                    int cur = dp[mask - (1 << i)]; //bit e i om ro 0 kon

                    if (ch == 'p')

                        cur += a[i];

                    dp[mask] = max(dp[mask] , cur);

                }

            }

        }

        if (team == 2)

        {

            dp[mask] = 2e9;

            for (int i = 0 ; i < n ; i++)

            {

                if (mask & (1 << i))

                {

                    int cur = dp[mask - (1 << i)]; //bit e i om ro 0 kon

                    if (ch == 'p')

                        cur -= a[i];

                    dp[mask] = min(dp[mask] , cur);

                }

            }

        }

    }

    cout << dp[(1 << n) - 1] << endl;

    return 0;      

}