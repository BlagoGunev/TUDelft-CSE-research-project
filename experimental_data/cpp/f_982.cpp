#include <bits/stdc++.h>
#define N 100005
#define M 500005
using namespace std;
int n, m, ans, res, flag[N], tag[N], check[N], sum[N];
int k, la[N], ff[M], c[N], tot, p[N], pre[N], pos[N];
struct node {
    int a, b;
} e[M];
vector<vector<int>> g;

void add(int a, int b) {
    e[++k] = (node){a, b};
    ff[k] = la[a];
    la[a] = k;
    g[a].push_back(b);
}

// find a cycle and store it in p in backwards order
void dfs1(int x) {
    if (tot || check[x])
        return;
    c[x] = -1;
    for (auto it = g[x].rbegin(); it != g[x].rend() && !tot; ++it) {
        int v = *it;
        // int v = e[a].b;
        if (check[v])
            continue;
        if (c[v] == -1) {
            while (x != v)
                p[++tot] = x, x = pre[x];
            p[++tot] = v;
            return;
        }
        if (!c[v])
            pre[v] = x, dfs1(v);
    }
    c[x] = 1;
}

void dfs2(int S, int x) {
    if (check[x])
        return;
    flag[x] = 1;
    for (int v : g[x]) {
        if (check[v])
            continue;
        if (tag[v]) {
            if (tag[x] && tag[v])
                continue;
            if (pos[S] >= pos[v])
                continue;
            res++;
            sum[1]++;
            sum[pos[S] + 1]--;
            sum[pos[v]]++;
            sum[tot + 1]--;
        } else if (!flag[v])
            dfs2(S, v);
    }
}
void dfs3(int S, int x) {
    if (check[x])
        return;
    flag[x] = 1;
    for (int a = la[x]; a; a = ff[a]) {
        int v = e[a].b;
        if (check[v])
            continue;
        if (tag[v]) {
            if (tag[x] && tag[v])
                continue;
            if (pos[S] < pos[v])
                continue;
            res++;
            sum[pos[v]]++;
            sum[pos[S] + 1]--;
        } else if (!flag[v])
            dfs3(S, v);
    }
}
int solve() {
    int po = 0;
    res = 0;
    tot = 0;
    memset(c, 0, sizeof(c));
    for (int i = 1; i <= n && !tot; i++)
        if (!c[i])
            dfs1(i);
    if (!tot)
        return 0;
    reverse(p + 1, p + tot + 1);
    memset(tag, 0, sizeof(tag));
    memset(pos, 0, sizeof(pos));
    memset(sum, 0, sizeof(sum));
    for (int i = 1; i <= tot; i++) {
        tag[p[i]] = 1;
        pos[p[i]] = i;
    }
    memset(flag, 0, sizeof(flag));

    for (int i = 1; i <= tot; i++)
        dfs2(p[i], p[i]);
    memset(flag, 0, sizeof(flag));
    for (int i = tot; i; i--)
        dfs3(p[i], p[i]);
    for (int i = 1; i <= tot; i++) {
        sum[i] += sum[i - 1];
        if (sum[i] == res) {
            po = p[i];
            break;
        }
    }
    check[po] = 1;
    return po;
}
int main() {
    int a, b;
    scanf("%d%d", &n, &m);
    g.resize(n + 1);
    for (int i = 1; i <= m; i++)
        scanf("%d%d", &a, &b), add(a, b);
    ans = solve();
    if (!ans) {
        printf("-1\n");
        return 0;
    }
    if (!solve())
        printf("%d\n", ans);
    else
        printf("-1\n");
    return 0;
}