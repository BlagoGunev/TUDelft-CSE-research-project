#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
const int N = 5005;

template <typename T> inline void read(T &WOW) {
    T x = 0, flag = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') flag = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    WOW = flag * x;
}

int n, m;
vector<int> g[N];
double f[N / 2][N], dp[N];

void prework() {
    f[1][0] = 0.5; f[1][1] = 0;
    for (int i = 2; i <= 2500; ++i) {
        n = i * 2;
        f[i][0] = 1.0 / n;
        f[i][1] = f[i - 1][0] * (n - 2) / n;
        for (int j = 2; j < n; ++j) {
            f[i][j] = (f[i - 1][j - 2] * (j - 1) + f[i - 1][j - 1] * (n - j - 1)) / n;
        }
    }
}

void solve() {
    read(n); read(m);
    for (int i = 1; i <= n; ++i) {
        g[i].clear();
    }
    for (int i = 1, u, v; i <= m; ++i) {
        read(u); read(v);
        g[u].push_back(v);
    }
    dp[n] = 1;
    for (int i = n - 1; i >= 1; --i) {
        dp[i] = 0;
        sort(g[i].begin(), g[i].end(), [](int x, int y){
            return dp[x] > dp[y];
        });
        int sz = g[i].size();
        if (sz & 1) {
            for (auto j : g[i]) {
                dp[i] += dp[j];
            }
            dp[i] /= sz;
        } else {
            for (int j = 0; j < sz; ++j) {
                dp[i] += dp[g[i][j]] * f[sz / 2][j];
            }
        }
    }
    printf("%.15f\n", dp[1]);
}

int main() {
    prework();
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}