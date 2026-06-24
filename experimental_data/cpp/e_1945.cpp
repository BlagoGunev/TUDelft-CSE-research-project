#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
const int inf = 0x3f3f3f3f;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int a[n + 5];
        int p;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        int l = 1, r = n + 1;
        vector<bool> f(n + 5, false);
        while (r - l != 1)
        {
            int m = r + l >> 1;
            f[m] = 1;
            if (a[m] <= x)
            {
                l = m;
            }
            else
            {
                r = m;
            }
        }
        f[l] = 1;
        if (a[l] == x)
        {
            cout << 0 << '\n';
            continue;
        }
        else
        {
            int c = 0;
            for (int i = 1; i <= n; i++)
            {
                if (f[i])
                {
                    for (int j = 1; j <= n; j++)
                    {
                        swap(a[i], a[j]);
                        int l = 1, r = n + 1;
                        while (r - l != 1)
                        {
                            int m = r + l >> 1;
                            if (a[m] <= x)
                            {
                                l = m;
                            }
                            else
                            {
                                r = m;
                            }
                        }
                        if (a[l] == x)
                        {
                            cout << 1 << '\n';
                            cout << i << ' ' << j << '\n';
                            c = 1;
                            break;
                        }
                        swap(a[i], a[j]);
                    }
                    if (c)
                    {
                        break;
                    }
                }
            }
        }
    }
    return 0;
}