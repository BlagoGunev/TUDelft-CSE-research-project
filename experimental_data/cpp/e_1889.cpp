// LUOGU_RID: 152157734
#include <bits/stdc++.h>
using namespace std;
int read() {
    int x = 0, f = 1; char c = getchar();
    while (c < '0' || c > '9') {if (c == '-') f = -f; c = getchar();}
    while (c >= '0' && c <= '9') {x = x * 10 + (c ^ 48); c = getchar();}
    return x * f;
}
const int N = 1e5 + 5, mod = 1e9 + 7;
int n, tot, cnt, ans, T, edg_cnt;
int num[2][N][17], fa[2][N][17], dep[2][N];
int a[N * 34], siz[N * 34], dfn[N * 34], low[N * 34], vis[N * 34], out[N * 34], bel[N * 34], head[N * 34];
vector <int> e[2][N];
struct Edge {
    int y, nxt;
} E[N * 134];
void addedge(int u, int v) {
    E[++edg_cnt].y = v;
    E[edg_cnt].nxt = head[u];
    head[u] = edg_cnt;
}
void tarjan(int x) {
    static int S[N * 34];
    static int tp = 0;
    S[++tp] = x; vis[x] = 1;
    dfn[x] = low[x] = ++T;
    for (int i = head[x]; i; i = E[i].nxt) {
        int y = E[i].y;
        if (!dfn[y]) {
            tarjan(y);
            low[x] = min(low[x], low[y]);
        }
        else if (vis[y]) low[x] = min(low[x], dfn[y]);
    }
    if (dfn[x] == low[x]) {
        int y; ++cnt;
        do {
            y = S[tp--];
            siz[cnt] += a[y]; vis[y] = 0;
            bel[y] = cnt;
        } while (x ^ y) ;
    }
}
void dfs(int x, int dad, int op) {
    fa[op][x][0] = dad;
    dep[op][x] = dep[op][dad] + 1;
    for (int y : e[op][x]) {
        if (y == dad) continue;
        dfs(y, x, op);
    }
}
void add(int u, int x, int y, int op) {
    if (dep[op][x] < dep[op][y]) swap(x, y);
    for (int i = 16; ~i; i--)
        if (dep[op][fa[op][x][i]] >= dep[op][y]) {
            addedge(u, num[op][x][i]);
            x = fa[op][x][i];
        }
    if (x == y) return;
    for (int i = 16; ~i; i--)
        if (fa[op][x][i] ^ fa[op][y][i]) {
            addedge(u, num[op][x][i]);
            addedge(u, num[op][y][i]);
            x = fa[op][x][i];
            y = fa[op][y][i];
        }
    addedge(u, num[op][x][0]);
    addedge(u, num[op][y][0]);
}
void Solve() {
    n = read(); tot = cnt = T = edg_cnt = 0;
    for (int i = 1; i <= n; i++) {
        e[0][i].clear();
        e[1][i].clear();
    }
    for (int j = 0; j < 2; j++)
        for (int i = 1; i < n; i++) {
            int u = read(), v = read();
            e[j][u].push_back(v);
            e[j][v].push_back(u);
        }
    dfs(1, 0, 0);
    dfs(1, 0, 1);
    for (int op = 0; op < 2; op++)
        for (int j = 1; j <= 16; j++)
            for (int i = 1; i <= n; i++)
                fa[op][i][j] = fa[op][fa[op][i][j - 1]][j - 1];
    for (int op = 0; op < 2; op++)
        for (int i = 1; i <= n; i++)
            for (int j = 0; j <= 16; j++) {
                if (!fa[op][i][j]) break;
                num[op][i][j] = ++tot;
            }
    for (int i = 1; i <= tot; i++) a[i] = dfn[i] = low[i] = siz[i] = out[i] = head[i] = 0;
    for (int x = 2; x <= n; x++)
        for (int op = 0; op < 2; op++)
            add(num[op][x][0], x, fa[op][x][0], op ^ 1);
    for (int op = 0; op < 2; op++)
        for (int x = 2; x <= n; x++) {
            for (int i = 1; i <= 16; i++) {
                if (!fa[op][x][i]) break;
                int u = num[op][x][i], v = num[op][x][i - 1];
                addedge(u, v);
                v = num[op][fa[op][x][i - 1]][i - 1];
                addedge(u, v);
            }
            a[num[op][x][0]] = 1;
        }
    for (int i = 1; i <= tot; i++) if (!dfn[i]) tarjan(i);
    for (int x = 1; x <= tot; x++)
        for (int i = head[x]; i; i = E[i].nxt) if (bel[x] ^ bel[E[i].y])
            out[bel[x]] = 1;
    int p = cnt;
    for (int i = 1; i <= cnt; i++) if ((siz[i] <= 2 && !out[i]) || !siz[i]) p--;
    ans = 1;
    for (int i = 1; i <= p; i++) ans = 2 * ans % mod;
    printf("%d\n", ans);
}
int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
    int _ = read();
    while (_--) Solve();
    return 0;
}