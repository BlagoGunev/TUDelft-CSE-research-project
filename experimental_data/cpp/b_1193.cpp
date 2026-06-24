#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
const int N = 4e6 + 10, oo = 1e15;
int n, m, k, d[N], w[N];
vector<int> g[N];

namespace Segtree {
    int root[N], idx;
    vector<int> deleted;
    struct TREE {
        int ls, rs, maxx, minn, tag;
    } tree[N];
    void del(int &rt) {
        if (!rt)
			return;
        deleted.push_back(rt);
        tree[rt] = {0, 0, 0, 0, 0};
        rt = 0;
    }
    int newnode() {
        if (deleted.empty())
			return ++idx;
        int p = deleted.back();
        deleted.pop_back();
        return p;
    }
    void push_up(int rt) {
        int ls = tree[rt].ls, rs = tree[rt].rs;
        tree[rt].maxx = max(tree[ls].maxx, tree[rs].maxx);
        tree[rt].minn = min(tree[ls].minn, tree[rs].minn);
        if (tree[rt].maxx == tree[rt].minn) {
            del(tree[rt].ls);
            del(tree[rt].rs);
        }
    }
    void push_down(int rt) {
        int ls = tree[rt].ls, rs = tree[rt].rs, tag = tree[rt].tag;
        if (ls) {
            tree[ls].maxx += tag;
            tree[ls].minn += tag;
            tree[ls].tag += tag;
        }
        if (rs) {
            tree[rs].maxx += tag;
            tree[rs].minn += tag;
            tree[rs].tag += tag;
        }
        tree[rt].tag = 0;
    }
    int merge(int p, int q) {
        if (!p or !q)
			return p + q;
        if (tree[p].maxx == tree[p].minn) {
            int v = tree[p].maxx;
            tree[q].maxx += v;
            tree[q].minn += v;
            tree[q].tag += v;
            return q;
        }
        if (tree[q].maxx == tree[q].minn) {
            int v = tree[q].maxx;
            tree[p].maxx += v;
            tree[p].minn += v;
            tree[p].tag += v;
            return p;
        }
        push_down(p);
        push_down(q);
        tree[p].ls = merge(tree[p].ls, tree[q].ls);
        tree[p].rs = merge(tree[p].rs, tree[q].rs);
        push_up(p);
        return p;
    }
    void update(int rt, int l, int r, int x, int y, int v) {
        if (l > y or r < x)
			return;
        if (tree[rt].minn >= v)
			return;
        if (x <= l and r <= y and tree[rt].maxx <= v) {
            tree[rt].maxx = tree[rt].minn = v;
            tree[rt].tag = 0;
            del(tree[rt].ls);
            del(tree[rt].rs);
            return;
        }
        push_down(rt);
        if (tree[rt].maxx == tree[rt].minn) {
            tree[rt].ls = newnode();
            tree[rt].rs = newnode();
            int ls = tree[rt].ls;
            int rs = tree[rt].rs;
            tree[ls].maxx = tree[ls].minn = tree[rs].maxx = tree[rs].minn = tree[rt].maxx;
        }
        int mid = (l + r) >> 1;
        update(tree[rt].ls, l, mid, x, y, v);
        update(tree[rt].rs, mid + 1, r, x, y, v);
        push_up(rt);
    }
    int query(int rt, int l, int r, int x) {
        if (tree[rt].maxx == tree[rt].minn)
			return tree[rt].maxx;
        push_down(rt);
        int mid = (l + r) >> 1;
        return x <= mid ? query(tree[rt].ls, l, mid, x) : query(tree[rt].rs, mid + 1, r, x);
    }
}

using namespace Segtree;

void dfs(int u) {
    root[u] = newnode();
    for (int v : g[u]) {
        dfs(v);
        root[u] = merge(root[u], root[v]);
    }
    if (d[u]) {
        int f = query(root[u], 1, k, d[u]) + w[u];
        update(root[u], 1, k, d[u], k, f);
    }
}

signed main() {
    IOS;
    cin >> n >> m >> k;
    for (int i = 2, u; i <= n; i++) {
        cin >> u;
        g[u].push_back(i);
    }
    for (int i = 1, x; i <= m; i++) {
        cin >> x >> d[x] >> w[x];
    }
    dfs(1);
    cout << tree[root[1]].maxx;
    return 0;
}