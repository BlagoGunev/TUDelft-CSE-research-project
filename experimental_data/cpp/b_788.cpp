#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 1000005;

int pa[N];
int sz[N];
bool mark[N];

int getpa(int u) {
    return (pa[u] < 0)?u:(pa[u] = getpa(pa[u]));
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) pa[i] = -1;

    int z = 0;

    for (int i = m; i > 0; i--) {
        int u, v;
        scanf("%d%d", &u, &v);
        if (u == v) {
            mark[u] = true;
            m--;
            z++;
        }
        else {
            sz[u]++;
            sz[v]++;
            u = getpa(u);
            v = getpa(v);
            if (u == v) continue;
            if (pa[u] > pa[v]) swap(u, v);
            pa[u] += pa[v];
            pa[v] = u;
        }
    }

    int luu = 0;

    for (int i = 1; i <= n; i++) {
        if (sz[i] == 0 && !mark[i]) continue;
        if (luu == 0) luu = getpa(i);
        else if (getpa(i) != luu) {
            printf("0"); return 0;
        }
    }

    LL ans = 0;

    for (int i = 1; i <= n; i++) {
        LL tmp = sz[i];
        ans += tmp * (tmp-1) / 2;
    }

    ans += LL(z) * (z-1) / 2;
    ans += LL(z) * m;

    printf("%lld", ans);
}