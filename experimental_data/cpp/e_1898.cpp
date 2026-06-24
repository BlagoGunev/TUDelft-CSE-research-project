#include <bits/stdc++.h>

#if __cplusplus >= 202002L
namespace stdv = std::views;
namespace stdr = std::ranges;
#endif

using i64 = int64_t;

constexpr int N = 2e5 + 10;

char s[N], t[N];

void solve() {
    int n, m;
    scanf("%d%d", &n, &m);
    scanf("%s%s", s, t);

    std::vector<int> stk[26]{};
    for (int i = n - 1; i >= 0; i--) {
        stk[s[i] - 'a'].push_back(i);
    }

    for (int i = 0; i < m; i++) {
        int x = t[i] - 'a';
        if (stk[x].empty()) {
            puts("NO");
            return;
        }
        for (int j = 0; j < x; j++) {
            while (!stk[j].empty() && stk[j].back() < stk[x].back()) {
                stk[j].pop_back();
            }
        }
        stk[x].pop_back();
    }

    puts("YES");
}

int main() {
    int c;
    scanf("%d", &c);

    while (c--) {
        solve();
    }

    return 0;
}