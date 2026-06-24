#include <bits/stdc++.h>
using namespace std;

int n, m;
string s;
int dp[5005][5005];

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s;
        int curr, prev = 0;
        int beg = 0, end = 0;
        for (int j = 0; j < m; j++) {
            curr = s[j] - '0';
            if (curr == 1) {
                if (prev == 0) beg = j;
                end = j;
            } else if (curr == 0) {
                if (prev == 1) dp[beg][end]++;
            }
            prev = curr;
        }
        if (curr == 1) dp[beg][end]++;
    }
    for (int i = 0; i < m; i++) for (int j = m - 1; j >= i; j--)
    dp[i][j] += (i ? dp[i - 1][j] : 0) + dp[i][j + 1] - (i ? dp[i - 1][j + 1] : 0);
    int ans = 0;
    for (int i = 0; i < m; i++) for (int j = i; j < m; j++) {
        ans = max(ans, dp[i][j] * (j - i + 1));
    }
    cout << ans << endl;
    return 0;
}