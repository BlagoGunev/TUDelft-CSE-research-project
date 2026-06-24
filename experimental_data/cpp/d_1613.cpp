#include <bits/extc++.h>

using __gnu_pbds::gp_hash_table;
using namespace std;
#define forn(i, j, k) for(auto i=j;i<k;i++)
#define Forn(i, j, k) for(auto i=j;i>k;i--)
#define mem(i, j) memset(i,j,sizeof(i))
#define mk make_pair
#define pb push_back
#define ctz __builtin_ctzll
#ifdef XYL_DEBUG
#define debug(x) cerr<<(#x)<<" : "<<(x)<<' '
#define bug() cerr<<'\n'
#define debugArr(x, i, n) cerr<<(#x)<<" : ";forn(_,i,n)cerr<<x[_]<<' '
#else
#define bug() 0
#define debug(x) 0
#define debugArr(x,i,n) 0
#endif
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
namespace fastIO {
#define gc()(is==it?it=(is=in)+fread(in,1,Q,stdin),(is==it?EOF:*is++):*is++)
#define pc(c) (QQ?*os++=(c),QQ--:0,out())
#define read(v, j, n) forn(_, j, n)rd(v[_])
#define outs(x, j, n) forn(_, j, n)( _ == j ? opt(x[_]) : opt(x[_]),opt(' '))
    const int Q = (1 << 20) + 1;
    int QQ = Q - 10;
    char in[Q], *is = in, *it = in;
    char ou[Q], *os = ou;
    char tem[107];
    namespace rd {

        void out() {
            *os = 0;
            fwrite(fastIO::ou, 1, os - fastIO::ou, stdout);
            os = fastIO::ou, QQ = Q - 10;
        }

        template<class T>
        void output(T x) {
            if (x / 10)output(x / 10);
            pc(x % 10 + '0');
        }

        template<class T>
        void opt(T x) {
            if (x < 0)pc('-'), output(-x);
            else output(x);
        }

        void opt(const char *x) { while (*x)pc(*x++); }

        void opt(char *x) { while (*x)pc(*x++); }

        void opt(char x) { pc(x); }

        void opt(const double &x) {
            sprintf(tem, "%.10lf%c", x, 0);
            opt(tem);
        }

        void opt(const long double &x) {
            sprintf(tem, "%.10Lf%c", x, 0);
            opt(tem);
        }

        template<class Tx, class...T>
        void opt(Tx x, T...x1) {
            opt(x), opt(x1...);
        }

        template<class T>
        void optl(T x) {
            opt(x), pc('\n');
        }

        template<class T>
        void rd(T &x) {
            char ch;
            x = 0;
            bool fl = false;
            while (!isdigit(ch = gc()))(ch == '-') && (fl = true);
            for (x = (ch - '0'); isdigit(ch = gc()); x = x * 10 + (ch - '0'));
            fl && (x = -x);
        }

        void rd(char *t) {
            char *p = t;
            while ((*p = gc()) != ' ' && *p != '\n' && *p != EOF)p++;
            *p = 0;
        }

        void rdl(char *t) {
            char *p = t;
            while ((*p = gc()) != '\n' && *p != EOF)p++;
            *p = 0;
        }

        template<class Tx, class...T>
        void rd(Tx &x, T &...x1) {
            rd(x);
            rd(x1...);
        }

    }
#undef gc
#undef pc
}
using fastIO::rd::rd;
using fastIO::rd::opt;
using fastIO::rd::optl;


namespace Modulo {
    using type = int;

    const type mod = 998244353;

    type ad(type x, type y) { return x + y >= mod ? x + y - mod : x + y; }

    type sub(type x, type y) { return ad(x, mod - y); }

    type mul(type x, type y) { return 1LL * x * y % mod; }

    void iadd(type &x, type y) { x = ad(x, y); }

    void imul(type &x, type y) { x = mul(x, y); }

    type qm(type x, type y = mod - 2) {
        type ret = 1;
        while (y) {
            if (y & 1) ret = mul(x, ret);
            x = mul(x, x);
            y >>= 1;
        }
        return ret;
    }

    type div(type x, type y) {
        if (x % y == 0)return x / y;
        return mul(x, qm(y));
    }

    template<class ...Args>
    type ad(type a, type b, Args ...args) { return ad(ad(a, b), args...); }

    template<class ...Args>
    type mul(type a, type b, Args ...args) { return mul(mul(a, b), args...); }

    type gcd(type a, type b) {
        if (!a || !b)return a + b;
        auto tmp = ctz(a | b);
        b >>= ctz(b);
        while (a) {
            a >>= ctz(a);
            if (a < b)swap(a, b);
            a -= b;
        }
        return b << tmp;
    }

    type lcm(type a, type b) { return mul(a / gcd(a, b), b); }
}
using namespace Modulo;
const int maxn = 5e5 + 20, maxm = 5e7 + 10;
bool MULTI = true;


void pre() {

}

int n;
int arr[maxn];
int arr2[maxn][2];

void solve() {
    rd(n);
    read(arr, 0, n);
    forn(i, 0, n + 10)arr2[i][1] = arr2[i][0] = 0;
    arr2[0][0] = 1;
    forn(i, 0, n) {
        int nm = arr[i];
        if (nm)arr2[nm - 1][1] = ad(arr2[nm - 1][0], mul(2, arr2[nm - 1][1]));
        arr2[nm + 1][1] = mul(2, arr2[nm + 1][1]);
        arr2[nm + 1][0] = ad(arr2[nm][0], mul(2, arr2[nm + 1][0]));
    }
    int ans = 0;
    forn(i, 0, n + 5)ans = ad(ans, arr2[i][0], arr2[i][1]);
    optl(sub(ans, 1));
}

signed main() {
#ifdef XYL_FREOPEN
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    auto clock = chrono::steady_clock::now();
#endif
    pre();
    int t = 1;
    if (MULTI)rd(t);
    for (int i = 1; i <= t; i++) {
        solve();
    }
    fastIO::rd::out();
#ifdef XYL_FREOPEN
    auto ends = chrono::steady_clock::now();
    cerr << "\ntimeit: " << chrono::duration_cast<chrono::microseconds>(ends - clock).count() << "μs\n";
    freopen("CON", "w", stdout);
    freopen("1.out", "r", stdin);
    char seq[(1u << 20u) + 7];
    while (!feof(stdin))fwrite(seq, 1, fread(seq, 1, 1u << 20u, stdin), stdout);
#endif
    return 0;
}