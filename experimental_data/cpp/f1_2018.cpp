#include <bits/stdc++.h>
using namespace std;

const int N = 3005;

long long mod;
int n;
long long f[3005][3005][3], g[3005], h[3005];

inline long long Power(long long x, long long y) {
    long long ans = 1;
    while (y) {
        if (y & 1) ans = ans * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return ans;
}

inline void Add(long long &x, long long y) {
    x = (x + y) % mod;
}

inline long long Work(int len) {
    long long cur = 1;
    for (int i = 1;i <= len;i++) cur = cur * (n - max(i, len - i + 1) + 1) % mod;
    for (int i = 0;i <= n + 1;i++) {
        for (int j = 0;j <= n + 1;j++) {
            f[i][j][0] = f[i][j][1] = f[i][j][2] = 0;
        }
    }
    f[len + 1][len][0] = cur;
    for (int i = len + 1;i <= n;i++) {
        for (int j = 1;j <= i;j++) {
            Add(f[i + 1][j][0], f[i][j][0]);
            Add(f[i][j][1], f[i][j][0]);
            Add(f[i][j][2], f[i][j][0]);
            Add(f[i][j + 1][1], f[i][j][1] * (n - i + 1) % mod);
            Add(f[i][j + 1][2], f[i][j][1]);
            if (i > j) Add(f[i + 1][j + 1][0], f[i][j][1]);
            Add(f[i][j + 1][2], f[i][j][2] * (n - i + 1) % mod);
            if (i > j) Add(f[i + 1][j + 1][0], f[i][j][2]);
            // cout << i << " " << j << f[i][j][0] << " " << f[i][j][1] << " " << f[i][j][2] << "\n";
        }
    }
    return f[n + 1][n][0];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> mod;
        g[0] = Power(n, n);
        for (int i = 1;i <= n;i++) g[i] = Work(i);
        for (int i = 1;i <= n;i++) h[i] = 0;
        h[n] = g[n];
        for (int i = n - 1;i >= 1;i--) {
            h[i] = g[i];
            for (int j = i + 1;j <= n;j++) h[i] = (h[i] - h[j] * (j - i + 1) % mod + mod) % mod;
        }
        h[0] = g[0];
        for (int i = 1;i <= n;i++) h[0] = (h[0] - h[i] + mod) % mod;
        for (int i = 0;i <= n;i++) cout << ((h[i]) % mod + mod) % mod << " ";
        cout << '\n';
    }
    return 0;
}