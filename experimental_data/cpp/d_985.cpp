#include <bits/stdc++.h>
using namespace std;
long long n, h;

long long calc(long long x) {
    long long k = sqrt(x * 2);
    while (k * (k + 1) / 2 <= x) k++;
    while (k * (k + 1) / 2 > x) k--;
    return k;
}

long long cal(long long n, long long h) {
    long long lo = 0, hi = sqrt(n);
    long long res = 0;
    while (lo <= hi) {
        long long x = (lo + hi) >> 1;
        if (x * x + 2 * h * x <= n) {
            res = x;
            lo = x + 1;
        } else hi = x - 1;
    }
    return res;
}

int main() {
    cin >> n >> h;
    long long k = min(calc(n), h);
    n -= k * (k + 1) / 2;
    long long t = (n + k - 1) / k;
    if (k < h) {
        cout << k + t << endl;
        return 0;
    }
    if (n == 0) {
        cout << k << endl;
        return 0;
    }
    long long x = cal(n, h);
    long long res = k + x * 2;
    n -= x * x + 2 * h * x;
    if (n > h + x) res += 2;
    else if (n > 0) res++;
    cout << res << endl;
}