#include<bits/stdc++.h>

#define int long long

using namespace std;

const int N = 2e5 + 10;

vector<int> G[N];

int a[N], d[N];

int in[N], out[N], tot;

map<int, int> mp, c;



void dfs(int u, int fa) {

    in[u] = ++ tot;

    int t = c[a[u]];

    c[a[u]] ++;

    for(auto v : G[u]) {

        if(v == fa) continue;

        int tmp = c[a[u]];

        dfs(v, u);

        if(c[a[u]] > tmp)  {

            d[1] ++, d[in[v]] --;

            d[out[v] + 1] ++;

        } //子树里有a[u]颜色的点

    }

    out[u] = tot;

    if(c[a[u]] - t < mp[a[u]]) {

        d[in[u]] ++, d[out[u] + 1] --;

    }

}



void solve() {

    int n; cin >> n;

    for(int i = 1; i <= n; i ++) cin >> a[i], mp[a[i]] ++;

    for(int i = 1; i < n; i ++) {

        int u, v; cin >> u >> v;

        G[u].push_back(v);

        G[v].push_back(u);

    }

    dfs(1, 0);

    int ans = 0;

    for(int i = 1; i <= n; i ++) {

        d[i] += d[i-1];

        if(d[i] == 0) ans ++;

    }

    cout << ans << "\n";

}



signed main() {

    ios::sync_with_stdio(false);

    cin.tie(nullptr); cout.tie(nullptr);

    solve();

    return 0;

}