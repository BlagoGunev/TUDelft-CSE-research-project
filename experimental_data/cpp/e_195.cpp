#include <stdio.h>
#include <memory.h>
#include <algorithm>

using namespace std;

const int mod = 1000000007;

int r[100005] = { 0 };
int a[100005] = { 0 };

int f(int x)
{
    if (x == r[x]) {
        return x;
    }
    int root = f(r[x]);
    a[x] = (a[x] + a[r[x]]) % mod;
    return r[x] = root;
}

int main()
{
    int n = 0, i = 0, rv = 0, now = 0, ans = 0, m = 0, v = 0, x = 0;

    while (scanf("%d", &n) == 1) {
        for (i = 1; i <= n; i ++) {
            r[i] = i;
        }
        ans = 0;
        memset(a, 0, sizeof(a));
        for (i = 1; i <= n; i ++) {
            scanf("%d", &m);
            while (m --) {
                scanf("%d%d", &v, &x);
                rv = f(v);
                now = ((a[v] + x) % mod + mod) % mod;
                ans = (ans + now) % mod;
                r[rv] = i;
                a[rv] = now;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}