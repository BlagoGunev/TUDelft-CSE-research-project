#include <bits/stdc++.h>

using namespace std;

const int MAXN = 105;
const int inf = 1e6;

int dp[MAXN][MAXN];
int n;
string s;

void solve() {
    cin >> n;
    cin >> s;
    iota(dp[n], dp[n]+n+1, 1);
    for (int i = n-1; i >= 0; i--) {
        if (s[i] == '>') {
            int bestl = inf;
            for (int j = 0; j <= n; j++) {
                dp[i][j] = max(j+1, bestl);
                bestl = min(bestl, dp[i+1][j]);
            }
        }
        else {
            int bestr = inf;
            for (int j = n; j >= 0; j--) {
                dp[i][j] = max(j+1, bestr);
                bestr = min(bestr, dp[i+1][j]);
            }
        }
    }
    int mn = inf;
    for (int i = 0; i <= n; i++) mn = min(mn, dp[0][i]);
    cout << mn << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    while (t--) solve();
}