#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef map<ll, ll> mll;

#define N 200'005
#define MOD 1000000007
#define FOR(i, n) for (i = 0; i < n; i++)
#define FORR(i, a, b) for (i = a; i <= b; i++)
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define FREOPEN                  \
    freopen("i.in", "r", stdin); \
    freopen("o.out", "w", stdout);
#define gohome      \
    cout << "NO\n"; \
    return;
#define arprt(x)           \
    for (auto it : x)      \
        cout << it << " "; \
    cout << "\n";

void solve();

#define MAX 2005

int lookup[MAX][MAX];

int logtwo(int x)
{
    return 31 - __builtin_clz(x);
}

void buildSparseTable(ll arr[], int n)
{
    for (int i = 0; i < n; i++)
        lookup[i][0] = arr[i];

    for (int j = 1; (1 << j) <= n; j++)
    {

        for (int i = 0; (i + (1 << j) - 1) < n; i++)
        {
            if (lookup[i][j - 1] > lookup[i + (1 << (j - 1))][j - 1])
                lookup[i][j] = lookup[i][j - 1];
            else
                lookup[i][j] = lookup[i + (1 << (j - 1))][j - 1];
        }
    }
}

int query(int L, int R)
{
    int j = logtwo(R - L + 1);

    if (lookup[L][j] >= lookup[R - (1 << j) + 1][j])
        return lookup[L][j];
    else
        return lookup[R - (1 << j) + 1][j];
}

int main()
{
    FASTIO
    int T;
    T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}

void solve()
{
    ll i, j, n;
    cin >> n;
    ll c[2 * n + 1] = {};
    FOR(i, 2 * n)
    {
        cin >> c[i + 1];
    }
    buildSparseTable(c, 2 * n + 1);
    pll dp[n + 1][n + 1][2];
    for (i = 0; i <= n; i++)
        for (j = 0; j <= n; j++)
        {
            dp[i][j][0] = dp[i][j][1] = {0, 0};
        }
    for (i = 1; i <= n; i++)
    {
        dp[i][0][0] = {1, 1};
        dp[0][i][1] = {1, 2};
    }
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
        {
            if (dp[i - 1][j][0].second)
                dp[i][j][0] = max(dp[i][j][0], {dp[i - 1][j][0].first, 1});
            if (dp[i - 1][j][1].second && c[i + j] > query(dp[i - 1][j][1].first, i + j - 1))
                dp[i][j][0] = max(dp[i][j][0], {i + j, 2});

            if (dp[i][j - 1][1].second)
                dp[i][j][1] = max(dp[i][j][1], {dp[i][j - 1][1].first, 2});
            if (dp[i][j - 1][0].second && c[i + j] > query(dp[i][j - 1][0].first, i + j - 1))
                dp[i][j][1] = max(dp[i][j][1], {i + j, 1});
        }
    ll x = n, y = n;
    vll a, b;
    if (dp[n][n][0].second || dp[n][n][1].second)
    {
        ll w = 1;
        if (dp[n][n][1].second)
            w = 2;
        while (x || y)
        {
            if (w == 1) 
            {
                a.push_back(c[x + y]);
                w = dp[x][y][0].second;
                x--;
            }
            else
            {
                b.push_back(c[x + y]);
                w = dp[x][y][1].second;
                y--;
            }
        }
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        arprt(a);
        arprt(b);
    }
    else
        cout << -1;
}