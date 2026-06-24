#include <algorithm>

#include <cstdio>



typedef long long ll;



const int MAX_N = 4005;



int N, M, a[MAX_N], ls[MAX_N], rs[MAX_N], lw[MAX_N], rw[MAX_N], sz[MAX_N];

ll f[MAX_N][MAX_N];



inline auto ckmax(ll& a, ll b) -> bool { return (a < b) && (a = b, true); }



auto dfs(int u) -> void {

    sz[u] = 1;

    if (ls[u]) {

        dfs(ls[u]);

        for (int i = std::min(M, sz[u]); i >= 0; i--) {

            for (int j = std::min(M, sz[ls[u]]); j >= 0; j--)

                ckmax(f[u][i + j],

                      f[u][i] + f[ls[u]][j] + 1LL * j * (M - j) * lw[u]);

        }



        sz[u] += sz[ls[u]];

    }



    if (rs[u]) {

        dfs(rs[u]);



        for (int i = std::min(M, sz[u]); i >= 0; i--) {

            for (int j = std::min(M, sz[rs[u]]); j >= 0; j--)

                ckmax(f[u][i + j],

                      f[u][i] + f[rs[u]][j] + 1LL * j * (M - j) * rw[u]);

        }



        sz[u] += sz[rs[u]];

    }

}



auto main() -> int {

    scanf("%d%d", &N, &M);

    static int st[MAX_N], tp;



    for (int i = 1; i <= N; i++) {

        scanf("%d", a + i);

        int k = tp;

        for (; k && a[i] < a[st[k]]; k--)

            ;

        if (k) {

            rs[st[k]] = i;

            rw[st[k]] = a[i] - a[st[k]];

        }



        if (k < tp) {

            ls[i] = st[k + 1];

            lw[i] = a[st[k + 1]] - a[i];

        }



        st[tp = ++k] = i;

    }

    dfs(st[1]);

    printf("%lld\n", f[st[1]][M]);

}