#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;
#define TLE (double)clock() / CLOCKS_PER_SEC <= 0.95
#define int long long
#define double long double
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int N = 2e5 + 5, M = 2e5 + 5, S = 1e6 + 5, inf = 0x3f3f3f3f3f3f3f3f, mod = 1e9 + 7;
int n;
int a[N], b[N];
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans++;
        int x = b[i];
        int y = a[i] * b[i];
        for (int j = i + 1; j <= n; j++)
        {
            x = lcm(x, b[j]);
            y = gcd(y, a[j] * b[j]);
            if (y % x != 0)
            {
                i = j - 1;
                break;
            }
            if (j == n)
            {
                i = j;
                break;
            }
        }
    }
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0); // cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        solve();
    }
    return 0;
}