#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') fu = -1; c = getchar(); }
    while(c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if(x < 0) putchar('-'), x = -x;
    if(x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const ll INF = 1e18;
const int N = 1e6 + 5;

struct ele {
    int id; ll val;
    ele (int a = 0, ll b = 0) : id(a), val(b) {}
    bool operator < (const ele A) const {
        if(val != A.val) return val < A.val;
        return id > A.id;
    }
};

struct node_t { int l, r; ll tag; ele maxn; } p[N << 2];

vector <pii> g[N];
int b[N], x[N], y[N], val[N];
ll maxn = 0;
int n, big, l = 2e9, r = 2e9;

void update(int u) { p[u].maxn = max(p[u << 1].maxn, p[u << 1 | 1].maxn); }

void addtag(int u, ll x) {
    p[u].maxn.val += x;
    p[u].tag += x;
}

void pushdown(int u) {
    if(p[u].tag) {
        addtag(u << 1, p[u].tag);
        addtag(u << 1 | 1, p[u].tag);
        p[u].tag = 0;
    }
}

void build(int u, int l, int r) {
    p[u].l = l; p[u].r = r;
    if(l == r) {
        p[u].maxn = ele(l, b[l]);
        return;
    }
    int mid = (l + r) >> 1;
    build(u << 1, l, mid); build(u << 1 | 1, mid + 1, r);
    update(u);
}

void change(int u, int l, int r, int x) {
    if(l <= p[u].l && p[u].r <= r) {
        addtag(u, x);
        return;
    }
    pushdown(u);
    int mid = (p[u].l + p[u].r) >> 1;
    if(mid >= l) change(u << 1, l, r, x);
    if(mid + 1 <= r) change(u << 1 | 1, l, r, x);
    update(u);
}

ele query(int u, int l, int r) {
    if(l <= p[u].l && p[u].r <= r) return p[u].maxn;
    int mid = (p[u].l + p[u].r) >> 1; ele ans = ele(0, -INF);
    pushdown(u);
    if(mid >= l) ans = max(ans, query(u << 1, l, r));
    if(mid + 1 <= r) ans = max(ans, query(u << 1 | 1, l, r));
    return ans;
}

int main() {
    read(n);
    for(register int i = 1; i <= n; i++) {
        read(x[i]); read(y[i]); read(val[i]);
        b[i * 2 - 1] = x[i]; b[i * 2] = y[i];
    }
    sort(b + 1, b + 2 * n + 1); big = unique(b + 1, b + 2 * n + 1) - b - 1;
    build(1, 1, big);
    for(register int i = 1; i <= n; i++) {
        x[i] = lower_bound(b + 1, b + big + 1, x[i]) - b;
        y[i] = lower_bound(b + 1, b + big + 1, y[i]) - b;
        if(x[i] > y[i]) swap(x[i], y[i]);
        g[y[i]].push_back(make_pair(x[i], val[i]));
    }
    for(register int i = 1; i <= big; i++) {
        for(register int j = 0; j < (int)g[i].size(); j++) {
            change(1, 1, g[i][j].first, g[i][j].second);
        }
        ele res = query(1, 1, i);
        if(res.val - b[i] > maxn) {
            maxn = res.val - b[i];
            l = res.id; r = i;
        }
    }
    print(maxn, '\n');
    if(maxn != 0) print(b[l], ' '), print(b[l], ' '), print(b[r], ' '), print(b[r], '\n');
    else print(l, ' '), print(l, ' '), print(l, ' '), print(l, '\n');
    return 0;
}