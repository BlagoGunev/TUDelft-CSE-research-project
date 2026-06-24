#include <stdio.h>
#include <string.h>
#include <string>
#include <math.h>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
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
    if (x <0) {
        putchar('-');
        x = -x;
    }
    if (x>9) pt(x / 10);
    putchar(x % 10 + '0');
}
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
int n;
ll A, B;
ll l, t, m, mx;
ll siz(ll x){
    return A + (x - 1)*B;
}
ll work(){
    if (siz(l) - t > 0)return -1;
    
    ll L = l, R = mx, ans = l;
    while (L <= R){
        ll mid = (L + R) >> 1;
        ll len = mid - l + 1;
        ll all = (siz(l) + siz(mid))*len / 2;
        ll M = min(m, len);
        if (all > t*M || siz(mid)>t)
            R = mid - 1;
        else {
            ans = mid;
            L = mid + 1;
        }
    }
    return ans;
}
int main() {
    while (cin >> A >> B >> n){
        mx = (1e6 - A) / B;
        mx++;
        while (n--){
            rd(l); rd(t); rd(m);
            pt(work()); puts("");
        }
    }
    return 0;
}



/*
1 1
a
1

1 0
a


*/