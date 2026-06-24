#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()

{

    ios_base::sync_with_stdio(0);

    cin.tie(0);

    cout.tie(0);

    int t;

    cin >> t;

    for (int i = 0; i < t; i++)

    {

        int n, k;

        cin >> n >> k;

        if (k > (n - 1) / 2) cout << -1 << endl;

        else

        {

            for (int j = 1; j <= k; j++)

            {

                cout << j << ' ' << n << ' ';

                n--;

            }

            for (int j = k + 1; j <= n; j++) cout << j << ' ';

            cout << endl;

        }

    }

    return 0;

}