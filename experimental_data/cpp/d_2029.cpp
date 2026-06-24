#include<bits/stdc++.h>
using namespace std;

struct Ans{
    int a,b,c;
};

int T,n,m;
set<int> adj[100005];

void change(int x, int y){
    if(adj[x].count(y)){
        adj[x].erase(y);
        adj[y].erase(x);
    }
    else{
        adj[x].insert(y);
        adj[y].insert(x);
    }
}

struct Dsu{
    int f[100005], sz[100005];
    void init(int n){
        for(int i=1;i<=n;i++){
            f[i] = i, sz[i] = 1;
        }
    }

    int find(int x){
        if(f[x] == x) return x;
        return f[x] = find(f[x]);
    }

    void uni(int x, int y){
        x = find(x), y = find(y);
        if(x == y) return;
        f[x] = y;
        sz[y] += sz[x];
    }
}dsu;

int main(){
    cin >> T;
    while(T--){
        cin >> n >> m;
        vector<Ans> ans;
        for(int i=1;i<=n;i++){
            adj[i].clear();
        }

        for(int i=1;i<=m;i++){
            int u,v;
            cin >> u >> v;
            adj[u].insert(v);
            adj[v].insert(u);
        }

        queue<int> q;

        for(int i=1;i<=n;i++){
            if(adj[i].size() >= 2) q.push(i);
        }

        while(q.size()){
            int i = q.front(); q.pop();
            if(adj[i].size() <= 1) continue;
            vector<int> v;
            for(auto x: adj[i]) v.push_back(x);
            int sz = v.size();
            for(int j=0;j<sz/2;j++){
                int a = v[j*2], b = v[j*2+1];
                ans.push_back({a,b,i});
                change(a, b);
                change(a, i);
                change(b, i);
                if(adj[a].size() >= 2) q.push(a);
                if(adj[b].size() >= 2) q.push(b);
            }
        }

        dsu.init(n);
        bool has_edge = false;
        for(int i=1;i<=n;i++){
            for(int x: adj[i]){
                dsu.uni(i, x);
                has_edge = true;
            }
        }

        if(has_edge){
            int p = 0;
            for(int i=1;i<=n;i++){
                if(dsu.find(i) == i && dsu.sz[i] > 1){
                    p = i; break;
                }
            }

            vector<int> v;
            for(int i=1;i<=n;i++){
                if(dsu.find(i) == p) v.push_back(i);
            }

            int a = v[0], b = v[1];
            for(int i=1;i<=n;i++){
                if(dsu.find(i) != dsu.find(p)){
                    ans.push_back({a,b,i});
                    b = i;
                    dsu.uni(i, p);
                }
            }
        }

        cout << ans.size() << "\n";
        for(auto [a,b,c]: ans){
            cout << a <<" " << b << " " << c << "\n";
        }
        
    }
}