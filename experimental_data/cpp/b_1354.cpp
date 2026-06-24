#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define fast                 \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define F first
#define FOR(i, n) for (int i = 0; i < (int)n; i++)
#define cin(v, n)                    \
    for (int i = 0; i < (int)n; i++) \
        cin >> v[i];
#define cout(v, n)                   \
    for (int i = 0; i < (int)n; i++) \
        cout << v[i] << (i == n - 1 ? "\n" : " ");
#define WL(t) while (t--)
#define S second
#define PB push_back
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define runtime() cerr << ((double)clock() / CLOCKS_PER_SEC) << endl;
#define MP make_pair
#define llu unsigned long long
#define ret return
#define endl "\n"
#define ordered_set tree<ll, null_type,greater<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define multi_ordered_set   tree<ll, null_type, greater_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
const ll mod = 1e9 + 7, N = 2e6 + 7, M = 2e6 + 7, INF = INT_MAX / 10;
ll powe (ll x, ll y)
{
    x = x % mod, y = y % (mod - 1);
    ll ans = 1;
    while (y > 0)
    {
        if (y & 1)
        {
            ans = (1ll * x * ans) % mod;
        }
        y >>= 1;
        x = (1ll * x * x) % mod;
    }
    return ans;
}

void solve ()
{
    string s;                      cin >> s;
    int ans = INT_MAX, cn = 0, n = s.size ();
    map < char, ll >mp;
    int i = 0, j = 0;
    ll c1 = count (all (s), '1');
    ll c2 = count (all (s), '2');
    ll c3 = count (all (s), '3');
    if (c1 == 0 or c2 == 0 or c3 == 0) cout << 0 << "\n";
    else
    {
        while (j < n)
        {
            if (i < n and cn != 3)
            {
                if (mp[s[i]] == 0) cn++;
                mp[s[i]]++;
                i++;
            }
            if (cn != 3 and i == n) break;

            if (cn == 3)
            {
                ans = min (ans, abs (i - j));
                if (mp[s[j]] == 1) cn--, mp[s[j]]--;
                if (mp[s[j]] > 1) mp[s[j]]--;
                j++;
            }
        }
        cout << ans << "\n";
    }
}

signed main ()
{
    fast;
    int t = 1;
    cin >> t;
    WL (t)
    {
        solve ();
    }
    runtime ();
    return 0;
}