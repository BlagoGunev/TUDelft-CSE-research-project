#include <iostream>

#include <algorithm>

#include <cstring>

#include <set>



using namespace std;



const int N = 300010, M = 600010;

const int INF = 2e9;



int n, m;

string s;

multiset<int, greater<int>> S[N]; 

int pos[N];

int trie[N][26], trie_idx = 1;

int fail[N];

int q[N];

int w[N];

int e[M], ne[M], h[N], idx;

int fa[N], dep[N], top[N];

int son[N], sz[N], seq[N], dfn[N];

int ts;

struct Node {

    int l, r;

    int mx;

}tr[N << 2];



void insert(int u, int v) {

    e[idx] = v, ne[idx] = h[u], h[u] = idx++; 

}



void dfs1(int u, int father) {

    dep[u] = dep[father] + 1;

    fa[u] = father, sz[u] = 1;

    for (int i = h[u]; ~i; i = ne[i]) {

        int j = e[i];

        if (j == father) continue;

        dfs1(j, u);

        sz[u] += sz[j];

        if (sz[j] > sz[son[u]]) son[u] = j;

    }

}



void dfs2(int u, int t) {

    top[u] = t, dfn[u] = ++ts, seq[ts] = u;

    if (son[u]) dfs2(son[u], t);

    for (int i = h[u]; ~i; i = ne[i]) {

        int j = e[i];

        if (j == fa[u] || j == son[u]) continue;

        dfs2(j, j);

    }

}



void pushup(int u) {

    tr[u].mx = max(tr[u << 1].mx, tr[u << 1 | 1].mx);

}



void build(int u, int l, int r) {

    tr[u] = {l, r};

    if (l == r) {

        tr[u].mx = -INF;

        if (S[seq[l]].size())

            tr[u].mx = *S[seq[l]].begin();

        return;

    }

    int mid = l + r >> 1;

    build(u << 1, l, mid);

    build(u << 1 | 1, mid + 1, r);

    pushup(u);

}



void modify(int u, int x) {

    if (tr[u].l == tr[u].r) 

        return tr[u].mx = *S[seq[tr[u].l]].begin(), void();

    int mid = tr[u].l + tr[u].r >> 1;

    if (x <= mid) modify(u << 1, x);

    else modify(u << 1 | 1, x);

    pushup(u);

}



int query(int u, int l, int r) {

    if (tr[u].l >= l && tr[u].r <= r) return tr[u].mx;

    int mid = tr[u].l + tr[u].r >> 1, res = -INF;

    if (l <= mid) res = max(res, query(u << 1, l, r));

    if (r > mid) res = max(res, query(u << 1 | 1, l, r));

    return res;

}



int query_path(int u, int v) {

    int res = -INF;

    while (top[u] != top[v]) {

        if (dep[top[u]] < dep[top[v]]) swap(u, v);

        res = max(res, query(1, dfn[top[u]], dfn[u]));

        u = fa[top[u]];

    }

    if (dep[u] < dep[v]) swap(u, v);

    res = max(res, query(1, dfn[v], dfn[u]));

    return res;

}



int insert(string s) {

    int p = 1;

    for (int i = 0; s[i]; i++) {

        int u = s[i] - 'a';

        if (!trie[p][u]) trie[p][u] = ++trie_idx;

        p = trie[p][u];

    }

    return p;

}



void build() {

    memset(h, -1, sizeof h);

    int tt = -1, hh = 0;

    for (int i = 0; i < 26; i++) trie[0][i] = 1;

    fail[1] = 0;

    q[++tt] = 1;

    while (hh <= tt) {

        int t = q[hh++];

        for (int i = 0; i < 26; i++) {

            int &p = trie[t][i];

            if (!p) p = trie[fail[t]][i];

            else {

                fail[p] = trie[fail[t]][i];

                q[++tt] = p;

            }

        }    

        insert(fail[t], t);

    }

    dfs1(1, 0), dfs2(1, 1);

    build(1, 1, ts);

} 



int run(string s) {

    int p = 1, res = -INF;

    for (int i = 0; s[i]; i++) {

        int u = s[i] - 'a';

        p = trie[p][u];

        res = max(res, query_path(p, 1)); 

    }

    return res == -INF ? -1 : res;

}



signed main() {

    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {

        cin >> s;

        pos[i] = insert(s);

        S[pos[i]].insert(w[i]);

    }

    build();

    while (m--) {

        int op;

        cin >> op;

        if (op == 1) {

            int a, b;

            cin >> a >> b;

            S[pos[a]].erase(S[pos[a]].find(w[a]));

            w[a] = b, S[pos[a]].insert(w[a]);

            modify(1, dfn[pos[a]]);

        }

        if (op == 2) {

            cin >> s;

            cout << run(s) << '\n';

        }

    }

    return 0;

}