#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long LL;
const int N = 1000010;
const LL MOD = 1000000007;

LL dp[N];
int main () {
    int n, ones = 0, twos = 0;
    scanf("%d", &n);
    for(int i=0;i<n;++i) {
        int t; scanf("%d", &t);
        if(t == 1) ones ++;
        else       twos ++;
    }
    LL ans = 1;
    for(int i=0;i<twos;++i)
        ans = ans * (n-i) % MOD;
    if(ones) {
        n = ones;
        dp[1] = 1; dp[2] = 2;
        for(int i=3;i<=n;++i)
            dp[i] = (dp[i-1] + (i-1)*dp[i-2]) % MOD;
        ans = ans * dp[n] % MOD;
    }
    int aa = (int) ans;
    printf("%d\n", aa);
    return 0;
}