#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <bitset>
#include <sstream>
#include <queue>

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(a) ((int) (a).size())
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

typedef long long int64;
typedef long double ldb;

const long double eps = 1e-10;
const int inf = (1 << 30) - 1;
const long long inf64 = ((long long)1 << 62) - 1;
const long double pi = acos(-1);

template <class T> T sqr (T x) {return x * x;}
template <class T> T abs (T x) {return x < 0 ? -x : x;}

const int MAXM = 120 * 1000;

long double ln_fact[MAXM];

long double ln_c (int a, int b) {
    return (ln_fact[a] - ln_fact[b] - ln_fact[a - b]);
}

int main () {
//  ios_base::sync_with_stdio(0);
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);

    int n, m, k;
    cin >> n >> m >> k;

    ln_fact[0] = 0.0;
    for (int i = 1; i <= m; ++i) {
        ln_fact[i] = ln_fact[i - 1] + logl((long double)i);
    }

    long double max_val = 1e100;
    long double max_ln = 100 * logl((long double)10);

    long double ans = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            int temp = n * (i + j) - i * j;
            if (temp <= k) {
                    long double ln_plus = ln_c(n, i) + ln_c(n, j) + ln_c(k, temp) - ln_c(m, temp);
                    if (ln_plus < max_ln + eps) {
                        ans += expl(ln_plus);
                    } else {
                        ans = max_val + 1000;
                    }
            }
        }
    }

    if (ans > 1e99 + eps) {
        cout << "1e99" << endl;
        return 0;
    }

    cout.precision(20);
    cout << ans << endl;

    return 0;
}