#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define bit(a, b) (((a)>>(b))&1)
#define lb(a) ((a)&(-(a)))

const int maxn = 2e5 + 20;

int h[maxn] , mx[maxn];

int d_a[maxn], d_b[maxn];

vector<int> adj[maxn];

void plant(int v, int p = -1)
{
    if(p == -1)
        h[v] = 0;
    mx[v] = max(mx[v], h[v]);
    for(auto u : adj[v])
        if(u != p)
        {
            h[u] = h[v] + 1;
            plant(u, v);
        }
}

int solve()
{
    int n;
    cin >> n;

    int a, b;
    cin >> a >> b;
    a--, b--;

    for(int i = 0; i < n; i++)
        adj[i].clear(), mx[i] = 0;

    for(int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;

        adj[a].pb(b);
        adj[b].pb(a);
    }

    plant(0);
    for(int _ = 0; _ < 2; _++)
    {
        int v = max_element(h, h + n) - h;
        plant(v);
    }

    plant(a);
    for(int i = 0; i < n; i++)
        d_a[i] = h[i];

    plant(b);
    for(int i = 0; i < n; i++)
        d_b[i] = h[i];

    int res = 1e9;
    for(int i = 0; i < n; i++)
        if(d_a[i] <= d_b[i])
            res = min(res, d_b[i] + 2 * (n - 1) - mx[i]);

    cout << res << endl;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();

    return 0;
}