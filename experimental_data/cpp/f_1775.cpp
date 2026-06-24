#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

template <typename T> inline void read(T &F) {

    int R = 1; F = 0; char CH = getchar();

    for(; !isdigit(CH); CH = getchar()) if(CH == '-') R = -1;

    for(; isdigit(CH); CH = getchar()) F = F * 10 + CH - 48;

    F *= R;

}

inline void file(string str) {

    freopen((str + ".in").c_str(), "r", stdin);

    freopen((str + ".out").c_str(), "w", stdout);

}

int calc(int x) {

    int l = 1, r = x * 2, res = 0;

    while(l <= r) {

        int mid = (l + r) >> 1;

        LL a = mid / 2, b = mid - a;

        if(a * b >= x) res = mid, r = mid - 1;

        else l = mid + 1;

    }

    return res;

}

const int N = 1550;

int f[N], mod, g[N];

void init() {

    const int n = 1500;

    f[0] = 1;

    for(int i = 1; i <= n; i++) {

        for(int j = i; j <= n; j++)

            f[j] += f[j - i], f[j] %= mod;

    }

    for(int i = 0; i <= n; i++)

        for(int j = 0; i + j <= n; j++)

            g[i + j] += 1LL * f[i] * f[j] % mod, g[i + j] %= mod;

    memcpy(f, g, sizeof(f)); memset(g, 0, sizeof(g));

    for(int i = 0; i <= n; i++)

        for(int j = 0; i + j <= n; j++)

            g[i + j] += 1LL * f[i] * f[j] % mod, g[i + j] %= mod;

}

int main() {

    //file("");

    int T, op; read(T), read(op);

    if(op == 1) {

        while(T--) {

            int n; read(n);

            int p = calc(n);

            int x = p / 2, y = p - x;

            cout << x << ' ' << y << '\n';

            int s = 0;

            for(int i = 1; i <= x; i++, puts(""))

                for(int j = 1; j <= y; j++) {

                    s++; if(s <= n) putchar('#');

                    else putchar('.');

                }

        }

    }

    else {

        read(mod); init();

        while(T--) {

            int n; read(n);

            int p = calc(n);

            cout << p * 2 << ' ';

            LL ans = 0;

            for(int i = 1; i < p; i++) {

                const int x = i, y = p - i;

                if(x * y >= n) ans += g[x * y - n];

            }

            cout << ans % mod << '\n';

        }

    }

    

    #ifdef _MagicDuck

        fprintf(stderr, "# Time: %.3lf s", (double)clock() / CLOCKS_PER_SEC);

    #endif

    return 0;

}