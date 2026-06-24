#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include "bits/stdc++.h"
using namespace std;

#define ff first
#define ss second
#define mp make_pair
#define ll long long
#define ld long double
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rev(i, n) for (ll i = n; i >= 0; i--)
#define rep_a(i, a, n) for (ll i = a; i < n; i++)
#define pb push_back
#define all(_obj) _obj.begin(), _obj.end()
#define pll pair<ll, ll>
#define vll vector<ll>
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
const ll N = 1e5 + 11, mod = 1e9 + 7, inf = LONG_LONG_MAX;

void solve()
{
    string s;
    cin >> s;
    vll ans;
    ll i = 0, j = s.size() - 1;
    while (j > i)
    {
        if (s[j] == ')' && s[i] == '(')
        {
            ans.pb(i + 1);
            ans.pb(j + 1);
            i++;
            j--;
        }
        if (s[i] != '(')
            i++;
        if (s[j] != ')')
            j--;
    }
    if (ans.empty())
    {
        cout << 0 << endl;
        return;
    }
    sort(all(ans));
    cout << 1 << endl;
    cout << ans.size() << endl;
    for (auto &i : ans)
        cout << i << " ";
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}