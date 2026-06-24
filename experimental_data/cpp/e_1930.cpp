#include<bits/stdc++.h>

typedef long long ll;

const int N = 1e6 + 10;
const ll M = 998244353;

int t;
ll n;
ll fact[N];
ll invf[N];


ll qpow(ll a, ll x) {
    ll ret = 1;
    while(x) {
        if(x & 1) {
            ret = ret * a % M;
        }
        a = a * a % M;
        x >>= 1;
    }
    return ret;
}
ll inv(ll a) {
    return qpow(a, M - 2);
}
ll comb(ll a, ll x) {
    return fact[a] * invf[x] % M * invf[a - x] % M;
}

void init() {
    fact[0] = 1;
    for(ll i = 1; i <= 1e6; i++) {
        fact[i] = fact[i - 1] * i % M;
    }
    for(ll i = 0; i <= 1e6; i++) {
        invf[i] = inv(fact[i]);
    }
}

int main() {
    init();
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(ll k = 1; 2 * k < n; k++) {
            ll ans = 1;
            for(ll i = 2; i * k < n; i += 2) {
                ans = (ans + (comb(n, n - i * k) - comb(n - (i - 2) * k - 1, n - i * k) + M) % M) % M;
            }
            printf("%lld ", ans);
        }
        printf("\n");
    }
    return 0;
}