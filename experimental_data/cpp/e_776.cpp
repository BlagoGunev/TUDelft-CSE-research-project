#include<bits/stdc++.h>
using namespace std;
#define LL long long
const LL mod = 1e9 + 7;
LL n, k;
LL geteuler(LL x)
{
    LL ans = x;
    for (LL i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            ans = ans / i * (i - 1);
            while (x % i == 0) x /= i;
        }
    }
    if (x > 1) ans = ans / x * (x - 1);
    return ans;
}
int main()
{
    LL t = geteuler(10);
    scanf("%lld%lld", &n, &k);
    LL ans = n;
    for (int i = 1; i <= k; i++)
    {
        if (i % 2 == 0) continue;
        ans = geteuler(ans);
        if (ans == 1) break;
    }
    printf("%lld\n", ans % mod );
    return 0;
}