#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n + 1);
    ll ans = 0;
    multiset<ll> slopes;
    for (int i = 1; i <= n; i++) {
        slopes.insert(k);
    }
    // vector<ll> dp(n + 1);
    // for (int i = 0; i <= n; i++)
    //     dp[i] = i * k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        // a[i] = rand() % k;
        a[i] %= k;
        if (a[i] <= a[i - 1]) {
            slopes.insert(k + a[i] - a[i - 1]);
        } else {
            slopes.insert(a[i] - a[i - 1]);
            ans += *slopes.begin();
            slopes.erase(slopes.begin());
        }

        // vector<ll> ndp(n - i + 1);
        // for (int j = 0; j <= n - i; j++) {
        //     ndp[j] = dp[j] + max(0LL, a[i] - a[i - 1]);
        //     if (j) {
        //         ndp[j] = min(ndp[j], dp[j - 1] + a[i] + k - a[i - 1]);
        //     }
        //     ndp[j] = min(ndp[j], dp[j + 1]);
        // }
        // dp = ndp;
    }
    // cout << dp[0] << '\n';
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve();
    }
    return 0;
}