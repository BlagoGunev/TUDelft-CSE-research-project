#include <bits/stdc++.h>
using namespace std;

const long long inf = 1e18 + 1;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<vector<pair<int, int>>> options(n);
    vector<vector<int>> positions(n);
    for (int i = 0; i < m; i++) {
        int e, t, p;
        cin >> e >> t >> p;
        options[e - 1].push_back({t, p});
        positions[e - 1].push_back(i);
    }

    vector<vector<int>> chosen(n);

    vector<long long> min_time(n, inf);

    for (int j = 0; j < n; j++) {
        int k = options[j].size();
        if (k == 0) continue;
        vector<vector<long long>> dp(k + 1, vector<long long>(201, inf));
        dp[0][0] = 0;
        for (int i = 1; i <= k; i++) {
            for (int w = 0; w <= 200; w++) {
                dp[i][w] = min(dp[i][w], dp[i - 1][w]);
                if (w >= options[j][i - 1].second) dp[i][w] = min(dp[i][w], dp[i - 1][w - options[j][i - 1].second] + options[j][i - 1].first);
            }
        }
        int min_w = 100;
        for (int w = 100; w <= 200; w++) if (dp[k][w] < dp[k][min_w]) min_w = w;
        if (dp[k][min_w] == inf) continue;
        min_time[j] = dp[k][min_w];
        for (int i = k; i >= 1; i--) {
            if (dp[i][min_w] == dp[i - 1][min_w]) continue;
            chosen[j].push_back(i - 1);
            min_w -= options[j][i - 1].second;
        }
    }
    long long curr_sum = 0;
    bool good = true;
    for (int i = 0; i < n; i++) {
        curr_sum += min_time[i];
        if (curr_sum > a[i]) {
            cout << -1 << "\n";
            good = false;
            break;
        }
    }
    if (good) {
        int k = 0;
        for (int i = 0; i < n; i++) k += chosen[i].size();
        cout << k << "\n";
        for (int i = 0; i < n; i++) {
            for (int j : chosen[i]) {
                cout << positions[i][j] + 1 << " ";
            }
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}