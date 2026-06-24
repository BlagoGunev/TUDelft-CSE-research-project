#include <bits/stdc++.h>

using namespace std;

#define int long long

#define endl '\n'

#define pii pair<int,int>

#define lowbit(x) (x & (-x))

const int N = 2e5 + 10, inf = 1e9;

int a[510], dp[2][510][510], n, ans;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

void solve() {

    cin >> n; for (int i = 1; i <= n; i++) cin >> a[i];

    memset(dp, -1, sizeof dp); dp[0][0][0] = 0;

    for (int i = 1; i <= n; i++) {

        memset(dp[i % 2], -1, sizeof(dp[i % 2]));

        for (int j = 0; j < i; j++)

            for (int k = max(0ll, i - (j + 1) - 1); k <= j; k++) {

                if (dp[(i + 1) % 2][j][k] == -1)continue;

                dp[i % 2][j + 1][k - (i - (j + 1)) + 1] = max(dp[i % 2][j + 1][k - (i - (j + 1)) + 1], dp[(i + 1) % 2][j][k] + a[i]);

            }

        for (int j = 1; j <= n; j++)

            for (int k = 0; k <= j; k++) {

                if (dp[i % 2][j - 1][k] == -1)continue;

                dp[i % 2][j][k] = max(dp[i % 2][j][k], dp[i % 2][j - 1][k] + a[i]);

            }

        for (int j = 0; j <= n; j++)

            for (int k = 0; k <= j; k++)

                dp[i % 2][j][k] = max(dp[i % 2][j][k], dp[(i + 1) % 2][j][k]);

    }

    for (int i = 0; i <= n; i++) ans = max(ans, dp[n % 2][n][i]);

    cout << ans;

}

signed main() {

	ios::sync_with_stdio(0);

	cin.tie(0); cout.tie(0);

	int T = 1; //cin >> T;

	while (T--) solve();

}