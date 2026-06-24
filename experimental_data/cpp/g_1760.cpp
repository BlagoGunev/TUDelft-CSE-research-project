#include <bits/stdc++.h>



using ll = long long;



void solve() {

    int n, start, end;

    std::cin >> n >> start >> end;



    std::vector<std::vector<std::array<int, 2>>> g(n + 1);

    for (int i = 2; i <= n; i++) {

        int u, v, w;

        std::cin >> u >> v >> w;

        g[u].push_back({ v, w });

        g[v].push_back({ u, w });

    }



    std::set<int> S;



    std::vector<int> f1(n + 1), f2(n + 1);

    auto dfs1 = [&](auto dfs1, int u, int fa) -> void {

        if (u != end) S.insert(f1[u]);

        for (auto [v, w] : g[u]) {

            if (v == fa || v == end) continue;

            f1[v] = f1[u] ^ w;

            dfs1(dfs1, v, u);

        }

    };

    dfs1(dfs1, start, -1);



    bool ok = 0;



    auto dfs2 = [&](auto dfs2, int u, int fa) -> void {

        if (u != end) {

            if (S.contains(f2[u])) ok = 1;

        }

        for (auto [v, w] : g[u]) {

            if (v == fa) continue;

            f2[v] = f2[u] ^ w;

            dfs2(dfs2, v, u);

        }

    };

    dfs2(dfs2, end, -1);



    std::cout << (ok ? "YES\n" : "NO\n");

}



int main() {

    std::cin.tie(0)->std::ios::sync_with_stdio(0);

    int _ = 1;

    std::cin >> _;

    while (_--)  solve();

    return 0;

}