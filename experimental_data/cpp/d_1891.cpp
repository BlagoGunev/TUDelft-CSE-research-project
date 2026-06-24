#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int f(long long l, long long r, int x) {
    int fx = 0;
    int res = 0;
    for(long long sl = 1, sr; sl <= r; sl = sr, ++fx) {
        if(r / x < sl) sr = r + 1;
        else sr = sl * x;
        if(sr - 1 >= l) res = (res + (min(r, sr - 1) - max(l, sl) + 1) % mod * fx) % mod;
    }
    return res;
}
int g(long long l, long long r) {
    int fx = 0;
    int res = 0;
    for(long long sl = 1, sr; sl <= r; sl = sr, ++fx) {
        sr = sl * 2;
        if(sr - 1 >= l) res = (res + f(max(l, sl), min(r, sr - 1), fx)) % mod;
    }
    return res;
}

int main() {
    int q;
    scanf("%d", &q);
    while(q--) {
        long long l, r;
        scanf("%lld %lld", &l, &r);
        printf("%d\n", g(l, r));
    }
    system("pause");
    return 0;
}