#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define pb push_back
#define vt vector
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define ub upper_bound
#define lb lower_bound


const int inf = (int)2e9, mod = (int)998244353, mx = (int)2e5 + 10;
const ll infll = (ll)7e18;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());


void solve(){
    int N; cin >> N;
    vector<vt<ll>> dp(N+1, vector<ll>(3)); 
    //dp[i][j] -> rooted at i, max path par len 
    //number of ways

    vector<vector<int>> adj(N+1);
    for(int i = 0; i < N - 1; i++){
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u); 
    }

    function<void(int, int)> dfs = [&](int v, int p) -> void{
        if(adj[v].size() == 1 && v != 1){
            dp[v][0] = 1; 
            dp[v][1] = 1;
            dp[v][2] = 0; 
            return; 
        }
        for(auto u : adj[v]){
            if(u == p)continue;
            dfs(u, v); 
        }
        //place an intersection here
        dp[v][1] = 1; 
        for(auto u : adj[v]){
            if(u == p)continue;
            dp[v][2] += dp[u][1];
            dp[v][2] %= mod; 
        }
        //dont place intersectoin here
        dp[v][0] = 1; 
        ll mu = 1; 
        for(auto u : adj[v]){
            if(u == p)continue;
            mu *= (dp[u][0] + dp[u][1]); 
            mu %= mod; 
        }
        dp[v][1] += mu; dp[v][1]--;dp[v][1] %= mod; 
        //do 2 here 
        for(auto u : adj[v]){
            if(u == p)continue;
            dp[v][2] += dp[u][2]; dp[v][2] %= mod; 
        }
    };
    dfs(1, -1);
    cout << (dp[1][0] + dp[1][1] + dp[1][2]) % mod << '\n';  
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}