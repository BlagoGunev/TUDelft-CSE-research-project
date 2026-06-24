#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 100005;
LL x;
int n, m;
int cnt[MAXN];
int main()
{
    scanf("%lld%d", &x, &n);
    if (x >= n)
    {
        for (int i = 62; i >= 0; i --)
            if (x >> i & 1)
            {
                cnt[62 - i]++;
                n--;
                m = 62 - i;
            }
    }
    else
    {
        cnt[62] = x;
        n -= x;
        m = 62;
    }
    if (n < 0) printf("No\n");
    else
    {
        for (int i = 0; cnt[i] <= n; m = max(m, ++i))
        {
            cnt[i + 1] += 2 * cnt[i];
            n -= cnt[i];
            cnt[i] = 0;
        }
        while (n)
        {
            cnt[m]--;
            cnt[++m] += 2;
            n--;
        }
        printf("Yes\n");
        for (int i = 0; i <= m; i ++)
            for (int j = 1; j <= cnt[i]; j ++)
                printf("%d ", 62 - i);
        printf("\n");
    }
    return 0;
}