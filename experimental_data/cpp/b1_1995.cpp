#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define int ll

#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define pb push_back
#define all(a) (a).begin(),(a).end()
#define sz(a) ((int)(a).size())
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define nrbits __builtin_popcount
#define nrbitsll __builtin_popcountll

int n,m,a[200005];

void testcase()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1,a + n + 1);
    map<int,int> c;
    map<int,bool> viz;
    for (int i = 1; i <= n; i++)
        c[a[i]]++;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int x = c[a[i]],y = c[a[i] + 1],z = a[i];
        if (viz[a[i]])
            continue;
        viz[a[i]] = true;
        for (int cnt = 1; cnt <= x; cnt++)
        {
            int cost = cnt * z;
            if (cost > m)
                continue;
            int rem = m - cost;
            int r2 = min(rem / (z + 1),y);
            cost += r2 * (z + 1);
            ans = max(ans,cost);
        }
    }
    cout << ans << '\n';
}

bool multiple_testcases = true;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc = 1;
    if (multiple_testcases == true)
        cin >> tc;
    while (tc--)
        testcase();
    return 0;
}