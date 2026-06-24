#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

struct max_bipartite_matching{
    int n, k;
    vector<vector<int>> g;
    vector<int> mt;
    vector<bool> used;  
    
    max_bipartite_matching(int nn, int kk){
        n = nn;
        k = kk;
        g.resize(n + 1);
    }
    
    void add_edge(int u, int v){
        g[u].push_back(v);
    }
    
    bool try_kuhn(int v){
        if (used[v])
            return false;
            
        used[v] = true;
        for (int to : g[v]) {
            if (mt[to] == -1 || try_kuhn(mt[to])) {
                mt[to] = v;
                return true;
            }
        }
        return false;
    }
    
    int find(){
        mt.assign(k + 1, -1);
        for (int v = 1; v <= n; v++){
            used.assign(n + 1, false);
            try_kuhn(v);
        }
        
        int ans = 0;
        
        for (int i = 1; i <= k; i++){
            if (mt[i] != -1){
                ans += 1;
            }
        }
        
        return ans;
    }
};

struct ufds{
    vector <int> root, sz;
    int n;
 
    void init(int nn){
        n = nn;
        root.resize(n + 1);
        sz.resize(n + 1, 1);
        for (int i = 1; i <= n; i++) root[i] = i;
    }
 
    int find(int x){
        if (root[x] == x) return x;
        return root[x] = find(root[x]);
    }
 
    bool unite(int x, int y){
        x = find(x); y = find(y);
        if (x == y) return false;
 
        if (sz[y] > sz[x]) swap(x, y);
        sz[x] += sz[y];
        root[y] = x;
        return true;
    }
};

void Solve() 
{
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;
    s = "0" + s;
    t = "0" + t;
    
    vector <pair<int, int>> e(m);
    for (auto &[u, v] : e) cin >> u >> v;
    
    if (s == t){
        cout << "Yes\n";
        return;
    }
    
    for (auto c : {s, t}){
        max_bipartite_matching G(n, n);
        int cnt = 0;
        for (int i = 1; i <= n; i++) cnt += c[i] == '1';
        
        for (auto [u, v] : e){
            if (c[u] == '1'){
                G.add_edge(u, v);
            }
            if (c[v] == '1'){
                G.add_edge(v, u);
            }
        }
        
        if (G.find() != cnt){
            cout << "No\n";
            return;
        }
    }
    
    ufds uf;
    uf.init(n);
    for (auto [u, v] : e){
        uf.unite(u, v);
    }
    
    vector <int> sum(n + 1, 0);
    for (int i = 1; i <= n; i++){
        if (s[i] == '1'){
            sum[uf.find(i)]++;
        }
        if (t[i] == '1'){
            sum[uf.find(i)]--;
        }
    }
    
    for (int i = 1; i <= n; i++) if (sum[i] != 0){
        cout << "No\n";
        return;
    }
    
    vector<vector<int>> adj(n + 1);
    for (auto [u, v] : e){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for (int p = 0; p < 2; p++){
        // try parity of p moves 
        // in every bipartite component, we must have some satisfying condition 
        
        vector <bool> vis(n + 1, false);
        vector <int> col(n + 1);
        vector <int> cs(2, 0), ct(2, 0);
        bool bip = true;
        
        auto dfs = [&](auto self, int u, int c) -> void{
            vis[u] = true;
            col[u] = c;
            
            if (s[u] == '1'){
                cs[col[u]]++;
            }
            if (t[u] == '1'){
                ct[col[u]]++;
            }
            
            for (int v : adj[u]){
                if (!vis[v]){
                    self(self, v, 1 - c);
                } else if (col[v] == col[u]){
                    bip = false;
                }
            }
        };
        
        bool good = true;
        
        for (int i = 1; i <= n; i++){
            if (!vis[i]){
                bip = true;
                cs[0] = cs[1] = ct[0] = ct[1] = 0;
                dfs(dfs, i, 0);
                
                if (bip){
                    good &= cs[0] == ct[(0 + p) % 2];
                    good &= cs[1] == ct[(1 + p) % 2];
                }
            }
        }
        
        if (good){
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
    return;
}

int32_t main() 
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);
    
    cin >> t;
    for(int i = 1; i <= t; i++) 
    {
        //cout << "Case #" << i << ": ";
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}