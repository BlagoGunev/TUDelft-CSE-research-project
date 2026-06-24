#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MXN = 1e7 + 7;
const int MXD = 1e6 + 7;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
LL n, m;
int main() {
    scanf("%lld", &n);
    if(n == 1) {
        printf("1\n");
        return 0;
    }else if(n == 2) {
        printf("2\n");
        return 0;
    }else if(n == 3) {
        printf("9\n");
        return 0;
    }
    LL ans = n-2;
    for(int i = 1; i <= n; ++i) ans = ans * i % MOD;
    LL tmp = 3;
    for(int i = 3; i < n; ++i) {
        tmp = (i+1) * (tmp-1) % MOD;
    }
    printf("%lld\n", (tmp+ans) % MOD);
    return 0;
}