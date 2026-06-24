#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 2e5 + 7;
int n, t;
char a[maxn];
int ans = 2147483647;
void xsearch(char dep, int now, int l, int r)
{
    if (l == r)
    {
        if (a[l] != dep) ++now;
        if (now < ans) ans = now;
        return;
    }
    int mid = (l + r) >> 1, x = 0, y = 0;
    for (int i = l; i <= mid; ++i)
        if (a[i] != dep) ++x;
    for (int i = mid + 1; i <= r; ++i)
        if (a[i] != dep) ++y;
    if (now + x < ans) xsearch(dep + 1, now + x, mid + 1, r);
    if (now + y < ans) xsearch(dep + 1, now + y, l, mid);
    return;
}
int main()
{
    for (scanf("%d", &t); t--;)
    {
        ans = 2147483647;
        scanf("%d", &n);
        scanf("%s", a + 1);
        xsearch('a', 0, 1, n);
        printf("%d\n", ans);
    }
    return 0;
}