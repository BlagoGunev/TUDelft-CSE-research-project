#include<bits/stdc++.h>

#define task "A"

#define ll long long

#define int ll

#define ld long double

#define fi first

#define se second

#define pb push_back

using namespace std;

const int maxN = 1e6+1;

const ll INF = 1e18;

const int mod = 2004511;

int n, k, a[maxN];



void Input()

{

    cin >> n;

    map<int, vector<int>> mp;

    for(int i = 1; i <= n; i++)

    {

         cin >> a[i];

         mp[a[i]].pb(i);

    }

    int x = a[1], l = 1, r = 1, q = 1;

    for(auto i: mp)

    {

        int val = i.fi;

        int st = i.se[0];

        int len = 1;

        for(int j = 1; j < i.se.size(); j++)

        {

            len++;

            len -= (i.se[j] - i.se[j-1] - 1);

            if(len < 1)

            {

                st = i.se[j];

                len = 1;

            }

            if(len > q)

            {

                q = len;

                l = st;

                r = i.se[j];

                x = val;

            }

        }

    }

    cout << x <<" "<< l << " " << r << '\n';

}



void Solve()

{



}



signed main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(nullptr);

    if (fopen(task".inp","r"))

    {

        freopen(task".inp","r",stdin);

        freopen(task".out","w",stdout);

    }

    int t;

    cin >> t;

    while(t--)

    {

        Input();

        Solve();

    }

}