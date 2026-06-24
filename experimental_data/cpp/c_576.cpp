//pb_ds NOI template 20150710
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cassert>
#include <cmath>
#include <vector>
#include <set>
#include <utility>
#include <queue>
#define For(i, a, b) for(register int i = a, ___u = b; i <= ___u; ++i)
#define ForDown(i, a, b) for(register int i = b, ___d = a; i >= ___d; --i)
#define cmax(i, j) ((i) < (j) ? (i) = (j) : (i))
#define cmin(i, j) ((i) > (j) ? (i) = (j) : (i))
#define dmax(i, j) ((j) < (i) ? (i) : (j))
#define dmin(i, j) ((i) < (j) ? (i) : (j))
#define ddel(i, j) ((i) > (j) ? (i) - (j) : (j) - (i))
#define dabs(i) ((i) > 0 ? (i) : -(i))
#define dsqr(x) ((x) * (x))
#define lowbit(i) ((i) & -(i))

//#include <bitset>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/tree_policy.hpp>

namespace io
{
    const int MAXBUF = 1 << 22;
    char B[MAXBUF], *S = B, *T = B;
    #define getc() (S == T && (T = (S = B) + fread(B, 1, MAXBUF, stdin), S == T) ? 0 : *S++)
    #define fastcall __attribute__((optimize("-O3")))
    template<class Type> inline Type read()
    {
        register Type aa = 0;
        register bool bb = 0;
        register char ch, *S = io::S, *T = io::T;
        for(ch = getc(); (ch < '0' || ch > '9') && ch != '-'; ch = getc())
            ;
        for(ch == '-' ? bb = 1 : aa = ch - '0', ch = getc(); '0' <= ch && ch <= '9'; ch = getc())
            aa += (aa << 3) + aa + ch - '0';
        io::S = S, io::T = T;
        return bb ? -aa : aa; 
    }
    int (*F)() = read<int>;
    
    template<> inline double read()
    {
        register double aa = 0, bb;
        register bool cc = 0;
        register char ch;
        register char *S = io::S, *T = io::T;
        for(ch = getc(); (ch < '0' || ch > '9') && ch != '-'; ch = getc())
            ;
        for(ch == '-' ? cc = 1 : aa = ch - '0', ch = getc(); '0' <= ch && ch <= '9'; ch = getc())
            aa = aa * 10 + ch - '0';
        if(ch == '.')
        {
            bb = 1;
            while(ch = getc(), ch >= '0' && ch <= '9')
                aa += (bb *= 0.1) * (ch - '0');
        }
        io::S = S, io::T = T;
        return cc ? -aa : aa;
    }
    
    char buff[MAXBUF], *iter = buff;
    template<class T>inline void P(register T x, register char ch = '\n')
    {
        static int stack[110];
        register int O = 0;
        register char *iter = io::iter;
        if(!x)*iter++ = '0';
        else
        {
            (x < 0) ? x = -x, *iter++ = '-' : 1;
            for(; x; x /= 10)
                stack[++O] = x % 10;
            for(; O; *iter++ = '0' + stack[O--])
                ;
        }
        *iter++ = ch, io::iter = iter;
    }

    inline int gets_a(register char *o)
    {
        register char *s = o, ch = getc();
        register char *S = io::S, *T = io::T;
        for(; ch < 'a' || 'z' < ch; ch = getc())
            ;
        for(; 'a' <= ch && ch <= 'z'; ch = getc())
            *s++ = ch;
        *s = 0;
        io::S = S, io::T = T;
        return s - o;
    }

    inline char get_a()
    {
        register char ch = getc();
        while(ch < 'a' || 'z' < ch) ch = getc();
        //puts("1");
        return ch;
    }
    
    inline void putc(register char ch) {*iter++ = ch;}
    
    inline void output() {fwrite(buff, 1, iter - buff, stdout), iter = buff;}
}


#define RG register
#define set_file(FILE) freopen(FILE ".in", "r", stdin), freopen(FILE ".out", "w", stdout)
#define close_file() fclose(stdin), fclose(stdout)
//#include <ext/pb_ds/priority_queue.hpp>
//#include <stdarg.h>

namespace pb_ds
{
    using io::P;
    
    struct Po {int x, y, id;} p[1000010];
    
    inline bool cmp(RG const Po& a, RG const Po& b)
    {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    }
    
    inline void main()
    {
        RG int (*F)() = io::F;
        RG int n = F();
        RG int x, y;
        For(i, 1, n)
        {
            x = F(), y = F();
            p[i] = (Po) {x / 1000, ((x / 1000) & 1) ? -y : y, i}; 
        }
        std::sort(p + 1, p + n + 1, cmp);
        For(i, 1, n) P(p[i].id, ' ');
        io::putc('\n');
        
        
    }
}

int main()
{
    //set_file("matchfit");
    pb_ds::main();
    io::output();
    close_file();
}
/*
10 6
(()(()))()
3 5
1 7
6 8
3 7
4 5
4 10
*/