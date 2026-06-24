/*

Blackpink is the Revolution

Light up the sky

Blackpink in your area

*/

#include <unordered_map>

#include <algorithm>

#include <iostream>

#include <cstring>

#include <cctype>

#include <bitset>

#include <vector>

#include <cstdio>

#include <cmath>

#include <queue>

#include <ctime>

#include <map>

#include <set>

using namespace std;

using ll = long long;

using P = pair <int, int>;



namespace scan {

template <typename T>

inline void read(T &x) {

    x = 0; char c = getchar(); int f = 0;

    for (; !isdigit(c); c = getchar()) f |= (c == '-');

    for (; isdigit(c); c=getchar()) x = x * 10 + (c ^ 48);

    if (f) x = -x;

}

template <typename T, typename ...Args>

inline void read(T &x, Args &...args) {

    read(x), read(args...);

}

template <typename T>

inline void write(T x, char ch) {

    if (x < 0) putchar('-'), x = -x;

    static short st[30], tp;

    do st[++tp] = x % 10, x /= 10; while(x);

    while (tp) putchar(st[tp--] | 48);

    putchar(ch);

}

template <typename T>

inline void write(T x) {

    if (x < 0) putchar('-'), x = -x;

    static short st[30], tp;

    do st[++tp] = x % 10, x /= 10; while(x);

    while(tp) putchar(st[tp--] | 48);

}

inline void write(char ch){

    putchar(ch);

}

template <typename T, typename ...Args>

inline void write(T x, char ch, Args ...args) {

    write(x, ch), write(args...);

}

} //namespace scan



using namespace scan;



#define vv vector

#define rd(x) int x; read(x)

#define Fr(i, a, b) for(int i = (a); (i) <= (b); ++i)

#define Rf(i, a, b) for(int i = (a); (i) >= (b); --i)

const int mod = 1e9 + 7;

const int N = 2e5 + 5;



int n, m, T, k;

int l, r, ans, len, res;

int a[N], b[N];



namespace RevolutionBP {

inline void main() {

#ifndef ONLINE_JUDGE

    // freopen("1.in", "r", stdin);

    // freopen("1.out", "w", stdout);

    double aaa = clock();

#endif



    read(T);

    while (T--) {

        ans = 0;

        read(n);

        Fr (i, 1, n) read(a[i]);

        Fr (i, 1, n) if (a[i] & 1) ans++;

        write(min(ans, n - ans), '\n');

    }



#ifndef ONLINE_JUDGE

    double bbb = clock();

    cerr << 1.0 * (bbb - aaa) / CLOCKS_PER_SEC << "s" << endl;

#endif

    return void();

}

}

signed main(){

    RevolutionBP::main();

    return 0;

}

//write: RevolutionBP