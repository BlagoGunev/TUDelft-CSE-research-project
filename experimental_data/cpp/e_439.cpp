#include <cstdio>
#include <vector>
using namespace std;
const int MOD = 1000000007;
int fact[100001];
int invfact[100001];
int modular_binom(int n, int k) {
    if (n < 0 || k < 0 || k > n) return 0;
    // n!/(k!(n-k)!)
    long long res = fact[n];
    res *= invfact[k]; res %= MOD;
    res *= invfact[n-k]; res %= MOD;
    return res;
}
int powermod(int b, int e) {
    long long res = 1;
    long long pwr = b;
    while (e) {
        if (e&1) {
            res *= pwr; res %= MOD;
        }
        e >>= 1;
        pwr *= pwr; pwr %= MOD;
    }
    return res;
}
void compute_factorials() {
    fact[0] = 1;
    for (int i = 1; i <= 100000; i++) {
        fact[i] = (fact[i-1]*(long long)i)%MOD;
    }
    // invert
    invfact[100000] = powermod(fact[100000], MOD-2);
    for (int i = 100000; i > 0; i--) {
        invfact[i-1] = (invfact[i]*(long long)i)%MOD;
    }
}
int main() {
    compute_factorials();
    int q; scanf("%d", &q);
    while (q--) {
        int n, f; scanf("%d %d", &n, &f);
        // find all distinct prime factors
        vector<int> primes;
        int x = 2;
        int m = n;
        while (x*x <= m) {
            if (m%x == 0) {
                primes.push_back(x);
                while (m%x == 0) m /= x;
            }
            x++;
        }
        if (m > 1) primes.push_back(m);
        long long res = 0;
        for (int bitmask = 0; bitmask < (1<<primes.size()); bitmask++) {
            int d = 1; int mobius = 1;
            for (int i = 0; i < primes.size(); i++) {
                if (bitmask&(1<<i)) {
                    d *= primes[i];
                    mobius *= -1;
                }
            }
            res += modular_binom(n/d-1, f-1) * mobius;
            res %= MOD;
        }
        if (res < 0) res += MOD;
        printf("%d\n", (int)res);
    }
}