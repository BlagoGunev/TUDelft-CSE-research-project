// betichod hu mai joh iss college aaya

#include <bits/stdc++.h>

#define ll long long

#define srv(v) sort(v.begin(), v.end())

#define fo(i, a, b) for (ll i = a; i < b; i++)

#define str string

#define sz size()

#define dv(v) vector<ll> v

#define ds(s) set<ll> s

#define dm(mp) map<ll, ll> mp

using namespace std;

const int M = 1e9 + 7;

const int N = 1e5 + 7;



int main()

{

    ios_base::sync_with_stdio(0);

    ll msamaj;

    cin >> msamaj;

    while (msamaj--)

    {

        ll a, ctr = 0, b, dig;

        cin >> a;

        while (!ctr)

        {

            b = a;

            while (b)

            {

                dig = b % 10;

                if (dig != 0 && a % dig != 0)

                {

                    break;

                }

                b = b / 10;

            }

            if (b)

            {

                a++;

            }

            else

            {

                ctr = a;

            }

        }

        cout << ctr << endl;

    }

}