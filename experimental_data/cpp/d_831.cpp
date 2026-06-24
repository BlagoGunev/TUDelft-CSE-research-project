#define _CRT_SECURE_NO_DEPRECATE
#define rep(i, b, e) for (auto i = b; i < e; ++i)
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <cmath>
#ifndef __GNUC__
  #include <intrin.h>
#endif // !__GNUC__
#include <vector>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <numeric>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <functional>
int bsf(int x) {
#ifdef __GNUC__
    return __builtin_ctz(x);
#else
    unsigned long i;
    _BitScanForward(&i, x);
    return i;
#endif
}
int bsr(int x) {
#ifdef __GNUC__
    return 31 - __builtin_clz(x);
#else
    unsigned long i;
    _BitScanReverse(&i, x);
    return i;
#endif
}

using namespace std;
typedef long long int64;
const double pi = 3.14159265358979323846;
const int inf = (int)2e+9 + 2;
const double eps = 1e-8;
const int N = 2000;

int n, k, p;
int a[N], b[N];

int dist(int hum, int key)
{
    if (hum <= key && key <= p || p <= key && key <= hum)
        return abs(p - hum);
    if (hum <= p && p <= key || key <= p && p <= hum)
        return abs(hum - key) + abs(key - p);
    return 2 * abs(hum - key) + abs(hum - p);
}

int calc(int l)
{
    int ret = 0;
    rep(i, 0, n) {
        ret = max(ret, dist(a[i], b[i + l]));
    }
    return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif // !ONLINE_JUDGE
    scanf("%d%d%d", &n, &k, &p);
    rep(i, 0, n)
        scanf("%d", a + i);
    rep(i, 0, k)
        scanf("%d", b + i);
    sort(a, a + n);
    sort(b, b + k);
    int ans = inf;
    rep(i, 0, k - n + 1) {
        ans = min(ans, calc(i));
    }
    printf("%d", ans);
    return 0;
}