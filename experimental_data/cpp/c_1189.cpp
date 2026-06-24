#include <bits/stdc++.h>
using namespace std;
#define onlinejudge
#ifdef onlinejudge
static char inp[1024];
static char* stdinDataEnd = inp + sizeof (inp);
static const char* stdinPos = stdinDataEnd;
struct X{
    bool dig[256];
    X(){
        for(int i = 48; i <= 57; ++i) dig[i] = 1; dig['-'] = 1;
    }
    inline void readAhead(size_t amount)
    {
        size_t remaining = stdinDataEnd - stdinPos;
        if (remaining < amount) {
            memmove(inp, stdinPos, remaining);
            size_t sz = fread(inp + remaining, 1, sizeof (inp) - remaining, stdin);
            stdinPos = inp;
            stdinDataEnd = inp + remaining + sz;
            if (stdinDataEnd != inp + sizeof (inp))
                *stdinDataEnd = 0;
        }
    }
    long long operator () ()
    {
        bool s=true;
        register long long x(0);
        readAhead(24);
        while(!dig[*stdinPos])readAhead(24),stdinPos++;
        if(*stdinPos=='-')s=false;else x=*stdinPos - 48;
        ++stdinPos;
        while (dig[*stdinPos])
            x =(x<<1)+(x<<3)+(*stdinPos & 15),stdinPos++;
        return s ? x : -x;
    }
}Rint;
#else
static inline long long Rint()
{
    struct X{ bool dig[256]{}; X(){
            for(int i = 48; i <= 57; ++i) dig[i] = true; dig['-'] = true;
        }};
    static 	X f;register long long  v = 0;int c;bool s = true;
    while (!f.dig[c = getchar()]);
    if (c == '-') s = false; else if (f.dig[c]) v = c & 15;
    for (;f.dig[c = getchar()]; v = (v<<1) + (v<<3)+ (c & 15));
    return s ? v : -v;
}
#endif
template<class T> void re(T& x) {  x=Rint(); }
template<class Arg, class... Args> void re(Arg& first, Args&... rest) {
    re(first); re(rest...);
}
template<class T> void Re(T& x) {  cin>>x; }
template<class Arg, class... Args> void Re(Arg& first, Args&... rest) {
    re(first); re(rest...);
}
int a[100005];
inline long long getSum(int index)
{
    long long sum (0);
    while (index>0)
    {
        sum += a[index];
        index -= index & (-index);
    }
    return sum;
}
int main()
{

    int n,q,l,r,i;
    n=Rint();
    for(i=1; i<=n; i++)
    {
        a[i] += Rint();
        if(i + (i & -i) <= n)
            a[i + (i & -i)] += a[i];
    }
    q=Rint();
    while(q--)
    {
        re(l,r);
        cout<<(getSum(r)-getSum(l-1))/10<<'\n';
    }
}