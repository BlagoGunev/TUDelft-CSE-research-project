// LUOGU_RID: 158361914
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define pr pair<int, int>
#define mid (l + r) / 2
#define ls num << 1
#define rs num << 1 | 1

inline int read() {
    int x = 0, mm = 1;
    char ch = getchar();

    while (!isdigit(ch)) {
        if (ch == '-') mm = -1;
        ch = getchar();
    }

    while (isdigit(ch)) {
        x = x * 10 + ch - 48;
        ch = getchar();
    }

    return x * mm;
}

inline void write(int x) {
    if (x < 0) {
        putchar('-');
        write(-x);
        return;
    }

    if (x >= 10) write(x / 10);
    putchar(x % 10 + '0');
}

const int N = 2e3 + 5, mod = 1e9 + 7;

int f[2][N][N], a[N], s[N], l[N], r[N];

signed main() {
    int n = read(), k = read(), m = 0, B = sqrt(k) * 2;

    for (int i = 1; i <= n; i++) {
        int x = read();
        if (x) a[++m] = i;
        s[i] = s[i - 1] + x;
    }

    f[0][0][0] = 1;

    for (int i = 1; i <= n; i++) {
        int t = i & 1;
        l[i] = max(0ll, s[i] - B);
        r[i] = min({i, s[i] + B, m});
        if (i > 1) {
            for (int x = l[i - 2]; x <= r[i - 2]; x++) {
                for (int j = 0; j <= k; j++) {
                    f[t][x][j] = 0;
                }
            }
        }
        for (int x = l[i]; x <= r[i]; x++) {
            for (int j = 0; j <= k; j++) {
                f[t][x][j] = f[t ^ 1][x][j];
                if (x) {
                    int dis = abs(i - a[x]);
                    if (j >= dis) (f[t][x][j] += f[t ^ 1][x - 1][j - dis]) %= mod;
                }
            }
        }
    }

    int ans = 0;

    for (int i = k; i >= 0; i -= 2) {
        (ans += f[n & 1][m][i]) %= mod;
    }

    write(ans);
    putchar('\n');
}