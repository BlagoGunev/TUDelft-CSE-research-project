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
const int N = 100007;
typedef long long ll;
const ll mod = (ll)1e9+7;
int n, k;
int l, r;

ll opt[N];

void init() {
    memset(opt, 0, sizeof opt);
    opt[0] = 1;
    for(int i = 0; i < N; ++i) {
        if(i + 1 < N) opt[i+1] = (opt[i+1] + opt[i] ) % mod;
        if(i + k < N) opt[i+k] = (opt[i+k] + opt[i] ) % mod;
    }

    for(int i = 1; i < N; ++i) opt[i] = (opt[i] + opt[i-1]) % mod;
    return ;
}

int main()
{
#ifdef PIT
    freopen("d.in", "r", stdin);
#endif // PIT

    while(read(n) != EOF) {
        read(k);
        init();
        while(n--) {
            read(l), read(r);
            ll ans = (opt[r] - opt[l-1] + mod) % mod;
            write(ans);
            puts("");
        }
    }
    return 0;
}