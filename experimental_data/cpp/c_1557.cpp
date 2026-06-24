//Author: Ankush Bhagat (https://github.com/ankushbhagat124)

//

#include <bits/stdc++.h>

#define int long long

#define setbits(x)        __builtin_popcountll(x)

#define zrobits(x)        __builtin_ctzll(x)

#define mod (int)(1e9+7)

const int N = 2e5 + 1;

const double pi = acos(-1);

using namespace std;

bool flag = true;



void init()

{

#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif

}

int power(int x, int y, int p)

{

    int res = 1;

    while (y > 0)

    {

        if (y % 2 == 1)

            res = (res * x) % p;

        y = y >> 1;

        x = (x * x) % p;

    }

    return res % p;

}

signed main()

{

    init();

    ios_base::sync_with_stdio(0);

    cin.tie(0); cout.tie(0);

    /*

    Tough

    */

    int t = 1;

    cin >> t;

    while (t--)

    {

        int n, k;

        cin >> n >> k;

        if (n % 2)

            cout << power(power(2, n - 1, mod) + 1, k, mod);

        else

        {

            int ans = 0, mul = 1;

            int x = power(2, n - 1, mod) - 1;

            for (int i = 1; i <= k; i++)

            {

                ans = (ans + mul * power(2, (k - i) * n, mod)) % mod;

                mul = mul * x % mod;

            }

            cout << (ans + mul) % mod;

        }

        cout << "\n";

    }

}