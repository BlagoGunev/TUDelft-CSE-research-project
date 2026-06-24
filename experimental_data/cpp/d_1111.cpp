#include <cassert>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
using std::cin; using std::cout;
using std::endl;
using std::bitset; using std::map;
using std::queue; using std::priority_queue;
using std::set; using std::string;
using std::stringstream; using std::vector;
using std::pair; using std::make_pair;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef pair<ULL, ULL> puu;
#ifdef DEBUG
using std::cerr;
#define pass cerr << "[" << __FUNCTION__ << "] : line = " << __LINE__ << endl;
#define display(x) cerr << #x << " = " << x << endl;
#define displaya(a, st, n)                                                     \
  {                                                                            \
    cerr << #a << " = {";                                                      \
    for (int qwq = (st); qwq <= (n); ++qwq)                                    \
      if (qwq == (st))                                                         \
        cerr << a[qwq];                                                        \
      else                                                                     \
        cerr << ", " << a[qwq];                                                \
    cerr << "}" << endl;                                                       \
  }
#define displayv(a) displaya(a, 0, (int)(a.size() - 1))
#include <ctime>
class MyTimer {
    clock_t st;
public:
    MyTimer() { cerr << std::fixed << std::setprecision(0); reset(); }
    ~MyTimer() { report(); }
    void reset() { st = clock_t(); }
    void report() {  cerr << "Time consumed: " << (clock() - st) * 1e3 / CLOCKS_PER_SEC << "ms" << endl; }
} myTimer;
#else
#define cerr if(false) std::cout
#define pass ;
#define display(x) ;
#define displaya(a, st, n) ;
#define displayv(a) ;
class MyTimer {
public: void reset() {} void report() {}
} myTimer;
#endif

template<typename A, typename B>
std::ostream& operator << (std::ostream &cout, const pair<A, B> &x) {
    return cout << "(" << x.first << ", " << x.second << ")";
}
template<typename T1, typename T2>
inline bool chmin(T1 &a, const T2 &b) { return a > b ? a = b, true : false; }
template<typename T1, typename T2>
inline bool chmax(T1 &a, const T2 &b) { return a < b ? a = b, true : false; }
#ifdef QUICK_READ
char pool[1<<15|1],*it=pool+32768;
#define getchar() (it>=pool+32768?(pool[fread(pool,sizeof(char),1<<15,stdin)]=EOF,*((it=pool)++)):*(it++))
#endif
inline int readint() {
    int a = 0; char c = getchar(), p = 0;
    while(isspace(c)) c = getchar();
    if(c == '-') p = 1, c = getchar();
    while(isdigit(c)) a = a*10 + c - '0', c = getchar();
    return p ? -a : a;
}

const int maxN = 100000 + 233;
const LL P = 1000000007;
LL qpow(LL a, LL b) {
    LL r = 1;
    while(b) {
        if(b & 1) (r *= a) %= P;
        (a *= a) %= P; b >>= 1;
    }
    return r;
}
char s[maxN];
int n, q;
LL fac[maxN], ifac[maxN];
int freq[128];

LL choose(int n, int k) {
    if(k < 0 || k > n) return 0;
    return fac[n] * ifac[k] % P * ifac[n - k] % P;
}

void inc(int &x, int y) {
    (x += y) >= P ? x -= P : x;
}
void dec(int &x, int y) {
    (x -= y) < 0 ? x += P : x;
}

int f[maxN];
map< int, vector<int> > g;
map< pii, vector<int> > h;

int main() {
    std::ios::sync_with_stdio(false);
    cin >> (s + 1);
    cin >> q;
    n = strlen(s + 1);
    memset(freq, 0, sizeof(freq));
    for(int i = 1; i <= n; ++i) freq[(int)s[i]]++;
    fac[0] = 1;
    for(int i = 1; i <= n; ++i) fac[i] = fac[i - 1] * i % P;
    ifac[n] = qpow(fac[n], P - 2);
    for(int i = n - 1; i >= 0; --i) ifac[i] = ifac[i + 1] * (i + 1) % P;
    LL prod = 1;
    for(int i = 0; i < 128; ++i) prod = prod * ifac[freq[i]] % P;
    prod = prod * fac[n / 2] % P * fac[n / 2] % P;
    memset(f, 0, sizeof(f));
    f[0] = 1;
    for(int c = 0; c < 128; ++c) if(freq[c]) {
        for(int i = n / 2 - freq[c]; i >= 0; --i) inc(f[i + freq[c]], f[i]);
    }
    set<int> S(freq, freq + 128);
    for(int x : S) {
        g[x] = vector<int>(f, f + n / 2 + 1);
        auto &now = g[x];
        for(int i = 0; i + x <= n / 2; ++i) dec(now[i + x], now[i]);
    }
    for(int x : S) for(int y : S) if(x <= y) {
        h[pii(x, y)] = g[x];
        auto &now = h[pii(x, y)];
        for(int i = 0; i + y <= n / 2; ++i) dec(now[i + y], now[i]);
    }
    while(q--) {
        int x, y; cin >> x >> y;
        if(s[x] == s[y]) {
            x = freq[(int)s[x]];
            printf("%lld\n", f[n / 2] * prod % P);
        } else {
            x = freq[(int)s[x]]; y = freq[(int)s[y]];
            if(x + y > n / 2) {
                printf("0\n");
                continue;
            }
            if(x > y) std::swap(x, y);
            LL ways = f[n / 2] - g[x][n / 2 - x] - g[y][n / 2 - y] + h[pii(x, y)][n / 2 - x - y] * 2;
            display(ways);
            ways += 2 * P; ways %= P;
            printf("%lld\n", ways * prod % P);
        }
    }
    return 0;
}