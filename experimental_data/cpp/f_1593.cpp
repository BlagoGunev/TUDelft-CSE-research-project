#pragma once
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

template <class T>
bool chmin(T& _old, T _new) { return _old > _new && (_old = _new, true); }
template <class T>
bool chmax(T& _old, T _new) { return _old < _new && (_old = _new, true); }

constexpr int MX = 40;
array<array<array<array<bool, MX + 1>, MX>, MX>, MX + 1> dp;
array<array<array<array<int, MX + 1>, MX>, MX>, MX + 1> par;

void solve() {
    int n, a, b;
    string x;
    cin >> n >> a >> b >> x;
    memset(dp.data(), false, sizeof(dp));
    dp[0][0][0][0] = true; // i-th digit, mod a, mod b, digits in red
    for (int t = 0; t < n; ++t) {
        for (int i = 0; i < a; ++i) {
            for (int j = 0; j < b; ++j) {
                for (int k = 0; k < n; ++k) {
                    if (dp[t][i][j][k]) {
                        dp[t + 1][(i * 10 + x[t] - '0') % a][j][k + 1] = true;
                        dp[t + 1][i][(j * 10 + x[t] - '0') % b][k] = true;
                        par[t + 1][(i * 10 + x[t] - '0') % a][j][k + 1] = i;
                        par[t + 1][i][(j * 10 + x[t] - '0') % b][k] = ~j;
                    }
                }
            }
        }
    }
    int ans = INT_MAX, sk = -1;
    for (int k = 1; k < n; ++k) {
        if (dp[n][0][0][k]) {
            if (chmin(ans, abs(n - k - k))) {
                sk = k;
            }
        }
    }
    if (ans == INT_MAX) {
        cout << "-1\n";
        return;
    }
    string res;
    for (int i = 0, j = 0, k = sk; n > 0; --n) {
        if (par[n][i][j][k] < 0) {
            res += 'B';
            j = ~par[n][i][j][k];
        } else {
            res += 'R';
            i = par[n][i][j][k];
            --k;
        }
    }
    reverse(res.begin(), res.end());
    cout << res << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef palilo
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) solve();
}