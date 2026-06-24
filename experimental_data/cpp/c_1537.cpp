#include<bits/stdc++.h>

#define imron ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

#define ll long long

#define ld long double

#define fi first

#define se second

using namespace std;

void AbduIT()

{

    ll n;

    cin >> n;

    ll a[n + 17] = {};

    for(ll i = 1; i <= n; i++)

    {

        cin >> a[i];

    }

    sort(a + 1, a + 1 + n);

    if(n == 2)

    {

        cout << a[1] << " " << a[2] << '\n';

        return;

    }

    ll mn = 1e18, sh = -1;

    for(ll i = 2; i <= n; i++)

    {

        if(mn > abs(a[i] - a[i - 1]))

        {

            sh = i;

            mn = abs(a[i] - a[i - 1]);

        }

    }

    for(ll i = sh; i <= n; i++)

    {

        cout << a[i] << " ";

    }

    for(ll i = 1; i < sh; i++)

    {

        cout << a[i] << " ";

    }

    cout << '\n';

}

signed main()

{

    imron

    ll T = 1;

    cin >> T;

    while(T--)

    {

        AbduIT();

    }

}

///kamera proverok\\\



/**



*/