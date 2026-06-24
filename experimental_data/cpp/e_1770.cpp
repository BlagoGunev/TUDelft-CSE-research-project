#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod=998244353;

const ll c=300001;



ll power(ll a, ll b){

    ll res=1;

    while(b){

        if(b&1){

            res*=a; res%=mod;

        }

        b>>=1;

        a*=a; a%=mod;

    }

    return res;

}





ll inv(ll a){

    return power(a,mod-2);

}





const ll inv2=inv(2);



ll n,k;

pair<ll,ll> edges[c];

vector<pair<ll,ll>> adj[c];

ll van[c];

ll db[c];

ll ans=0;



void dfs(ll v, ll p, ll e){

    if(e!=0 && edges[e].first != p) swap(edges[e].first,edges[e].second);

    if(van[v]) db[v]=1;

    for(pair<ll,ll> x:adj[v]){

        if(x.first != p){

            dfs(x.first,v,x.second);

            db[v]+=db[x.first];

        }

    }

}   



int main() {

    ios_base::sync_with_stdio(false);

    cin.tie(0);



    cin>>n>>k;

    for(ll i=0 ;i<k;i++) {

        ll a;

        cin>>a;

        van[a]=1;

    }

    for(ll i=1;i<n;i++){

        cin >> edges[i].first >> edges[i].second;

        adj[edges[i].first].push_back({edges[i].second, i});

        adj[edges[i].second].push_back({edges[i].first, i});       

    }

    dfs(1, 0, 0);



    for(ll i=1;i<n;i++){

        ll u=edges[i].first, v=edges[i].second;

        ll a = db[v], b = k - a;

        ll le = inv2*van[u]%mod*(1-van[v]+mod) % mod, fel=inv2*van[v]%mod*(1-van[u]+mod) % mod, nem=(1-le-fel+2*mod)%mod;

        ll prvans=ans;

        ans += nem * a % mod * b % mod;

        ans += le * (a + 1) % mod * (b - 1 + mod) % mod;

        ans += fel * (a - 1 + mod) % mod * (b + 1) % mod;       

        ans%=mod; 

        van[u] = (van[u]+van[v])*inv2%mod;

        van[v] = van[u];

    }

 

    cout << ans*inv(k*(k-1)%mod*inv2%mod) %mod << endl;

}