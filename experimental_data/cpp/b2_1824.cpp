// LUOGU_RID: 155509561
#include <bits/stdc++.h>
#define lowbit(x) (x & -x)
#define eb emplace_back
#define pb push_back
#define mp make_pair
using namespace std;

typedef long long ll;
const int N = 2e5+5;
const int Mod = 1e9+7;

int n, k, siz[N];
int ans;
int f[N];

ll fac[N], ifac[N];

vector<int> T[N];

void dfs(int x, int fa) {
    siz[x] = 1;
    for (int son : T[x]) {
        if (son == fa) continue;
        dfs(son, x);
        siz[x] += siz[son];
    }
}

inline int qpow(int a, int b) {
    ll base = a, ans = 1;
    while (b) {
        if (b & 1) ans = ans * base % Mod;
        base = base * base % Mod;
        b >>= 1;
    }
    return ans;
}

inline void Add(int &a, int b) { a += b; if (a >= Mod) a -= Mod; }
inline ll C(int n, int m) { return n >= m ? fac[n] * ifac[m] % Mod * ifac[n - m] % Mod : 0; }

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        T[u].pb(v);
        T[v].pb(u);
    }

    dfs(1, 0);

    fac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % Mod;
    ifac[n] = qpow(fac[n], Mod - 2);
    for (int i = n; i; i--) ifac[i - 1] = ifac[i] * i % Mod;

    for (int i = 1; i <= n; i++) {
        f[i] = (f[i - 1] + C(n - i, k - k / 2 - 1) * C(i - 1, k / 2)) % Mod;
    }

    for (int i = 1; i <= n; i++) {
        Add(ans, C(n, k));
        for (int son : T[i]) {
            int s = siz[son] < siz[i] ? siz[son] : n - siz[i];
            Add(ans, Mod - f[s]);
        }
    }

    printf("%lld", (ll) ans * qpow(C(n, k), Mod - 2) % Mod);
    return 0;
}