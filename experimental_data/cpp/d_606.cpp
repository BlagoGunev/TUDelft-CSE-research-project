#include <stack>
#include <cstdio>
#include <vector>
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
const int maxm = 200005;

int n, m;
pair<pair<int, int>, int> e[maxn];
pair<int, int> ans[maxn];

void input()
{
    Read(n), Read(m);
    for (register int i = 1; i <= m; i++) Read(e[i].first.first), Read(e[i].first.second), e[i].second = i, e[i].first.second ^= 1;
}

void solve()
{
    int cnt = 1, lft = 0;
    int n1 = 3, n2 = 1;
    int a, b;
    sort(e + 1, e + m + 1);
    for (register int i = 1; i <= m; i++) {
        if (e[i].first.second == 0) {
            a = 1, b = ++cnt;
            lft += cnt - 2;
            ans[e[i].second] = make_pair(a, b);
        } else {
            if (lft > 0) {
                n2 ++;
                a = n2, b = n1;
                lft --;
                if (n2 + 1 == n1)
                    n1 ++, n2 = 1;
                ans[e[i].second] = make_pair(a, b);
            } else {
                cout << -1 << endl;
                return;
            }
        }
    }
    for (register int i = 1; i <= m; i++) printf("%d %d\n", ans[i].first, ans[i].second);
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