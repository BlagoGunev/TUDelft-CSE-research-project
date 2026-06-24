#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

using ll = long long;
#define pb push_back

#define int long long
using namespace std;

const int MOD = 0;

int n, m;
vector<int> c;
vector<int> dp;
vector<vector<int>> graph;
vector<bool> found;

int dfs(int x){
    if(found[x]){return dp[x];}
    found[x] = true;

    int count = 0;

    for(int i : graph[x]){
        count += dfs(i);
    }

    if(!graph[x].empty()){
        dp[x] = min(dp[x], count);
    }
    return dp[x];

}

void solve() {
    cin >> n >> m;

    c = vector<int>(n+1);
    dp = vector<int>(n+1);
    graph = vector<vector<int>>(n+1);
    found = vector<bool>(n+1);
    for(int i = 1; i <= n; ++i){
        cin >> c[i];
    }

    for(int i = 0; i < m; ++i){
        int x; cin >> x;
        c[x] = 0;
    }

    for(int i = 1; i <= n; ++i){
        dp[i] = c[i];
    }

    for(int i = 1; i <= n; ++i){
        int x; cin >> x;
        for(int j = 0; j < x; ++j){
            int y; cin >> y;
            graph[i].pb(y);
        }
    }

    for(int i = 1; i <= n; ++i){
        dfs(i);
    }

    for(int i = 1; i <= n; ++i){
        cout << dp[i] << ' ';
    }

    cout << endl;


}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}