#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()

const int N = 5007, mod = 1e9 + 7;
ll f[N][N];

void solve() {
    int n;
    cin >> n;

    ll ans = 0;
    vector<ll> dp0(n + 1), dp1(n + 1);
    dp0[0] = 1;

    for (int i = 1; i <= n; i++) {
        vector<ll> ndp0(n + 1), ndp1(n + 1);
        for (int j = 0; j <= n; j++) {
            ndp0[j] = (dp0[j] + dp1[j]) % mod;
            if (j >= 1)
                ndp1[j] = (dp0[j - 1] + dp1[j - 1]) % mod;
        }

        swap(dp0, ndp0);
        swap(dp1, ndp1);

        for (int j = 0; j <= n; j++) {
            int x = i - j - 1;
            if (x >= j) {
                (ans += dp0[j] * i % mod * f[n - i][x - j] % mod) %= mod;
            }
        }
    }

    for (int j = 0; j <= n; j++) {
        int x = (j + 1) - (n - j);
        if (x > 0) {
            (ans += (dp0[j] + dp1[j]) % mod * (n + x) % mod) %= mod;
        }
    }

    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    f[0][0] = 1;
    for (int i = 1; i < N; i++) {
        f[i][0] = 1;
        for (int j = 1; j <= i; j++)
            f[i][j] = (f[i - 1][j - 1] + f[i - 1][j]) % mod;
    }

    int t;
    cin >> t;
    
    while (t--)
        solve();

    return 0;
}