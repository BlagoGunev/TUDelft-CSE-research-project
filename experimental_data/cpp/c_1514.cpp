#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

#define LL long long

const int MOD = 1000000007;

int quick_pow(LL n, int m) {
    LL res = 1;
    while(m) {
        if (m&1)
            res = res * n % MOD;
        n = n * n % MOD;
        m >>= 1;
    }
    return res;
}

int C(int n, int m) {
    LL res = 1;
    for (int i = 1; i <= n; i++)
        res = res * i % MOD;
    for (int i = 1; i <= m; i++)
        res = res * quick_pow(i, MOD - 2) % MOD;
    for (int i = 1; i <= n - m; i++)
        res = res * quick_pow(i, MOD - 2) % MOD;
    return res;
}

int gcd(int m, int n) {
    int r = m % n;
    while (r) {
        m = n;
        n = r;
        r = m % n;
    }
    return n;
}

int main() {
    int T = 1;
    while (T--) {
        int n;
        scanf("%d", &n);
        LL pro = 1;
        vector<int>V;
        V.push_back(1);
        for (int i = 2; i < n - 1; i++) if(gcd(i, n) == 1) {
            V.push_back(i);
            pro = pro * i % n;
        }
        if (pro != 1) {
            V.push_back(n - 1);
            pro = pro * (n - 1) % n;
        }
        int ln = V.size();
        printf("%d\n", ln);
        for (int i = 0; i < ln; i++)
            printf("%d ", V[i]);
        printf("\n");
    }
}