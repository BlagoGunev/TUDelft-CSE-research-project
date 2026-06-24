#include<bits/stdc++.h>



#define int long long

#define pb push_back

#define fi first

#define se second

using namespace std;

using ll = long long;

using ld = long double;

using ull = unsigned long long;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int maxN = 1e6 + 5;

const int mod = 1e9 + 7;

const ll oo = 1e18;

int n, q;

int a[maxN];

vector<int> adj[maxN];

int nChain = 0;

int chainhead[maxN], chainid[maxN];

int p[maxN], depth[maxN], sz[maxN];

int timein[maxN], Time = 0;

int st[4 * maxN];

void update(int id, int l, int r, int pos, int val)

{

    if(l > pos || r < pos) return;

    if(l == r && l == pos)

    {

        st[id] = val;

        return;

    }

    int mid = (l + r) / 2;

    update(id * 2, l, mid, pos, val);

    update(id * 2 + 1, mid + 1, r, pos, val);

    st[id] = st[id * 2] + st[id * 2 + 1];

}

int get(int id, int l, int r, int u, int v)

{

    if(l > v || r < u) return 0;

    if(l >= u && r <= v) return st[id];

    int mid = (l + r) / 2;

    return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);

}

void ReadInput()

{

    cin >> n >> q;

    for(int i=1; i<=n; i++) cin >> a[i];

    for(int i=1; i<n; i++)

    {

        int u, v;

        cin >> u >> v;

        adj[u].pb(v);

        adj[v].pb(u);

    }

}

void dfs(int u)

{

    sz[u] = 1;

    for(int v : adj[u])

    {

        if(p[u] == v) continue;

        p[v] = u;

        depth[v] = depth[u] + 1;

        dfs(v);

        sz[u] += sz[v];

    }

}

void HLD(int u)

{

    if(!chainhead[nChain]) chainhead[nChain] = u;

    chainid[u] = nChain;

    int bigChild = -1;

    timein[u] = ++Time;

    for(int v : adj[u])

    {

        if(v == p[u]) continue;

        if(bigChild == -1 || sz[bigChild] < sz[v])

            bigChild = v;

    }

    if(bigChild != -1) HLD(bigChild);

    for(int v : adj[u])

    {

        if(v == p[u] || v == bigChild) continue;

        nChain++;

        HLD(v);

    }

}

int Query(int u, int v)

{

    int res = 0;

    while(chainhead[chainid[u]] != chainhead[chainid[v]])

    {

        if(depth[chainhead[chainid[u]]] < depth[chainhead[chainid[v]]]) swap(u, v);

        res += get(1, 1, n, timein[chainhead[chainid[u]]], timein[u]);

        u = p[chainhead[chainid[u]]];

    }

    if(depth[u] > depth[v]) swap(u, v);

    res += get(1, 1, n, timein[u], timein[v]);

    return res;

}

void Solve()

{

    dfs(1);

    HLD(1);

    for(int i=1; i<=n; i++)

        update(1, 1, n, timein[i], abs(a[i]));

    while(q--)

    {

        int type;

        cin >> type;

        if(type == 1)

        {

            int u, c;

            cin >> u >> c;

            update(1, 1, n, timein[u], abs(c));

        }

        else

        {

            int u, v;

            cin >> u >> v;

            cout << Query(u, v) * 2 - get(1, 1, n, timein[u], timein[u]) - get(1, 1, n, timein[v], timein[v]) << '\n';

        }

    }

}

int32_t main()

{

 //   freopen("x.inp", "r", stdin);

    ios_base::sync_with_stdio(false);

    cin.tie(nullptr);

    ReadInput();

    Solve();

}