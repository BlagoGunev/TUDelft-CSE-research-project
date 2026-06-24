#include <bits/stdc++.h>
const int MOD = 998244353;
struct mint
{
    unsigned v;
    mint(unsigned v_ = 0) : v(v_) {}
    mint operator-() const { return v ? MOD - v : v; }
    mint &operator+=(const mint &X) { return (v += X.v) >= MOD ? v -= MOD : v, *this; }
    mint &operator-=(const mint &X) { return (v += MOD - X.v) >= MOD ? v -= MOD : v, *this; }
    mint &operator*=(const mint &X) { return v = 1llu * v * X.v % MOD, *this; }
    mint &operator/=(const mint &X) { return *this *= X.inv(); }
    mint power(long long B) const
    {
        B %= MOD - 1;
        if (B < 0)
            B += MOD - 1;
        mint res = 1, A = *this;
        while (B)
        {
            if (B & 1)
                res *= A;
            B >>= 1;
            A *= A;
        }
        return res;
    }
    mint inv() const { return power(MOD - 2); }
    friend mint operator+(const mint &A, const mint &B) { return mint(A) += B; }
    friend mint operator-(const mint &A, const mint &B) { return mint(A) -= B; }
    friend mint operator*(const mint &A, const mint &B) { return mint(A) *= B; }
    friend mint operator/(const mint &A, const mint &B) { return mint(A) /= B; }
    friend std::ostream &operator<<(std::ostream &A, const mint &B) { return A << B.v; }
    explicit operator bool() const { return v; }
} f[1000005], tmp[1000005], sum[1000005], mu[1000005], ans[1000005];
int T, m;
std::vector<int> p, g[1000005];
bool isp[1000005];
signed main()
{
    std::ios::sync_with_stdio(false);
    mu[1] = 1;
    for (int i = 2; i <= 1000000; ++i)
    {
        if (!isp[i])
            p.push_back(i), mu[i] = MOD - 1;
        for (auto j : p)
        {
            if (i * j > 1000000)
                break;
            mu[i * j] = mu[i] * mu[j];
            isp[i * j] = true;
            if (i % j == 0)
            {
                mu[i * j] = 0;
                break;
            }
        }
    }
    for (int i = 1; i <= 1000000; ++i)
        for (int j = 1; i * j <= 1000000; ++j)
            g[i * j].push_back(i);
    sum[1] = 1;
    for (int i = 1; i <= 1000000; ++i)
    {
        for (auto j : g[i])
            tmp[j] = 0;
        for (auto j : g[i])
        {
            tmp[j] += f[j];
            for (auto k : g[j])
                tmp[j] += sum[k];
        }
        ans[i] += tmp[i];
        for (auto j : g[i])
            for (auto k : g[j])
                sum[j] += 2 * mu[j / k] * tmp[k];
        for (auto j : g[i])
            f[j] -= tmp[j] * 2;
    }
    for (int i = 1; i <= 1000000; ++i)
        ans[i] += ans[i - 1];
    // for (int i = 1; i <= 1000000; ++i)
    //     std::cout << ans[i] << " \n"[i == 1000000];
    std::cin >> T;
    while (T--)
    {
        std::cin >> m;
        std::cout << ans[m] << std::endl;
    }
    return 0;
}