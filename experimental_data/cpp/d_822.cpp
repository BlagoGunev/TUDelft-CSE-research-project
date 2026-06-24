#include <cstdio>
#include <algorithm>
const int MAXN = 5000005;
const int MOD = 1000000007;
int prime[MAXN], primeCnt;
long long f[MAXN];
bool notPrime[MAXN];
void linearShaker() {
    notPrime[1] = notPrime[0] = true;
    for (int i = 2; i < MAXN; i++) {
        if (!notPrime[i]) {
            prime[primeCnt++] = i;
            f[i] = ((long long) i * (i - 1) / 2) % MOD;
        }
        for (int j = 0; j < primeCnt && i * prime[j] < MAXN; j++) {
            notPrime[i * prime[j]] = true;
            f[i * prime[j]] = (f[i] + (i * f[prime[j]] % MOD)) % MOD;
            if (i % prime[j] == 0) break;
        }
    }
}
int main() {
    linearShaker();
    int t, l, r;
    scanf("%d %d %d", &t, &l, &r);
    long long ans = 0, tp = 1;
    for (int i = l; i <= r; i++) {
        (ans += (tp * f[i])) %= MOD;
        (tp *= t) %= MOD;
    }
    printf("%lld\n", ans);
    return 0;
}