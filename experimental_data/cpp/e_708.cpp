#include <algorithm>

#include <bitset>

#include <cassert>

#include <cmath>

#include <complex>

#include <cstdio>

#include <cstring>

#include <ctime>

#include <deque>

#include <fstream>

#include <iomanip>

#include <iostream>

#include <list>

#include <map>

#include <memory>

#include <queue>

#include <set>

#include <stack>

#include <string>

#include <vector>

#include <unordered_map>

#include <unordered_set>



using namespace std;



const int inf = (int)1e9 + 7;

const int N = (int)1e5 + 4;

const int K = 21;



int f[N], p[N], dp[N], dpp[N], pr[N], s[N];



inline int pw(int a, int k) {

    if (k == 0) {

        return 1;

    }

    if (k % 2 == 1) {

        return a * 1LL * pw(a, k - 1) % inf;

    }

    int t = pw(a, k / 2);

    return t * 1LL * t % inf;

}



int main() {

#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif

    int n, m, a, b, k;

    scanf("%d%d%d%d%d", &n, &m, &a, &b, &k);

    int d = a * 1LL * pw(b, inf - 2) % inf;

    f[0] = 1;

    for (int i = 1; i <= k; ++i) {

        f[i] = f[i - 1] * 1LL * i % inf;

    }

    for (int i = 0; i < min(m, k + 1); ++i) {

        p[i] = f[k] * 1LL * pw(f[i] * 1LL * f[k - i] % inf, inf - 2) % inf * pw(d, i) % inf * pw(1 + inf - d, k - i) % inf;

    }

    for (int i = 0; i < m; ++i) {

        pr[i + 1] = (pr[i] + p[i]) % inf;

    }

    for (int i = 0; i < m; ++i) {

        dp[i + 1] = (dp[i] + p[i] * 1LL * pr[m - i]) % inf;

    }

    for (int i = 1; i < n; ++i) {

        for (int j = 0; j < m; ++j) {

            s[j + 1] = (s[j] + p[j] * 1LL * dp[m - j]) % inf;

        }

        for (int j = 0; j < m; ++j) {

            dpp[j + 1] = (dpp[j] + p[j] * 1LL * ((dp[m - j] + inf - dp[m]) * 1LL * pr[m - j] % inf + s[m - j]) % inf) % inf;

        }

        for (int j = 0; j <= m; ++j) {

            dp[j] = dpp[j];

        }

    }

    printf("%d", dp[m]);

    return 0;

}