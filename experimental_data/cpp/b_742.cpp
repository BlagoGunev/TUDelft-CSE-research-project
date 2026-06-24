#include<bits/stdc++.h>

#define sp putchar(' ')
#define ln putchar('\n')
#ifdef __linux__
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#endif

typedef long long ll;
typedef std::pair<int, int> pii;

template<typename T>inline bool chkmin(T &a, T b){return b < a ? a = b, true : false;}
template<typename T>inline bool chkmax(T &a, T b){return b > a ? a = b, true : false;}

template<class T> inline T read(T &x)
{
    int sign = 1;
    char c = getchar();
    for(; !isdigit(c); c = getchar())
        if(c == '-')
            sign = -1;
    for(x = 0; isdigit(c); c = getchar())
        x = x * 10 + c - '0';
    return x *= sign;
}
template<class T> inline void write(T x)
{
    if(x == 0) {putchar('0'); return;}
    if(x < 0) {putchar('-'); x = -x;}
    static char s[20];
    int top = 0;
    for(; x; x /= 10)
        s[++ top] = x % 10 + '0';
    while(top)
        putchar(s[top --]);
}

const int maxN = 2e5 + 100;
int a[maxN];
int cnt[maxN];
int n, m;

int main()
{
    if(fopen("tmp.in", "r")) {
        freopen("tmp.in", "r", stdin);
        freopen("tmp.out", "w", stdout);
    }

    read(n), read(m);
    for(int i = 1; i <= n; ++i)
        read(a[i]);

    ll ans = 0;
    for(int i = 1; i <= n; ++i) {
        ans += cnt[m ^ a[i]];
        ++ cnt[a[i]];
    }
    write(ans), ln;

    return 0;
}