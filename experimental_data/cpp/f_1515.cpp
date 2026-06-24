#include <bits/stdc++.h>

using namespace std;



using i64 = long long;

using pii = pair<int, int>;



void run() {

    int n, m, x;

    cin >> n >> m >> x;

    vector<i64> a(n + 1);

    i64 sum = 0;

    for (int i = 1; i <= n; i++) {

        cin >> a[i];

        sum += a[i];

    }

    if (sum < (n - 1) * 1ll * x) {

        cout << "NO\n";

        return;

    }

    vector<vector<pair<int, int>>> e(n + 1);

    for (int i = 1; i <= m; i++) {

        int u, v;

        cin >> u >> v;

        e[u].emplace_back(v, i);

        e[v].emplace_back(u, i);

    }

    vector<int> vis(n + 1);

    vector<pair<int, int>> sta;

    vector<int> dfn(n + 1);

    int cnt = 0, cnt2 = n, p = 0;

    vector<int> ans(n);

    auto dfs = [&](auto dfs, int u, int fa, int ii) -> void {

        vis[u] = 1;

        dfn[u] = ++cnt;

        for (auto [v, i] : e[u]) {

            if (vis[v])

                continue;

            dfs(dfs, v, u, i);

        }

        if (u == 1)

            return;

        if (a[u] + a[fa] >= x) {

            a[fa] = a[fa] + a[u] - x;

            ans[++p] = ii;

        } else {

            ans[--cnt2] = ii;

        }

    };

    cout << "YES\n";

    dfs(dfs, 1, 0, 0);

    for (int i = 1; i < n; i++)

        cout << ans[i] << "\n";

}



int main() {

    ios::sync_with_stdio(0);

    cin.tie(0), cout.tie(0);

    int T = 1;

    // cin >> T;

    while (T--) {

        run();

    }

    return 0;

}