#include <bits/stdc++.h>
// Author: Igor Smirnov
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
/**
 * Fast input-output author: Sergey Kopeliovich (Burunduk30@gmail.com)
 */
#define VERSION "0.1.4"

#include <cassert>
#include <cstdio>
#include <algorithm>
#include <string>

/** Fast allocation */

//#define FAST_ALLOCATOR_MEMORY 2e8

#ifdef FAST_ALLOCATOR_MEMORY
int allocator_pos = 0;
	char allocator_memory[(int)FAST_ALLOCATOR_MEMORY];
	inline void * operator new ( size_t n ) {
		char *res = allocator_memory + allocator_pos;
		allocator_pos += n;
		assert(allocator_pos <= (int)FAST_ALLOCATOR_MEMORY);
		return (void *)res;
	}
	inline void operator delete ( void * ) noexcept { }
	//inline void * operator new [] ( size_t ) { assert(0); }
	//inline void operator delete [] ( void * ) { assert(0); }
#endif

/** Fast input-output */

template <class T = int> inline T readInt();
inline double readDouble();
inline int readUInt();
inline int readChar(); // first non-blank character
inline void readWord( char *s );
inline bool readLine( char *s ); // do not save '\n'
inline bool isEof();
inline int getChar();
inline int peekChar();
inline bool seekEof();
inline void skipBlanks();
inline std::string readString();

template <class T> inline void writeInt( T x, char end = 0, int len = -1 );
inline void writeChar( int x );
inline void writeWord( const char *s );
inline void writeDouble( double x, int len = 0 );
inline void flush();

static struct buffer_flusher_t {
    ~buffer_flusher_t() {
        flush();
    }
} buffer_flusher;

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef unsigned int ui;
typedef unsigned long long ull;

inline void init() {
    srand(time(0));
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

// Number Theory
template <class T, class S>  inline void rmax(T& a, S b) {
    a = max(a, (T) b);
}
template <class T, class S>  inline void rmin(T& a, S b) {
    a = min(a, (S) b);
}
inline ll mul(ll a, ll b, ll m) {
    return a * b % m;
}
inline ll binpow(ll n, ll p, ll m) {
    if (!p) return 1;
    if (p & 1) return mul(n, binpow(n, p - 1, m), m);
    ll v = binpow(n, p / 2, m);
    return mul(v, v, m);
}
/*template <class T> inline pair<T, T> gcdex(T a, T b) {
    if (b == 0) return {1, 0};
    auto [x, y] = gcdex(b, a % b);
    return {y, x - a / b * y};
}*/
inline bool is_prime(ll n) {
    for (ll i = 2; i * i <= n; ++i)
        if (n % i == 0) return 0;
    return 1;
}
inline vector<ll> factor(ll n) {
    vector<ll> ans;
    for (ll i = 2; i * i <= n; ++i)
        while (n % i == 0)
            ans.push_back(i), n /= i;
    if (n != 1)
        ans.push_back(n);
    return ans;
}
inline vector<ll> divisors(ll n ) {
    vector<ll> ret;
    for (ll i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n)
                ret.push_back(n / i);
        }
    }
    return ret;
}
inline vector<pair<ll, int>> factor_pows(ll n) {
    auto fac = factor(n);
    vector<pair<ll, int>> ret;
    int L = 0;
    while (L < (int) fac.size()) {
        int R = L;
        while (R < (int) fac.size() && fac[R] == fac[L]) ++R;
        ret.push_back({fac[L], R - L});
        L = R;
    }
    return ret;
}
inline ll gen_random_prime(ll L = (int) 1e9) {
    L += rand() % 4242;
    while (!is_prime(L)) ++L;
    return L;
}
inline ll nmod(ll a, ll m) {
    return (a % m + m) % m;
}
inline int mrand() {
    return abs((1LL * rand() << 15) + rand());
}

// Strings
struct HashedString {
    string s;
    vector<ll> MOD, POW;
    vector<vector<ll>> hash; // 1-index
    vector<vector<ll>> pows;
    string substr(int L, int n) { return s.substr(L, n); }
    int size() const { return s.size(); }
    char operator[](int n) const { return s[n]; }
    vector<ll> get_hash(int L, int R) { // 0-index [L; R)
        vector<ll> ret;
        for (int i = 0; i < (int) hash.size(); ++i) {
            ret.push_back(nmod(hash[i][R] - hash[i][L] * pows[i][R - L], MOD[i]));
        }
        return ret;
    }
    bool equal(int L1, int R1, int L2, int R2) { // 0-index [L; R)
        return get_hash(L1, R1) == get_hash(L2, R2);
    }
    void operator+=(char c) {
        s += c;
        for (int i = 0; i < (int) hash.size(); ++i) {
            ll m = MOD[i], p = POW[i], cp = pows[i].back(), cm = hash[i].back();
            cm = (cm * p + c) % m, cp = cp * p % m;
            hash[i].push_back(cm);
            pows[i].push_back(cp);
        }
    }
    void operator+=(const string& oth) {
        for (int i = 0; i < (int) hash.size(); ++i)
            for (char c : oth)
                (*this) += c;
    }
    HashedString(const string& s, int n = 1) {
        for (int i = 0; i < n; ++i) {
            MOD.push_back(gen_random_prime());
            POW.push_back(gen_random_prime());
            hash.push_back({0}), pows.push_back({1});
        }
        (*this) += s;
    }
};

#ifdef ONLINE_JUDGE
#define cerr if (false) cerr
#endif
#define forn(i, n) for (int i = 0; i < n; ++i)
#define all(a) (a).begin(), (a).end()
#define rev(a) reverse(all(a))
#define csp(a) cout << a << ' '
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define hash hash42
#define next next42

const int MAXN = 1e5 + 42;

signed main() {
    init();
    ll n = readInt<ll>();
    int m = readInt();
    ll k = readInt<ll>();
    vector<ll> drop(m);
    for (int i = 0; i < m; ++i) {
        drop[i] = readInt<ll>() - 1;
    }
    ll ctr = 0;
    int ptr = 0;
    ll dropped = 0;
    while (ptr != m) {
        ll st_ptr = ptr;
        ll index_start = (drop[ptr] - dropped) / k * k;
        ll index_end = index_start + k;
        ++ptr;
        while (ptr < m && (drop[ptr] - dropped) < index_end) {
            ++ptr;
        }
        ++ctr;
        dropped += ptr - st_ptr;
    }
    cout << ctr << endl;
}

/** Read */

static const int buf_size = 4096;

static unsigned char buf[buf_size];
static int buf_len = 0, buf_pos = 0;

inline string readString() {
    const int MAX = 1e6 + 42;
    static char buf[MAX];
    readWord(buf);
    return string(buf);
}

inline bool isEof() {
    if (buf_pos == buf_len) {
        buf_pos = 0, buf_len = fread(buf, 1, buf_size, stdin);
        if (buf_pos == buf_len)
            return 1;
    }
    return 0;
}

inline int getChar() {
    return isEof() ? -1 : buf[buf_pos++];
}

inline int peekChar() {
    return isEof() ? -1 : buf[buf_pos];
}

inline bool seekEof() {
    int c;
    while ((c = peekChar()) != -1 && c <= 32)
        buf_pos++;
    return c == -1;
}

inline void skipBlanks() {
    while (!isEof() && buf[buf_pos] <= 32U)
        buf_pos++;
}

inline int readChar() {
    int c = getChar();
    while (c != -1 && c <= 32)
        c = getChar();
    return c;
}

inline int readUInt() {
    int c = readChar(), x = 0;
    while ('0' <= c && c <= '9')
        x = x * 10 + c - '0', c = getChar();
    return x;
}

template <class T>
inline T readInt() {
    int s = 1, c = readChar();
    T x = 0;
    if (c == '-')
        s = -1, c = getChar();
    else if (c == '+')
        c = getChar();
    while ('0' <= c && c <= '9')
        x = x * 10 + c - '0', c = getChar();
    return s == 1 ? x : -x;
}

inline double readDouble() {
    int s = 1, c = readChar();
    double x = 0;
    if (c == '-')
        s = -1, c = getChar();
    while ('0' <= c && c <= '9')
        x = x * 10 + c - '0', c = getChar();
    if (c == '.') {
        c = getChar();
        double coef = 1;
        while ('0' <= c && c <= '9')
            x += (c - '0') * (coef *= 1e-1), c = getChar();
    }
    return s == 1 ? x : -x;
}

inline void readWord( char *s ) {
    int c = readChar();
    while (c > 32)
        *s++ = c, c = getChar();
    *s = 0;
}

inline bool readLine( char *s ) {
    int c = getChar();
    while (c != '\n' && c != -1)
        *s++ = c, c = getChar();
    *s = 0;
    return c != -1;
}

/** Write */

static int write_buf_pos = 0;
static char write_buf[buf_size];

inline void writeChar( int x ) {
    if (write_buf_pos == buf_size)
        fwrite(write_buf, 1, buf_size, stdout), write_buf_pos = 0;
    write_buf[write_buf_pos++] = x;
}

inline void flush() {
    if (write_buf_pos)
        fwrite(write_buf, 1, write_buf_pos, stdout), write_buf_pos = 0;
}

template <class T>
inline void writeInt( T x, char end, int output_len ) {
    if (x < 0)
        writeChar('-'), x = -x;

    char s[24];
    int n = 0;
    while (x || !n)
        s[n++] = '0' + x % 10, x /= 10;
    while (n < output_len)
        s[n++] = '0';
    while (n--)
        writeChar(s[n]);
    if (end)
        writeChar(end);
}

inline void writeWord( const char *s ) {
    while (*s)
        writeChar(*s++);
}

inline void writeDouble( double x, int output_len ) {
    if (x < 0)
        writeChar('-'), x = -x;
    int t = (int)x;
    writeInt(t), x -= t;
    writeChar('.');
    for (int i = output_len - 1; i > 0; i--) {
        x *= 10;
        t = std::min(9, (int)x);
        writeChar('0' + t), x -= t;
    }
    x *= 10;
    t = std::min(9, (int)(x + 0.5));
    writeChar('0' + t);
}