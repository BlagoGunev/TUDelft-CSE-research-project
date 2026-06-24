#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pll pair<ll,ll>
#define mp make_pair
#define pb push_back
#define fi first
#define se second

using namespace std;

#define LOCALIO "C:/Users/admin/Documents/Code/freopen/"

vector <pll> A[1000005];
priority_queue <pll, vector <pll>, greater <pll>> q;
ll dis[1000005], n, m;

void addedge(ll x, ll y, ll z)
{
    A[x].pb({y, z});
    A[x].pb({y+n, 0});
    A[x].pb({y+2*n, z*2});
    A[x].pb({y+3*n, z});
    A[x+n].pb({y+3*n, z*2});
    A[x+2*n].pb({y+3*n, 0});
    A[x+n].pb({y+n, z});
    A[x+2*n].pb({y+2*n, z});
    A[x+3*n].pb({y+3*n, z});
}

void dijkstra(ll s)
{
    q.push({0, s});
    dis[s]=0;
    while (!q.empty())
    {
        ll x=q.top().se, dis1=q.top().fi; q.pop();
        if (dis[x]!=dis1)
            continue;
        for (ll i=0; i<A[x].size(); i++)
        {
            ll v=A[x][i].fi, disv=A[x][i].se;
            if (dis[v]==-1 || dis[v]>dis1+disv)
            {
                dis[v]=dis1+disv;
                q.push({dis1+disv, v});
            }
        }
    }
}

int main()
{
    #ifdef LOCAL
        freopen( LOCALIO "input.txt","r",stdin) ;
        freopen( LOCALIO "output.txt","w",stdout) ;
    #endif

    ios_base::sync_with_stdio(NULL); cin.tie(nullptr); cout.tie(nullptr);
//	freopen("FIBONACCI.inp","r",stdin);
//	freopen("FIBONACCI.out","w",stdout);
    cin >> n >> m;
    for (ll i=1; i<=m; i++)
    {
        ll x, y, z; cin >> x >> y >> z;
        addedge(x, y, z);
        addedge(y, x, z);
    }
    fill(begin(dis), end(dis), -1);
    dijkstra(1);
    for (ll i=2; i<=n; i++)
        cout << dis[i+3*n] << " ";
}