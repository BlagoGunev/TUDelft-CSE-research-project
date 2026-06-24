#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
const int maxn = 2e5 + 5;
LL inv[maxn], fac[maxn], facinv[maxn];
char s[maxn];
int st[maxn], en[maxn];
LL c(int n, int m)
{
    LL ret = fac[n] * facinv[n - m] % MOD * facinv[m] % MOD;
    return ret;
}
int main()
{
    inv[0] = inv[1] = fac[0] = fac[1] = facinv[0] = facinv[1] = 1;
    for (int i = 2; i < maxn; i++)
    {
        inv[i]  = (MOD - MOD / i) * inv[MOD % i] % MOD;
        facinv[i] = facinv[i - 1] * inv[i] % MOD;
        fac[i] = fac[i - 1] * i % MOD;
    }
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    for (int i = 1; i <= n; i++)
        if (s[i] == '(') st[i] = st[i - 1] + 1;
        else st[i] = st[i - 1];
    for (int i = n; i >= 1; i--)
        if (s[i] == ')') en[i] = en[i + 1] + 1;
        else en[i] = en[i + 1];
    LL ans = 0;
    for (int i = 1; i <= n; i++)
        if (s[i] == '(')
        {
            int mx = min(st[i], en[i + 1]);
            if (mx == 0) continue;
            ans+=c(st[i]-1+en[i+1],st[i]);
            ans%=MOD;
            /*
            for (int j = 0; j <= mx - 1; j++)
            {
                ans += c(st[i] - 1, j) * c(en[i + 1], j + 1);
                ans %= MOD;
            }
            */
        }
    printf("%lld\n", ans);
}