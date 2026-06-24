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

        ll a, ctr, ctr1 = 0;

        cin >> a;

        ll b[a];

        dm(mp);

        dv(v);

        fo(i, 0, a)

        {

            cin >> b[i];

            mp[b[i]]++;

            v.push_back(i + 1);

        }

        fo(i, 0, a)

        {

            if (mp[b[i]] == 1)

            {

                cout << -1 << endl;

                ctr1 = 1;

                break;

            }

        }

        fo(j, 0, a - 1)

        {

            ctr = j + mp[b[j]];

            for (; j < ctr - 1; j++)

            {

                swap(v[j], v[j + 1]);

            }

        }

        if (ctr1 == 0)

        {

            fo(i, 0, a)

            {

                cout << v[i] << " ";

            }

            cout << endl;

        }

    }

}