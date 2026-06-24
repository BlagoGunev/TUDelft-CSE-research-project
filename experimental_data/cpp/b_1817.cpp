#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define ll long long int
#define fi first
#define se second

#define md1 1000000007
#define md2 998244353 //r=3  upto root of 1<<23
#define md3 1000000009
#define md4 7340033   //r=5  upto root of 1<<20

#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
 
using namespace __gnu_pbds;
using namespace std;

// ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int t,n,m,vis[2010],U[2010],V[2010],deg,cnct[2010];
vector<pair<int,int>> adj[2010];
vector<int> order;
bool dfs(int x,int rt,int p){
    if(vis[x]){
        if(x==rt){
            if(deg>=2)return true;
            return false;
        }
        return false;
    }
    if(cnct[x])deg--;
    vis[x]=1;
    bool ans=false;
    for(pair<int,int> pr:adj[x]){
        int i=pr.first,ed=pr.second;
        if(i==p)continue;
        order.pb(ed);
        ans|=dfs(i,rt,x);
        if(ans)return true;
        order.pop_back();
    }
    if(cnct[x])deg++;
    return false;
}
int main(){
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1,u,v;i<=m;i++){
            cin>>u>>v;
            U[i]=u;V[i]=v;
            adj[u].pb({v,i});
            adj[v].pb({u,i});
        }
        int can=0;
        for(int x=1;x<=n;x++){
            for(int i=1;i<=n;i++)cnct[i]=0;
            for(pair<int,int> j:adj[x])cnct[j.first]=1;
            deg=adj[x].size();
            
            if(dfs(x,x,-1)){
                for(int i:order){
                    vis[U[i]]=2;
                    vis[V[i]]=2;
                    // cout<<U[i]<<" "<<V[i]<<"\n";
                }
                int cnt=0;
                for(pair<int,int> pr:adj[x]){
                    if(vis[pr.first]!=2 && cnt<2){
                        vis[pr.first]=2;
                        order.pb(pr.second);
                        cnt++;
                    }
                }
                can=1;
                break;
            }
            for(int j=1;j<=n;j++)vis[j]=0;
        }
        if(can){
            cout<<"YES\n"<<order.size()<<"\n";
            for(int i:order)cout<<U[i]<<" "<<V[i]<<"\n";
        }
        else cout<<"NO\n";
        for(int i=1;i<=max(n,m);i++){
            adj[i].clear();
            vis[i]=0;
            U[i]=0;
            V[i]=0;
            cnct[i]=0;
        }
        deg=0;
        order.clear();
    }
    return 0;
}