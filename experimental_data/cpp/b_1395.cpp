#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef pair<ll, ll> pii;

const ll mn = 1e6 + 10;

ll n, m, sx, sy,nx,ny;

bool flag=1;

signed main()

{

    cin >> n>>m>>sx>>sy;

    nx = sx; ny = sy;

    cout << nx << " " << ny<<"\n";

    for (ll i = 1; i <= m; i++)

    {

        if (i == ny) continue;

        cout << nx << " " << i << '\n';

    }

    while (nx!=n)

    {

        nx += 1;

        if (flag)

        {

            for (ll i = m; i >= 1; i--)

            {

                cout << nx << " " << i << '\n';

            }

        }

        else

        {

            for (ll i = 1; i <= m; i++)

            {

                cout << nx << " " << i << '\n';

            }

        }

        flag = !flag;

    }

    nx = sx;

    while (nx != 1)

    {

        nx -= 1;

        if (flag)

        {

            for (ll i = m; i >= 1; i--)

            {

                cout << nx << " " << i << '\n';

            }

        }

        else

        {

            for (ll i = 1; i <= m; i++)

            {

                cout << nx << " " << i << '\n';

            }

        }

        flag = !flag;

    }

}