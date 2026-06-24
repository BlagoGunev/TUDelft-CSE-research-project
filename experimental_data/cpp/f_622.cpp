#include <bits/stdc++.h>

using namespace std;

const int p = 1000000007, K = 1000005;

int a[K], b[K], inv[K], f[K], q[K];

bool vis[K];

int pw(int x, int y) {

    int ret = 1;

    while (y) {

        if (y & 1) ret = 1ll * ret * x % p;

        x = 1ll * x * x % p;

        y >>= 1;

    }

    return ret;

}

int main() {

    int x, k, i, j, r = 0, ans = 0;

    scanf("%d%d", &x, &k);

    f[1] = 1;

    for (i = 2; i <= k + 2; ++i) {

        if (!vis[i]) {q[r++] = i; f[i] = pw(i, k);}

        for (j = 0; j < r && i * q[j] <= k + 2; ++j) {

            vis[i * q[j]] = true;

            f[i * q[j]] = 1ll * f[i] * f[q[j]] % p;

            if (!(i % q[j])) break;

        }

    }

    for (i = 2; i <= k + 2; ++i) (f[i] += f[i - 1]) %= p;

    for (i = a[0] = b[k + 3] = 1; i <= k + 2; ++i) {

        a[i] = 1ll * a[i - 1] * (x - i) % p;

        b[k + 3 - i] = 1ll * b[k + 4 - i] * (x - k - 3 + i) % p;

    }

    for (i = 2, inv[1] = 1; i <= k + 1; ++i) inv[i] = (p - 1ll * p / i * inv[p % i] % p) % p;

    for (i = inv[0] = 1; i <= k + 1; ++i) inv[i] = 1ll * inv[i] * inv[i - 1] % p;

    for (i = 1, j = (k & 1) ? 1 : -1; i <= k + 2; ++i, j = -j)

        ans = (ans + 1ll * f[i] * j * inv[i - 1] % p * inv[k + 2 - i] % p * a[i - 1] % p * b[i + 1] % p) % p;

    printf("%d\n", (ans + p) % p);

    return 0;

}