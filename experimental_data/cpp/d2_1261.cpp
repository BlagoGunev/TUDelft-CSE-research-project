#include <stdio.h>
const int MOD = 998244353;
const int maxn = 200100;
int f[maxn], g[maxn], h[maxn];
int Pow(int a, int n){
    if(n == 0) return 1;
    else{
        int rnt = Pow(a, n / 2);
        rnt = 1ll * rnt * rnt % MOD;
        if(n & 1) rnt = 1ll * rnt * a % MOD;
        return rnt;
    }
};
int C(int m, int n){
    if(m > n) return 0;
    return 1ll * f[n] * g[m] % MOD * g[n - m] % MOD;
};
int main(){
    for(int i = 0; i < maxn; ++i) 
        f[i] = i == 0 ? 1 : 1ll * f[i - 1] * i % MOD;
    for(int i = 0; i < maxn; ++i)
        g[i] = i <= 1 ? 1 : 1ll * g[MOD % i] * (MOD - MOD / i) % MOD;
    for(int i = 1; i < maxn; ++i)
        g[i] = 1ll * g[i - 1] * g[i] % MOD;

    int n, K;
    scanf("%d%d", &n, &K);
    for(int i = 1; i <= n; ++i)
        scanf("%d", &h[i]);
    int m = 0;
    for(int i = 1; i <= n; ++i)
        m += h[i] != h[i % n + 1];

   //printf("m:%d\n", m);
    int pos = (m - 1) / 2, S = 0;
    for(int i = 0; i <= (m - 1) / 2; ++i)
        S = (S + C(i, m)) % MOD;

    int ans = 0;
    for(int k = 0, pw = 1; k < m; ++k, pw = 1ll * pw * (K - 2) % MOD){
        while(pos > (m - k - 1) / 2){
            S = (S - C(pos, m - k) + MOD) % MOD;
            --pos;
        }

        int coe = 1ll * C(k, m) * pw % MOD;
        ans = (ans + 1ll * coe * S % MOD) % MOD;

        S = 1ll * (S + C(pos, m - (k + 1))) % MOD * g[2] % MOD;
       //printf("k:%d coe:%d cur:%d coe*cur:%d\n", k, coe, cur, coe * cur);
    }

    ans = 1ll * ans * Pow(K, n - m) % MOD;

    printf("%d\n", ans);
    return 0;
}