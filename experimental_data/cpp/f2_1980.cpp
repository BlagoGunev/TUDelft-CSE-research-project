#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define endl '\n'
#define pb push_back
#define ff first
#define ss second
#define all(v) v.begin(), v.end()
#define rev(v) v.rbegin(), v.rend()

const int inf = 2e18;
const int N = 1e6 + 5;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<array<int, 3>> v(k);
    for (int i = 0; i < k; i++)
        cin >> v[i][0] >> v[i][1], v[i][2] = i;
    sort(rev(v));
    int area = 0;
    int x = n, y = m + 1, y2 = m + 1;
    int ind = -1;
    vector<int> ans(k);
    for (int i = 0; i < k; i++)
    {
        if (ind != -1)
            ans[ind] += (x - v[i][0]) * (y2 - y);
        area += (x - v[i][0]) * (y - 1);
        x = v[i][0];
        if (v[i][1] < y)
            y2 = y, y = v[i][1], ind = v[i][2];
        else if (v[i][1] < y2)
            y2 = v[i][1];
    }
    area += x * (y - 1);
    if (ind != -1)
        ans[ind] += x * (y2 - y);
    cout << area << endl;
    for (int &x : ans)
        cout << x << ' ';
    cout << endl;
    return;
}

int32_t main()
{
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}