#include <bits/stdc++.h>
using namespace std;

#ifdef __LOCAL__
  #include <debug_local.h>
#endif

const int mod = 1e9 + 7;

pair<int, int> merge(pair<int, int> a, pair<int, int> b) {
  if (a.first > b.first) return a;
  if (b.first > a.first) return b;
  return {a.first, (a.second + b.second) % mod};
}

void solve1() {
    int n, k;
    cin >> n >> k;
    vector<vector<pair<int, int>>> dp(n + 1, vector<pair<int, int>> (k, {0, 0}));
    auto val = dp;
    dp[0][k - 1] = {0, 1};
    vector<int> c(n + 1);
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < k; j++) {
            dp[i][j] = val[c[i]][j];
        }
        for (int j = 0; j < i; j++) {
            dp[i][0] = merge(dp[i][0], {dp[j][k - 1].first + 1, dp[j][k - 1].second});
        }
        for (int j = 0; j < k - 1; j++) {
            if (dp[i][j].first > 0) {
            	val[c[i]][j + 1] = merge(val[c[i]][j + 1], {dp[i][j].first + 1, dp[i][j].second});
			}
       }
    }
    pair<int, int> ans = {0, 0};
    for (int i = 0; i <= n; i++) {
        ans = merge(ans, dp[i][k - 1]);
    }
    cout << ans.second << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) {
    	solve1();
	}
    return 0;
}