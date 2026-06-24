#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define x first
#define y second
 
#define int long long
#define ll long long
#define all(x) x.begin(), x.end()
const int N = 1e6 + 10, M = 5e5 + 10, mod = 998244353, inf = 1e18;
const double pi = acos(-1);
int qmi(int a, int b, int mod)
{
    int res = 1;
    for (; b; b >>= 1)
    {
        if (b & 1)
            res = 1ll * res * a % mod;
        a = 1ll * a * a % mod;
    }
    return res;
}
void solve()
{
    int n, q;
    cin >> n >> q;
    vector st(2 * n + 1, vector(20, 0));
    for (int i = 1; i <= n; ++i)
        cin >> st[i][0], st[i + n][0] = st[i][0];
    for (int j = 1; j < 20; ++j)
    {
        for (int i = 1; i + (1 << j - 1) <= 2 * n; ++i)
        {
            st[i][j] = st[i][j - 1] | st[i + (1 << (j - 1))][j - 1];
        }
    }
    auto get = [&](int l, int r)
    {
        int len = __lg(r - l + 1);
        return st[l][len] | st[r - (1 << len) + 1][len];
    };
    vector<pii> v;
    for (int i = 1; i <= n; ++i)
    {
        vector<pii> cur;
        cur.push_back({st[i][0], i});
        int l = i;
        while (l <= 2 * n)
        {
            int r = 2 * n + 1;
            while (l + 1 < r)
            {
                int mid = l + r >> 1;
                if (get(i, mid) > cur.back().x)
                    r = mid;
                else
                    l = mid;
            }
            // cout<<l<<' '<<r<<' '<<i<<endl;
            if (r == 2* n + 1)
                break;
            int len = r - i;
            if(r > n && len > (n - i + 1)) len--;
            cur.push_back({get(i, r), len * n + i});
            l = r;
        }
        for (auto x : cur)
            v.push_back(x);
    }
    sort(all(v));
    n = v.size();
    for (int i = n - 2; i >= 0; --i)
        v[i].second = min(v[i + 1].second, v[i].second);
    while (q--)
    {
        int x;
        cin >> x;
        auto it = lower_bound(all(v), make_pair(x, inf));
        if (it == v.end())
            cout << "-1\n";
        else
            cout << it->second << endl;
    }
}
 
signed main()
{
    ios ::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(10);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}