#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define FILE ""

unordered_map<string, long long> nm;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    //freopen(FILE".in", "r", stdin);
    //freopen(FILE".out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    long long n, k, m;
    cin >> n >> k >> m;
    for (long long i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        nm[s] = i;
    }
    long long c[n];
    for (long long i = 0; i < n; ++i)
        cin >> c[i];
    long long cost[n];
    for (long long i = 0; i < k; ++i)
    {
        long long x;
        cin >> x;
        long long cur[x], mn = 2e9;
        for (long long j = 0; j < x; ++j)
        {
            cin >> cur[j];
            cur[j]--;
            mn = min(mn, c[cur[j]]);
        }
        for (long long j = 0; j < x; ++j)
        {
            cost[cur[j]] = mn;
        }

    }
    long long ans = 0;
    for (long long i = 0; i < m; ++i)
    {
        string s;
        cin >> s;
        ans += cost[nm[s]];
    }
    cout << ans;
    return 0;
}