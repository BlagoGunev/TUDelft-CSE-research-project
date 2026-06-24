#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e5 + 5;

int n;
int p[MAX_N], L[MAX_N], R[MAX_N], pos[MAX_N];

struct Node {
    int mi, cnt, lazy;

    Node() : mi(0), cnt(1), lazy(0) {}
    Node(int m, int c) : mi(m), cnt(c), lazy(0) {}

    Node operator+(const Node &o) const {
        int mi_ = min(mi, o.mi), cnt_ = 0;
        if (mi_ == mi) cnt_ += cnt;
        if (mi_ == o.mi) cnt_ += o.cnt;
        return Node(mi_, cnt_);
    }
}tree[4 * MAX_N];

void build(int idx, int l ,int r) {
    tree[idx] = Node(0, r - l + 1);
    if (l == r) return;

    int mid = (l + r) / 2;
    build(idx * 2, l, mid);
    build(idx * 2 + 1, mid + 1, r);
}

void push(int idx, int l, int r) {
    if (tree[idx].lazy == 0) return;

    tree[idx].mi += tree[idx].lazy;
    if (l < r) {
        tree[2 * idx].lazy += tree[idx].lazy;
        tree[2 * idx + 1].lazy += tree[idx].lazy;
    }
    tree[idx].lazy = 0;
}

void update(int idx, int l, int r, int ql, int qr, int v) {
    push(idx, l, r);
    if (r < ql or qr < l) return;
    if (ql <= l and r <= qr) {
        tree[idx].lazy += v;
        push(idx, l, r);
        return;
    }

    int mid = (l + r) / 2;
    update(idx * 2, l, mid, ql, qr, v);
    update(idx * 2 + 1, mid + 1, r, ql, qr, v);
    tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
}

void swap_pos(int i, int j) {
    update(1, 1, n, min(i, p[i]), max(i, p[i]), -1);
    update(1, 1, n, min(j, p[j]), max(j, p[j]), -1);

    swap(p[i], p[j]);

    update(1, 1, n, min(i, p[i]), max(i, p[i]), 1);
    update(1, 1, n, min(j, p[j]), max(j, p[j]), 1);
}

void testcase() {
    cin >> n;

    bool sorted = true;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];

        pos[p[i]] = i;
        if (i != p[i]) sorted = false;
    }

    if (sorted == true) {
        cout << n - 2 << '\n';
        return;
    }

    int ma = 0, mi = n + 1;
    for (int i = 1; i <= n; i++) {
        L[i] = L[i - 1];
        if (ma < p[i]) ma = p[i], L[i] = i;
    }
    for (int i = n; i >= 1; i--) {
        R[i] = R[i + 1];
        if (mi > p[i]) mi = p[i], R[i] = i;
    }

    build(1, 1, n);
    for (int i = 1; i <= n; i++) update(1, 1, n, min(i, p[i]), max(i, p[i]), 1);

    int ans = 0;
    for (int i = 2; i < n; i++) {
        swap_pos(L[i - 1], R[i + 1]);
        if (tree[1].mi == 1) ans = max(ans, tree[1].cnt);
        swap_pos(L[i - 1], R[i + 1]);
    }
    for (int i = 1; i <= n; i++) {
        swap_pos(i, pos[i]);
        if (tree[1].mi == 1) ans = max(ans, tree[1].cnt);
        swap_pos(i, pos[i]);
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int t = 1;
    cin >> t;

    while (t--) testcase();
    return 0;
}