#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

const int INF = 1e18;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(15);

    int t;
    cin >> t;
    while (t--) {
        int n, m, p;
        cin >> n >> m >> p;
        vector<int> s(p);
        for (auto& x : s)
            cin >> x;
        vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));
        for (int i = 1; i <= n; i++)
            dist[i][i] = 0;
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            dist[u][v] = min(dist[u][v], (int)w);
            dist[v][u] = min(dist[v][u], (int)w);
        }
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                if (dist[i][k] == INF)
                    continue;
                for (int j = 1; j <= n; j++) {
                    if (dist[k][j] == INF)
                        continue;
                    dist[i][j] = min(dist[i][j], max(dist[i][k], dist[k][j]));
                }
            }
        }
        vector<vector<int>> dist2(p, vector<int>(n, INF));
        for (int i = 0; i < p; i++) {
            for (int j = 1; j <= n; j++) {
                dist2[i][j - 1] = dist[s[i]][j];
            }
        }
        vector<int> cur_min(p, INF);
        vector<bool> sel(n, false);
        vector<long long> result;
        long long tot_dist = 0;
        long long min_sum = INF;
        int bs = -1;
        for (int j = 0; j < n; j++) {
            long long temp_sum = 0;
            for (int i = 0; i < p; i++) {
                temp_sum += dist2[i][j];
            }
            if (temp_sum < min_sum) {
                min_sum = temp_sum;
                bs = j;
            }
        }
        sel[bs] = true;
        for (int i = 0; i < p; i++) {
            cur_min[i] = min(cur_min[i], dist2[i][bs]);
        }
        tot_dist = 0;
        for (int i = 0; i < p; i++) {
            tot_dist += cur_min[i];
        }
        result.push_back(tot_dist);
        for (int k = 2; k <= n; k++) {
            long long best_r = -1;
            int nxt_s = -1;
            for (int j = 0; j < n; j++) {
                if (sel[j])
                    continue;
                long long redu = 0;
                for (int i = 0; i < p; i++) {
                    if (dist2[i][j] < cur_min[i]) {
                        redu += (cur_min[i] - (long long)dist2[i][j]);
                    }
                }
                if (redu > best_r) {
                    best_r = redu;
                    nxt_s = j;
                }
            }
            if (nxt_s == -1) {
                result.push_back(tot_dist);
                continue;
            }
            sel[nxt_s] = true;
            for (int i = 0; i < p; i++) {
                cur_min[i] = min(cur_min[i], (int)dist2[i][nxt_s]);
            }
            tot_dist -= best_r;
            result.push_back(tot_dist);
        }
        for (int k = p + 1; k <= n; k++) {
            result.push_back(0);
        }
        for (int k = 0; k < n; k++) {
            if (k < result.size()) {
                cout << result[k] << " ";
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }

    return 0;
}