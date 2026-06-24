#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector dp(n + 1, vector<int>(3, n));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = min({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]}) + (a[i] != 0);
        if (a[i] == 0) continue;
        if (a[i] <= 2) {
            dp[i][1] = min({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]}) + 1;
            dp[i][0] = min({dp[i][0], dp[i - 1][1]});
        } else if (a[i] <= 4) {
            dp[i][1] = min({dp[i - 1][2] + 1});
            dp[i][2] = min({dp[i - 1][1] + 1});
        }
    }
    cout << min({dp[n][0], dp[n][1], dp[n][2]}) << '\n';
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
/*
g++ -std=c++20 1.cpp -o 1 && ./1 < in.txt > out.txt
./1 < in.txt > out.txt
*/