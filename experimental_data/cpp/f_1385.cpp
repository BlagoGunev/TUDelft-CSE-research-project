///  ┌( ´_ゝ` )┐  че пришел
//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int long long

signed main() {
    {
    #ifndef LOCAL
        ios_base::sync_with_stdio(0); /// НЕ УДАЛЯТЬ
        cin.tie(0);  /// НЕ УДАЛЯТЬ
        cout.tie(0); /// НЕ УДАЛЯТЬ
        cout << fixed << setprecision(15);
    #else
        cout << fixed << setprecision(3);
    #endif // LOCAL
    }
    int q;
    cin >> q;
    while (q --> 0) {
        int n, k;
        cin >> n >> k;
        vector<vector<int> > g(n);
        vector<pair<int, int> > sz(n);
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            g[a - 1].push_back(b - 1);
            g[b - 1].push_back(a - 1);
        }
        for (int i = 0; i < n; i++) {
            sz[i] = {g[i].size(), i};
        }
        sort(all(sz));
        vector<int> p(n);
        vector<int> used(n);
        int ans = 0;
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (sz[i].fi == 1)
                q.push(sz[i].se);
        }
        while (!q.empty()) {
            int id = q.front();
            q.pop();
            used[id] = 1;
            for (auto to : g[id]) {
                if (!used[to]) {
                    p[to]++;
                    if (p[to] % k == 0) {
                        ans++;
                        if (g[to].size() - p[to] == 1) {
                            q.push(to);
                        }
                    }
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}