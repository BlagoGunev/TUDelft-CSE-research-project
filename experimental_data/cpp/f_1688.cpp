//I wrote this code 4 u today

#include <bits/stdc++.h>

namespace IO {

    const int DPAIRSIZ = 1 << 10;

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



int main() {

    int t;

    read(t);

    while (t--) {

        int n, m;

        read(n, m);

        vc<int> a(n), b(n);

        for (auto &i : a) read(i);

        for (auto &i : b) read(i);

        vc<pair<int, int>> f(m);

        vc<vc<int>> wh(n + 1);

        for (auto &i : f) read(i.first, i.second);

        vc<int> cnt(m), p(n + 1);

        iota(p.begin(), p.end(), 0);

        for (int i = 0; i < f.size(); ++i) wh[f[i].first - 1].push_back(i), wh[f[i].second].push_back(i);

        vc<ll> d(n + 1);

        d[0] = 0;

        for (int i = 1; i <= n; ++i) d[i] = d[i - 1] + (a[i - 1] - b[i - 1]);

        vc<int> st;

        for (int i = 0; i <= n; ++i) {

            if (!d[i]) {

                for (auto x : wh[i]) {

                    cnt[x]++;

                    if (cnt[x] == 2) st.push_back(x);

                }

            }

            if (i < n && !d[i] && d[i] == d[i + 1]) {

                p[i] = i + 1;

            }

        }

        function<int(int)> get = [&](int i) {

            return p[i] == i ? i : p[i] = get(p[i]);

        };

        while (!st.empty()) {

            int v = st.back();

            st.pop_back();

            int i = get(f[v].first - 1);

            while (i < f[v].second) {

                p[i] = get(i + 1);

                for (auto x : wh[i + 1]) {

                    cnt[x] += !!d[i + 1];

                    if (cnt[x] == 2) st.push_back(x);

                }

                i = get(i);

            }

        }

        if (get(0) == n) {

            print("YES");

        } else {

            print("NO");

        }

    }

}