#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define doprint false

#if doprint

template <typename... T>
void write(T... a)
{
    ((cout << a << ' '), ...);
}

template <typename... T>
void writeln(T... a)
{
    ((cout << a << ' '), ...) << endl;
}

void writecr()
{
    cout << endl;
}

#else

#define write(...)
#define writeln(...)
#define writecr()

#endif

#define MAXN 220005
#define MOD 998244353ll

using ll = long long;
using vl = vector<ll>;

ll pow(ll b, ll p, ll m)
{
    ll r = 1;
    while (p)
    {
        if (p & 1)
        {
            r = r * b % m;
        }
        b = b * b % m;
        p >>= 1;
    }
    return r;
}

int l[MAXN];

class Poly
{
public:
    vl f;
    Poly operator<<(int v)
    {
        Poly a = *this;
        a.f.insert(a.f.begin(), v, 0);
        return a;
    }
    Poly operator+(int v)
    {
        Poly a = *this;
        a.f[0] += v;
        return a;
    }
    Poly operator+(Poly b)
    {
        Poly a = *this;
        if (a.f.size() < b.f.size())
        {
            a.f.resize(b.f.size());
        }
        for (int i = 0; i < b.f.size(); i++)
        {
            (a.f[i] += b.f[i]) %= MOD;
        }
        return a;
    }
    void btf(int len)
    {
        for (int i = 1, j = len >> 1; i < len - 1; i++)
        {
            if (i < j)
            {
                swap(f[i], f[j]);
            }
            int k = len >> 1;
            while (j >= k)
            {
                j -= k;
                k >>= 1;
            }
            j += k;
        }
    }
    void ntt(int len, int on)
    {
        btf(len);
        for (int h = 2; h <= len; h <<= 1)
        {
            ll g0 = pow(3, (MOD - 1) / h, MOD);
            for (int j = 0; j < len; j += h)
            {
                ll g = 1;
                for (int k = j; k < j + (h >> 1); k++)
                {
                    ll u = f[k], t = f[k + (h >> 1)] * g % MOD;
                    f[k] = (u + t) % MOD;
                    f[k + (h >> 1)] = (u - t + MOD) % MOD;
                    g = g * g0 % MOD;
                }
            }
        }
        if (on == -1)
        {
            reverse(f.begin() + 1, f.end());
            ll inv = pow(len, MOD - 2, MOD);
            for (ll &v : f)
            {
                v = v * inv % MOD;
            }
        }
    }
    Poly operator*(Poly b)
    {
        vl &g = b.f;
        int n = f.size(), m = g.size();
        int l = ::l[n + m - 1];
        writeln("conv", n, m, l);
        f.resize(l), g.resize(l);
        ntt(l, 1);
        b.ntt(l, 1);
        writeln("cv");
        Poly c;
        for (int i = 0; i < l; i++)
        {
            c.f.push_back(f[i] * g[i] % MOD);
        }
        ntt(l, -1);
        c.ntt(l, -1);
        f.resize(n);
        c.f.resize(n + m - 1);
        return c;
    }
};

using ppp = pair<Poly, Poly>;

int n;
ll x;

vector<int> e[MAXN];
int ss[MAXN][2], sz[MAXN];

void dfs1(int p, int f)
{
    sz[p] = 1;
    int c = 0;
    for (int u : e[p])
    {
        if (u == f)
        {
            continue;
        }
        ss[p][c++] = u;
        dfs1(u, p);
        sz[p] += sz[u];
    }
    if (c == 2 && sz[ss[p][0]] < sz[ss[p][1]])
    {
        swap(ss[p][0], ss[p][1]);
    }
}

vector<Poly> ps[MAXN];

ppp solve(vector<Poly> &ps, int l, int r)
{
    writeln("solve", l, r);
    if (l == r)
    {
        Poly p = ps[l];
        return {p + 1, p};
    }
    int mid = (l + r) >> 1;
    auto [hl, gl] = solve(ps, l, mid);
    auto [hr, gr] = solve(ps, mid + 1, r);
    return {hl + gl * (hr + (-1)), gl * gr};
}

Poly dfs(int p, int top)
{
    writeln(p, top);
    if (ss[p][1])
    {
        ps[top].push_back(dfs(ss[p][1], ss[p][1]) << 1);
    }
    else
    {
        ps[top].push_back({{0, 1}});
    }
    if (ss[p][0])
    {
        dfs(ss[p][0], top);
    }
    if (p == top)
    {
        return solve(ps[p], 0, ps[p].size() - 1).first;
    }
    else
    {
        return Poly();
    }
}

int main()
{
    cin >> n >> x;
    x %= MOD;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    l[1] = 1;
    for (int i = 2; i < MAXN; i++)
    {
        if (l[i - 1] == i - 1)
        {
            l[i] = (i - 1) << 1;
        }
        else
        {
            l[i] = l[i - 1];
        }
    }
    dfs1(1, 1);
    write(123);
    Poly p = dfs(1, 1);
    ll res = 0, c = 1;
    for (int i = 1; i <= n; i++)
    {
        write(p.f[i]);
        (res += p.f[i] * c % MOD) %= MOD;
        (c *= (x + i) * pow(i, MOD - 2, MOD) % MOD) %= MOD;
    }
    writecr();
    cout << res << endl;
    return 0;
}