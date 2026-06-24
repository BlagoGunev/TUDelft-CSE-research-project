#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
void solve()
{
    int n, k;
    cin >> n >> k;
    if (n == 4 and k == 3)
    {
        cout << -1 << "\n";
        return;
    }
    int lg = 1;
    while (((1 << lg)) != n)
        lg++;
    vector <bool> used(n + 1, 0);
    if ((n - 1) == k)
    {
        cout << n - 1 << " " << n - 2 << "\n";
        cout << n / 2 - 1 << " " << 1 << "\n";
        used[1] = 1; used[n / 2 - 1] = 1; used[n - 1] = 1; used[n - 2] = 1;
        cout << n - n / 2 << " " << 0 << "\n";
        used[n - n / 2] = 1; used[0] = 1;
        for (int i = 0; i < n; i++)
        {
            int x = 0;
            if (used[i])
                continue;
            for (int j = 0; j < lg; j++)
            {
                if (!((i >> j) & 1))
                    x += (1 << j);
            }
            cout << i << " " << x << "\n";
            used[i] = 1; used[x] = 1;
        }
        return;
    }
    if (k == 0)
    {
        for (int i = 0; i < n; i++)
        {
            int x = 0;
            if (used[i])
                continue;
            for (int j = 0; j < lg; j++)
            {
                if (!((i >> j) & 1))
                    x += (1 << j);
            }
            cout << i << " " << x << "\n";
            used[i] = 1; used[x] = 1;
        }
        return;
    }
    cout << k << " " << n - 1 << "\n";
    int x = 0;
    for (int i = 0; i < lg; i++)
    {
        if (!((k >> i) & 1))
            x += (1 << i);
    }
    cout << 0 << " " << x << "\n";
    used[0] = 1;
    used[x] = 1;
    used[k] = 1;
    used[n - 1] = 1;
    for (int i = 0; i < n; i++)
    {
        if (used[i])
            continue;
        int x = 0;
        for (int j = 0; j < lg; j++)
        {
            if (!((i >> j) & 1))
                x += (1 << j);
        }
        cout << x << " " << i << "\n";
        used[i] = 1;
        used[x] = 1;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}