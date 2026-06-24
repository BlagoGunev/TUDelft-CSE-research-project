#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

template<class T>inline void Read(T &x)
{
    int f = 1;
    char t = getchar();
    while (t < '0' || t > '9') {
        if (t == '-') f = -1;
        t = getchar();
    }
    x = 0;
    while (t >= '0' && t <= '9') {
        x = x * 10 + t - '0';
        t = getchar();
    }
    x *= f;
}

const int maxn = 100005;

#define A first
#define B second

int n, f[maxn];
pair<int, int> g[maxn];

void input()
{
    Read(n);
    for (register int i = 1; i <= n; i++) {
        Read(g[i].first), Read(g[i].second);
    }
    sort(g + 1, g + n + 1);
}

void solve()
{
    int ans = 0x3f3f3f3f;
    for (register int i = 1; i <= n; i++) {
        int l = g[i].A - g[i].B;
        int re = lower_bound(g + 1, g + n + 1, make_pair(l, 0)) - g - 1;
        if (re < i) {
            f[i] = f[re] + (i - re - 1);
        } else {
            f[i] = i - 1;
        }
    }
    for (register int i = 1; i <= n; i++) {
        ans = min(ans, f[i] + n - i);
    }
    printf("%d\n", ans);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    input();
    solve();

#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}