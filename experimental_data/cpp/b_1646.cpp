#include <iostream>
#include <streambuf>
#include <fstream>
#include <cstring>
#include <algorithm>

namespace AKA
{
    #if __cplusplus >= 201103L
        using uint = unsigned int;
        using ll = long long;
        using ull = unsigned long long;
        using llrg = __int128_t;
        using ullrg = __uint128_t;
        using dbl = double;
        using ldbl = long double;
    #else
        typedef unsigned int uint;
        typedef long long ll;
        typedef unsigned long long ull;
        typedef __int128_t llrg;
        typedef __uint128_t ullrg;
        typedef double dbl;
        typedef long double ldbl;
    #endif    
} // namespace AKA


namespace IO
{
    using namespace AKA;
    std::streambuf* inbuf, *outbuf;
    char ibuf[1 << 23 | 1], *i1 = ibuf, *i2 = ibuf;
    char outstk[105];
    int top = 0;
    inline char gc() { return (i1 == i2 && (i2 = (i1 = ibuf) + inbuf->sgetn(ibuf, 1 << 23), i1 == i2) ? EOF : *i1++); }
    inline void pc(char x) { outbuf->sputc(x); }
    inline int iget() { int x = 0; bool f = false; char c = gc(); while (c < '0' || c > '9') { f |= c == '-'; c = gc(); } while (c >= '0' && c <= '9') { x = (x << 3) + (x << 1) + (c ^ 48); c = gc(); } return f ? -x : x; }
    inline void ipr(int x) { if (x == 0) { pc('0'); return ; } if (x < 0) { pc('-'); x = -x; } top = 0; while (x) { outstk[top++] = x % 10 + 48; x /= 10; } while (top--) { pc(outstk[top]); } }
    inline void iwsp(int x) { ipr(x); pc(' '); }
    inline void iwln(int x) { ipr(x); pc('\n'); }
    inline ll llget() { ll x = 0; bool f = false; char c = gc(); while (c < '0' || c > '9') { f |= c == '-'; c = gc(); } while (c >= '0' && c <= '9') { x = (x << 3) + (x << 1) + (c ^ 48); c = gc(); } return f ? -x : x; }
    inline void llpr(ll x) { if (x == 0) { pc('0'); return ; } if (x < 0) { pc('-'); x = -x; } top = 0; while (x) { outstk[top++] = x % 10 + 48; x /= 10; } while (top--) { pc(outstk[top]); } }
    inline void llwsp(ll x) { llpr(x); pc(' '); }
    inline void llwln(ll x) { llpr(x); pc('\n'); }
    inline ull ullget() { ll x = 0; bool f = false; char c = gc(); while (c < '0' || c > '9') { f |= c == '-'; c = gc(); } while (c >= '0' && c <= '9') { x = (x << 3) + (x << 1) + (c ^ 48); c = gc(); } return f ? -x : x; }
    inline void ullpr(ull x) { if (x == 0) { pc('0'); return ; } if (x < 0) { pc('-'); x = -x; } top = 0; while (x) { outstk[top++] = x % 10 + 48; x /= 10; } while (top--) { pc(outstk[top]); } }
    inline void ullwsp(ull x) { ullpr(x); pc(' '); }
    inline void ullwln(ull x) { ullpr(x); pc('\n'); }
    inline void spr(const char* s) { char* t = const_cast<char*>(s); while (*t && (pc(*t++), true)) {} }
    inline void swsp(const char* s) { spr(s); pc(' '); }
    inline void swln(const char* s) { spr(s); pc('\n'); }
    template<typename _Tp> inline void iget(_Tp& x) { x = 0; bool f = false; char c = gc(); while (c < '0' || c > '9') { f |= c == '-'; c = gc(); } while (c >= '0' && c <= '9') { x = (x << 3) + (x << 1) + (c ^ 48); c = gc(); } f && (x = -x); }
    template<typename _Tp, typename ... Args> inline void iget(_Tp& x, Args& ... args) { iget(x), iget(args ...); }
    template<typename _Tp> inline void pr(_Tp x) { if (x == 0) { pc('0'); return ; } if (x < 0) { pc('-'); x = -x; } top = 0; while (x) { outstk[top++] = x % 10 + 48; x /= 10; } while (top--) { pc(outstk[top]); } }
    template<typename _Tp, typename ... Args> inline void pr(_Tp x, Args ... args) { pr(x), pr(args ...); }
    template<typename _Tp> inline void wsp(_Tp x) { pr(x), pc(' '); }
    template<typename _Tp, typename ... Args> inline void wsp(_Tp x, Args ... args) { wsp(x), wsp(args ...); }
} // namespace IO



namespace Solution
{
    #ifndef ONLINE_JUDGE
        std::ifstream cin; 
        std::ofstream cout;
    #else  
        using std::cin;
        using std::cout;
    #endif
    using namespace AKA;
    using IO::gc; using IO::pc; 
    using IO::iget; using IO::ipr; using IO::iwsp; using IO::iwln;
    using IO::llget; using IO::llpr; using IO::llwsp; using IO::llwln;
    using IO::ullget; using IO::ullwsp; using IO::ullwln;
    using IO::spr; using IO::swsp; using IO::swln;
    using IO::pr; using IO::wsp; 
    #define flp(name, lpst, lped) for (int name = lpst, name##end = lped; name <= name##end; ++name)
    #define plf(name, lpst, lped) for (int name = lpst, name##end = lped; name >= name##end; --name)


    constexpr int maxn = 2e5 + 5;

    int a[maxn];

    inline void real_main()
    {
        int n = iget();
        flp (i, 1, n)
        {
            a[i] = iget();
        }
        std::sort(a + 1, a + n + 1, [](int x, int y)
        {
            return x > y;
        });
        ll lit = 0, big = 0;
        if (n & 1)
        {
            flp (i, 1, n / 2)
            {
                big += a[i];
            }
            flp (i, n / 2 + 1, n)
            {
                lit += a[i];
            }
        }
        else   
        {
            flp (i, 1, n / 2 - 1)
            {
                big += a[i];
            }
            flp (i, n / 2 + 1, n)
            {
                lit += a[i];
            }
        }
        swln(big > lit ? "YES" : "NO");
    }


    void main(void)
    {
        std::ios::sync_with_stdio(false);
        #ifndef ONLINE_JUDGE
            cin.open("main.in"), cout.open("main.out");
            IO::inbuf = cin.rdbuf(); IO::outbuf = cout.rdbuf();
        #else
            #if __cplusplus >= 201103L
                cin.tie(nullptr); cout.tie(nullptr);
            #else
                cin.tie(NULL); cout.tie(NULL);
            #endif
            IO::inbuf = cin.rdbuf(); IO::outbuf = cout.rdbuf();
        #endif


        int General_Q = iget();
        flp (general_q, 1, General_Q)
        {
            real_main();
        }


        #ifndef ONLINE_JUDGE
            cin.close(); cout.close();
        #endif
    }
} // namespace Solution

int main(void)
{
    Solution::main();
    return 0;
}