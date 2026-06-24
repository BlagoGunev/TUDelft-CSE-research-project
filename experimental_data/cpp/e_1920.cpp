#include <bits/stdc++.h>
#define int long long

const int NMAX = 3e3 + 5, mod = 998244353;

int n, k, dp[NMAX][NMAX]; /// dp[last][sum]
bool f[NMAX][NMAX];

int DP(int last, int sum) {
    if (sum == 0) {
        return 1;
    }

    if (f[last][sum] == true) {
        return dp[last][sum];
    }

    f[last][sum] = true;

    dp[last][sum] = 0;

    for (int v = 1; v + last - 1 <= k && v * last <= sum; ++ v) {
        dp[last][sum] = (dp[last][sum] % mod + DP(v, sum - v * last) % mod) % mod;
    }

    return dp[last][sum];
}

void solve() {
    std :: cin >> n >> k;

    for (int j = 0; j <= n; ++ j) {
        for (int c = 0; c <= n; ++ c) {
            f[j][c] = false;
        }
    }

    std :: cout << DP(0, n) << "\n";

    return;
}

signed main() {
    int tc;

    std :: cin >> tc;

    while (tc --) {
        solve();
    }

    return 0;
}