#include <bits/stdc++.h>

constexpr int P = int(1e9) + 7;

int power(int a, int b) {
    int r = 1;
    while (b) {
        if (b & 1) r = 1ll * r * a % P;
        a = 1ll * a * a % P;
        b >>= 1;
    }
    return r;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> p[i];
        --p[i];
    }
    std::map<int, int> map;
    std::vector<bool> vis(n);
    for (int i = 0; i < n; ++i) {
        if (vis[i]) continue;
        int u = i;
        int len = 0;
        while (!vis[u]) {
            ++len;
            vis[u] = true;
            u = p[u];
        }
        ++map[len];
    }

    std::vector<int> cnt, len;
    for (auto i : map) {
        len.push_back(i.first);
        cnt.push_back(i.second + 1);
    }
    int m = cnt.size();
    std::vector<int> pre(m + 1);
    pre[0] = 1;
    for (int i = 0; i < m; ++i) {
        pre[i + 1] = pre[i] * cnt[i];
    }

    int all = pre[m];
    std::vector<std::vector<int>> sub(all);
    for (int s = 0; s < all; ++s) {
        auto dfs = [&](auto self, int i, int t) -> void {
            if (i == m) {
                if (t != 0) {
                    sub[s].push_back(t);
                }
                return;
            }
            int up = s / pre[i] % cnt[i];
            for (int j = 0; j <= up; ++j) {
                self(self, i + 1, t + pre[i] * j);
            }
        };
        dfs(dfs, 0, 0);
    }

    std::vector<int> fac(n + 1), ifac(n + 1);
    fac[0] = ifac[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fac[i] = 1ll * fac[i - 1] * i % P;
    }
    ifac.back() = power(fac.back(), P - 2);
    for (int i = n; i > 1; --i) {
        ifac[i - 1] = 1ll * ifac[i] * i % P;
    }
    auto binom = [&](int x, int y) -> int {
        return 1ll * fac[x] * ifac[y] % P * ifac[x - y] % P;
    };

    std::vector<std::vector<int>> link(n, std::vector<int>(n + 1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            link[i][1] = (link[i][1] + 1ll * binom(i, j) * fac[j] % P * fac[n - j - 1]) % P;
        }
        for (int j = 2; j <= n; ++j) {
            link[i][j] = 1ll * link[i][j - 1] * link[i][1] % P;
        }
    }

    std::vector<int> dp(all);
    dp[0] = 1;
    for (int s = 1; s < all; ++s) {
        std::vector<int> sc(m);
        for (int i = 0; i < m; ++i) {
            sc[i] = s / pre[i] % cnt[i];
        }
        for (int t : sub[s]) {
            std::vector<int> tc(m);
            for (int i = 0; i < m; ++i) {
                tc[i] = t / pre[i] % cnt[i];
            }

            int from = 0;
            int to = 0;
            int coef = 1;
            int sign = P - 1;
            for (int i = 0; i < m; ++i) {
                from += len[i] * (tc[i]);
                to += len[i] * (sc[i] - tc[i]);
                coef = 1ll * coef * binom(sc[i], tc[i]) % P;
                if (tc[i] % 2 == 1) {
                    sign = P - sign;
                }
            }
            dp[s] = (dp[s] + 1ll * sign * link[to][from] % P * coef % P * dp[s - t]) % P;
        }
    }
    std::cout << dp[all - 1] << '\n';

    return 0;
}