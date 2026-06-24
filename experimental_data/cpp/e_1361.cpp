#include <bits/stdc++.h>

using namespace std;

#pragma GCC target("avx")

#pragma GCC optimize(2)

#pragma GCC optimize(3)

#pragma GCC optimize("Ofast")

const int N = 1e5 + 5;

int n, m;

int vis[N];

set<int> ans;

vector<int> e[N];

multiset<int> s[N];

inline bool check(const int &u)

{

    vis[u] = 1;

    for (int v : e[u])

    {

        if (vis[v] == 2) return false;

        else if (vis[v] == 0 && !check(v)) return vis[u] = 2, false;

    }

    vis[u] = 2;

    return true;

}

inline void dfs1(const int &u)

{

    vis[u] = 1;

    for (int v : e[u])

    {

        if (vis[v] == 1) s[u].insert(v);

        else if (vis[v] == 0)

        {

            dfs1(v);

            auto tmp = s[v];

            if(s[u].size() < tmp.size())

                swap(tmp, s[u]);

            for(auto i : tmp)

                s[u].insert(i);

        }

    }

    vis[u] = 2;

    s[u].erase(u);

}

inline void dfs2(const int &u)

{

    if (s[u].size() == 1 && ans.count(*s[u].begin())) ans.insert(u);

    vis[u] = 1;

    for (int v : e[u])

        if (vis[v] != 1)

            dfs2(v);

}

int id[N];

signed main()

{

    srand(2022/10/27);

    int T;

    cin >> T;

    while (T --> 0)

    {

        ans.clear();

        for (int i = 1; i <= n; i++) s[i].clear();

        for (int i = 1; i <= n; i++) e[i].clear();

        cin >> n >> m;

        for (int i = 1, u, v; i <= m; i++)

        {

            cin >> u >> v;

            e[u].emplace_back(v);

        }

        iota(id+1, id+n+1, 1);

        shuffle(id+1, id+n+1, mt19937(random_device{}()));

        int root(0);

        for (int i = 1; memset(vis, false, sizeof(vis)), i <= min(n, 100) && !root; i++)

            if (check(id[i]))

                root = id[i];

        if (!root){cout << -1 << '\n'; continue;}

        memset(vis, false, sizeof(vis));

        dfs1(root);

        ans.insert(root);

        dfs2(root);

        if (ans.size() * 5 < n) {cout << -1 << '\n'; continue;}

        for (auto x : ans) cout << x << ' '; putchar('\n');

    }

    return 0;

}