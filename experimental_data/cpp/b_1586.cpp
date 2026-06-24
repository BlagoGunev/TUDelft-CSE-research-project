//Author:Hewlett
#ifdef Hewlett
#include "Hewlett.h"
#endif 
#include <ctime>
#include <tuple>
#include <chrono>
#include <cstdio>
#include <random>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#include <ext/pb_ds/hash_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/assoc_container.hpp>
std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count() + 20051107);
std::mt19937_64 Rnd(std::chrono::steady_clock::now().time_since_epoch().count() + 20060923);
namespace fastio {
constexpr int HL = 1 << 19 ;
char buf[HL], buff[HL], *t1 = buf, *t2 = buf, *T = buff;
#define getc() (t1 == t2 && (t2 = (t1 = buf) + fread(buf,1,HL,stdin),t1 == t2)?EOF:*t1++)
inline void flush() {
    fwrite(buff, 1, T - buff, stdout), T = buff;
}
inline void putc(const char ch) {
    T == buff + HL ? flush(), *T++ = ch : *T ++ = ch;
}
struct Read {
    template <typename Tp>inline Read &operator >> (Tp &x) {
        char ch = getc() ;
        int f = 0 ;

        for (; ch < '0' || ch > '9'; ch = getc())
            f = (ch == '-') ? 1 : 0 ;

        x = 0;

        for (; ch >= '0' && ch <= '9'; ch = getc())
            x = x * 10 + (ch ^ 48) ;

        return x = f ? -x : x, *this ;
    } inline Read &operator >> (char &c) {
        for (c = getc(); c == ' ' || c == '\n' || c == '\r'; c = getc()) ;

        return *this;
    } inline Read &operator >> (char *str) {
        int len = 0;
        char ch = getc() ;

        while (ch == ' ' || ch == '\n')
            ch = getc() ;

        while (ch != ' ' && ch != '\n' && ch != '\r' && ch != EOF)
            str[len++] = ch, ch = getc() ;

        return str[len] = '\0', *this;
    }
} cin ;
struct Write {
    template <typename Tp> inline Write &operator << (Tp x) {
        if (!x)
            return putc('0'), *this ;

        if (x < 0)
            putc('-'), x = -x;

        int stk[20], top = 0 ;

        while (x)
            stk[++top] = x % 10, x /= 10 ;

        while (top)
            putc(stk[top--] + '0') ;

        return *this ;
    }
    inline Write &operator << (const char ch) {
        return putc(ch), *this;
    }
    inline Write &operator << (char *str) {
        int cur = 0 ;

        while (str[cur])
            putc(str[cur++]);

        return *this ;
    }
    inline Write &operator << (const char *str) {
        int cur = 0 ;

        while (str[cur])
            putc(str[cur++]) ;

        return *this ;
    }
} cout ;
}
using fastio::cin;
using fastio::cout;

namespace useful_function {
template<typename Tp> inline Tp max(const Tp &a, const Tp &b) {
    return a > b ? a : b;
}
template<typename Tp, typename... Rst> inline Tp max(const Tp &a, const Rst... rst) {
    return max(a, max(rst...));
}
template<typename Tp> inline Tp min(const Tp &a, const Tp &b) {
    return a < b ? a : b;
}
template<typename Tp, typename... Rst> inline Tp min(const Tp &a, const Rst... rst) {
    return min(a, min(rst...));
}
}
using useful_function::max ;
using useful_function::min ;

constexpr int N = 1e5 + 5;

int n, m, t;
bool vis[N];

namespace {

void solve() {
    cin >> n >> m;
    for (int i = 1, a, b, c; i <= m; ++i) {
        cin >> a >> b >> c;
        vis[b] = 1;
    }
    int center_point = 0;
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            center_point = i;
            break;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (i == center_point) {
            continue;
        }
        cout << i << " " << center_point << '\n';
    }
    for (int i = 1; i <= n; ++i) {
        vis[i] = 0;
    }
}

inline void HL() {
    cin >> t;
    for (; t; --t) {
        solve();
    }
}

}

int main(int argc, const char **argv) {
#ifdef Hewlett
    freopen("std.in", "r", stdin);
    freopen("std.ans", "w", stdout);
    auto Time_Start = std::chrono::steady_clock::now() ;
#endif
    HL() ;
#ifdef Hewlett
    auto Time_End = std::chrono::steady_clock::now() ; 
    std::cerr << "This program costs " << std::chrono::duration<double,std::nano>(Time_End-Time_Start).count() / 1e6 << " ms" ;
#endif
    return fastio::flush(),0 ;
}