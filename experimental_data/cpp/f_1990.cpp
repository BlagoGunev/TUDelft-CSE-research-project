#include <bits/stdc++.h>

using LL = long long;

constexpr int N = 200'010;

struct Info {
    LL mx, sum;
    int pos, lst;
}v[N << 2];

Info operator+(const Info &a, const Info &b) {
    return {
        std::max(a.mx, b.mx),
        a.sum + b.sum,
        a.mx > b.mx ? a.pos : b.pos,
        std::max(a.lst, b.lst)
    };
}

int n, q;
std::pair<LL, int> a[N];

void build(int x, int l, int r) {
    if (l == r) {
        v[x] = {a[l].first, a[l].first, l, a[l].second};
        return;
    }
    int mid = (l + r) / 2;
    build(x * 2, l, mid);
    build(x * 2 + 1, mid + 1, r);
    v[x] = v[x * 2] +  v[x * 2 + 1];
}

void modify(int x, int l, int r, int p) {
    if (l == r) {
        v[x] = {a[l].first, a[l].first, l, a[l].second};
        return;
    }
    int mid = (l + r) / 2;
    if (p <= mid) {
        modify(x * 2, l, mid, p);
    } else {
        modify(x * 2 + 1, mid + 1, r, p);
    }
    v[x] = v[x * 2] +  v[x * 2 + 1];
}

Info query(int x, int l, int r, int ql, int qr) {
    if (l == ql && r == qr) {
        return v[x];
    }
    int mid = (l + r) / 2;
    if (qr <= mid) {
        return query(x * 2, l, mid, ql, qr);
    }
    if (ql > mid) {
        return query(x * 2 + 1, mid + 1, r, ql, qr);
    }
    return query(x * 2, l, mid, ql, mid) + query(x * 2 + 1, mid + 1, r, mid + 1, qr);
}

int cur;

std::map<std::pair<int, int>, std::pair<int, int>> mp;

int dc(int l, int r) {
    if (r - l + 1 < 3) {
        return -1;
    }
    Info t = query(1, 1, n, l, r);
    if (t.mx * 2 < t.sum) {
        mp[{l, r}] = {cur, r - l + 1};
        return r - l + 1;
    }
    if (mp.contains({l, r})) {
        auto [tt, vv] = mp[{l, r}];
        if (t.lst <= tt) {
            return vv;
        }
    }
    int tmp = std::max(dc(l, t.pos - 1), dc(t.pos + 1, r));
    mp[{l, r}] = {cur, tmp};
    return tmp;
}

void solve() {
    mp.clear();
    std::cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i].first;
        a[i].second = 0;
    }
    build(1, 1, n);
    cur = 0;
    while (q--) {
        cur++;
        LL o, x, y;
        std::cin >> o >> x >> y;
        if (o == 1) {
            std::cout << dc(x, y) << '\n';
        } else {
            a[x] = {y, cur};
            modify(1, 1, n, x);
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int _;
    std::cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}