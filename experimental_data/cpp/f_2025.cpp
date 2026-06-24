#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int INF = 0x3f3f3f3f;
const i64 mod = 1e9 + 7;
const int N = 200004;
i64 n, q;

void solve() {
    cin >> n >> q;
    vector<string> ans(q+1, "x+");
    vector<vector<int>> h(n+1);
    vector<pair<int, int>> E(q+1);
    vector<bool> match(q+1, 0);
    for(int i = 1; i <= q; ++i) {
        int u, v;
        cin >> u >> v;
        E[i] = make_pair(u, v);
        h[u].push_back(i*2);
        h[v].push_back(i*2+1);        
    }

    auto try_match = [&](int i, int j, int v) -> bool { //边编号，选择的匹配点
        if(match[i] || match[j]) return 0;

        ans[i][1] = i < j ? '+' : '-';
        ans[j][1] = j < i ? '+' : '-';
        ans[i][0] = E[i].first == v ? 'x' : 'y';
        ans[j][0] = E[j].first == v ? 'x' : 'y';
        
        match[i] = match[j] = 1;

        return 1;
    };
    vector<int> vis(n+1, 0), dfn(n+1, 0);
    int tot;
    auto dfs =[&](auto& self, int u, int cur) -> int {
        int e = -1;//未匹配边
        vis[u] = 1, dfn[u] = ++tot;
        for(int i : h[u]) {
            int v = i%2 ? E[i/2].first : E[i/2].second;
            if(vis[v]) {
                if(dfn[v] > dfn[u]) {//重边,正常处理
                    if(~e) {
                        try_match(e, i/2, u);
                        e = -1;
                    }
                    else {
                        e = i/2;
                    }
                }
                else {//环边，留着后面处理
                    continue;
                }
            }
            else {
                int d = self(self, v, i/2);
                if(~d) {
                    if(~e) {
                        try_match(d, e, u);
                        e = -1;
                    }
                    else {
                        e = d;
                    }
                }
            }
        }
        if(~e && ~cur) {
            try_match(e, cur, u);
            return -1;
        }
        else {
            return cur;
        }
    };
    for(int i = 1; i <= n; ++i) {
        if(!vis[i]) dfs(dfs, i, -1);
    }
    for(int i = 1; i <= q; ++i) {
        cout << ans[i] << '\n';
    }
};
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    solve();
    return 0;
}