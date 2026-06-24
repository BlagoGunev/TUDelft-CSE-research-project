#pragma comment(linker, "/STACK:1024000000")
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <stack>
#include <cstring>
#include <cmath>
#include <set>
#include <vector>
using namespace std;
template <class T>
inline bool rd(T &ret) {
    char c; int sgn;
    if (c = getchar(), c == EOF) return 0;
    while (c != '-' && (c<'0' || c>'9')) c = getchar();
    sgn = (c == '-') ? -1 : 1;
    ret = (c == '-') ? 0 : (c - '0');
    while (c = getchar(), c >= '0'&&c <= '9') ret = ret * 10 + (c - '0');
    ret *= sgn;
    return 1;
}
template <class T>
inline void pt(T x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) pt(x / 10);
    putchar(x % 10 + '0');
}
typedef long long ll;
const int N = 2e5 + 10;
int n, a[N];
const ll C = 1e9;
ll k;
map<ll, ll>mp, pp;
int main() {
    while (cin >> n >> k) {
        mp.clear(); pp.clear();
        for (int i = 1; i <= n; i++)rd(a[i]);
        ll ans = 0;
        for (int i = n; i; i--) {
            ll d = a[i] * k;
            if (d <= C && d >= -C)
            {
                if (pp.count(d))
                {
                    ans += pp[d];
                }
                if (mp.count(d)) {
                    pp[a[i]] += mp[d];
                }
            }
            mp[a[i]]++;
        }
        pt(ans);
    }
    return 0;
}