#pragma GCC optimize("Ofast", "inline")
#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
const int N = 200005, M = 31, K = 20, mod = 998244353;
// const int N = 1010, M = 31, mod = 998244353;
int n, res;
int a[N], b[M], ix[M];
int apr[N][M];
struct node{
    int l, x, nx;
    int L, R;
    node(int _l = 0, int _x = 0, int _nx = 0)
        : l(_l), x(_x), nx(_nx) {}
};
vector<node> v[N];
int hsh[N * M], t;
void Add(int &x, int y) {
    x += y;
    if (x >= mod) x -= mod;
}
vector<pii> id[N * M];
struct BIT{
    int c[N];
    void add(int x, int k) {
        ++x;
        for (; x <= n + 1; x += -x & x) Add(c[x], k);
        return;
    }
    int qr(int x) {
        int k = 0; ++x;
        for (; x; x -= -x & x) Add(k, c[x]);
        return k;
    }
    int qr(int l, int r) {return (qr(r) - qr(l - 1) + mod) % mod;}
} zq;

int main() {
    int tm1 = clock();
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
        for (int j = 0; j < M; ++j) apr[i][j] = apr[i - 1][j];
        for (int j = 0; j < M; ++j) if (a[i] & (1 << j)) apr[i][j] = i;
    }
    for (int u = 1; u <= n; ++u) {
        for (int j = 0; j < M; ++j) b[j] = apr[u][j], ix[j] = j;
        sort(ix, ix + M, [=](int x, int y) -> bool{return b[x] > b[y];});
        for (int i = 0, res = 0; i < M;) {
            if (b[ix[i]] == 0) break;
            int j = i;
            while (j < M && b[ix[j]] == b[ix[i]]) res |= 1 << ix[j], ++j;
            v[u].emplace_back(b[ix[i]], res, 0), i = j, hsh[++t] = res;
        }
        if (v[u].empty()) v[u].emplace_back(u, a[u], 0), hsh[++t] = a[u];
    }
    sort(hsh + 1, hsh + t + 1), t = unique(hsh + 1, hsh + t + 1) - (hsh + 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < v[i].size(); ++j) {
            v[i][j].nx = lower_bound(hsh + 1, hsh + t + 1, v[i][j].x) - hsh;
            v[i][j].L = (j + 1 == v[i].size() ? 0 : v[i][j + 1].l), v[i][j].R = v[i][j].l - 1;
            id[v[i][j].nx].emplace_back(i, j);
        }
    }
    zq.add(0, 1);
    for (int o = 1; o <= t; ++o) {
        for (int oo = 0; oo < id[o].size(); ++oo) {
            int i = id[o][oo].first, j = id[o][oo].second; 
            zq.add(i, zq.qr(v[i][j].L, v[i][j].R));
        }
    }
    printf("%d\n", zq.qr(n, n));
    cerr << "use " << (clock() - tm1) * 1.0 / CLOCKS_PER_SEC << " s\n";
    return 0;
}