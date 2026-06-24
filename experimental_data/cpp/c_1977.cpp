#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int __ = 0; __ < t; __++) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int fl = 1;
        for (int i = n - 1; i >= 0; i--) {
            if (a.back() % a[i]) {
                cout << n << endl;
                fl = 0;
                break;
            }
        }
        if (fl) {
            vector<map<int, int>> dp(n + 1);
            dp[0][1] = 0;
            for (int i = 0; i < n; i++) {
                dp[i + 1] = dp[i];
                for (auto& [j, count] : dp[i]) {
                    int c = j / __gcd(j, a[i]) * a[i];
                    if (dp[i + 1].count(c) == 0) {
                        dp[i + 1][c] = dp[i][j] + 1;
                    }
                    else {
                        dp[i + 1][c] = max(dp[i][j] + 1, dp[i + 1][c]);
                    }
                }
            }
            int ans = 0;
            for (auto& [i, count] : dp[n]) {
                //cout << i << "." << count << " ";
                if (find(a.begin(), a.end(), i) == a.end()) {
                    ans = max(ans, count);
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}