#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;
const long long MAXANS18 = (long long) 1000000000000000000;
const long long MAXANS17 = (long long) 100000000000000000;
const long long MAXANS9 = (long long) 1000000000;
char st[MAXN];
long long dp[MAXN];

int GetLen(long long x)
{
    int ret = 0;
    while(x) ret++, x /= 10;
    if(ret == 0) ret = 1;
    return ret;
}

long long GetNum(int l, int r)
{
    long long ret = 0;

    for(int i = l; i <= r; i++)
    {
        if(ret > MAXANS17 || ret == MAXANS17 && st[i] != '0') return LLONG_MAX;
        ret = ret * 10 + st[i] - '0';
    }

    if(r > l && st[l] == '0') return -1;

    return ret;
}

long long MulAdd(long long a, long long b, long long c)
{
    if((double) a * b + c > MAXANS18) return LLONG_MAX;
    else return a * b + c;
}

int main()
{
    int m;
    long long n;

    // freopen("D:\\1.in", "r", stdin);
    // freopen("D:\\1.out", "w", stdout);

    scanf("%lld%s", &n, st);
    m = strlen(st);

    if(m == 1 && st[0] == '0')
    {
        printf("0\n");
        return 0;
    }

    dp[0] = st[0] - '0';
    for(int i = 1; i < m; i++)
    {
        dp[i] = LLONG_MAX;
        for(int j = i; j >= 0; j--)
        {
            long long now = GetNum(j, i);
            if(now >= n) break;
            if(now < 0) continue;
            if(j > 0) dp[i] = min(dp[i], MulAdd(dp[j - 1], n, now));
            else dp[i] = min(dp[i], now);
        }
    }
    printf("%lld\n", dp[m - 1]);

    return 0;
}