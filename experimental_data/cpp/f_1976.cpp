#include<bits/stdc++.h>
#define ll long long
#define N 300005
#define endl "\n" 
#define fi first
#define se second
using namespace std;
const ll mod=1e9+7;
const ll inf=1e18;
const double eps=1e-6;
priority_queue<ll>q;
namespace sp{
    ll fa[N],dep[N],son[N],siz[N],len[N],top[N];
    vector<ll>v[N];
    void dfs(ll x,ll fat){
        len[x]=x;
        fa[x]=fat;
        dep[x]=dep[fa[x]]+1;
        for(auto y:v[x]){
            if(y==fa[x])continue;
            dfs(y,x);
            if(dep[len[x]]<dep[len[y]]){
                len[x]=len[y];
                son[x]=y;
            }
        }
    }
    void dfs2(ll x,ll tp){
        top[x]=tp;
        if(son[x])dfs2(son[x],tp);
        for(auto y:v[x]){
            if(y==fa[x]||y==son[x])continue;
            dfs2(y,y);
        }
        if(len[x]==x)q.push(dep[x]-dep[top[x]]+1);
    }

}using namespace sp;
ll n;
void sol(){
    cin>>n;
    while (!q.empty())q.pop();
    for(int i=1;i<=n;i++){
        fa[i]=dep[i]=son[i]=siz[i]=len[i]=top[i]=0;
        v[i].clear();
    }
    for(int i=1;i<n;i++){
        ll x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1,0);
    dfs2(1,1);
    ll res=n;
    auto t=q.top();
    q.pop();
    res-=t;
    cout<<res<<" ";
    for(int i=1;i<n-1;i++){
        if(q.size()>=1){
            t=q.top();
            q.pop();
            res-=t;
        }
        if(q.size()>=1){
            t=q.top();
            q.pop();
            res-=t;
        }
        cout<<res<<" ";
    }
    cout<<endl;
}
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ll ttt;
    cin>>ttt;
    while(ttt--)sol();
    return 0;
}