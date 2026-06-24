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
    int w, f, n;
    cin >> w >> f >> n;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;

    int l = 1, r = e6, sum = accumulate(v.begin(), v.end(), 0LL);
    while (l < r)
    {
        int mid = (l + r) >> 1, ww = w * mid, ff = f * mid;

        if (sum <= ww || sum <= ff)
        {
            r = mid;
            continue;
        }
        vector<int> ok(ww + 1, 0);
        ok[0] = 1;
        for (int i : v)
        {
            for (int j = ww; j >= i; --j)
                ok[j] |= ok[j - i];
        }
        int mx = 0;
        for (int i = 0; i <= ww; ++i)
            if (ok[i])
                mx = i;
        
        if (ff >= sum - mx)
            r = mid;
        else
            l = mid  + 1;
    }
    cout << l << '\n';
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