#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()

const int N = 5007, mod = 1e9 + 7;
ll fac[N], inv[N];

ll binpow(ll x, ll y) {
    ll ret = 1;
    for(; y; y >>= 1, (x *= x) %= mod)
        if(y & 1)
            (ret *= x) %= mod;
    return ret;
}

ll nck(int n, int k) {
    return fac[n] * inv[n - k] % mod * inv[k] % mod;
}

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> c(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> c[i];

    vector<vector<ll>> ways(n + 1, vector<ll> (n + 1, -1));
    for(int i = 1; i <= n; i++) {
        int cnt = 0;
        for(int j = i; j >= 1; j--) {
            if(c[j] == c[i])
                cnt++;

            if(cnt >= k && cnt < k * 2)
                ways[j][i] = nck(cnt - 1, cnt % k);
        }
    }

    vector<array<ll, 2>> dp(n + 1, {0, 0});
    dp[0][1] = 1;

    array<ll, 2> ans = {0, 1};
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            array<ll, 2> cur = dp[j - 1];

            if(~ways[j][i]) {
                cur[0]++, (cur[1] *= ways[j][i]) %= mod;

                if(cur[0] > dp[i][0])
                    dp[i] = cur;
                else if(cur[0] == dp[i][0])
                    (dp[i][1] += cur[1]) %= mod;
            }
        }

        if(dp[i][0] > ans[0])
            ans = dp[i];
        else if(dp[i][0] == ans[0])
            (ans[1] += dp[i][1]) %= mod;
    }

    cout << ans[1] << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    fac[0] = inv[0] = 1;
    for(int i = 1; i < N; i++) {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = binpow(fac[i], mod - 2);
    }

    int t;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}