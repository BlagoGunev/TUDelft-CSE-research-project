#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
#define ff first
#define ss second
const int maxn = 2e5 + 10;
vector <ii> adj[maxn],b[maxn];
int n;
int a[2][maxn],id[maxn];
int cnt,sz;
bool check=1;
vector <int> tmp;
void dfs(int x, int val)
{
    if (!check) return;
    tmp.push_back(x);
    id[x]=val;
    cnt+=id[x];
    for (ii i:adj[x])
    {
        if (!check) return;
        if (id[i.ff]==-1)
        {
            dfs(i.ff,(val^i.ss));
        }
        else
        {
            if ((id[i.ff]^i.ss)!=id[x])
            {
                check=0;
                return;
            }
        }
    }

}

void xuly()
{
    cin>>n;
    for (int i=1; i<=n; i++) b[i].clear(),adj[i].clear();
    for (int i=0; i<2; i++)
        for (int j=1; j<=n; j++)
    {
        cin>>a[i][j];
        b[a[i][j]].push_back({i,j});
    }
    for (int i=1; i<=n; i++)
    {
        if (b[i].size()!=2)
        {
            cout<<"-1\n";
            return;
        }
    }
    for (int i=1; i<=n; i++)
    {
        pair<int,int> u=b[i][0]; pair<int,int> v=b[i][1];
        if (u.ss==v.ss) continue;
        adj[u.ss].push_back({v.ss,(u.ff==v.ff)});
        adj[v.ss].push_back({u.ss,(u.ff==v.ff)});
//        cout<<u.ss<<' '<<v.ss<<' '<<(u.ff==v.ff)<<"!\n";
    }
    fill_n(id,n+1,-1);
    vector <int> ans;
    check=1;
    for (int i=1; i<=n; i++)
    {
        if (id[i]!=-1) continue;
        tmp.clear();
        cnt=0;
        dfs(i,0);
        if (!check)
        {
            cout<<"-1\n";
            return;
        }
//        cout<<i<<' '<<tmp.size()<<'\n';
        if (cnt<tmp.size()-cnt)
            {for (int j:tmp) if (id[j]==1) ans.push_back(j);}
        else
            for (int j:tmp) if (id[j]==0) ans.push_back(j);
    }
    cout<<ans.size()<<'\n';
    for (int i:ans) cout<<i<<' '; cout<<'\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int tt; cin>>tt;
    while (tt--) xuly();
}