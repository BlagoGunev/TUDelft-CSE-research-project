#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

#define PI acos(-1)

#define pb push_back

#define F first

#define S second

#define ll long long

#define all(v) v.begin(),v.end()

#define sz size()

#define fast     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const int N = 5e5 + 3;

ll n, m;



int main()

{

    fast

       



        ll t;

    cin >> t;

    while (t--)

    {

        string s;

        cin >> s;

        map<char, ll>mp;

        ll count = 0;

        for (int i = 0; i < s.size(); i++)

        {

            mp[s[i]]++;

            if (mp[s[i]] > 1)

            {

                count++;

                mp.clear();

            }

        }// sdsdff 2

        cout << s.size() - (2 * count) << '\n';

    }

}