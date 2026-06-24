#include <climits>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdarg>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <exception>
#include <stdexcept>
#include <memory>
#include <locale>
#include <bitset>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>
#include <string>
#include <complex>
#include <valarray>

using namespace std;

/************** 读入输出优化 *****************/
template<class T>
inline char read(T &n){
    T x = 0, tmp = 1; char c = getchar();
    while((c < '0' || c > '9') && c != '-' && c != EOF) c = getchar();
    if(c == '-') c = getchar(), tmp = -1;
    while(c >= '0' && c <= '9') x *= 10, x += (c - '0'),c = getchar();
    n = x*tmp;
    return c;
}

template <class T>
inline void write(T n) {
    if(n < 0) {
        putchar('-');
        n = -n;
    }
    int len = 0,data[20];
    while(n) {
        data[len++] = n%10;
        n /= 10;
    }
    if(!len) data[len++] = 0;
    while(len--) putchar(data[len]+48);
}
/** -_- ** -_- ** -_- ** -_- ** -_- ** -_- **/
const int N = 100017;
typedef long long ll;

int n, m;

int a[N];

set<int > s;

void rd() {
    for(int i = 0; i < n; ++i) read(a[i]);
//    s.insert(a[0]);
    for(int i = 1; i < n; ++i) a[i] += a[i-1];
    return ;
}

void solve() {
    read(m);
    int q;
    while(m--) {
        read(q);
        int l = 0, r = n-1, m;
        while(r >= l) {
            m = l + r >> 1;
            if(a[m] >= q) r = m - 1;
            else l = m + 1;
        }
        write(l+1);puts("");
    }
    return ;
}

int main()
{
#ifdef PIT
    freopen("b.in", "r", stdin);
#endif // PIT
    while(read(n) != EOF) {
        rd();
        solve();
    }
    return 0;
}