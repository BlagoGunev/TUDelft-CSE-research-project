#include<bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

#define Speedneed ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define Yes cout << "YES" << endl;

#define No cout << "NO" << endl;

#define nl cout << endl;

#define ld long double

#define pf push_front

#define pfg pop_front

#define en return 0;

#define ll long long

#define pb push_back

#define pbg pop_back

#define ct continue;

#define ss second;

#define ff first;

int main()

{

    Speedneed;

    ll n, flt = 0;

    cin >> n;

    string s1 = "blue";

    for (int i = 0; i < n; i++)

    {

        string s;

        cin >> s;

        if (s == "lock"){flt = 1;ct;}

        if (s == "unlock"){flt = 0;ct;}

        if (flt == 0)

        {

            s1 = s;

        }

    }

    cout << s1;

}