#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define ff first
#define ss second
#define all(s) s.begin(),s.end()
#define rall(s) s.rbegin(),s.rend()

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll n,t;
    cin>>n>>t;
    vector<ll>adj[n+5];
    for(ll i=1;i<n;i++){
        ll u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    ll s;
    cin>>s;
    vector<ll>ord;
    function <void(ll,ll)> dfs=[&](ll x,ll p){
        ord.pb(x);
        for(ll y:adj[x]){
            if(y!=p){
                dfs(y,x);
            }
        }
    };
    for(ll i=1;i<=n;i++){
        if(adj[i].size()==1){
            dfs(i,0);
            break;
        }
    }
    ll pos=0;
    for(ll i=0;i<ord.size();i++){
        if(ord[i]==s){
            pos=i+1;
            break;
        }
    }
    if(n%2==0){
        cout<<"Ron";
    }
    else if(pos%2==0){
        cout<<"Ron";
    }
    else{
        cout<<"Hermione";
    }
}