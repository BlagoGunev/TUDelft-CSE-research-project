#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 9, MOD = 998'244'353;
int fact[N], inv[N], invf[N];
int power(int x, int y) {
    int res = 1;
    while (y) {
        if (y & 1) res = res * x % MOD;
        x = x * x % MOD;
        y >>= 1;
    }
    return res;
};
void solve() {
    int n;
    cin >> n;
    unordered_map < int , int > sum, cnt;
    set < int > se; se.insert(n);
    int ans = 0;
    sum[n] = cnt[n] = 1;
    while (se.size() > 0) {
        int n = *se.rbegin(); se.erase(--se.end());
        if (n == 1) {
            ans += sum[n]; ans %= MOD;
            continue;
        }
        int l = (n + 1) / 2, r = n - l;
        sum[l] = (sum[l] + sum[n] * 2) % MOD;          cnt[l] = cnt[l] + cnt[n];         se.insert(l);
        sum[r] = (sum[r] + sum[n] * 2 + cnt[n]) % MOD; cnt[r] = (cnt[r] + cnt[n]) % MOD; se.insert(r);
        ans += sum[n] % MOD * (power(2, l) - 1) % MOD * (power(2, r) - 1) % MOD; ans %= MOD;
    }
    cout << ans << '\n';
};
main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    fact[0] = invf[0] = 1;
    for (int i = 1; i < N; i++) {
        inv[i] = (i == 1 ? 1LL : MOD - (MOD / i) * inv[MOD % i] % MOD);
        fact[i] = fact[i - 1] * i % MOD;
        invf[i] = invf[i - 1] * inv[i] % MOD;
    }
    int n; cin >> n;
    while (n--) solve();
}