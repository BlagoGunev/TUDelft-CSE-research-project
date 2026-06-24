#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// const int mod=998244353;

const int mod=1e9+7;

#define inf 0x3f3f3f3f

int main()

{

    // freopen("1.in","r",stdin);

    // freopen("1.out","w",stdout);

    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n;cin>>n;

    vector<int>a(n+1);

    for(int i=1;i<=n;++i) cin>>a[i];

    auto b=a;

    

    vector<vector<int>>e(n+1);

    for(int i=1;i<n;++i)

    {

        int u,v;cin>>u>>v;e[u].push_back(v);e[v].push_back(u);

    }

    int rt=1;



    vector<int>son(n+1),si(n+1),f(n+1);





    function<void(int,int)>getrt=[&](int u,int p)

    {

        si[u]=1;

        f[u]=0;

        for(int v:e[u])

            if(v!=p)

            {

                getrt(v,u);

                si[u]+=si[v];

                f[u]=max(f[u],si[v]);

            }

        f[u]=max(f[u],n-si[u]);

    };

    getrt(rt,0);

    for(int i=2;i<=n;++i)

        if(f[i]<f[rt]) rt=i;



    function<void(int,int)>dfs=[&](int u,int p)

    {

        si[u]=1;

        b[u]^=b[p];

        for(int v:e[u])

            if(v!=p)

        {

            dfs(v,u);

            si[u]+=si[v];

            if(si[v]>si[son[u]])

                son[u]=v;

        }

    };

    dfs(rt,0);

    

    int ans=0;

    map<int,bool>vis;

    vector<bool>del(n+1);

    bool flag;

    vector<int>vc;

    function<void(int,int,int)>gfs=[&](int u,int p,int au)

    {

        if(del[u]) return;

        if(vis.count(b[u]^au)) flag=false;

        vc.push_back(b[u]);

        for(int v:e[u])

            if(v!=p)

            gfs(v,u,au);

    };

    function<void(int,int)>getans=[&](int u,int p)

    {

        for(int v:e[u])

            if(v!=son[u]&&v!=p)

            {

                getans(v,u);

                vis.clear();

            }

        if(son[u]) getans(son[u],u);

        flag=true;

        for(int v:e[u])

            if(v!=son[u]&&v!=p)

        {

            gfs(v,u,a[u]);

            for(int val:vc) vis[val]=true;

            vc.clear();

        }

        if(vis.count(b[u]^a[u])) flag=false;

        vis[b[u]]=true;

        if(!flag) ++ans,vis.clear(),del[u]=true;

    };

    getans(rt,0);

    cout<<ans<<'\n';

}