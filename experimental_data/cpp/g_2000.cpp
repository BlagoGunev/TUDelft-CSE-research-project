#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int TT;
    cin >> TT;

    while (TT--) {
        int n, m;
        cin >> n >> m;

        array<int, 3> t;
        for (auto &i : t) {
            cin >> i;
        }

        vector<vector<array<int, 3>>> g(n);
        for (int i = 0, u, v, l1, l2; i < m; i++) {
            cin >> u >> v >> l1 >> l2;
            u--; v--;
            g[u].push_back({v, l1, l2});
            g[v].push_back({u, l1, l2});
        }

        constexpr int INF = numeric_limits<int>::max() / 2;

        auto check = [&](int val) {
            priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pq;
            pq.push({val, 0, 0});

            vector dis(n, array<int, 2>{INF, INF});
            dis[0][0] = val;

            while (!pq.empty()) {
                auto [_, u, i] = pq.top();
                pq.pop();
                if (dis[u][i] != _) {
                    continue;
                }
                if (_ > t[0]) {
                    break;
                }
                if (_ <= t[2] && dis[u][1] > t[2]) {
                    dis[u][1] = t[2];
                    pq.push({dis[u][1], u, 1});
                }
                for (auto [v, l1, l2] : g[u]) {
                    int t1 = dis[u][i], t2 = t1 + l1;
                    if (t2 <= t[1] || t1 >= t[2]) {
                        if (dis[v][i] > dis[u][i] + l1) {
                            dis[v][i] = dis[u][i] + l1;
                            pq.push({dis[v][i], v, i});
                        }
                    } else if (dis[v][i] > dis[u][i] + l2) {
                        dis[v][i] = dis[u][i] + l2;
                        pq.push({dis[v][i], v, i});
                    }
                }
            }

            int ans = min(dis[n - 1][0], dis[n - 1][1]);
            //cout << val << ' ' << ans << '\n';
            return ans <= t[0];
        };

        int l = -1, r = t[0];
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (check(mid)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        cout << l << '\n';
    }
    return 0;
}