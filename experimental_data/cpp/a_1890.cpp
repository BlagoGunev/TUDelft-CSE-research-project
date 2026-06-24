#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;

void solve()
{
    ll n;
    cin >> n;
    map<ll,ll> x;
    // set<ll,ll> se;
    for(ll i=0; i<n; i++)
    {
        ll u;
        cin >> u;
        x[u]++;
        // se.insert(u);
    }

    if(x.size() == 1)
    {
        cout << "Yes" << "\n";
        return;
    }
    if(x.size() != 2)
    {
        cout << "No" << "\n";
        return;
    }
    ll a = x.begin()->first;
    ll b = (++x.begin())->first;
    if(n%2 == 0)
    {
        if(x[a] == n/2 && x[b] == n/2)
        {
            cout << "Yes" << "\n";
            return;
        }
        else
        {
            cout << "No" << "\n";
            return;
        }
    }
    else
    {
        if(x[a] == n/2 || x[b] == n/2)
        {
            cout << "Yes" << "\n";
            return;
        }
        else
        {
            cout << "No" << "\n";
            return;
        }
    
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}