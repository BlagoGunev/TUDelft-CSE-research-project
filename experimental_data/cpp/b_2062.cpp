#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define ld double
ll mod = 998244353;
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frr(i, a, b) for (ll i = a; i < b; i++)
#define fi(i, arr) for (auto i : arr)
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vp vector<pair<ll, ll>>
#define vvp vector<vector<pair<ll, ll>>>
#define vb vector<bool>
#define all(c) c.begin(), c.end()
#define print(f) cout << ((f) ? "Yes\n" : "No\n")
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> indexed_multiset;
mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vl v(n);
        bool f = true;
        fr(i, n)
        {
            ll x;
            cin >> x;
            if (x <= 2 * i || x <= 2 * (n - i - 1))
                f = false;
        }
        print(f);
    }
}