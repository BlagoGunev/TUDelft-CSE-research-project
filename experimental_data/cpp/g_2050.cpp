#include <bits/stdc++.h>
#include <random>
#include <unordered_set>
using namespace std;
#define int long long
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
#define lowbit(x) ((x)&(-x))
#define endl '\n';

struct Tree {
    int n,root;
    vector<vector<int>> adj, child, acs;

    vector<int> dep,hei;

    Tree(vector<vector<int>> &adj_, int root_=1) {
        adj=adj_;
        root=root_;
        n=adj.size()-1;
        child=vector<vector<int>>(n+1);
        dep=hei=vector<int>(n+1);
        acs=vector<vector<int>>(20,vector<int>(n+1));
        dfs(root,0);
        for(int i=1;i<20;i++) {
            for(int j=1;j<=n;j++) {
                acs[i][j]=acs[i-1][acs[i-1][j]];
            }
        }
    }

    void dfs(int curr, int fa) {
        acs[0][curr]=fa;
        dep[curr]=dep[fa]+1;
        for(auto e:adj[curr]) {
            if(e==fa) continue;
            child[curr].push_back(e);
            dfs(e,curr);
            hei[curr]=max(hei[curr],hei[e]+1);
        }
    }

    int find_acs(int u, int d) {
        while(d) {
            int lb=d&-d;
            u=acs[__lg(lb)][u];
            d-=lb;
        }
        return u;
    }

    int find_lca(int u, int v) {
        if(dep[u]<dep[v]) swap(u,v);
        u=find_acs(u,dep[u]-dep[v]);

        if(u==v) return u;

        for(int i=19;i>=0;i--) {
            int ua=acs[i][u], va=acs[i][v];
            if(ua!=va) u=ua,v=va;
        }
        
        return acs[0][u];
    }

    pair<int,int> find_lca_dis(int u, int v) {
        bool flag=false;
        if(dep[u]<dep[v]) {
            swap(u,v);
            flag=true;
        }
        int dd=dep[u]-dep[v];
        u=find_acs(u,dd);

        pair<int,int> ans;

        if(u==v) {

            ans={dd,0};

        } else {

            int cnt=0;

            for(int i=19;i>=0;i--) {
                int ua=acs[i][u], va=acs[i][v];
                if(ua!=va) {
                    u=ua,v=va;
                    cnt+=(1LL<<i);
                }
            }
            
            ans={cnt+dd+1,cnt+1};
        }

        if(flag) swap(ans.first,ans.second);
        
        return ans;
    }
};

void solve() {

    int n;cin>>n;

    vector<vector<int>> adj(n+1);

    for(int i=0;i<n-1;i++) {
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    Tree tr(adj);

    vector<int> dp(n+1);
    int ans=0;

    function<void(int)> dfs=[&](int curr){

        vector<int> ch=tr.child[curr];

        int m=ch.size();

        dp[curr]=m;

        for(auto e:ch) {
            dfs(e);
            dp[curr]=max(dp[curr],m-1+dp[e]);
        }

        int extra=curr!=1;

        ans=max(ans,dp[curr]+extra);

        if(m>=2) {
            vector<int> val;
            for(auto e:ch) {
                val.push_back(dp[e]);
            }
            sort(val.rbegin(),val.rend());
            ans=max(ans,val[0]+val[1]+m-2+extra);
        }
    };

    dfs(1);

    cout<<ans<<endl;
}

main() {
 
	ios::sync_with_stdio(0); cout.tie(0);

    int _=1;
    cin>>_;
    while(_--) {
        solve();
    }

    return 0;
}