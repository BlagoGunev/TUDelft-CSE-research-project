#include <bits/stdc++.h>
#define ll long long
using namespace std;

inline ll read()
{
    ll x = 0, f = 1;
    char ch = getchar();
    for (; ch < '0' || ch > '9'; ch = getchar())
        if (ch == '-')
            f = -1;
    for (; ch >= '0' && ch <= '9'; ch = getchar())
        x = x * 10 + ch - '0';
    return x * f;
}

const ll N = 2e5 + 5;

ll a[N], sum[N], ans[N];

int main()
{
    ll n = read(), k = read();
    for (ll i = 1; i <= n; i++)
        a[i] = read();
    sort(a + 1, a + n + 1);
    for (ll i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + a[i];
        ans[i] = sum[i];
        if (i > k)
            ans[i] += ans[i - k];
    }
    for (ll i = 1; i <= n; i++)
        printf("%I64d ", ans[i]);
    return 0;
}