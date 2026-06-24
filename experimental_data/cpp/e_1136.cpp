#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct node {
    int L, R;
    ll v;
    node(int L) : L(L) {}
    node(int L, int R, ll v) : L(L), R(R), v(v) {}
    bool operator<(const node &p) const {
        return L < p.L;
    }
};

ll seg[400005];
ll add[400005];

void lazy(int i, int s, int m, int e) {
    seg[i * 2] += add[i] * (m - s + 1);
    add[i * 2] += add[i];
    seg[i * 2 + 1] += add[i] * (e - m);
    add[i * 2 + 1] += add[i];
    add[i] = 0;
}

void update(int i, int s, int e, int x, int y, ll v) {
    if (e < x || y < s) return;
    if (x <= s && e <= y) {
        seg[i] += v * (e - s + 1);
        add[i] += v;
        return;
    }
    int m = (s + e) / 2;
    lazy(i, s, m, e);
    update(i * 2, s, m, x, y, v);
    update(i * 2 + 1, m + 1, e, x, y, v);
    seg[i] = seg[i * 2] + seg[i * 2 + 1];
}

ll sum(int i, int s, int e, int x, int y) {
    if (e < x || y < s) return 0;
    if (x <= s && e <= y) return seg[i];
    int m = (s + e) / 2;
    lazy(i, s, m, e);
    return sum(i * 2, s, m, x, y) + sum(i * 2 + 1, m + 1, e, x, y);
}

ll K[100005];
int main() {
    int n;
    scanf("%d", &n);
    set<node> S;
    for (int i = 1; i <= n; i++) {
        int a;
        scanf("%d", &a);
        update(1, 1, n, i, i, a);
        S.emplace(i, i, a);
    }
    for (int i = 2; i <= n; i++) {
        scanf("%lld", K + i);
        K[i] += K[i - 1];
    }
    int q;
    scanf("%d", &q);
    for (int it = 0; it < q; it++) {
        char c[10];
        int x, y;
        scanf("%s%d%d", c, &x, &y);
        if (c[0] == '+') {
            if (y == 0) continue;
            auto i = prev(S.upper_bound(node(x)));
            int L = i->L, R = i->R;
            ll v = i->v;
            S.erase(i);
            if (L < x) S.emplace(L, x - 1, v);
            update(1, 1, n, x, R, y);
            v += y;
            i = S.upper_bound(node(x));
            auto f = i;
            while (i != S.end()) {
                if (v + K[i->L] - K[L] <= i->v) break;
                update(1, 1, n, i->L, i->R, v + K[i->L] - K[L] - i->v);
                R = i->R;
                ++i;
            }
            S.erase(f, i);
            S.emplace(x, R, v + K[x] - K[L]);
        }
        else printf("%lld\n", sum(1, 1, n, x, y));
    }
}