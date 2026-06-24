#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 512;
const int CS = 64;

bitset<N> f0[CS][N], f1[CS][N];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    while (m--) {
        int u, v, t;
        scanf("%d%d%d", &u, &v, &t);
        u--; v--;
        if (t == 0)
            f0[0][u].set(v);
        else
            f1[0][u].set(v);
    }
    for (int i = 0; i < 60; i++) {
        for (int u = 0; u < n; u++) {
            f0[i+1][u].reset();
            f1[i+1][u].reset();
            for (int v = 0; v < n; v++) {
                if (f0[i][u].test(v)) {
                    f0[i+1][u] |= f1[i][v];
                }
                if (f1[i][u].test(v)) {
                    f1[i+1][u] |= f0[i][v];
                }
            }
        }
    }

    bitset<N> bs;
    bs.reset();
    bs.set(0);

    LL ans = 0;
    bool turn = true;

    for (int i = 60; i >= 0; i--) {
        bitset<N> tmp;
        tmp.reset();
        for (int u = 0; u < n; u++)
            if (bs.test(u)) {
                if (turn) tmp |= f0[i][u];
                else tmp |= f1[i][u];
            }
        if (tmp.any()) {
            turn = !turn;
            ans += (1LL << i);
            bs = tmp;
        }
    }

    if (ans > 1000000000000000000LL)
        printf("-1");
    else printf("%lld", ans);
}