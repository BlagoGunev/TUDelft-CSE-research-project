#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int mod = 1e9+7;
const int maxn = 1e5+11;
int n, k, a[maxn], b[maxn];
LL p[11];
LL cal(LL num, LL a) {
    return num / a + 1;
}
int main()
{
    p[0] = 1;
    for (int i=1; i<=10; ++i) {
        p[i] = p[i-1] * 10 % mod;
    }
    scanf ("%d%d", &n, &k);
    int m = n / k;
    for (int i=1; i<=m; ++i) {
        scanf ("%d", &a[i]);
    }
    for (int i=1; i<=m; ++i) {
        scanf ("%d", &b[i]);
    }
    LL ans = 1;
    for (int i=1; i<=m; ++i) {
        LL tmp = cal(p[k]-1, a[i]) - cal((LL)(b[i]+1)*p[k-1]-1, a[i]);
        if (b[i] != 0) {
            tmp += cal(b[i]*p[k-1]-1, a[i]);
        }
        tmp %= mod;
        ans = ans * tmp % mod;
    }
    printf ("%I64d\n", ans);
    return 0;
}