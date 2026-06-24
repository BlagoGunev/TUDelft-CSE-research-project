#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <iostream>
#include <sstream>
#include <ctime>

using namespace std;

template<class T> int size(const T& a) {
    return (int)a.size();
}
template<class T> T sqr(const T& a) {
    return a * a;
}
typedef long long i64;

const int max_n = 5000000;
i64 s2[max_n + 1];
int main() {
#ifdef pperm
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    s2[0] = 0;
    for (int i = 1; i <= max_n; i++) {
        s2[i] = s2[i - 1] + 2 * (i - 1) + 1;
    }
    scanf("%d %d", &n, &m);
    i64 res = 0;
    for (int b = 1, d = 0; b <= n; b++) {
        i64 c = max(s2[b] - m, 0LL);
        while (s2[d] < c) d++;
        res += 2 * (s2[b] - c - (b - d));//I
    }
    for (i64 x = 1; x <= 10000000; x++) {
        if (x & 1) {
            if (x <= m && x + 1 <= n + n) {
                res++;
            }
        } else {
            if (x + x <= m && x + 2 <= n + n) {
                res++;
            }
        }
    }
    cout << res;
    return 0;
}