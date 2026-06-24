#include <bits/stdc++.h>

using namespace std;



// template {{{

#define pb push_back

#define eb emplace_back

#define mp make_pair

#define mt make_tuple

#define lb lower_bound

#define ub upper_bound

#define f first

#define s second

#define resz resize



#define sz(x) int((x).size())

#define all(x) (x).begin(), (x).end()



#define FOR(i, a, b) for (int i = (a); i < (b); i++)

#define F0R(i, a) for (int i = 0; i < (a); i++)

#define FORd(i, a, b) for (int i = (b)-1; i >= (a); i--)

#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)

#define trav(a, x) for (auto& a : x)



#define sort_by(x, y) sort(all(x), [&](const auto& a, const auto& b) { return y; })



using ll = long long;

using vi = vector<int>;

using vvi = vector<vi>;

using vll = vector<ll>;

using vvll = vector<vll>;

using vb = vector<bool>;

using vd = vector<double>;

using vs = vector<string>;



using pii = pair<int, int>;

using pll = pair<ll, ll>;

using pdd = pair<double, double>;



using vpii = vector<pii>;

using vvpii = vector<vpii>;

using vpll = vector<pll>;

using vvpll = vector<vpll>;

using vpdd = vector<pdd>;

using vvpdd = vector<vpdd>;



template<typename T> void ckmin(T& a, const T& b) { a = min(a, b); }

template<typename T> void ckmax(T& a, const T& b) { a = max(a, b); }



mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());



namespace __input {

    template<class T1, class T2> void re(pair<T1,T2>& p);

    template<class T> void re(vector<T>& a);

    template<class T, size_t SZ> void re(array<T,SZ>& a);



    template<class T> void re(T& x) { cin >> x; }

    void re(double& x) { string t; re(t); x = stod(t); }

    template<class Arg, class... Args> void re(Arg& first, Args&... rest) {

        re(first); re(rest...);

    }



    template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }

    template<class T> void re(vector<T>& a) { F0R(i,sz(a)) re(a[i]); }

    template<class T, size_t SZ> void re(array<T,SZ>& a) { F0R(i,SZ) re(a[i]); }

}

using namespace __input;



namespace __output {

    template<class T1, class T2> void pr(const pair<T1,T2>& x);

    template<class T, size_t SZ> void pr(const array<T,SZ>& x);

    template<class T> void pr(const vector<T>& x);

    template<class T> void pr(const deque<T>& x);

    template<class T> void pr(const set<T>& x);

    template<class T1, class T2> void pr(const map<T1,T2>& x);



    template<class T> void pr(const T& x) { cout << x; }

    template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) {

        pr(first); pr(rest...);

    }



    template<class T1, class T2> void pr(const pair<T1,T2>& x) {

        pr("{",x.f,", ",x.s,"}");

    }

    template<class T, bool pretty = true> void prContain(const T& x) {

        if (pretty) pr("{");

        bool fst = 1; for (const auto& a: x) pr(!fst?pretty?", ":" ":"",a), fst = 0;

        if (pretty) pr("}");

    }

    template<class T> void pc(const T& x) { prContain<T, false>(x); pr("\n"); }

    template<class T, size_t SZ> void pr(const array<T,SZ>& x) { prContain(x); }

    template<class T> void pr(const vector<T>& x) { prContain(x); }

    template<class T> void pr(const deque<T>& x) { prContain(x); }

    template<class T> void pr(const set<T>& x) { prContain(x); }

    template<class T1, class T2> void pr(const map<T1,T2>& x) { prContain(x); }



    void ps() { pr("\n"); }

    template<class Arg> void ps(const Arg& first) {

        pr(first); ps();

    }

    template<class Arg, class... Args> void ps(const Arg& first, const Args&... rest) {

        pr(first," "); ps(rest...);

    }

}

using namespace __output;



#define TRACE(x) x

#define __pn(x) pr(#x, " = ")

#define pd(...) __pn((__VA_ARGS__)), ps(__VA_ARGS__), cout << flush



namespace __algorithm {

    template<typename T> void dedup(vector<T>& v) {

        sort(all(v)); v.erase(unique(all(v)), v.end());

    }

    template<typename T> typename vector<T>::iterator find(vector<T>& v, const T& x) {

        auto it = lower_bound(all(v), x); return it != v.end() && *it == x ? it : v.end();

    }

    template<typename T> size_t index(vector<T>& v, const T& x) {

        auto it = find(v, x); assert(it != v.end() && *it == x); return it - v.begin();

    }

    template<typename C, typename T, typename OP> vector<T> prefixes(const C& v, T id, OP op) {

        vector<T> r(sz(v)+1, id); F0R (i, sz(v)) r[i+1] = op(r[i], v[i]); return r;

    }

    template<typename C, typename T, typename OP> vector<T> suffixes(const C& v, T id, OP op) {

        vector<T> r(sz(v)+1, id); F0Rd (i, sz(v)) r[i] = op(v[i], r[i+1]); return r;

    }

}

using namespace __algorithm;



#pragma GCC diagnostic push

#pragma GCC diagnostic ignored "-Wunused-parameter"

struct monostate {

    friend istream& operator>>(istream& is, const monostate& ms) { return is; }

    friend ostream& operator<<(ostream& os, const monostate& ms) { return os; }

    friend monostate operator+(const monostate& a, const monostate& b) { return a; }

} ms;

#pragma GCC diagnostic pop



namespace __io {

    void setIn(string s) { freopen(s.c_str(),"r",stdin); }

    void setOut(string s) { freopen(s.c_str(),"w",stdout); }

    void setIO(string s = "") {

        ios_base::sync_with_stdio(0); cin.tie(0);

        cout << fixed << setprecision(15);

        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }

    }

}

using namespace __io;

// }}}



// modnum {{{

using v_t = int;

using vv_t = ll;

template<v_t MOD> struct modnum {

    v_t v;

    modnum() : v(0) {}

    modnum(vv_t _v) : v(_v % MOD) { if (v < 0) v += MOD; }

    explicit operator v_t() const { return v; }

    friend istream& operator >> (istream& i, modnum& n) { vv_t w; i >> w; n = modnum(w); return i; }

    friend ostream& operator << (ostream& o, const modnum& n) { return o << n.v; }



    friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }

    friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }



    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {

#if !defined(_WIN32) || defined(_WIN64)

        return x % m;

#endif

        // x must be less than 2^32 * m so that x / m fits in a 32-bit integer.

        unsigned x_high = x >> 32, x_low = (unsigned) x, quot, rem;

        asm("divl %4\n"

                : "=a" (quot), "=d" (rem)

                : "d" (x_high), "a" (x_low), "r" (m));

        return rem;

    }



    modnum& operator += (const modnum& o) { v += o.v; if (v >= MOD) v -= MOD; return *this; }

    modnum& operator -= (const modnum& o) { v -= o.v; if (v < 0) v += MOD; return *this; }

    modnum& operator *= (const modnum& o) { v = fast_mod(vv_t(v) * o.v); return *this; }

    modnum operator - () { modnum res; if (v) res.v = MOD - v; return res; }

    friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }

    friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }

    friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }



    modnum pow(vv_t e) const {

        if (e < 0) return 1 / this->pow(-e);

        if (e == 0) return 1;

        if (e & 1) return *this * this->pow(e-1);

        return (*this * *this).pow(e/2);

    }



    modnum inv() const {

        v_t g = MOD, x = 0, y = 1;

        for (v_t r = v; r != 0; ) {

            v_t q = g / r;

            g %= r; swap(g, r);

            x -= q * y; swap(x, y);

        }



        assert(g == 1);

        assert(y == MOD || y == -MOD);

        return x < 0 ? x + MOD : x;

    }

    modnum& operator /= (const modnum& o) { return (*this) *= o.inv(); }

    friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= modnum(b); }



    static constexpr v_t totient() {

        v_t tot = MOD, tmp = MOD;

        for (v_t p = 2; p * p <= tmp; p++) if (tmp % p == 0) {

            tot = tot / p * (p - 1);

            while (tmp % p == 0) tmp /= p;

        }

        if (tmp > 1) tot = tot / tmp * (tmp - 1);

        return tot;

    }



    static v_t primitive_root() {

        if (MOD == 1) return 0;

        if (MOD == 2) return 1;



        v_t tot = totient(), tmp = tot;

        vi tot_pr;

        for (v_t p = 2; p * p <= tmp; p++) if (tot % p == 0) {

            tot_pr.push_back(p);

            while (tmp % p == 0) tmp /= p;

        }

        if (tmp > 1) tot_pr.push_back(tmp);



        for (v_t r = 2; r < MOD; r++) if (__gcd(r, MOD) == 1) {

            bool root = true;

            for (v_t p : tot_pr) root &= modnum(r).pow(tot / p) != 1;

            if (root) return r;

        }

        assert(false);

    }



    static modnum generator() { static modnum g = primitive_root(); return g; }

    static v_t discrete_log(modnum v) {

        static const v_t M = ceil(sqrt(MOD));

        static unordered_map<v_t, v_t> table;

        if (table.empty()) {

            modnum e = 1;

            for (v_t i = 0; i < M; i++) { table[e.v] = i; e *= generator(); }

        }

        static modnum f = generator().pow(totient() - M);



        for (v_t i = 0; i < M; i++) {

            if (table.count(v.v)) return table[v.v] + i * M;

            v *= f;

        }

        assert(false);

    }



    static modnum unity_root(int deg) {

        assert(totient() % deg == 0);

        return generator().pow(totient() / deg);

    }



    static modnum unity_root(int deg, int pow) {

        static vector<modnum> table{ 0, 1 };

        while (sz(table) <= deg) {

            modnum w = unity_root(sz(table));

            for (int i = sz(table)/2, s = sz(table); i < s; i++) {

                table.push_back(table[i]);

                table.push_back(table[i] * w);

            }

        }

        return table[deg + (pow < 0 ? deg + pow : pow)];

    }



    static modnum factorial(int n) {

        static vector<modnum> fact = {1};

        assert(n >= 0);

        if (sz(fact) <= n) {

            int had = sz(fact);

            fact.resize(n + 1);

            for (int i = had; i <= n; i++) fact[i] = fact[i-1] * i;

        }

        return fact[n];

    }

    static modnum inverse_factorial(int n) {

        static vector<modnum> finv = {1};

        assert(n >= 0);

        if (sz(finv) <= n) {

            int had = sz(finv);

            finv.resz(n + 1), finv[n] = factorial(n).inv();

            for (int i = n - 1; i >= had; i--) finv[i] = finv[i+1] * (i+1);

        }

        return finv[n];

    }



    static modnum small_inv(int n) {

        assert(n > 0); return factorial(n - 1) * inverse_factorial(n);

    }



    static modnum ncr(int n, int r) {

        if (r < 0 || n < r) return 0;

        return factorial(n) * inverse_factorial(r) * inverse_factorial(n - r);

    }

};

// }}}

using mn = modnum<int(998244353)>;

using vmn = vector<mn>;

using vvmn = vector<vmn>;



mn solve_k1(int N) { // number of multisets summing to <= N

    vmn dp(N + 1);

    dp[0] = 1;

    FORd (v, 1, N + 1) {

        F0R (sum, N - v + 1) {

            dp[sum + v] += dp[sum];

        }

    }

    return accumulate(all(dp), mn(0)) - 1;

}



mn solve_k2(int N) { // number of multisets s.t. dot prod with [1,2,....] <= N

    /*

     * used * (used + 1) / 2 <= N

     * used * (used + 1) <= 2 * N

     * used <= sqrt(2 * N)

     */

    int max_used = ceil(sqrt(2 * N)) + 1;



    vvmn dp(max_used, vmn(N + 1));

    dp[0][0] = 1;



    FORd (v, 1, N + 1)

        F0R (used, max_used - 1)

            F0R (sum, N - (used + 1) * v + 1)

                dp[used + 1][sum + (used + 1) * v] += dp[used][sum];



    mn ans = 0;

    FOR (used, 1, max_used)

        FOR (sum, 1, N + 1)

            ans += dp[used][sum];

    return ans;

}



const int MAXS = 2021;



vi vals[MAXS];



int cost(int level) {

    int tot = accumulate(all(vals[level]), 0);

    if (level == 1) return tot;

    if (tot >= MAXS) return MAXS;



    vals[level - 1].clear();



    F0R (i, sz(vals[level]))

        F0R (j, vals[level][i])

            vals[level - 1].pb(i + 1);



    reverse(all(vals[level - 1]));



    return cost(level - 1);

};



int ct[MAXS];



int go(int level) {

    vi &v = vals[level];



    int ans = 0;

    while (1) {

        int cur_cost = cost(level);

        if (cur_cost < MAXS) {

            ct[cur_cost]++;

        } else break;



        {

            v.pb(1);

            go(level);

            v.pop_back();

        }



        if (sz(v) == 1 || v.back() < v[sz(v) - 2])

            v.back()++;

        else break;

    }



    return ans;

}



int ct3[] = {0, 1, 0, 1, 1, 0, 1, 1, 0, 0, 2, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 2, 0, 1, 2, 0, 1, 2, 1, 0, 2, 1, 0, 2, 3, 1, 1, 1, 2, 1, 2, 2, 1, 0, 1, 3, 1, 2, 2, 2, 1, 1, 1, 1, 4, 4, 0, 3, 2, 0, 3, 1, 2, 1, 3, 2, 2, 1, 2, 4, 3, 2, 3, 1, 1, 3, 3, 1, 4, 5, 2, 3, 1, 3, 2, 3, 0, 4, 2, 3, 4, 3, 2, 4, 2, 3, 4, 3, 1, 4, 6, 2, 3, 2, 5, 3, 3, 4, 4, 2, 3, 4, 5, 1, 3, 5, 1, 3, 5, 6, 3, 3, 3, 4, 5, 7, 5, 2, 4, 5, 2, 5, 6, 5, 1, 6, 6, 2, 7, 6, 4, 3, 3, 4, 4, 5, 7, 4, 5, 3, 6, 5, 2, 8, 8, 2, 4, 7, 4, 5, 10, 5, 7, 7, 2, 5, 5, 6, 3, 7, 8, 5, 4, 5, 12, 7, 6, 8, 3, 1, 7, 5, 4, 8, 9, 6, 7, 6, 5, 7, 11, 8, 6, 8, 6, 6, 6, 2, 12, 10, 7, 7, 8, 5, 5, 11, 6, 7, 9, 9, 7, 7, 7, 7, 6, 12, 8, 8, 5, 9, 8, 5, 8, 9, 12, 11, 7, 7, 9, 10, 8, 13, 8, 8, 7, 10, 10, 9, 8, 6, 14, 9, 8, 13, 10, 9, 8, 9, 9, 8, 12, 9, 11, 8, 9, 13, 10, 7, 9, 12, 12, 9, 13, 6, 13, 15, 9, 9, 12, 13, 11, 14, 12, 9, 10, 9, 10, 12, 13, 16, 13, 9, 10, 13, 10, 17, 17, 5, 12, 19, 12, 12, 9, 12, 11, 13, 7, 14, 11, 15, 15, 12, 15, 14, 8, 11, 15, 18, 11, 19, 23, 10, 8, 12, 17, 12, 14, 14, 14, 11, 11, 20, 20, 16, 14, 15, 13, 13, 19, 14, 16, 21, 11, 15, 20, 13, 13, 13, 22, 12, 17, 16, 14, 17, 13, 15, 20, 12, 15, 15, 18, 14, 17, 16, 17, 24, 20, 20, 16, 19, 18, 16, 13, 20, 22, 17, 17, 14, 14, 20, 18, 20, 23, 17, 18, 19, 18, 22, 24, 22, 21, 19, 15, 16, 25, 24, 12, 17, 23, 16, 19, 23, 16, 22, 20, 23, 21, 17, 15, 22, 28, 23, 20, 16, 22, 27, 24, 18, 25, 22, 12, 20, 30, 18, 23, 31, 21, 16, 27, 25, 21, 23, 23, 23, 21, 27, 24, 26, 16, 29, 27, 18, 24, 30, 17, 20, 33, 22, 26, 24, 29, 21, 18, 29, 26, 21, 30, 26, 22, 18, 36, 32, 19, 30, 28, 20, 26, 25, 27, 25, 32, 35, 25, 31, 15, 27, 30, 23, 32, 31, 28, 25, 27, 23, 34, 41, 27, 28, 33, 28, 22, 22, 36, 29, 33, 35, 31, 26, 25, 32, 36, 27, 23, 36, 23, 36, 33, 26, 27, 41, 36, 28, 32, 28, 28, 36, 28, 27, 30, 36, 34, 34, 29, 33, 39, 41, 37, 30, 34, 29, 31, 31, 29, 30, 43, 42, 28, 32, 31, 34, 34, 41, 37, 28, 35, 42, 35, 38, 43, 35, 40, 43, 37, 36, 37, 39, 31, 36, 29, 40, 37, 27, 49, 41, 42, 37, 38, 28, 32, 39, 51, 43, 39, 35, 37, 38, 46, 40, 47, 39, 32, 37, 34, 41, 38, 44, 51, 39, 34, 37, 51, 40, 42, 55, 39, 38, 46, 33, 39, 47, 41, 42, 45, 45, 44, 47, 45, 52, 43, 38, 45, 38, 43, 45, 60, 44, 41, 52, 46, 50, 50, 53, 34, 42, 46, 58, 43, 30, 51, 49, 38, 62, 51, 39, 44, 59, 37, 44, 57, 46, 43, 60, 46, 51, 59, 55, 47, 45, 43, 55, 60, 45, 51, 46, 44, 40, 53, 55, 51, 62, 57, 43, 52, 58, 52, 56, 59, 56, 57, 54, 53, 55, 42, 57, 59, 49, 65, 56, 52, 45, 62, 60, 54, 59, 59, 57, 58, 56, 55, 51, 63, 54, 55, 52, 60, 66, 57, 55, 57, 63, 65, 59, 51, 44, 73, 63, 56, 66, 52, 61, 66, 63, 65, 61, 58, 66, 61, 60, 62, 60, 48, 60, 69, 66, 66, 71, 53, 59, 64, 65, 78, 77, 52, 59, 71, 67, 65, 75, 71, 59, 69, 69, 55, 66, 77, 70, 73, 72, 65, 59, 54, 73, 63, 72, 81, 74, 65, 62, 72, 70, 75, 76, 66, 67, 66, 74, 80, 72, 69, 72, 67, 70, 70, 79, 69, 74, 78, 60, 82, 83, 78, 69, 73, 74, 73, 77, 73, 62, 82, 78, 76, 84, 67, 75, 78, 81, 88, 77, 78, 66, 88, 76, 78, 91, 76, 81, 86, 77, 78, 88, 75, 81, 72, 82, 91, 85, 85, 84, 84, 62, 89, 90, 86, 75, 91, 71, 72, 91, 93, 92, 94, 91, 69, 85, 84, 94, 87, 79, 95, 96, 81, 90, 80, 76, 84, 105, 85, 90, 97, 92, 94, 84, 89, 85, 91, 81, 102, 87, 66, 106, 109, 83, 88, 95, 89, 91, 100, 90, 86, 99, 104, 94, 82, 92, 99, 110, 107, 103, 93, 81, 103, 107, 88, 104, 111, 93, 82, 102, 98, 90, 128, 98, 77, 97, 109, 98, 103, 100, 94, 107, 109, 98, 112, 91, 113, 119, 95, 95, 104, 112, 82, 128, 123, 98, 105, 116, 97, 92, 111, 106, 101, 112, 106, 105, 99, 113, 120, 106, 114, 113, 108, 109, 98, 109, 100, 116, 112, 107, 113, 97, 127, 120, 114, 129, 108, 111, 103, 120, 109, 128, 126, 104, 106, 118, 108, 121, 125, 112, 112, 120, 121, 138, 122, 103, 124, 126, 116, 110, 139, 114, 116, 130, 109, 111, 127, 130, 127, 117, 134, 124, 112, 121, 132, 145, 126, 119, 134, 99, 113, 137, 146, 131, 135, 132, 112, 114, 133, 138, 133, 149, 130, 116, 117, 121, 142, 131, 139, 138, 114, 116, 145, 121, 126, 147, 148, 127, 130, 132, 123, 143, 156, 148, 135, 132, 141, 133, 118, 136, 150, 127, 138, 164, 129, 136, 148, 151, 137, 150, 140, 137, 151, 147, 139, 125, 142, 155, 140, 135, 148, 145, 137, 147, 154, 149, 157, 164, 141, 139, 153, 161, 150, 163, 142, 142, 145, 139, 158, 160, 127, 159, 172, 141, 144, 167, 142, 143, 179, 134, 148, 169, 169, 151, 153, 160, 145, 163, 153, 158, 155, 148, 185, 165, 151, 154, 162, 155, 146, 163, 168, 158, 181, 164, 153, 157, 154, 153, 177, 174, 159, 184, 160, 153, 178, 173, 187, 188, 166, 148, 164, 183, 168, 182, 163, 162, 167, 163, 166, 160, 181, 181, 192, 173, 168, 176, 143, 179, 197, 176, 175, 185, 186, 165, 186, 170, 178, 192, 198, 174, 177, 180, 171, 190, 177, 194, 189, 185, 175, 180, 166, 200, 188, 188, 173, 190, 188, 184, 188, 176, 179, 206, 188, 182, 185, 184, 197, 196, 201, 171, 207, 159, 209, 211, 179, 178, 203, 216, 177, 211, 187, 186, 197, 224, 205, 188, 193, 193, 194, 192, 202, 208, 191, 195, 233, 196, 203, 214, 192, 191, 220, 218, 180, 203, 223, 202, 214, 214, 212, 177, 201, 220, 222, 207, 199, 221, 197, 207, 224, 209, 224, 224, 218, 215, 184, 203, 224, 227, 233, 233, 203, 193, 225, 225, 212, 224, 249, 233, 204, 211, 212, 218, 236, 245, 222, 216, 215, 236, 227, 190, 221, 239, 220, 211, 234, 219, 219, 261, 238, 217, 230, 236, 225, 231, 217, 240, 235, 240, 248, 227, 223, 234, 254, 227, 214, 251, 231, 244, 263, 221, 226, 265, 263, 246, 234, 240, 219, 237, 239, 248, 256, 251, 239, 238, 219, 227, 259, 247, 255, 277, 250, 243, 257, 246, 253, 240, 285, 260, 245, 253, 236, 245, 252, 257, 263, 249, 261, 270, 236, 250, 269, 260, 271, 295, 254, 255, 293, 252, 249, 261, 244, 264, 276, 246, 274, 265, 262, 276, 293, 254, 250, 270, 270, 261, 269, 266, 264, 301, 281, 266, 253, 273, 276, 275, 275, 274, 269, 263, 306, 270, 279, 269, 308, 297, 266, 299, 279, 282, 293, 254, 275, 306, 263, 289, 307, 278, 276, 321, 287, 264, 305, 285, 283, 302, 288, 280, 286, 299, 282, 288, 293, 285, 320, 296, 288, 298, 306, 287, 324, 291, 299, 332, 302, 291, 320, 317, 285, 321, 289, 312, 300, 291, 279, 316, 314, 327, 334, 319, 308, 301, 312, 321, 305, 313, 288, 306, 311, 301, 306, 336, 330, 321, 328, 310, 293, 308, 324, 355, 340, 307, 337, 307, 329, 361, 312, 301, 351, 304, 304, 326, 319, 326, 350, 334, 315, 328, 339, 340, 337, 324, 341, 342, 327, 361, 340, 316, 338, 369, 357, 316, 348, 358, 303, 348, 334, 324, 354, 366, 350, 324, 342, 324, 349, 346, 353, 371, 351, 365, 386, 345, 320, 360, 356, 320, 354, 360, 348, 365, 362, 377, 352, 363, 383, 349, 346, 357, 367, 374, 367, 385, 349, 360, 414, 373, 345, 359, 412, 358, 340, 382, 364, 364, 343, 392, 380, 350, 388, 373, 360, 383, 407, 360, 361, 394, 406, 368, 394, 398, 368, 380, 360, 392, 387, 381, 389, 401, 381, 377, 396, 372, 366, 413, 435, 393, 381, 418, 373, 410, 416, 375, 385, 407, 416, 419, 348, 394, 429, 373, 427, 415, 383, 389, 435, 410, 373, 399, 420, 392, 438, 436, 407, 389, 428, 437, 389, 395, 421, 436, 388, 401, 446, 414, 413, 422, 406, 393, 446, 434, 424, 446, 459, 419, 413, 414, 423, 444, 438, 483, 449, 377, 428, 448, 413, 448, 463, 427, 406, 453, 437, 421, 454, 442, 433, 471, 401, 438, 475, 417, 455, 455, 440, 445, 472, 443, 428, 463, 471, 425, 445, 463, 429, 471, 463, 449, 455, 460, 481, 462, 462, 489, 479, 454, 435, 456, 445, 465, 484, 461, 463, 446, 465, 465, 501, 475, 443, 474, 474, 464, 515, 462, 455, 514, 452, 487, 487, 480, 457, 535, 483, 448, 464, 480, 492, 510, 457, 484, 500, 506, 488, 508, 487, 464, 541, 503, 493, 493, 492, 474, 515, 487, 453, 496, 553, 497, 517, 515, 485, 502, 479, 515, 517, 489, 542, 564, 489, 499, 562, 553, 482, 507, 506, 498, 528, 552, 509, 480, 521, 534, 521, 510, 544, 506, 534, 524, 535, 513, 541, 534, 555, 504, 555, 542, 549, 577, 527, 502, 517, 524, 514, 549, 496, 572, 568, 527, 546, 576, 534, 554, 593, 522, 537, 583, 555, 497, 582, 568, 549, 560, 561, 542, 543, 578, 579, 574, 536, 527, 538, 566, 544, 585, 575, 538, 589, 583, 533, 600, 596, 592, 620, 544, 543, 568, 585, 591, 587, 559, 602, 583, 573, 560, 601, 555, 591, 629, 567, 557, 589, 620, 569, 611, 631, 607, 607, 630, 560, 588, 598, 613, 603, 598, 580, 622, 581, 570, 631, 608, 600, 639, 614, 584, 605, 656, 613, 623, 598, 608, 632, 614, 626, 609, 590, 646, 661, 616, 606, 650, 595, 590, 649, 647, 616, 632, 672, 630, 600, 674, 640, 620, 656, 614, 631, 619, 665, 679, 644, 634, 681, 652, 607, 663, 644, 623, 643, 661, 649, 630, 677, 641, 626, 673, 689, 690, 663, 664, 652, 615, 682, 693, 657, 627, 676, 686, 660, 685, 683, 703, 630, 671, 691, 655, 663, 685, 721, 687, 679, 715, 659, 680, 745, 661, 672, 735, 710, 642, 688, 691, 688, 719, 691, 695, 693, 696, 742, 723, 689, 682, 725, 696, 679, 743, 678, 698, 758, 728, 689, 744, 710, 701, 735, 708, 688, 737, 733, 715, 734, 666, 723, 775, 776, 714, 734, 711, 704, 738, 763, 694, 752, 769, 740, 704, 724, 760, 747, 779, 731, 762, 716, 730, 747, 761, 716, 777, 757, 759, 782, 758, 764, 794, 764, 706, 764, 746, 793, 767, 740, 771, 794, 728, 783, 779, 772, 749, 801, 755, 749, 827, 784, 786, 782, 776, 738, 846, 813, 785, 781, 819, 752, 742, 805, 775, 785, 809, 809, 824, 798, 776, 825, 795, 811, 822, 809, 771};



int main() {

    setIO();



    /*{

        go({1}, 3);

        cout << "{";

        F0R (v, MAXS) {

            if (v) cout << ", ";

            cout << ct[v];

        }

        cout << "}\n";

        return 0;

    }*/



    int N, K; re(N, K);



    if (K == 1) {

        ps(solve_k1(N));

    } else if (K == 2) {

        ps(solve_k2(N));

    } else if (K == 3) {

        ps(accumulate(ct3 + 1, ct3 + N + 1, 0));

    } else {

        vals[K] = {1};

        go(K);

        ps(accumulate(ct + 1, ct + N + 1, 0));

    }



    // did you check N=1? did you mix up N,M?

    // check your "infinity" and "null" values against the bounds

    return 0;

}



/*

maximum size?

f0: n

f1: n

f2: sqrt n



1... 1

1 1

1 2

1 1 2

1 1 2 3

1 1 1 2 2 3 4 

1 1 1 1 2 2 2 3 3 4 4 5 6 7



1 1 2 2 3 4 7 14 42 213 2837



only nontrivial for k<11 (i searched on oeis)



k=1:

anything with sum n

easy



k=2:

sum aibi <=n, where bi must be unique

then sort ai, and let bi=1,2,3...



do dp[ai][i][sum] (only visit nonzero values for sum, there is a very limited number)



k>2:

do brute force

*/