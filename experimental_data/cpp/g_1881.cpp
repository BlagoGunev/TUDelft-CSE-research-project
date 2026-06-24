#include<bits/stdc++.h>

using namespace std;

const int maxn = 5e5 + 5555;
#define ll long long
#define lid (nowid << 1)
#define rid ((nowid << 1) | 1)
#define mid ((l + r) / 2)

char ori[maxn];

int ok2[maxn << 2];
int ok3[maxn << 2];

ll orival[maxn << 2];
ll tag[maxn << 2];

void build(int nowid, int l, int r) {
    ok2[nowid] = 0;
    ok3[nowid] = 0;
    orival[nowid] = 0;
    tag[nowid] = 0;
    if (l == r) {
        return;
    }
    build(lid, l, mid);
    build(rid, mid + 1, r);
}

void update(int *tree, int nowid, int l, int r, int pos, int v) {
    if (l == r) {
        tree[nowid] = v;
        return;
    }
    if (pos <= mid) {
        update(tree, lid, l, mid, pos, v);
    } else {
        update(tree, rid, mid + 1, r, pos, v);
    }
    tree[nowid] = tree[lid] + tree[rid];
}

int query(int *tree, int nowid, int l, int r, int ql, int qr) {
    if (ql > qr) {
        return 0;
    }
    if (ql <= l && r <= qr) {
        return tree[nowid];
    }
    int res = 0;
    if (ql <= mid) {
        res += query(tree, lid, l, mid, ql, qr);
    }
    if (mid < qr) {
        res += query(tree, rid, mid + 1, r, ql, qr);
    }
    return res;
}


void update(int nowid, int l, int r, int ul, int ur, int v) {
    if (ul <= l && r <= ur) {
        tag[nowid] += v;
        orival[nowid] += v;
        return;
    }
    tag[lid] += tag[nowid];
    orival[lid] += tag[nowid];
    tag[rid] += tag[nowid];
    orival[rid] += tag[nowid];

    tag[nowid] = 0;
    if (ul <= mid) {
        update(lid, l, mid, ul, ur, v);
    }
    if (mid < ur) {
        update(rid, mid + 1, r, ul, ur, v);
    }
}

ll query(int nowid, int l, int r, int pos) {
    if (l == r) {
        return orival[nowid] % 26;
    }

    tag[lid] += tag[nowid];
    orival[lid] += tag[nowid];
    tag[rid] += tag[nowid];
    orival[rid] += tag[nowid];

    tag[nowid] = 0;
    if (pos <= mid) {
        return query(lid, l, mid, pos) % 26;
    } else {
        return query(rid, mid + 1, r, pos) % 26;
    }
}

int n, m;

void up(int i) {
    // len2
    if (i + 1 <= n) {
        if (query(1, 1, n, i) == query(1, 1, n, i + 1)) {
            update(ok2, 1, 1, n, i, 1);
        } else {
            update(ok2, 1, 1, n, i, 0);
        }
    }
    // len3
    if (i + 2 <= n) {
        if (query(1, 1, n, i) == query(1, 1, n, i + 2)) {
            update(ok3, 1, 1, n, i, 1);
        } else {
            update(ok3, 1, 1, n, i, 0);
        }
    }
}

void solve() {
    scanf("%d %d", &n, &m);
    scanf("%s", ori + 1);
    build(1, 1, n);

    for (int i = 1; i <= n; i++) {
        update(1, 1, n, i, i, ori[i] - 'a');

        if (i < n && ori[i] == ori[i + 1]) {
            update(ok2, 1, 1, n, i, 1);
        }

        if (i + 1 < n && ori[i] == ori[i + 2]) {
            update(ok3, 1, 1, n, i, 1);
        }
    }

    while (m--) {
        int t, l, r;
        scanf("%d %d %d", &t, &l, &r);
        if (t == 1) {
            int x;
            scanf("%d", &x);
            update(1, 1, n, l, r, x);
            for (int i = max(1, l - 3); i <= l; i++) {
                up(i);
            }
            for (int i = max(1, r - 3); i <= r; i++) {
                up(i);
            }
        } else {
            if (query(ok2, 1, 1, n, l, r - 1) > 0 || query(ok3, 1, 1, n, l, r - 2) > 0) {
                puts("NO");
            } else {
                puts("YES");
            }
        }
    }
}

signed main() {
//    freopen("g_in.txt", "r", stdin);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}