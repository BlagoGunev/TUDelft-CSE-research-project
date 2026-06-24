#include <bits/stdc++.h>

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define in(x) int (x); input((x));
#define x first
#define y second
#define fi first
#define se second
#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)
#define for1(i, n) for(int i = 1; i <= (int)(n); ++i)


typedef int itn;

#define next next12345
#define prev prev12345
#define left lefdsf232
#define right rig43783
#define x1 x12345
#define y1 y12345

using namespace std;

template<typename T>
T gcd(T x, T y) {
    while (y > 0) {
        x %= y;
        swap(x, y);
    }
    return x;
}

template<class _T>
inline _T sqr(const _T &x) {
    return x * x;
}

template<class _T>
inline string tostr(const _T &a) {
    ostringstream os("");
    os << a;
    return os.str();
}

typedef long double ld;
typedef long long ll;
typedef long long i64;
typedef unsigned long long ull;
typedef unsigned long long u64;
typedef pair<int, int> PII;
typedef pair<int, int> pii;
const long double PI = 3.1415926535897932384626433832795L;

template<typename T>
inline void input(T &a) {
    static int ed;
    a = 0;
    while (!isdigit(ed = getchar()) && ed != '-') { }
    char neg = 0;
    if (ed == '-') {
        neg = 1;
        ed = getchar();
    }
    while (isdigit(ed)) {
        a = 10 * a + ed - '0';
        ed = getchar();
    }
    if (neg) a = -a;
}

template<typename T = int>
inline T nxt() {
    T res;
    input(res);
    return res;
}
long long mod = 1000000007;

long long pw(long long a, long long n) {
    long long res = 1;
    while (n) {
        if (n & 1ll) {
            res = res * a % mod;
        }
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

long long inv(long long a) {
    return pw(a, mod - 2);
}

struct pt  {
    ll x, y;
    pt() {}
    pt(ll x, ll y) : x(x), y(y) {}
    inline pt operator + (const pt &r) const {
        return pt(x + r.x, y + r.y);
    }
    inline pt operator - (const pt &r) const {
        return pt(x - r.x, y - r.y);
    }
    inline bool operator < (const pt &r) const {
        if (x != r.x) return x < r.x;
        return y < r.y;
    }
    inline bool operator == (const pt &r) const {
        return x == r.x && y == r.y;
    }
};

inline ll dot(const pt &l, const pt &r) {
    return l.x * r.x + l.y * r.y;
}

inline ll cross(const pt &l, const pt &r) {
    return l.x * r.y - l.y * r.x;
}

const int N = 200000 + 100;
pt w[N];

deque<pt> s;

void solve() {
    int d = nxt();
    int n = nxt();
    int m = nxt();
    w[0] = pt(0, 0);
    for (int i = 1; i <= m; ++i) {
        w[i].x = nxt();
        w[i].y = nxt();
    }
    w[m + 1] = pt(d, 0);
    sort(w, w + m + 2);
    s.push_back(pt(0, n));
    ll madist = n;
    ll cost = 0;
    for (int i = 0; i <= m; ++i) {
        while (!s.empty() && s.back().x >= w[i].y) {
            madist -= s.back().y;
            s.pop_back();
        }
        ll delta = w[i + 1].x - w[i].x;
        if (delta > n) {
            cout << "-1\n";
            return;
        }
        ll startdetla = delta;
        while (!s.empty() && delta >= s.front().y) {
            cost += s.front().x * s.front().y;
            delta -= s.front().y;
            madist -= s.front().y;
            s.pop_front();
        }
        if (s.empty()) {
            cost += delta * w[i].y;
            s.push_back(pt(w[i].y, n - startdetla));
        } else {
            s.front().y -= delta;
            madist -= delta;
            cost += delta * s.front().x;
            s.push_back(pt(w[i].y, n - startdetla - madist));
        }
        madist = n - startdetla;
    }
    cout << cost << endl;
}

int main() {
    //#define int long
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
#define fname "race"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif

    solve();

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}