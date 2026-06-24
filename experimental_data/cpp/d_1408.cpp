#include <bits/stdc++.h>

#define ll long long

#define ar array

using namespace std;

template<typename T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

int main() {

    cin.tie(0)->sync_with_stdio(0);

    int n, m;

    cin >> n >> m;

    vector<ar<int, 2>> r(n), s(m);

    for (auto &x : r) cin >> x[0] >> x[1];

    for (auto &x : s) cin >> x[0] >> x[1];

    const int N = 1e6;

    vector<int> dp(N+1);

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {

            int x_move = max(0, s[j][0]-r[i][0]+1);

            if (x_move) dp[x_move-1] = max(dp[x_move-1], s[j][1]-r[i][1]+1);

        }

    }

    for (int i = N-1; i >= 0; i--) dp[i] = max(dp[i], dp[i+1]);

    int ans = 1e9;

    for (int i = 0; i <= N; i++) ans = min(ans, i + dp[i]);

    cout << ans << '\n';

}