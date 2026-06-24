/**
 *    author:  skmonir
 *    created: 24-Mar-2018 10:20:48
**/

#include <bits/stdc++.h>

using namespace std;

#define endl                '\n'
#define TN                  typename
#define mod                 1000000007LL
#define all(x)              x.begin(), x.end()
#define rall(x)             x.rbegin(), x.rend()
#define mem(x, y)           memset(x, y, sizeof x)
#define FOR(x, l, r)        for (int x = l; x <= r; ++x)
#define ROF(x, l, r)        for (int x = l; x >= r; --x)

template <TN T> inline void Int(T &n) {
    n = 0; int f = 1; register int ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = -1;
    for (; isdigit(ch); ch = getchar()) n = (n << 3) + (n << 1) + ch - '0';
    n = n * f;
}

template <TN T> T gcd(T a, T b) {return !b ? a : gcd(b, a % b);}
template <TN T> T modinverse(T bs) {return modpow(bs, mod - 2);}
template <TN T> inline void umin(T &a, T b) {a = a < b ? a : b;}
template <TN T> inline void umax(T &a, T b) {a = a > b ? a : b;}
template <TN T, TN W> inline void Int(T &x, W &y) {Int(x), Int(y);}
template <TN T, TN W, TN Q> inline void Int(T &x, W &y, Q &z) {Int(x, y), Int(z);}

const int N = 1e6 + 7;
const int inf = 1e9 + 7;
int tests = 1, CaseNo = 0;

int bad[N];
vector <long long> v;

inline bool okay(long long x, int y) {
    return 0 < x and x < 1000000000000000001LL and x % y == 0;
}

void init() {
    FOR (i, 2, 1000) bad[i * i] = 1;
    FOR (i, 2, 1000000) if (!bad[i]) {
        bool f = 1;
        long long x = 1LL * i * i * i;
        while (okay(x, i)) {
            if (f) v.push_back(x);
            x = x * i, f ^= 1;
        }
    }

    sort(all(v));
    v.erase(unique(all(v)), v.end());
}

long long get(long long b) {
    int x = upper_bound(all(v), b) - v.begin();
    int y = sqrt(b);

    return x + y;
}

int solve() {
    init();

    int q; Int(q);
    while (q--) {
        long long L, R; Int(L, R);
        printf("%lld\n", get(R) - get(L - 1));
    }

    return 0;
}

int main() {
    //Int(tests);

    while (tests--) {
        //printf("Case %d: ", ++CaseNo);
        solve();
    }

    return 0;
}