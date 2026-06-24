#include <cstdio>
#include <cctype>
#include <cassert>
#include <cstring>
#include <iostream>
#include <algorithm>
#define R register
#define ll long long
using namespace std;
const int N = 1100, M = 2520;

int n, q, val[N], num[N], to[N][12], vis[N][M], ans[N][M], stck[N * M], top, instck[N * M], cnt[N];

template <class T> inline void read(T &x) {
    x = 0;
    char ch = getchar(), w = 0;
    while (!isdigit(ch))
        w = (ch == '-'), ch = getchar();
    while (isdigit(ch))
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    x = w ? -x : x;
    return;
}

inline int addMod(int x, int y) {
    return (x += y) >= M ? x - M : x;
}

inline int ind(int x, int y) {
    return x * M + y;
}

int dfs(int now, int c) {
    c = addMod(c, val[now]);
    if (vis[now][c]) return ans[now][c];
    int k = ind(now, c);
    if (instck[k]) {
        int ret = 0, w;
        for (R int i = top; i; --i) {
            if (!cnt[w = stck[i] / M])
                ++ret;
            ++cnt[w];
            if (stck[i] == k) {
                vis[now][c] = 1;
                for (R int j = top; j >= i; --j)
                    cnt[stck[j] / M] = 0;
                return ans[now][c] = ret;
            }
        }
    }
    stck[++top] = k, instck[k] = 1;
    ans[now][c] = dfs(to[now][c % num[now]], c);
    --top, instck[k] = 0, vis[now][c] = 1;
    return ans[now][c];
}

int main() {
    int x, y;
    read(n);
    for (R int i = 1; i <= n; ++i)
        read(val[i]), val[i] = (val[i] % M + M) % M;
    for (R int i = 1; i <= n; ++i) {
        read(num[i]);
        for (R int j = 0; j < num[i]; ++j)
            read(to[i][j]);
    }
    read(q);
    while (q--) {
        read(x), read(y), y = (y % M + M) % M;
        printf("%d\n", dfs(x, y));
    }
    return 0;
}