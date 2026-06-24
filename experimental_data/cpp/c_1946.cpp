#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;
const int maxn = 1e5 + 10;
const int root = 1;
vector<int> G[maxn];
int sz[maxn],tot,n,k;
bool ban[maxn];
void dfs(int u,int pa,int mid)
{
    sz[u]=1;
    for(const auto& v : G[u])
    {
        if(v!=pa)
        {
            dfs(v,u,mid);
            if(!ban[v])
            {
                sz[u]+=sz[v];
            }
        }
    }
    if(sz[u]>=mid)
    {
        ban[u]=true;
        tot++;
    }
}
bool check(int mid)
{
    tot=0;
    for(int i=1;i<=n;i++)
    {
        ban[i]=false;
    }
    dfs(root,0,mid);
    return (tot>=1+k);
}
void solve(void)
{
    int u,v;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        G[i].clear();
    }
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    int l=1,r=n;
    while(l<r)
    {
        int mid=(l+r+1)>>1;
        if(check(mid))
        {
            l=mid;
        }
        else
        {
            r=mid-1;
        }
    }
    cout<<r<<endl;
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}