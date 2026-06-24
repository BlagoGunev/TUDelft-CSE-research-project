#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX_A = 1024;
const int MOD = 1e9 + 7;


ll mod_pow(ll a, ll b) {
    ll res = 1;
    a %= MOD;
    while(b) {
        if(b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}


ll mod_inv(ll a) {
    return mod_pow(a, MOD - 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    const int MAX_N = 2e5 + 5;
    vector<int> a(MAX_N);
    vector<int> p(MAX_N);

    while(t--) {
        int n;
        cin >> n;
        for(int i = 0; i < n; ++i)
            cin >> a[i];

        for(int i = 0; i < n; ++i)
            cin >> p[i];

        vector<ll> dp(MAX_A, 0), dp_new(MAX_A, 0);
        dp[0] = 1;  
        for(int i = 0; i < n; ++i) {
            int ai = a[i];
            int pi = p[i];
            for(int x = 0; x < MAX_A; ++x) {
                if(dp[x]) {
                    
                    int nx = x ^ ai;
                    dp_new[nx] = (dp_new[nx] + dp[x] * pi) % MOD;
                    
                    dp_new[x] = (dp_new[x] + dp[x] * (10000 - pi)) % MOD;
                }
            }
            dp.swap(dp_new);
            fill(dp_new.begin(), dp_new.end(), 0);
        }

        ll D = mod_pow(10000, n);
        ll D_inv = mod_inv(D);

        ll total = 0;
        for(int x = 0; x < MAX_A; ++x) {
            ll val = dp[x] % MOD;
            ll term = val * x % MOD * x % MOD;  
            total = (total + term) % MOD;
        }

        ll answer = total * D_inv % MOD;
        cout << answer << '\n';
    }

    return 0;
}