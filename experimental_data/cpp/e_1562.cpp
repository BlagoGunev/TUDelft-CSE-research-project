#pragma GCC optimize(2)
#include <bits/stdc++.h>
constexpr int N = 5005;

int f[N];
char s[N];
int rk[N], tp[N], tax[N], sa[N];
int st[std::__lg(N) + 1][N];
int query(int l, int r) {
    if (l > r)
        std::swap(l, r);
    int lg = std::__lg(r - l);
    return std::min(st[lg][l + 1], st[lg][r - (1 << lg) + 1]);
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n; std::cin.get();
        std::cin.get(s + 1, N - 1);
        memset(rk, 0, sizeof(rk));
        memset(tp, 0, sizeof(tp));
        memset(tax, 0, sizeof(tax));
        memset(sa, 0, sizeof(sa));
        for (int i = 1; i <= n; i++)
            tax[rk[i] = s[i] - 48]++;
        for (int i = 1; i <= 74; i++)
            tax[i] += tax[i - 1];
        for (int i = n; i; i--)
            sa[tax[s[i] - 48]--] = i;
        for (int len = 1, p = 0, m = 74; p < n; m = p, len <<= 1) {
            p = len;
            for (int i = 1; i <= len; i++)
                tp[i] = n - len + i;
            for (int i = 1; i <= n; i++)
                if (sa[i] > len)
                    tp[++p] = sa[i] - len;
            for (int i = 0; i <= m; i++)
                tax[i] = 0;
            for (int i = 1; i <= n; i++)
                tax[rk[i]]++;
            for (int i = 1; i <= m; i++)
                tax[i] += tax[i - 1];
            for (int i = n; i; i--)
                sa[tax[rk[tp[i]]]--] = tp[i];
            std::swap(tp, rk);
            rk[sa[1]] = p = 1;
            for (int i = 2; i <= n; i++)
                rk[sa[i]] = (tp[sa[i - 1]] == tp[sa[i]] && tp[sa[i - 1] + len] == tp[sa[i] + len]) ? p : ++p;
        }
        memset(tax, 0, sizeof(int) * (n + 1));
        memset(st, 0, sizeof(st));
        for (int i = 1, k = 0; i <= n; i++) {
            if (k)
                k--;
            int j = sa[rk[i] - 1];
            while (s[i + k] == s[j + k])
                k++;
            st[0][rk[i]] = k;
        }
        for (int j = 1; (1 << j) <= n; j++)
            for (int i = 1; i + (1 << j) - 1 <= n; i++)
                st[j][i] = std::min(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int x = sa[i];
            f[x] = n - x + 1;
            for (int j = 1; j < i; j++)
                if (sa[j] < x)
                    f[x] = std::max(f[x], f[sa[j]] + n - x + 1 - query(j, i));
            ans = std::max(ans, f[x]);
        }
        std::cout << ans << "\n";
    }
    return 0;
}