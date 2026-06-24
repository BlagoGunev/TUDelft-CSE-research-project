#include <bits/stdc++.h>
using namespace std;

#ifdef __LOCAL__
  #include <debug_local.h>
#endif
#define INF (int)1e18
#define f first
#define s second
#define int long long

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
int n, m;
const int N = 2e5 + 69;
vector <int> adj[N];
set <int> orz, comp;
bool vis[N];
vector <int> cyc;
set <pair<int, int>> e;

void dfs1(int u){
    vis[u] = true;
    comp.insert(u);
    
    for (int v: adj[u]){
        if (vis[v]) continue;
        if (adj[v].size() == 2){
            dfs1(v);
        } else {
            orz.insert(v);
        }
    }
}

void dfs2(int u){
    vis[u] = true;
    cyc.push_back(u);
    
    for (int v: adj[u]){
        if (vis[v]) continue;
        
        dfs2(v);
        break;
    }
}

void Solve() 
{
    cin>>n>>m;
    e.clear();
    cyc.clear();
    for (int i=1; i<=n; i++) {
        adj[i].clear();
        vis[i] = false;
    }
    
    for (int i=1; i<=m; i++){
        int u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        e.insert({u, v});
        e.insert({v, u});
    }
    int cnt = 0;
    set <int> rem;
    for (int i=1; i<=n; i++){
        if (adj[i].size() != 2 && adj[i].size() != 4) {
            cout<<"NO\n";
            return;
        }
        if (adj[i].size() == 4) cnt++;
        else rem.insert(i);
    }
    int k = -1;
    for (int kk = 3; kk <= 500; kk++){
        if (n == kk * kk && m == kk * kk + kk && cnt == kk){
            k = kk;
        }
    } 
    if (k==-1){
        cout<<"NO\n";
        return;
    }
    bool bad = false;
    for (int i=1; i<=k; i++){
        orz.clear();
        comp.clear();
        if (rem.size() == 0){
            bad = true; break;
        }
        int z = *rem.begin();
        dfs1(z);
        if (orz.size() != 1){
            bad = true; break;
        }
        if (comp.size() != k - 1){
            bad = true; break;
        }
        for (auto x: comp){
            rem.erase(x);
        }
    }
    if (bad){
        cout<<"NO\n";
        return;
    }
    for (int i=1; i<=n; i++){
        if (!vis[i]){
            dfs2(i);
            if (cyc.size() != k){
                bad = true; break;
            }
            pair <int, int> pi = {cyc[0], cyc.back()};
            if (e.find(pi) == e.end()){
                bad = true; break;
            }
        }
    }
    if (bad) cout<<"NO\n";
    else cout<<"YES\n";
}

int32_t main() 
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) 
    {
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    return 0;
}