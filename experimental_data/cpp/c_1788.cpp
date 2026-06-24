/// endless ?



#pragma GCC optimize("O3")

#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;



typedef long double ld;

#define ll                       long long

#define F                        first

#define S                        second

#define pii                      pair<int, int>

#define all(x)                   x.begin(), x.end()

#define vi                       vector<int>

#define vii                      vector<pii>

#define pb                       push_back

#define pf                       push_front

#define wall                     cout <<'\n'<< "-------------------------------------" <<'\n';

#define fast                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);



#define int ll

const ll MAXN = 2e5 + 43;

const ll MOD  = 1e9  + 7; ///998244353;

const ll INF  = 1e18 + 19763;

const ll LG   = 19;

ll pw(ll a, ll b){return b == 0 ? 1LL : (pw(a * a%MOD , b / 2)%MOD * (b % 2 == 0 ? 1LL : a))%MOD;}



void solve()

{

    fast

    int n; cin >> n;

    if (n%2 == 0){cout << "NO\n" << '\n';return;}



    cout << "YES\n";

    int x = (3*(n/2)) + 3;

    for (int i = 1; i <= n/2; i ++)

    {

        cout << i << ' ' << x << '\n';

        x ++;

    }

    x = (2*(n/2)) + 2;

    for (int i = n/2 + 1; i <= n; i++)

    {

        cout << i << ' ' << x << '\n';

        x ++;

    }

    cout << '\n';

}



int32_t main ()

{

    fast

    int t = 1; cin >> t;

    while (t --)

    {

        solve();

    }

}

/// Thanks GOD :)