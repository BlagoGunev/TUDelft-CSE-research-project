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

int n, p[maxn], ans[maxn];

void input()
{
    Read(n);
    for (register int i = 1; i <= n; i++) Read(p[i]);
}

void solve()
{
    int mx = 0;
    for (register int i = 1; i <= n; i++) {
        ans[p[i]] = ans[p[i] - 1] + 1;
        mx = max(mx, ans[p[i]]);
    }
    cout << n - mx << endl;
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