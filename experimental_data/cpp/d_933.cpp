#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<LL, int> P;

const int maxn = 1e6 + 5;
const int mod = 1e9 + 7;

int add(int x, int y) {
    x += y;
    if(x >= mod) x -= mod;
    return x;
}

int mul(int x, int y) {
    LL z = 1LL * x * y;
    return z - z / mod * mod;
}

int powt(int a, int b) {
    int r = 1;
    while(b) {
        if(b & 1) r = mul(r, a);
        a = mul(a, a);
        b >>= 1;
    }
    return r;
}

int f0[maxn], f1[maxn], f2[maxn], f3[maxn];

int main() {
#ifdef CX_TEST
    freopen("E:\\program--GG\\test_in.txt", "r", stdin);
#endif
    LL m, i, j;
    int inv2 = (mod + 1) >> 1, inv3 = powt(3, mod - 2);
    int inv6 = mul(inv2, inv3);
    scanf("%lld", &m);
    int d = mul(mul(m % mod + 2, m % mod + 1), mul(m % mod, inv6));
    int A = inv3, B = mul(add(m % mod, 2), mod - inv2), C = mul(add(mul(3, m % mod), 4), inv6);
    for(i = 0; i * i <= m; i++) {
        int k = mul(i, i);
        f0[i] = add(add(d, mul(C, k)), add(mul(B, mul(k, k)), mul(A, mul(mul(k, k), k))));
        f1[i] = add(add(mul(k, k), mul(k, mul(2, B))), C);
        f2[i] = add(k, B);
        f3[i] = inv3;
        if(i) {
            f0[i] = add(mul(f0[i], 2), f0[i - 1]);
            f1[i] = add(mul(f1[i], 2), f1[i - 1]);
            f2[i] = add(mul(f2[i], 2), f2[i - 1]);
            f3[i] = add(mul(f3[i], 2), f3[i - 1]);
        }
    }
    int ans = 0;
    for(j = 0; j * j <= m; j++) {
        while(j * j + i * i > m) i--;
        int res = f0[i], k = mul(j, j);;
        res = add(res, mul(f1[i], k));
        res = add(res, mul(f2[i], mul(k, k)));
        res = add(res, mul(f3[i], mul(mul(k, k), k)));
        if(j) ans = add(ans, mul(res, 2));
        else ans = add(ans, res);
    }
    printf("%d\n", ans);
    return 0;
}