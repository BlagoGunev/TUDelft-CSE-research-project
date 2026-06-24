#include <bits/stdc++.h>

#define ls(x) ((x) << 1)
#define rs(x) (ls(x) | 1)
#define mid ((l + r) >> 1)
#define lch ls(x), l, mid
#define rch rs(x), mid + 1, r

using LL = long long;

const int max_N = (int) 3e5 + 21;

int n, a, d[max_N], c[max_N];

LL seg[2][max_N << 2], sum[max_N], dd[max_N], ans;

int st[max_N], top, L[max_N], R[max_N];

void build(int x, int l, int r) {
    if (l == r) {
        seg[0][x] = seg[1][x] = sum[l];
    } else {
        build(lch), build(rch);
        seg[0][x] = std::min(seg[0][ls(x)], seg[0][rs(x)]);
        seg[1][x] = std::max(seg[1][ls(x)], seg[1][rs(x)]);
    }
}

int ql, qr;

LL qa[2];

void query(int x, int l, int r) {
    if (ql <= l && r <= qr) {
        qa[0] = std::min(qa[0], seg[0][x]);
        qa[1] = std::max(qa[1], seg[1][x]);
    } else {
        if (ql <= mid) query(lch);
        if (qr >  mid) query(rch);
    }
}

int main() {
    scanf("%d%d", &n, &a);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", d + i, c + i);
        ans = std::max(ans, 1LL * a - c[i]);
        sum[i] = sum[i - 1] + a - c[i];
        if (i > 1) {
            dd[i - 1] = 1LL * (d[i] - d[i - 1]) * (d[i] - d[i - 1]);
        }
    }
    for (int i = 1; i < n; ++i) {
        while (top && dd[st[top]] <= dd[i]) {
            int j = st[top--];
            R[j] = i - 1;
        }
        L[i] = st[top] + 1;
        R[i] = n - 1;
        st[++top] = i;
    }
    build(1, 0, n);
    for (int i = 1; i < n; ++i) {
        LL ret = 0;
        ql = L[i] - 1, qr = i - 1, qa[0] = LLONG_MAX;
        query(1, 0, n);
        ret -= qa[0];
        ql = i + 1, qr = R[i] + 1, qa[1] = LLONG_MIN;
        query(1, 0, n);
        ret += qa[1];
        ret -= dd[i];
        ans = std::max(ans, ret);
    }
    printf("%lld\n", ans);
}