#include<iostream>
#include<vector>
#include<algorithm>
#define SZ(X) ((int)(X).size())
using namespace std;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> d(k);
    int m = n % k;
    if(!m) m = k;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        d[i % k].push_back(x);
    }
    int low = 1, hi = 1e9;
    while(low < hi) {
        int mid = low + (hi - low + 1) / 2;
        vector<vector<int>> dp(k);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < SZ(d[i]); j++) {
                if(!i) {
                    dp[i].push_back(d[i][j] >= mid ? 1 : -1);
                    if(SZ(dp[i]) > 1) dp[i].back() = max(dp[i].back(), dp[i][SZ(dp[i]) - 2]);
                } else {
                    dp[i].push_back(d[i][j] >= mid ? 1 : -1);
                    dp[i].back() += dp[i - 1][j];
                    if(SZ(dp[i]) > 1) dp[i].back() = max(dp[i].back(), dp[i][SZ(dp[i]) - 2]);
                }
            }
        }
        if(dp[m - 1].back() > 0) {
            low = mid;
        } else {
            hi = mid - 1;
        }
    }
    cout << low << '\n';
}
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) solve();
}