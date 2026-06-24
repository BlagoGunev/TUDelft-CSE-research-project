#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
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
    if (x <0) {
        putchar('-');
        x = -x;
    }
    if (x>9) pt(x / 10);
    putchar(x % 10 + '0');
}

typedef long long ll;
const int N = 2e5 + 10;
const double eps = 1e-10;
typedef pair<ll, int> pii;
int n;
ll a[N], b[N];
int main(){
    while (cin >> n){
        for (int i = 1; i <= n; i++)
            rd(a[i]), a[i] += i;
        sort(a + 1, a + n + 1);
        bool ok = true;
        for (int i = 1; i <= n && ok; i++){
            b[i] = a[i] - i;
            if ((i >= 2 && b[i - 1] > b[i]) || b[i] < 0)
                ok = false;
        }
        if (ok)
        for (int i = 1; i <= n; i++)
            pt(b[i]), putchar(' ');
        else puts(":(");
    }
    return 0;
}