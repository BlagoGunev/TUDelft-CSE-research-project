#include <bits/stdc++.h>

using namespace std;
#define int long long
const int mod = 998244353;
#define pii pair<int, int>
const int N = 2e5 + 10;
map<int, int> mp;
void solve()
{
    int n, m;
    mp.clear();
    vector<int> v;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mp[v[i]] = x;
    }
    sort(v.begin(), v.end());
    int maxn = 0;
    for (auto j : v)
    {
        maxn = max(maxn, min(m / j, mp[j]) * j);
    }

    for (int i = 0; i < v.size() - 1; i++)
    {
        if (v[i + 1] - v[i] == 1)
        {
            int fa = min(m / v[i], mp[v[i]]);
            int tt = m - fa * v[i];
            int fb = min(tt / v[i + 1], mp[v[i + 1]]);
            int syb = mp[v[i + 1]] - fb;
            tt -= fb * v[i + 1];
            tt -= min({syb, fa, tt});
            maxn = max(maxn, m - tt);
        }
    }
    cout << maxn << '\n';
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(20);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}