#include<bits/stdc++.h>



using i64 = long long;

//using int128 = __int128_t;

constexpr int P = 998244353;

//constexpr int P = 1000000007;



struct Info {

    i64 w, s, v;

};



void solve() {

    int n, m;

    std::cin >> n >> m;

    std::vector<int> g[n];

    std::vector<std::pair<int, int>> q;

    while(m--){

        int op, u, v;

        std::cin >> op >> u >> v;

        u--;

        v--;

        if(op){

            g[u].push_back(v);

        }else{

            q.push_back({u, v});

        }

    }

    int ok = 1;

    std::vector<int> topsort;

    std::vector<int> vis(n), instk(n);

    std::function<void(int)> dfs = [&] (int u) {

        vis[u] = 1, instk[u] = 1;

        for(int v : g[u]){

            if(!vis[v]){

                dfs(v);

            }else if(instk[v]){

                ok = 0;

                break;

            }

        }

        instk[u] = 0, topsort.push_back(u);

    };

    for(int i = 0; i < n; ++i){

        if(!vis[i]){

            dfs(i);

        }

    }

    if(!ok){

        std::cout << "NO\n";

    }else{

        std::cout << "YES\n";

        assert(topsort.size() == n);

        std::reverse(topsort.begin(), topsort.end());

        std::vector<int> pos(n);

        for(int i = 0; i < n; ++i){

            int x = topsort[i];

            pos[x] = i;

        }

        for(auto [a, b] : q){

            if(pos[a] > pos[b]){

                std::swap(a, b);

            }

            g[a].push_back(b);

        }

        for(int i = 0; i < n; ++i){

            for(int x : g[i]){

                std::cout << i + 1 << ' ' << x + 1 << '\n';

            }

        }

    }

}



signed main() {

    std::ios::sync_with_stdio(false);

    std::cin.tie(nullptr);



    int t = 1;  std::cin >> t;

    while(t--){

        solve();

    }



    return 0;

}