// LUOGU_RID: 157605487
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define pb emplace_back
#define sz(a) int(a.size())

const int N = 100009, B = 3000;
int n, q, a[N], b[N];
int rka[N], rkb[N], buc[N], s[N], w[N];
bool put[N], ok[N];

int ch[N], cg[N];
vector<int> h[N], g[N], p, ih, ig;
tuple<int, int, int> o[N];
unordered_map<LL, int> stand;

struct info {
    int tag;
    vector<int> rks, pos, ws;
    void change(int x, int v)
    {
        int p = lower_bound(pos.begin(), pos.end(), x, greater<int>()) - pos.begin();
        while (p < sz(pos) && pos[p] == x) {
            rks[p++] += v;
        }
    }
    int qry(int v)
    {
        int p = lower_bound(rks.begin(), rks.end(), v - tag) - rks.begin();
        return p ? ws[p - 1] : 0;
    }
    void clear()
    {
        tag = 0, vector<int>().swap(rks), vector<int>().swap(pos), vector<int>().swap(ws);
    }
    void resize(int siz)
    {
        rks.resize(siz), pos.resize(siz), ws.resize(siz);
    }
    info() : tag(0) {}
};

struct {
    int tr[N * 2];
    void add(int x, int v)
    {
        for (; x <= 2 * n; x += x & -x) {
            tr[x] += v;
        }
    }
    int ask(int x)
    {
        int y = 0;
        for (; x; x -= x & -x) {
            y += tr[x];
        }
        return y;
    }
    void clear()
    {
        memset(tr, 0, sizeof(int) * (2 * n + 5));
    }
} bit;

info hB[N], gB[N];

void addrow(int x, int v)
{
    hB[x].tag += v;
    for (auto i : h[x]) {
        bit.add(s[i], -w[i]), bit.add(s[i] += v, w[i]);
    }
    for (int i : ig) {
        gB[i].change(x, v);
    }
    for (int i : p) {
        if (a[i] == x) {
            bit.add(s[i], -1), bit.add(s[i] += v, 1);
        }
    }
}

void addcol(int x, int v)
{
    gB[x].tag += v;
    for (auto i : g[x]) {
        bit.add(s[i], -w[i]), bit.add(s[i] += v, w[i]);
    }
    for (int i : ih) {
        hB[i].change(x, v);
    }
    for (int i : p) {
        if (b[i] == x) {
            bit.add(s[i], -1), bit.add(s[i] += v, 1);
        }
    }
}

int qryrnk(int x)
{
    int res = 1 + bit.ask(x - 1);
    for (auto i : ih) {
        res += hB[i].qry(x);
    }
    for (auto i : ig) {
        res += gB[i].qry(x);
    }
    return res;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        int op, k, c = 0;
        cin >> op >> k;
        if (op <= 2) {
            char t;
            cin >> t, c = t == '+';
        }
        o[i] = make_tuple(op, k, c);
    }
    for (int l = 1, r; l <= q; l = r + 1) {
        r = min(l + B - 1, q);
        for (int i = 1; i <= n; ++i) {
            ++buc[a[i]];
        }
        for (int i = 100000; i; --i) {
            buc[i] += buc[i + 1];
        }
        for (int i = 1; i <= n; ++i) {
            rka[i] = buc[a[i] + 1] + 1;
        }
        memset(buc, 0, sizeof(int) * 100005);
        for (int i = 1; i <= n; ++i) {
            ++buc[b[i]];
        }
        for (int i = 100000; i; --i) {
            buc[i] += buc[i + 1];
        }
        for (int i = 1; i <= n; ++i) {
            rkb[i] = buc[b[i] + 1] + 1;
        }
        memset(buc, 0, sizeof(int) * 100005);

        for (int i = l; i <= r; ++i) {
            auto [op, k, c] = o[i];
            if (!put[k]) {
                p.pb(k), put[k] = true;
            }
        }

        for (int i = 1; i <= n; ++i) {
            ++ch[a[i]], ++cg[b[i]];
            if (!put[i]) {
                LL hsh = a[i] * 1000000ll + b[i];
                if (stand.count(hsh)) {
                    ++w[stand[hsh]], put[i] = true;
                    continue;
                }
                stand[hsh] = i, w[i] = 1;
                h[a[i]].pb(i), g[b[i]].pb(i);
            }else {
                w[i] = 1;
            }
        }
        for (int i = 1; i <= 100000; ++i) {
            if (sz(h[i]) >= B) {
                ih.pb(i);
                sort(h[i].begin(), h[i].end(), [](int x, int y) 
                {
                    return b[x] > b[y];
                });
                int s = 0;
                hB[i].resize(sz(h[i]));
                for (int j = 0; j < sz(h[i]); ++j) {
                    int v = h[i][j];
                    hB[i].ws[j] = (s += w[v]);
                    hB[i].pos[j] = b[v];
                    hB[i].rks[j] = rka[v] + rkb[v];
                    put[v] = true;
                }
                vector<int>().swap(h[i]);
            }
        }
        
        for (int i = 1; i <= 100000; ++i) {
            {
                vector<int> t;
                t.swap(g[i]);
                for (auto v : t) {
                    if (!put[v]) {
                        g[i].pb(v);
                    }
                }
            }
            if (sz(g[i]) >= B) {
                ig.pb(i);
                sort(g[i].begin(), g[i].end(), [](int x, int y) 
                {
                    return a[x] > a[y];
                });
                int s = 0;
                gB[i].resize(sz(g[i]));
                for (int j = 0; j < sz(g[i]); ++j) {
                    int v = g[i][j];
                    gB[i].ws[j] = (s += w[v]);
                    gB[i].pos[j] = a[v];
                    gB[i].rks[j] = rka[v] + rkb[v];
                    put[v] = true;
                }
                vector<int>().swap(g[i]);
            }
        }
        
        for (int i = 1; i <= 100000; ++i) {
            vector<int> t;
            t.swap(h[i]);
            for (auto v : t) {
                if (!put[v]) {
                    h[i].pb(v);
                }
            }
        }

        for (int i = l; i <= r; ++i) {
            auto [op, k, c] = o[i];
            put[k] = false;
        }

        for (int i = 1; i <= n; ++i) {
            if (!put[i]) {
                bit.add(s[i] = rka[i] + rkb[i], w[i]);
            }
        }

        for (int i = l; i <= r; ++i) {
            auto [op, k, c] = o[i];
            if (op == 1) {
                if (!c) {
                    bit.add(s[k], -1);
                    bit.add(s[k] += ch[a[k]], 1);
                    --ch[a[k]], ++ch[--a[k]];
                    addrow(a[k], -1);
                }else {
                    addrow(a[k], 1);
                    bit.add(s[k], -1);
                    --ch[a[k]], ++ch[++a[k]];
                    bit.add(s[k] -= ch[a[k]], 1);
                }
            }else if (op == 2) {
                if (!c) {
                    bit.add(s[k], -1);
                    bit.add(s[k] += cg[b[k]], 1);
                    --cg[b[k]], ++cg[--b[k]];
                    addcol(b[k], -1);
                }else {
                    addcol(b[k], 1);
                    bit.add(s[k], -1);
                    --cg[b[k]], ++cg[++b[k]];
                    bit.add(s[k] -= cg[b[k]], 1);
                }
            }else {
                cout << qryrnk(s[k]) << '\n';
            }
        }

        memset(cg, 0, sizeof(int) * 100005);
        memset(ch, 0, sizeof(int) * 100005);
        memset(put, 0, sizeof(bool) * (n + 1));
        memset(s, 0, sizeof(int) * (n + 1));
        vector<int>().swap(ih);
        vector<int>().swap(ig);
        vector<int>().swap(p);
        for (int i = 1; i <= 100000; ++i) {
            hB[i].clear(), gB[i].clear();
            vector<int>().swap(h[i]);
            vector<int>().swap(g[i]);
        }
        bit.clear(), stand.clear();
    }
    return 0;
}