#include <iostream>  
#include <cstring>  
#include <string>  
#include <algorithm>  
#include <cstdio>  
#include <queue>
#include <cmath>
#include <ctime>  

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
typedef pair<int, int> pii;
const int inf = 1e9;
const int N = 2e5 + 10;
int n, a[N];
int main() {
    rd(n);
    for (int i = 1; i <= n; i++)rd(a[i]);
    a[1] = min(a[1], 1);
    int pre = a[1];
    for (int i = 2; i <= n; i++)
    {
        pre++;
        pre = min(pre, a[i]);
        a[i] = min(a[i], pre);
    }
    a[n] = min(a[n], 1);
    pre = a[n];
    for (int i = n - 1; i >= 1; i--) {
        pre++;
        pre = min(pre, a[i]);
        a[i] = min(a[i], pre);
    }
    int ans = a[1];
    for (int i = 2; i <= n; i++)ans = max(ans, a[i]);
    pt(ans); puts("");
    return 0;
}