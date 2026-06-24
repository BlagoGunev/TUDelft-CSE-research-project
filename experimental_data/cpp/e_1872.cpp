// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define int long long // ....................
// using ll = long long; // ....................
// #define int __int128 // ....................
using namespace std;
typedef pair<int, int> pii;

const int e3 = 1000, e6 = e3 * e3, e9 = e6 * e3;
const int e12 = e9 * e3, e15 = e12 * e3, e18 = e15 * e3; // ....................
const int m998 = 998244353, m197 = 1000000007, m297 = 2971215073;

inline void init()
{
}

inline void solve()
{
    int n;
    cin >> n;
    vector<int> v(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    string s;
    cin >> s;

    vector<int> pre(v);
    for (int i = 1; i <= n; ++i)
        pre[i] ^= pre[i - 1];

    int ans = 0;
    for (int i = 1; i <= n; ++i)
        if (s[i - 1] == '1')
            ans ^= v[i];
    
    int q;
    cin >> q;
    // cout << ans << ' ' << pre[n] << "..\n";
    while (q--)
    {
        int tp;
        cin >> tp;
        if (tp == 2)
        {
            int g;
            cin >> g;
            if (g == 1)
                cout << ans << ' ';
            else
                cout << (pre[n] ^ ans) << ' ';
        }
        else
        {
            int l, r;
            cin >> l >> r;
            ans ^= pre[r] ^ pre[l - 1];
            // cout << ans << '\n';
        }
        // cout << ans << '\n';
    }
    cout << '\n';
}
/*
 */

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tc = 1;

    cin >> tc; // ....................

    init();
    while (tc--)
        solve();
    return 0;
}