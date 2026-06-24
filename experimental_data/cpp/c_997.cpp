#include <bits/stdc++.h>
using namespace std;

int n;
const int MOD = 998244353;
const int N = 1100000;
int F[N], G[N], fac[N], inv[N], pw3[N], res;
int C(int a, int b)
{
    return 1ll * fac[a] * inv[b] % MOD * inv[a - b] % MOD;
}
int powi(int a, int b)
{
    int c = 1;
    for (; b; b >>= 1, a = 1ll * a * a % MOD)
        if (b & 1) c = 1ll * c * a % MOD;
    return c;
}
int main()
{
    cin >> n;
    pw3[0] = 1;
    for (int i = 1; i <= n; ++ i) pw3[i] = 3ll * pw3[i - 1] % MOD;
    fac[0] = 1;
    for (int i = 1; i <= n; ++ i) fac[i] = 1ll * fac[i - 1] * i % MOD;
    inv[n] = powi(fac[n], MOD - 2);
    for (int i = n - 1; ~i; -- i) inv[i] = 1ll * inv[i + 1] * (i + 1) % MOD;

    F[0] = powi(pw3[n] - 3, n) % MOD;
    for (int i = 1; i <= n; ++ i)
        F[i] = 1ll * C(n, i) * ((1ll * (pw3[i] - 3) * powi(pw3[n - i], n) + 3ll * powi(pw3[n - i] - 1, n)) % MOD) % MOD;

    // for (int i = n; i >= 0; -- i)
    // {
    //     G[i] = F[i];
    //     for (int j = i + 1; j <= n; ++ j)
    //         G[i] = ((G[i] - 1ll * G[j] * C(j, i)) % MOD + MOD) % MOD;
    // }
    for (int i = 0; i <= n; ++ i)
        res = (res + F[i] * (i & 1 ? -1 : 1)) % MOD;
    res = (res + MOD) % MOD;
    cout << (powi(pw3[n], n) - res + MOD) % MOD << endl;
}