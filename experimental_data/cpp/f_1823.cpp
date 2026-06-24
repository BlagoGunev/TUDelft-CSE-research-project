/*
 * Author: Lanly
 * Time: 2023-04-28 15:55:38
*/

#include <bits/stdc++.h>
#include <vector>
using namespace std;
using LL = long long;
#define FOR(i, x, y) for (decay<decltype(y)>::type i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (decay<decltype(x)>::type i = (x), _##i = (y); i > _##i; --i)

#ifndef ONLINE_JUDGE
#include "debug.h"
#else 
#define debug(x...)
#endif

const int mod = 998244353;

int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int n, s, t;
    cin >> n >> s >> t;
    -- s, -- t;
    vector<vector<int>> edge(n);
    vector<int> du(n);
    for(int i = 1; i < n; ++ i){
        int u, v;
        cin >> u >> v;
        -- u, -- v;
        edge[u].push_back(v);
        edge[v].push_back(u);
        ++ du[u];
        ++ du[v];
    }
    vector<int> fa(n);
    function<void(int, int)> dfs = [&](int u, int f){
        fa[u] = f;
        for(auto &v : edge[u]){
            if (v == f)
                continue;
            dfs(v, u);
        }
    };
    dfs(s, s);
    vector<int> ans(n);
    int cnt = 1;
    ans[t] = 1;
    function<void(int, int, int)> dfs2 = [&](int u, int f, int cnt){
        ans[u] = 1ll * du[u] * cnt % mod;
        for(auto &v : edge[u]){
            if (v == f)
                continue;
            dfs2(v, u, cnt);
        }
    };
    do{
        int cur = fa[t];
        ans[cur] = 1ll * cnt * du[cur] % mod;
        for(auto &u : edge[cur]){
            if (u != fa[cur] && u != t)
                dfs2(u, cur, cnt);
        }
        t = cur;
        ++ cnt;
    }while(s != t);
    for(auto &i : ans)
        cout << i << ' ';
    cout << '\n';

    return 0;
}