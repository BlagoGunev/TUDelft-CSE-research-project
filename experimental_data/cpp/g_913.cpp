#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include <algorithm>
#include <cstring>
#include <iostream>
#include <ios>
#include <functional>
#include <map>
#include <set>
#include <tuple>
#include <utility>
#include <vector>
#include <stdio.h>
#include <string>
uint32_t readu32() { int c; while((c = getchar()) < '0'); uint32_t n = c & 15U; while((c = getchar()) >= '0') n = n * 10 + (c & 15U); return n; } uint64_t readu64() { int c; while((c = getchar()) < '0'); uint64_t n = c & 15U; while((c = getchar()) >= '0') n = n * 10 + (c & 15U); return n; } int32_t read32() { int c; while((c = getchar()) < '-'); bool neg = c == '-'; if(neg) c = getchar(); uint32_t n = c & 15U; while((c = getchar()) >= '0') n = n * 10 + (c & 15U); return neg ? -(int32_t)n : n; } int64_t read64() { int c; while((c = getchar()) < '-'); bool neg = c == '-'; if(neg) c = getchar(); uint64_t n = c & 15; while((c = getchar()) >= '0') n = n * 10 + (c & 15U); return neg ? -(int64_t)n : n; } std::string read_word() { int c; while ((c = getchar()) <= ' '); std::string s; do { s += (char) c; } while ((c = getchar()) > ' '); return s; } template<typename F, F f> struct no_arg_call { template<typename T> struct stupid_compiler { typedef T type; }; operator typename stupid_compiler<decltype(f())>::type() { return f(); } }; no_arg_call<decltype(&readu32), readu32> IU; no_arg_call<decltype(&read32), read32> II; no_arg_call<decltype(&readu64), readu64> IUL; no_arg_call<decltype(&read64), read64> IL; no_arg_call<decltype(&read_word), read_word> IW;
using namespace std;

#define M 762939453125 // 5^17
#define MHIGH 390625 // 5^8
#define MLOW 1953125 // 5^9

#define MUST_DIVIDE 131072 // 2^17
#define ORDER_2 (M / 5 * 4)

struct I {
    uint32_t lo, hi;
};

uint64_t mul(uint32_t a, uint32_t b) {
    return uint64_t(a) * b;
}
I mul(I a, I b) {
    I p;
    p.lo = mul(a.lo, b.lo) % MLOW;
    p.hi = (mul(a.lo, b.lo) / MLOW + mul(a.hi, b.lo) + mul(a.lo, b.hi)) % MHIGH;
    return p;
}

I pow(I b, uint64_t x) {
    I a = {1};
    for (; x; x >>= 1) {
        if (x & 1)
            a = mul(a, b);
        b = mul(b, b);
    }
    return a;
}

bool order_indiv(I x, uint64_t d) {
    I p = pow(x, ORDER_2 / d);
    return p.lo != 1 || p.hi != 0;
}

uint64_t exponent(I x) {
    uint64_t a = 0;
    if (order_indiv(x, 2)) {
        a += 1;
        x = mul(x, { 2 });
    }
    if (order_indiv(x, 4)) {
        a += 2;
        x = mul(x, { 4 });
    }
    I p = { 16 };
    for (uint64_t p5 = 1, aa = 4; (p5 *= 5) < ORDER_2; aa *= 5) {
        while (order_indiv(x, p5)) {
            x = mul(x, p);
            a += aa;
        }
        p = pow(p, 5);

    }
    return 3 * ORDER_2 - a;
}

int main(int argc, char** argv)
{
    if (argc == 2) freopen(argv[1], "r", stdin);
    ios_base::sync_with_stdio(0);

    for (int n = IU; n--; ) {
        uint64_t b = (((IUL + 1) * 1000000 - 1) & ~(MUST_DIVIDE - 1));
        if (b % 5 == 0)
            b -= MUST_DIVIDE;
        b %= M;
        I t = { b % MLOW, b / MLOW };
        cout << exponent(t) << '\n';
    }

    return 0;
}