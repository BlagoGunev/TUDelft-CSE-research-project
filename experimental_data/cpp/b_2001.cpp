// HastMithun FTW
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debugTemplate.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif
using namespace std;
#define forn(i, n, k) for (ll i = k; i < n + k; i++)
#define ffl(i, a, b) for (ll i = a; i <= b; ++i)
#define bfl(i, a, b) for (ll i = a; i >= b; --i)
#define all(v) v.begin(), v.end()
#define space << " "
#define M (998244353) // 1000000007
#define take(n) \
    ll n;       \
    cin >> n;
#define takean(a, n, k) \
    vi a(n + k, 0);     \
    forn(i, n, k) cin >> a[i];
#define yes                \
    cout << "YES" << endl; \
    return;
#define no                \
    cout << "NO" << endl; \
    return;
#define ll long long int
#define vi vector<long long int>
#define vvi vector<vector<long long int>>
#define pandeyji "abhigyan"

void solve()
{
    take(n);
    if (n % 2)
    {
        forn(i, n / 2 + 1, 1)
        {
            cout << 2 * i - 1 space;
        }
        bfl(i, n - 1, 2)
        {
            cout << i space;
            i--;
        }
        cout << endl;
    }
    else
    {
        cout << -1 << endl;
        return;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int e_fia_mataupu = 1;
    cin >> e_fia_mataupu;
    while (e_fia_mataupu--)
    {
        solve();
    }
}

// ˄˅<3