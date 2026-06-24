#include <bits/stdc++.h>
using i64 = long long;

std::vector<long long> fact, inv;

constexpr auto pow(long long x, long long n, const long long mod) {
    long long ret = 1;
    while(n > 0) {
        if ((n & 1) == 1) ret = (ret * x) % mod;
        x = (x * x) % mod;
        n >>= 1;
    }
    return ret;
}

constexpr auto inverse(const long long x, const long long p) {
    return pow(x, p - 2, p);
}

void init_factorial(const int n, const long long mod) {
    fact.resize(n + 1);
    inv.resize(n + 1);
    fact[0] = 1;
    for (long long i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % mod;
    inv[n] = inverse(fact[n], mod);
    for (long long i = n; i > 0; i--) inv[i - 1] = inv[i] * i % mod;
}

int main() {
    constexpr i64 mod = 998244353;
    i64 n, k;
    std::cin >> n >> k;
    init_factorial(n, mod);

    if (k == 0) {
        std::cout << fact[n] << std::endl;
        return 0;
    }

    if (k > n - 1) {
        std::cout << 0 << std::endl;
        return 0;
    }

    i64 ret = 0;
    for (int i = 0; i <= n - k; i++) {
        const i64 x = fact[n - k] * inv[i] % mod * inv[n - k - i] % mod * pow(i, n, mod) % mod;
        if ((n - k - i) % 2) ret = (ret + mod - x) % mod;
        else ret = (ret + x) % mod;
    }

    std::cout << 2 * ret * fact[n] % mod * inv[k] % mod * inv[n - k] % mod << std::endl;

    return 0;
}