#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;

const int N = 200010, mod = 1e9 + 7, SZ = (1 << 18) + 5;
static char buf[SZ], *bgn = buf, *til = buf;
char getc() {
    if(bgn == til)  bgn = buf, til = buf + fread(buf, 1, SZ, stdin);
    return bgn == til ? EOF : *bgn++;
}
template<typename T>
void read(T &x) {
    char ch = getc();  T fh = 0;   x = 0;
    while(ch < '0' || ch > '9')    fh |= (ch == '-'), ch = getc();
    while(ch >= '0' && ch <= '9')   x = x * 10 + ch - '0', ch = getc();
    x = fh ? -x : x;
}
template<typename Type, typename... argc>
void read(Type &x, argc &...args)   {read(x), read(args...);}
template<typename T>
void print(T x) {
    if(x < 0)  putchar('-'), x = -x;
    if(x / 10)  print(x / 10);
    putchar(x % 10 + '0');
}
int n, a[N], qzh[N], f[N], g[N];
map<int, int> bk, bk2;
void mian() {
    read(n), bk.clear(), bk2.clear();
    for(int i = 0; i <= n + 1; ++i) f[i] = g[i] = 0;
    for(int i = 1; i <= n; ++i) read(a[i]), qzh[i] = qzh[i - 1] ^ a[i];
    f[n] = 3, g[n] = a[n] != a[n - 1] ? 1 : 3, f[n + 1] = g[n + 1] = 1;
    bk2[qzh[n - 1] ^ a[n]] = n - 1;
    for(int i = n - 1; i > 0; --i) {
        bk[qzh[i] ^ a[i + 1]] = i;
        int p = bk[qzh[i - 1]];
        if(p) {
            f[i] = (f[p + 2] + 2ll * g[p + 2] % mod) % mod * 3ll % mod;
        }
        else    f[i] = 3;
        // cerr << i << " : " << f[i] << " " << p << " ";
        if(i > 1) {
            bk2[qzh[i - 1] ^ a[i]] = i - 1;
            int p = bk2[qzh[i - 2]];
            if(p)   g[i] = (f[p + 2] + g[p + 2] * 2ll) % mod;
            else    g[i] = 1;
            // cerr << g[i] << " " << p << "\n";
        }
    }
    // cerr << "\n";
    print(f[1]), putchar('\n');
}
int main() {
    #ifdef Kelly
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
        freopen("err.txt", "w", stderr);
    #endif
    int T = 1;  read(T);
    while(T--)  mian();
    return 0; 
}