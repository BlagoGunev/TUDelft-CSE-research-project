#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>

const int kN = 300000 + 5;
int n;
int ch[kN][26];
int effort[kN];
int sz[kN];

std::vector<std::pair<int&, int>> history;

void rollback(int h)
{
    while (history.size() > h) {
        history.back().first = history.back().second;
        history.pop_back();
    }
}

void modify(int &a, int b)
{
    history.emplace_back(a, a);
    a = b;
}

int merge(int a, int b)
{
    if (sz[a] < sz[b]) std::swap(a, b);
    if (b == 0) return a;
    modify(sz[a], 1);
    for (int c = 0; c < 26; ++ c) if (ch[a][c] || ch[b][c]) {
        modify(ch[a][c], merge(ch[a][c], ch[b][c]));
        modify(sz[a], sz[a] + sz[ch[a][c]]);
    }
    return a;
}

void dfs(int u, int depth)
{
    sz[u] = 1;
    for (int c = 0; c < 26; ++ c) if (ch[u][c]) {
        int v = ch[u][c];
        dfs(v, depth + 1);
        sz[u] += sz[v];
    }
    int p = 0;
    int h = history.size();
    for (int c = 0; c < 26; ++ c) if (ch[u][c]) {
        if (!p) p = ch[u][c];
        else {
            p = merge(p, ch[u][c]);
        }
    }
    if (p) effort[depth] += sz[u] - sz[p];
    rollback(h);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++ i) {
        int a, b;
        char buffer[2];
        scanf("%d%d%s", &a, &b, buffer);
        ch[a][buffer[0] - 'a'] = b;
    }
    dfs(1, 0);
    int p = std::max_element(effort, effort + n) - effort;
    printf("%d\n%d\n", n - effort[p], p + 1);
}