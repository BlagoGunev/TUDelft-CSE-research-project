#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

#define RG register
#define IL __inline__ __attribute__((always_inline))

namespace PROG {

namespace io {
    const int MaxBuff = 1 << 15;
    const int Output = 1 << 23;
    char B[MaxBuff], *S = B, *T = B;
#define getc() ((S == T) && (T = (S = B) + fread(B, 1, MaxBuff, stdin), S == T) ? 0 : *S++)
    char Out[Output], *iter = Out;
    IL void flush()
    {
        fwrite(Out, 1, iter - Out, stdout);
        iter = Out;
    }
}

template <class Type>
IL Type read()
{
    using namespace io;
    RG char ch;
    RG Type ans = 0;
    RG bool neg = 0;
    while (ch = getc(), (ch < '0' || ch > '9') && ch != '-')
        ;
    ch == '-' ? neg = 1 : ans = ch - '0';
    while (ch = getc(), '0' <= ch && ch <= '9')
        ans = ans * 10 + ch - '0';
    if (ch == '.') {
        double t = 1;
        while (ch = getc(), '0' <= ch && ch <= '9')
            ans = ans * 10 + ch - '0', t *= 10;
        ans /= t;
    }
    return neg ? -ans : ans;
}
template <>
IL string read<string>()
{
    using namespace io;
    static char str[100000];
    int top = 0;
    char ch;
    string ans;
    bool neg = 0;
    while (ch = getc(), isspace(ch))
        ;
    str[top++] = ch;
    while (ch = getc(), !isspace(ch))
        str[top++] = ch;
    str[top] = 0;
    return string(str);
}
template <class Type>
IL void Print(Type x, char ch = '\n')
{
    using namespace io;
    if (!x)
        *iter++ = '0';
    else {
        if (x < 0)
            *iter++ = '-', x = -x;
        static int s[100];
        RG int t = 0;
        while (x)
            s[++t] = x % 10, x /= 10;
        while (t)
            *iter++ = '0' + s[t--];
    }
    if (ch)
        *iter++ = ch;
}
IL void puts(const char* s, char ch = '\n')
{
    using namespace io;
    while (*s)
        *iter++ = *s++;
    if (ch)
        *iter++ = ch;
}
}

namespace PROG {

//Declare your variables and functions here

const int N = 200005;

struct Record {
    int x1, y1, x2, y2;
} a[N];

int n;
Record pre[N], suf[N];

inline Record test(Record a, Record b)
{
    Record ret;
    ret.x1 = max(a.x1, b.x1);
    ret.y1 = max(a.y1, b.y1);
    ret.x2 = min(a.x2, b.x2);
    ret.y2 = min(a.y2, b.y2);
    return ret;
}

inline bool can(Record a)
{
    return (a.x1 <= a.x2 && a.y1 <= a.y2);
}

int main()
{

    n = read<int>();
    for (int i = (1); i <= (n); i++) {
        a[i].x1 = read<int>();
        a[i].y1 = read<int>();
        a[i].x2 = read<int>();
        a[i].y2 = read<int>();
    }
    pre[1] = a[1];
    for (int i = (2); i <= (n); i++)
        pre[i] = test(pre[i - 1], a[i]);
    suf[n] = a[n];
    for (int i = (n - 1); i >= (1); i--)
        suf[i] = test(suf[i + 1], a[i]);
    if (can(suf[2])) {
        printf("%d %d\n", suf[2].x1, suf[2].y1);
        return 0;
    }
    if (can(pre[n - 1])) {
        printf("%d %d\n", pre[n - 1].x1, pre[n - 1].y1);
        return 0;
    }
    for (int i = 2; i <= (n - 1); i++) {
        Record now = test(pre[i - 1], suf[i + 1]);
        if (can(now)) {
            printf("%d %d\n", now.x1, now.y1);
            return 0;
        }
    }

    return 0;
}
}

int main(void)
{
    PROG::main();
    return 0;
}