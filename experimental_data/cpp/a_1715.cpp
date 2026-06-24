#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()

{

    ll t;

    cin >> t;

    while(t--)

    {

        ll a,b;

        cin >> a >> b;

        if(a==b && b == 1)

        {

            cout << 0 << endl;

            continue;

        }

        if(a>b)swap(a,b);

        ll res  = (a*2)+b-2;

        cout << res << endl;

    }

}