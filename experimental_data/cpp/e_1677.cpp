//I wrote this code 4 u today

#include <bits/stdc++.h>



namespace IO {

    const int DPAIRSIZ = 1 << 18;

    char BB[DPAIRSIZ], *SS = BB, *TT = BB;



    inline char getcha() {

        return SS == TT && (TT = (SS = BB) + fread(BB, 1, DPAIRSIZ, stdin), SS == TT) ? EOF : *SS++;

    }



    template<typename T = int>

    inline T read() {

        T x = 0;

        int fu = 1;

        char c = getcha();

        while (c > 57 || c < 48) {

            if (c == 45) fu = -1;

            c = getcha();

        }

        while (c <= 57 && c >= 48) {

            x = x * 10 + c - 48;

            c = getcha();

        }

        x *= fu;

        return x;

    }



    template<typename T>

    inline void read(T &x) {

        x = 0;

        int fu = 1;

        char c = getcha();

        while (c > 57 || c < 48) {

            if (c == 45) fu = -1;

            c = getcha();

        }

        while (c <= 57 && c >= 48) {

            x = x * 10 + c - 48;

            c = getcha();

        }

        x *= fu;

    }



    template<typename T>

    inline void read(T *bg, T *ed) { while (bg != ed) read(*bg++); }



    inline void read(char &ch) {

        ch = getcha();

        while (ch <= 32) ch = getcha();

    }



    inline void read(char *s) {

        char ch = getcha();

        while (ch <= 32) ch = getcha();

        while (ch > 32) *s++ = ch, ch = getcha();

        *s = '\0';

    }



    inline void sread(char *s) {

        char ch = getcha();

        while (ch < 32) ch = getcha();

        while (ch >= 32) *s++ = ch, ch = getcha();

        *s = '\0';

    }



    inline void pread(char *&s) {

        char ch = getcha();

        while (ch <= 32) ch = getcha();

        while (ch > 32) *s++ = ch, ch = getcha();

        *s = '\0';

    }



    inline void spread(char *&s) {

        char ch = getcha();

        while (ch < 32) ch = getcha();

        while (ch >= 32) *s++ = ch, ch = getcha();

        *s = '\0';

    }



    template<typename T, typename ...Args>

    inline void read(T &x, Args &...args) {

        read(x);

        read(args...);

    }



    char out[DPAIRSIZ], *Out = out;

#define flush() fwrite(out, 1, Out - out, stdout)



    inline void putcha(char x) {

        *Out++ = x;

        if (Out - out >= (DPAIRSIZ)) flush(), Out = out;

    }



    template<typename T>

    inline void fprint(T x) {

        if (x < 0) putcha(45), x = -x;

        if (x > 9) fprint(x / 10);

        putcha(x % 10 + 48);

    }



    inline void print() { putcha(10); }



    template<typename T>

    inline void print(T x) {

        fprint(x);

        putcha(10);

    }



    inline void print(char *ch) {

        while (*ch != '\0') putcha(*(ch++));

        putcha(10);

    }



    inline void put(char *ch) { while (*ch != '\0') putcha(*(ch++)); }



    inline void print(const char *ch) {

        while (*ch != '\0') putcha(*(ch++));

        putcha(10);

    }



    inline void put(const char *ch) { while (*ch != '\0') putcha(*(ch++)); }



    template<typename T, typename ...Args>

    inline void print(T x, Args ...args) {

        fprint(x);

        putcha(32);

        print(args...);

    }



    template<typename ...Args>

    inline void print(const char *ch, Args ...args) {

        while (*ch != '\0') putcha(*(ch++));

        putcha(32);

        print(args...);

    }



    template<typename ...Args>

    inline void print(char *ch, Args ...args) {

        while (*ch != '\0') putcha(*(ch++));

        putcha(32);

        print(args...);

    }



    template<typename T, typename ...Args>

    inline void printl(T x, Args ...args) {

        fprint(x);

        putcha(10);

        printl(args...);

    }



    template<typename ...Args>

    inline void printl(const char *ch, Args ...args) {

        while (*ch != '\0') putcha(*(ch++));

        putcha(10);

        printl(args...);

    }



    template<typename ...Args>

    inline void printl(char *ch, Args ...args) {

        while (*ch != '\0') putcha(*(ch++));

        putcha(10);

        printl(args...);

    }



    template<typename T>

    inline void sprint(T x) {

        fprint(x);

        putcha(32);

    }



    template<typename T, typename ...Args>

    inline void sprint(T x, Args ...args) {

        fprint(x);

        putcha(32);

        sprint(args...);

    }



    template<typename T>

    inline void sprint(T *bg, T *ed) { while (bg != ed) sprint(*bg++); }



    template<typename T>

    inline void print(T *bg, T *ed) {

        while (bg != ed) sprint(*bg++);

        putcha(10);

    }



    template<typename T>

    inline void printl(T *bg, T *ed) { while (bg != ed) print(*bg++); }



    class AutoFlush {

    public:

        ~AutoFlush() { flush(); }

    } __AutoFlush;

} // namespace IO

using namespace IO;



#define vc vector



#define nd node*

#define pnd pair<nd, nd>



using namespace std;

typedef long long ll;

typedef vector<ll> vll;

typedef pair<ll, ll> pll;

typedef vc<pll> vpll;

typedef vc<vll> vvll;

typedef vc<vpll> vvpll;



template<const ll MOD>

struct mod_mul : std::multiplies<const ll> {

    ll operator()(const ll a, const ll b) {

        return (a * b) % MOD;

    }

};





template<typename T>

inline void sort(T &a) {

    sort(a.begin(), a.end());

}



template<typename T>

inline void unique(T &a) {

    a.resize(unique(a.begin(), a.end()) - a.begin());

}



template<typename T>

inline void reverse(T &a) {

    reverse(a.begin(), a.end());

}



const ll INF = 9023372036854775808ll;

const ll MOD = 1000000007ll;



struct Sx {

    int n;

    vc<ll> sm;

    vc<int> cnt;

    struct md {

        int mul = 0;

        int ch = -1;

        int add = 0;

    };

    vc<md> mod;



    Sx(int n) : n(n), sm(n * 4), cnt(n * 4), mod(n * 4) {}



    void merge(md &x, md y) {

        if (x.ch == -1) x.mul += y.mul;

        else x.add += y.mul * x.ch;

        if (y.ch != -1) {

            x.add += y.add;

            x.ch = y.ch;

        }

    }



    void push(int l, int r, int v) {

        sm[v] += (ll) cnt[v] * mod[v].mul + mod[v].add * (r - l + 1);

        if (mod[v].ch != -1) cnt[v] = (r - l + 1) * mod[v].ch;

        if (l != r) merge(mod[v * 2], mod[v]), merge(mod[v * 2 + 1], mod[v]);

        mod[v] = md();

    }



    void add() {

        push(0, n - 1, 1);

        mod[1].mul += 1;

    }



    ll get(int l_, int r_, int l, int r, int v) {

        if (r_ < l || r < l_) return 0;

        push(l, r, v);

        if (l_ <= l && r <= r_) return sm[v];

        int mid = (l + r) / 2;

        return

                get(l_, r_, l, mid, v * 2) +

                get(l_, r_, mid + 1, r, v * 2 + 1);

    }



    ll get(int l, int r) {

        return get(l, r, 0, n - 1, 1);

    }



    void modify(int l_, int r_, bool x, int l, int r, int v) {

        if (l_ <= l && r <= r_) return mod[v].ch = x, push(l, r, v);

        push(l, r, v);

        if (r < l_ || r_ < l) return;

        int mid = (l + r) / 2;

        modify(l_, r_, x, l, mid, v * 2), modify(l_, r_, x, mid + 1, r, v * 2 + 1);

        sm[v] = sm[v * 2] + sm[v * 2 + 1];

        cnt[v] = cnt[v * 2] + cnt[v * 2 + 1];

    }



    void modify(int l, int r, bool x) {

        modify(l, r, x, 0, n - 1, 1);

    }

};





vc<pair<int, int>> e[200005];

vc<int> d[200005];



int main() {

    cin.tie(nullptr)->ios_base::sync_with_stdio(false);

    int n, q;

    read(n, q);

    vc<int> a(n), wh(n + 1);

    for (auto &i: a) read(i);

    for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) d[j].push_back(i);

    Sx F(n);

    for (int i = 0; i < q; ++i) {

        int l, r;

        read(l, r);

        e[r - 1].emplace_back(l - 1, i);

    }

    for (int i = 0; i < n; ++i) wh[a[i]] = i;

    vc<int> mx;

    mx.push_back(-1);

    vc<int> x(n + 1, -1);

    vc<ll> ans(q);

    for (int i = 0; i < n; ++i) {

        while (mx.back() != -1 && a[mx.back()] <= a[i]) {

            int f = mx[mx.size() - 2];

            F.modify(f + 1, mx.back(), false);

            x[a[mx.back()]] = -1;

            mx.pop_back();

        }

        mx.push_back(i);

        x[a[i]] = mx.size() - 1;

        int z = -1;

        for (auto x: d[a[i]]) {

            int e = -1;

            if (wh[x] <= i && wh[a[i] / x] <= i && x != a[i] / x) e = max(e, min(wh[x], wh[a[i] / x]));

            z = max(z, e);

        }

        F.modify(mx[mx.size() - 2] + 1, z, true);

        for (int y = a[i] * 2; y <= n; y += a[i]) {

            if (x[y] == -1) continue;

            if (wh[y / a[i]] <= i && y / a[i] != a[i]) {

                int z = min(wh[y / a[i]], mx[x[y]]);

                F.modify(mx[x[y] - 1] + 1, z, true);

            }

        }

        F.add();

        for (auto [l, ind]: e[i]) {

            ans[ind] = F.get(l, i);

        }

    }

    for (int i = 0; i < q; ++i) {

        print(ans[i]);

    }

}