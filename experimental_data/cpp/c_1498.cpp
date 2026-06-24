#include <bits/stdc++.h>



using namespace std;

typedef long long ll;

typedef pair<int, int> PII;

const int P = 1e9 + 7;



void solve() {

    int n, k;

    cin >> n >> k;

    vector dp(n + 1, vector<int>(k + 1));

    for (int i = 0; i <= n; i++) dp[i][1] = 1;

    for (int i = 1; i <= k; i++) dp[0][i] = 1;

    for (int i = 1; i <= n; i++) {

        for (int j = 2; j <= k; j++) {

            dp[i][j] += dp[i - 1][j] + dp[n - i][j - 1];

        }

    }

    for (int j = 2; j <= k; j++) {

        for (int i = 1; i <= n; i++) {

            dp[i][j] = (dp[i - 1][j] + dp[n - i][j - 1]) % P;

        }

    }

    cout << dp[n][k] << '\n';

}



int main() {

    ios::sync_with_stdio(false);

    cin.tie(nullptr);



    int T = 1;

    cin >> T;

    while (T--) {

        solve();

    }

    return 0;

}