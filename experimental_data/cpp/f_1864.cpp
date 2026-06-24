#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;
typedef long long ll;

const int inf = 1e9;

struct maxSegmentTree{
    int tree[1010101 * 4];
    void Init(int n) {
        fill(tree, tree+n*4+10, 0);
    }
    void update(int node, int s, int e, int tar, int val) {
        if (s > tar || tar > e) return;
        if (s == e) {
            tree[node] = val;
            return;
        }
        int mid = s + e >> 1;
        update(node*2, s, mid, tar, val);
        update(node*2+1, mid+1, e, tar, val);
        tree[node] = max(tree[node*2], tree[node*2+1]);
    }
    int query(int node, int s, int e, int l, int r) {
        if (l > e || s > r) return 0;
        if (l <= s && e <= r) return tree[node];
        int mid = s + e >> 1;
        return max(query(node*2, s, mid, l, r), query(node*2+1, mid+1, e, l, r));
    }
} seg1;

struct PST{
    struct Node{
        int l, r, v;
    };
    vector<Node> tree;
    void build(int node, int s, int e) {
        if (s == e) return;
        int mid = s + e >> 1;
        tree[node].l = tree.size();
        tree.push_back({-1, -1, 0});
        build(tree[node].l, s, mid);
        tree[node].r = tree.size();
        tree.push_back({-1, -1, 0});
        build(tree[node].r, mid+1, e);
    }
    void update(int node, int pnode, int s, int e, int tar, int val) {
        if (s == e) {
            tree[node].v = tree[pnode].v + val;
            return;
        }
        int mid = s + e >> 1;
        if (tar <= mid) {
            tree[node].l = tree.size();
            tree[node].r = tree[pnode].r;
            tree.push_back({-1, -1, 0});
            update(tree[node].l, tree[pnode].l, s, mid, tar, val);
        }
        else {
            tree[node].l = tree[pnode].l;
            tree[node].r = tree.size();
            tree.push_back({-1, -1, 0});
            update(tree[node].r, tree[pnode].r, mid+1, e, tar, val);
        }
        tree[node].v = tree[tree[node].l].v + tree[tree[node].r].v;
    }
    int query(int node, int s, int e, int l, int r) {
        if (l > e || s > r) return 0;
        if (l <= s && e <= r) return tree[node].v;
        int mid = s + e >> 1;
        return query(tree[node].l, s, mid, l, r) + query(tree[node].r, mid+1, e, l, r);
    }
} pst;

int n, q;
int a[1010101];
int root[1010101];
vector<int> v[1010101], t[1010101];

void run_case() {
    scanf("%d %d", &n, &q);
    for (int i=1; i<=n; i++) {
        scanf("%d", &a[i]);
        t[a[i]].push_back(i);
    }
    seg1.Init(n);
    for (int i=1; i<=n; i++) {
        int pr = 0;
        for (auto &j : t[i]) {
            if (pr == 0) {
                v[i].push_back(i);
            }
            else {
                int ret = seg1.query(1, 1, n, pr + 1, j - 1);
                if (ret != 0) {
                    v[ret].push_back(i);
                }
            }
            pr = j;
            seg1.update(1, 1, n, j, i);
        }
    }
    root[n+1] = 0;
    pst.tree.push_back({-1, -1, 0});
    pst.build(root[n+1], 1, n);
    int pr = 0;
    for (int i=n; i>=1; i--) {
        if (v[i].empty()) {
            root[i] = root[i+1];
            continue;
        }
        for (auto &j : v[i]) {
            root[i] = pst.tree.size();
            pst.tree.push_back({-1, -1, 0});
            pst.update(root[i], pr, 1, n, j, 1);
            pr = root[i];
        }
    }
    while (q --) {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%d\n", pst.query(root[l], 1, n, l, r));
    }
}

int main() {
    int tc = 1;
    //scanf("%d", &tc);
    while (tc --) {
        run_case();
    }
}