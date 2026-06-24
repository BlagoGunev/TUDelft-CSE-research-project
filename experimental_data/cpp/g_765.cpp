#include <bits/stdc++.h>

using namespace std; const int maxn = 5e5 + 5, mod = 1e9 + 7; typedef long long ll;

bool ST;

inline int qpow(int x, int k) { int res = 1; while (k) { if (k & 1) res = (ll)res * x % mod; x = (ll)x * x % mod, k >>= 1; } return res; }

char s[42]; int m; ll tar; int n, p[maxn], b[maxn], delta = 1;

const int MOD = 3e6 + 5, maxm = 1.6e7 + 5;

struct HashTable
{
    struct node { ll a; int b, nx; } a[maxm]; int hd[MOD], tt;

    int& operator [](const ll& x)
    {
        int pos = (x ^ (x >> 1)) % MOD;
        for (int i = hd[pos]; i; i = a[i].nx) if (a[i].a == x) return a[i].b;
        a[++tt] = { x, 0, hd[pos] }, hd[pos] = tt; return a[tt].b;
    }

    void clear() { memset(hd, 0, sizeof(int) * MOD), tt = 0; }
} mp;

struct VALUE { ll a; int b; } f[maxm]; int fLen;

inline void get(int& x, int y) { if ((x += y) >= mod) x -= mod; }

bool ED;

int main()
{
    cerr << (&ST - &ED) / 1024.0 / 1024.0 << endl;
    scanf("%s", s), m = strlen(s); for (int i = 0; i < m; i++) if (s[i] == '1') tar |= 1ll << i; cerr << s << ' ' << tar << endl;
    scanf("%d", &n); for (int i = 1; i <= n; i++) scanf("%d%d", p + i, b + i), delta = (ll)delta * qpow(p[i], b[i] - 1) % mod;
    sort(p + 1, p + n + 1);
    p[n + 1] = 1e9 + 5;
    register int g[2][41], cur = 0; memset(g[cur], 0, sizeof(int) * 41);
    if (p[1] <= (m + 2 >> 1))
    {
        mp[(1ll << m) - 1] = 1;
    }
    else if (p[1] < m)
    {
        register ll Msk = (1ll << p[1]) - (1ll << m - p[1]), nS = (1ll << m) - 1;
        get(mp[(ll)__builtin_popcountll((nS & ~tar) & Msk) << m | (nS & ~Msk)], 1);
    }
    else get(g[cur][__builtin_popcountll(~tar & (1ll << m) - 1)], 1);
    if ((p[1] <= (m + 2 >> 1)) || p[1] < m)
    for (int i = 1; i <= n; i++)
    {
        fLen = 0;
        for (int I = 0; I < MOD; I++)
        {
            for (int i = mp.hd[I]; i; i = mp.a[i].nx) f[fLen++] = { mp.a[i].a, mp.a[i].b };
        }
        mp.clear();
        register ll msk[40]; register int P = p[i], nP = p[i + 1]; cerr << "P: " << P << ' ' << fLen << ' ' << f[0].a << ' ' << f[0].b << endl;
        for (int i = 0; i < P; i++) { msk[i] = 0; for (int j = i; j < m; j += P) msk[i] |= 1ll << j; }
        if (nP <= (m + 2 >> 1))
        {
            cerr << "*";
            register int i, j; register ll nS = 0;
            for (register VALUE *i = f, *ed = f + fLen; i != ed; i++) for (j = 0; j < P; j++) if (((nS = i->a & ~msk[j]) & tar) == tar) get(mp[nS], i->b)
                /*, cerr << "trans: " << i->a << ' ' << j << ' ' << msk[j] << endl*/;
        }
        else if (P <= (m + 2 >> 1) && nP < m)
        {
            cerr << "$";
            register int i, j; register ll Msk = (1ll << nP) - (1ll << m - nP), nS;
            for (register VALUE *i = f, *ed = f + fLen; i != ed; i++) for (j = 0; j < P; j++)
                if (((nS = i->a & ~msk[j]) & tar) == tar) get(mp[(ll)__builtin_popcountll((nS & ~tar) & Msk) << m | (nS & ~Msk)], i->b);
        }
        else if (nP < m)
        {
            cerr << "!";
            register int i, j; register ll Msk = (1ll << nP) - (1ll << m - nP), nS;
            register ll nMsk = (1ll << P) - (1ll << m - P); register int ct = __builtin_popcountll(~tar & nMsk), nct;
            for (register VALUE *i = f, *ed = f + fLen; i != ed; i++)
            {
                for (j = 0; j < P; j++) if (j + P < m)
                    if ((((nS = i->a & ~msk[j]) & (tar & ~nMsk))) == (tar & ~nMsk))
                        get(mp[((nS >> m) + __builtin_popcountll((nS & ~tar) & Msk) << m) | (nS & ~Msk & (1ll << m) - 1)], i->b);
                nct = i->a >> m;
                nS = i->a - (1ll << m); if (nct)
                get(mp[((nS >> m) + __builtin_popcountll((nS & ~tar) & Msk) << m) | (nS & ~Msk & (1ll << m) - 1)], (ll)nct * i->b % mod);
                nS = i->a;
                get(mp[((nS >> m) + __builtin_popcountll((nS & ~tar) & Msk) << m) | (nS & ~Msk & (1ll << m) - 1)], (ll)(ct - nct) * i->b % mod);
            }
        }
        else if (P <= (m + 2 >> 1) && nP >= m)
        {
            cerr << "#";
            register int i, j; register ll nS;
            for (register VALUE *i = f, *ed = f + fLen; i != ed; i++) for (j = 0; j < P; j++)
                if (((nS = i->a & ~msk[j]) & tar) == tar) get(g[cur][__builtin_popcountll(nS & ~tar)], i->b);
            break;
        }
        else if (nP >= m)
        {
            cerr << "&";
            register int i, j; register ll nS;
            register ll nMsk = (1ll << P) - (1ll << m - P); register int ct = __builtin_popcountll(~tar & nMsk), nct;
            for (register VALUE *i = f, *ed = f + fLen; i != ed; i++)
            {
                // cerr << "insert: " << i->a << ' ' << i->b << endl;
                for (j = 0; j < P; j++) if (j + P < m)
                    if (((nS = i->a & ~msk[j]) & (tar & ~nMsk)) == (tar & ~nMsk))
                        get(g[cur][(nS >> m) + __builtin_popcountll(nS & ~tar & (1ll << m) - 1)], i->b);
                nct = i->a >> m;
                nS = i->a - (1ll << m); if (nct)
                get(g[cur][(nS >> m) + __builtin_popcountll(nS & ~tar & (1ll << m) - 1)], (ll)nct * i->b % mod);
                nS = i->a;
                get(g[cur][(nS >> m) + __builtin_popcountll(nS & ~tar & (1ll << m) - 1)], (ll)(ct - nct) * i->b % mod);
            }
            break;
        }
        else
        {
            cerr << "Exception: " << P << ' ' << nP << endl;
            assert(0);
        }
    }
    for (int j = 0; j <= m; j++) cerr << g[cur][j] << ' '; cerr << endl;
    for (register int i = 1, j, ct = __builtin_popcountll(((1ll << m) - 1) & ~tar); i <= n; i++) if (!(p[i] <= (m + 2 >> 1)) && p[i] >= m)
    {
        memset(g[cur ^ 1], 0, sizeof(int) * 41);
        for (j = 0; j <= m; j++)
        {
            if (j) get(g[cur ^ 1][j - 1], (ll)g[cur][j] * j % mod);
            get(g[cur ^ 1][j], (ll)g[cur][j] * (ct - j + p[i] - m) % mod);
        }
        cur ^= 1;
    }
    g[cur][0] = (ll)g[cur][0] * delta % mod;
    return 0 * printf("%d\n", g[cur][0]);
}