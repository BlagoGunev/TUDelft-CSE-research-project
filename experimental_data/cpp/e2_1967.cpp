#pragma GCC optimize("Ofast")
//#pragma GCC target("popcnt")
#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef long double ld;
const double start_time = (double)clock() * 1.0 / CLOCKS_PER_SEC;
#define TIME ((double)clock() * 1.0 / CLOCKS_PER_SEC - start_time)
#define y0 _y0
#define kill _kill

// permanent constants
const ld pi = acosl(-1.0);
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
// RDLU
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
// starting from (LU)
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const ld eps = 1e-12;
const ll INF = (ll)(1e18) + 239;
const int BIG = (int)(1e9) + (int)(239);
//const int BIG = (int)(2e9) + (int)(1e6);
//const int MOD = 1'000'000'007;
const int MOD = 998'244'353;
const ll MOD2 = (ll)MOD * (ll)MOD;

void Init() {
    (void)pi; (void)day; (void)dx; (void)dy; (void)dxo; (void)dyo;
    (void)eps; (void)INF; (void)BIG; (void)MOD; (void)MOD2;
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
}
//using Mint = ModInt;

// random
#ifdef ONPC
mt19937_64 rnd(239);
#else
mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

template<typename T, typename U>
ostream& operator<<(ostream& o, const pair<T, U>& p) {
    return o << "(" << p.first << ", " << p.second << ")";
}

template<typename T>
ostream& operator<<(ostream& o, const vector<T>& v) {
    bool first = true;
    o << "{";
    for (const auto& l : v) {
        if (!first) o << ", ";
        o << l;
        first = false;
    }
    return o << "}";
}

#ifdef ONPC
#define show(x) cout << "LINE " << __LINE__ << ": " << #x << "=" << x << std::endl;
#else
#define show(x) 42
#endif

constexpr bool is_prime(unsigned n) {
    if (n == 0 || n == 1) {
        return false;
    }
    for (unsigned i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

constexpr unsigned mod_pow(unsigned x, unsigned y, unsigned mod) {
    unsigned ret = 1, self = x;
    while (y != 0) {
        if (y & 1) {
            ret = (unsigned)((unsigned long long)ret * self % mod);
        }
        self = (unsigned)((unsigned long long)self * self % mod);
        y /= 2;
    }
    return ret;
}

template <unsigned mod>
constexpr unsigned primitive_root() {
    static_assert(is_prime(mod), "`mod` must be a prime number.");
    if (mod == 2) {
        return 1;
    }

    unsigned primes[32] = {};
    int it = 0;
    {
        unsigned m = mod - 1;
        for (unsigned i = 2; i * i <= m; ++i) {
            if (m % i == 0) {
                primes[it++] = i;
                while (m % i == 0) {
                    m /= i;
                }
            }
        }
        if (m != 1) {
            primes[it++] = m;
        }
    }
    for (unsigned i = 2; i < mod; ++i) {
        bool ok = true;
        for (int j = 0; j < it; ++j) {
            if (mod_pow(i, (mod - 1) / primes[j], mod) == 1) {
                ok = false;
                break;
            }
        }
        if (ok) return i;
    }
    return 0;
}

// y >= 1
template <typename T>
constexpr T safe_mod(T x, T y) {
    x %= y;
    if (x < 0) {
        x += y;
    }
    return x;
}

// y != 0
template <typename T>
constexpr T floor_div(T x, T y) {
    if (y < 0) {
        x *= -1;
        y *= -1;
    }
    if (x >= 0) {
        return x / y;
    } else {
        return -((-x + y - 1) / y);
    }
}

// y != 0
template <typename T>
constexpr T ceil_div(T x, T y) {
    if (y < 0) {
        x *= -1;
        y *= -1;
    }
    if (x >= 0) {
        return (x + y - 1) / y;
    } else {
        return -(-x / y);
    }
}

// b >= 1
// returns (g, x) s.t. g = gcd(a, b), a * x = g (mod b), 0 <= x < b / g
// from ACL
template <typename T>
std::pair<T, T> extgcd(T a, T b) {
    a = safe_mod(a, b);
    T s = b, t = a, m0 = 0, m1 = 1;
    while (t) {
        T u = s / t;
        s -= t * u;
        m0 -= m1 * u;
        std::swap(s, t);
        std::swap(m0, m1);
    }
    if (m0 < 0) {
        m0 += b / s;
    }
    return std::pair<T, T>(s, m0);
}

// b >= 1
// returns (g, x, y) s.t. g = gcd(a, b), a * x + b * y = g, 0 <= x < b / g, |y| < max(2, |a| / g)
template <typename T>
std::tuple<T, T, T> extgcd2(T a, T b) {
    T _a = safe_mod(a, b);
    T quot = (a - _a) / b;
    T x00 = 0, x01 = 1, y0 = b;
    T x10 = 1, x11 = -quot, y1 = _a;
    while (y1) {
        T u = y0 / y1;
        x00 -= u * x10;
        x01 -= u * x11;
        y0 -= u * y1;
        std::swap(x00, x10);
        std::swap(x01, x11);
        std::swap(y0, y1);
    }
    if (x00 < 0) {
        x00 += b / y0;
        x01 -= a / y0;
    }
    return std::tuple<T, T, T>(y0, x00, x01);
}

// gcd(x, m) == 1
template <typename T>
T inv_mod(T x, T m) {
    return extgcd(x, m).second;
}
// ============

template <unsigned mod>
struct ModInt {
    static_assert(mod != 0, "`mod` must not be equal to 0.");
    static_assert(mod < (1u << 31),
                  "`mod` must be less than (1u << 31) = 2147483648.");

    unsigned val;

    static constexpr unsigned get_mod() { return mod; }

    constexpr ModInt() : val(0) {}
    template <typename T, std::enable_if_t<std::is_signed_v<T>> * = nullptr>
    constexpr ModInt(T x)
            : val((unsigned)((long long)x % (long long)mod + (x < 0 ? mod : 0))) {}
    template <typename T, std::enable_if_t<std::is_unsigned_v<T>> * = nullptr>
    constexpr ModInt(T x) : val((unsigned)(x % mod)) {}

    static constexpr ModInt raw(unsigned x) {
        ModInt<mod> ret;
        ret.val = x;
        return ret;
    }

    constexpr unsigned get_val() const { return val; }

    constexpr ModInt operator+() const { return *this; }
    constexpr ModInt operator-() const { return ModInt<mod>(0u) - *this; }

    constexpr ModInt &operator+=(const ModInt &rhs) {
        val += rhs.val;
        if (val >= mod) val -= mod;
        return *this;
    }
    constexpr ModInt &operator-=(const ModInt &rhs) {
        val -= rhs.val;
        if (val >= mod) val += mod;
        return *this;
    }
    constexpr ModInt &operator*=(const ModInt &rhs) {
        val = (unsigned long long)val * rhs.val % mod;
        return *this;
    }
    constexpr ModInt &operator/=(const ModInt &rhs) {
        val = (unsigned long long)val * rhs.inv().val % mod;
        return *this;
    }

    friend constexpr ModInt operator+(const ModInt &lhs, const ModInt &rhs) {
        return ModInt<mod>(lhs) += rhs;
    }
    friend constexpr ModInt operator-(const ModInt &lhs, const ModInt &rhs) {
        return ModInt<mod>(lhs) -= rhs;
    }
    friend constexpr ModInt operator*(const ModInt &lhs, const ModInt &rhs) {
        return ModInt<mod>(lhs) *= rhs;
    }
    friend constexpr ModInt operator/(const ModInt &lhs, const ModInt &rhs) {
        return ModInt<mod>(lhs) /= rhs;
    }

    constexpr ModInt pow(unsigned long long x) const {
        ModInt<mod> ret = ModInt<mod>::raw(1);
        ModInt<mod> self = *this;
        while (x != 0) {
            if (x & 1) ret *= self;
            self *= self;
            x >>= 1;
        }
        return ret;
    }
    constexpr ModInt inv() const {
        static_assert(is_prime(mod), "`mod` must be a prime number.");
        assert(val != 0);
        return this->pow(mod - 2);
    }

    friend std::istream &operator>>(std::istream &is, ModInt<mod> &x) {
        long long val;
        is >> val;
        x.val = val % mod + (val < 0 ? mod : 0);
        return is;
    }

    friend std::ostream &operator<<(std::ostream &os, const ModInt<mod> &x) {
        os << x.val;
        return os;
    }

    friend bool operator==(const ModInt &lhs, const ModInt &rhs) {
        return lhs.val == rhs.val;
    }

    friend bool operator!=(const ModInt &lhs, const ModInt &rhs) {
        return lhs.val != rhs.val;
    }
};

template <unsigned mod>
void debug(ModInt<mod> x) {
    std::cerr << x.val;
}
// ============

constexpr int ctz_constexpr(unsigned n) {
    int x = 0;
    while (!(n & (1u << x))) {
        ++x;
    }
    return x;
}

template <unsigned MOD>
struct FFTRoot {
    static constexpr unsigned R = ctz_constexpr(MOD - 1);
    std::array<ModInt<MOD>, R + 1> root, iroot;
    std::array<ModInt<MOD>, R> rate2, irate2;
    std::array<ModInt<MOD>, R - 1> rate3, irate3;
    std::array<ModInt<MOD>, R + 1> inv2;

    constexpr FFTRoot() : root{}, iroot{}, rate2{}, irate2{}, rate3{}, irate3{}, inv2{} {
        unsigned pr = primitive_root<MOD>();
        root[R] = ModInt<MOD>(pr).pow(MOD >> R);
        iroot[R] = root[R].inv();
        for (int i = R - 1; i >= 0; --i) {
            root[i] = root[i + 1] * root[i + 1];
            iroot[i] = iroot[i + 1] * iroot[i + 1];
        }
        ModInt<MOD> prod(1), iprod(1);
        for (int i = 0; i < (int)R - 1; ++i) {
            rate2[i] = prod * root[i + 2];
            irate2[i] = iprod * iroot[i + 2];
            prod *= iroot[i + 2];
            iprod *= root[i + 2];
        }
        prod = ModInt<MOD>(1);
        iprod = ModInt<MOD>(1);
        for (int i = 0; i < (int)R - 2; ++i) {
            rate3[i] = prod * root[i + 3];
            irate3[i] = iprod * iroot[i + 3];
            prod *= iroot[i + 3];
            iprod *= root[i + 3];
        }
        ModInt<MOD> i2 = ModInt<MOD>(2).inv();
        inv2[0] = ModInt<MOD>(1);
        for (int i = 0; i < (int)R; ++i) {
            inv2[i + 1] = inv2[i] * i2;
        }
    }
};

template <typename M>
void fft(M *a, int n) {
    using ull = unsigned long long;
    static_assert(M::get_mod() < (1u << 30));
    static constexpr FFTRoot<M::get_mod()> fftroot;
    static constexpr ull CEIL = 2ULL * M::get_mod() * M::get_mod();
    int l = __builtin_ctz(n);
    int ph = 0;
    while (ph < l) {
        if (ph + 1 == l) {
            int b = 1 << ph;
            M z = M::raw(1);
            for (int i = 0; i < b; ++i) {
                int offset = i << 1;
                M x = a[offset];
                M y = a[offset + 1] * z;
                a[offset] = x + y;
                a[offset + 1] = x - y;
                z *= fftroot.rate2[__builtin_ctz(~i)];
            }
            ++ph;
        } else {
            int bl = 1 << ph;
            int wd = 1 << (l - 2 - ph);
            M zeta = M::raw(1);
            for (int i = 0; i < bl; ++i) {
                int offset = i << (l - ph);
                M zeta2 = zeta * zeta;
                M zeta3 = zeta2 * zeta;
                for (int j = 0; j < wd; ++j) {
                    ull w = a[offset + j].val;
                    ull x = (ull)a[offset + j + wd].val * zeta.val;
                    ull y = (ull)a[offset + j + 2 * wd].val * zeta2.val;
                    ull z = (ull)a[offset + j + 3 * wd].val * zeta3.val;
                    ull ix_m_iz = (CEIL + x - z) % M::get_mod() * fftroot.root[2].val;
                    a[offset + j] = M(w + x + y + z);
                    a[offset + j + wd] = M(CEIL + w - x + y - z);
                    a[offset + j + 2 * wd] = M(CEIL + w - y + ix_m_iz);
                    a[offset + j + 3 * wd] = M(CEIL + w - y - ix_m_iz);
                }
                zeta *= fftroot.rate3[__builtin_ctz(~i)];
            }
            ph += 2;
        }
    }
}

template <typename M>
void ifft(M *a, int n) {
    using ull = unsigned long long;
    static_assert(M::get_mod() < (1u << 30));
    static constexpr FFTRoot<M::get_mod()> fftroot;
    int l = __builtin_ctz(n);
    int ph = l;
    while (ph > 0) {
        if (ph == 1) {
            --ph;
            int wd = 1 << (l - 1);
            for (int i = 0; i < wd; ++i) {
                M x = a[i];
                M y = a[i + wd];
                a[i] = x + y;
                a[i + wd] = x - y;
            }
        } else {
            ph -= 2;
            int bl = 1 << ph;
            int wd = 1 << (l - 2 - ph);
            M zeta = M::raw(1);
            for (int i = 0; i < bl; ++i) {
                int offset = i << (l - ph);
                M zeta2 = zeta * zeta;
                M zeta3 = zeta2 * zeta;
                for (int j = 0; j < wd; ++j) {
                    unsigned w = a[offset + j].val;
                    unsigned x = a[offset + j + wd].val;
                    unsigned y = a[offset + j + 2 * wd].val;
                    unsigned z = a[offset + j + 3 * wd].val;
                    unsigned iy_m_iz = (ull)(M::get_mod() + y - z) * fftroot.root[2].val % M::get_mod();
                    a[offset + j] = M(w + x + y + z);
                    a[offset + j + wd] = M((ull)zeta.val * (2 * M::get_mod() + w - x - iy_m_iz));
                    a[offset + j + 2 * wd] = M((ull)zeta2.val * (2 * M::get_mod() + w + x - y - z));
                    a[offset + j + 3 * wd] = M((ull)zeta3.val * (M::get_mod() + w - x + iy_m_iz));
                }
                zeta *= fftroot.irate3[__builtin_ctz(~i)];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        a[i] *= fftroot.inv2[l];
    }
}

template <typename M>
void fft(std::vector<M> &a) {
    fft(a.data(), (int)a.size());
}
template <typename M>
void ifft(std::vector<M> &a) {
    ifft(a.data(), (int)a.size());
}

template <typename M>
std::vector<M> convolve_naive(const std::vector<M> &a,
                              const std::vector<M> &b) {
    int n = (int)a.size();
    int m = (int)b.size();
    std::vector<M> c(n + m - 1);
    if (n < m) {
        for (int j = 0; j < m; ++j) {
            for (int i = 0; i < n; ++i) {
                c[i + j] += a[i] * b[j];
            }
        }
    } else {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                c[i + j] += a[i] * b[j];
            }
        }
    }
    return c;
}

template <typename M>
std::vector<M> convolve_fft(std::vector<M> a, std::vector<M> b) {
    int n = (int)a.size() + (int)b.size() - 1;
    int m = 1;
    while (m < n) {
        m <<= 1;
    }
    bool shr = false;
    M last;
    if (n >= 3 && n == m / 2 + 1) {
        shr = true;
        last = a.back() * b.back();
        m /= 2;
        while ((int)a.size() > m) {
            a[(int)a.size() - 1 - m] += a.back();
            a.pop_back();
        }
        while ((int)b.size() > m) {
            b[(int)b.size() - 1 - m] += b.back();
            b.pop_back();
        }
    }
    a.resize(m);
    b.resize(m);
    fft(a);
    fft(b);
    for (int i = 0; i < m; ++i) {
        a[i] *= b[i];
    }
    ifft(a);
    a.resize(n);
    if (shr) {
        a[0] -= last;
        a[n - 1] = last;
    }
    return a;
}

template <typename M>
std::vector<M> convolve(const std::vector<M> &a, const std::vector<M> &b) {
    if (a.empty() || b.empty()) {
        return std::vector<M>(0);
    }
    if (std::min(a.size(), b.size()) <= 60) {
        return convolve_naive(a, b);
    } else {
        return convolve_fft(a, b);
    }
}
// ============
// 10 FFT(n)
template <typename T>
std::vector<T> fps_inv(std::vector<T> f) {
    assert(!f.empty() && f[0] != T(0));
    std::vector<T> g(1, T(1) / f[0]);
    while (g.size() < f.size()) {
        int n = (int)g.size();
        std::vector<T> fft_f(2 * n), fft_g(2 * n);
        std::copy(f.begin(), f.begin() + std::min(2 * n, (int)f.size()), fft_f.begin());
        std::copy(g.begin(), g.end(), fft_g.begin());
        fft(fft_f);
        fft(fft_g);
        for (int i = 0; i < 2 * n; ++i) {
            fft_f[i] *= fft_g[i];
        }
        ifft(fft_f);
        std::fill(fft_f.begin(), fft_f.begin() + n, T(0));
        fft(fft_f);
        for (int i = 0; i < 2 * n; ++i) {
            fft_f[i] *= fft_g[i];
        }
        ifft(fft_f);
        g.resize(2 * n);
        for (int i = n; i < 2 * n; ++i) {
            g[i] = -fft_f[i];
        }
    }
    g.resize(f.size());
    return g;
}

using Mint = ModInt<MOD>;


const int M = (int)(4e6 + 239);

Mint fact[M], inv[M];

Mint getC(int n, int k) {
    if (n < 0 || n < k || k < 0) return 0;
    return fact[n] * inv[k] * inv[n - k];
}

Mint cat(int cnt_x, int cnt_y, int m) {
    if (cnt_y < m) {
        return getC(cnt_x + cnt_y, cnt_y);
    }
    if (cnt_y > cnt_x + m - 1) {
        return 0;
    }
    return getC(cnt_x + cnt_y, cnt_y) - getC(cnt_x + cnt_y, cnt_y - m);
}

void print(int n, int m, int b0) {
    vector<vector<int>> all_b;
    for (int mask = 0; mask < (1 << n); mask++) {
        vector<int> b(n);
        int bc = b0;
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if ((mask >> i) & 1) {
                bc--;
            } else {
                bc++;
            }
            if (bc < 0) {
                ok = false;
            }
            b[i] = bc;
        }
        if (!ok) {
            continue;
        }
        all_b.emplace_back(b);
    }
    vector<vector<int>> all_a;
    all_a.emplace_back();
    for (int i = 0; i < n; i++) {
        vector<vector<int>> nw;
        for (auto t : all_a) {
            for (int x = 1; x <= m; x++) {
                t.emplace_back(x);
                nw.emplace_back(t);
                t.pop_back();
            }
        }
        swap(all_a, nw);
    }
    for (const auto& a : all_a) {
        bool stop = false;
        for (const auto& b : all_b) {
            bool ok = true;
            for (int i = 0; i < n; i++) {
                if (a[i] == b[i]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                stop = true;
                break;
            }
        }
        if (!stop) {
            cout << a << "\n";
        }
    }
}

Mint slow(int n, int m, int b0) {
    vector<vector<int>> all_b;
    for (int mask = 0; mask < (1 << n); mask++) {
        vector<int> b(n);
        int bc = b0;
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if ((mask >> i) & 1) {
                bc--;
            } else {
                bc++;
            }
            if (bc < 0) {
                ok = false;
            }
            b[i] = bc;
        }
        if (!ok) {
            continue;
        }
        all_b.emplace_back(b);
    }
    vector<vector<int>> all_a;
    all_a.emplace_back();
    for (int i = 0; i < n; i++) {
        vector<vector<int>> nw;
        for (auto t : all_a) {
            for (int x = 1; x <= m; x++) {
                t.emplace_back(x);
                nw.emplace_back(t);
                t.pop_back();
            }
        }
        swap(all_a, nw);
    }
    Mint ans = 0;
    for (const auto& a : all_a) {
        bool stop = false;
        for (const auto& b : all_b) {
            bool ok = true;
            for (int i = 0; i < n; i++) {
                if (a[i] == b[i]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                stop = true;
                break;
            }
        }
        if (stop) {
            ans += 1;
        }
    }
    return ans;
}

Mint fast(int n, int m, int b0) {
    Mint tot = 1;
    for (int i = 0; i < n; i++) {
        tot *= Mint(m);
    }
    if (b0 >= m) {
        return tot;
    }
    vector<Mint> f(n);
    for (int cnt_up = 0; cnt_up <= n; cnt_up++) {
        int cnt_dn = b0 + cnt_up + 1;
        if (cnt_up + cnt_dn <= n) {
            f[cnt_up + cnt_dn - 1] += cat(cnt_dn, cnt_up, m - b0);
        }
    }

    vector<Mint> ct((n / 2) + 1, 0);
    ct[0] = 1;
    for (int j = 1; 2 * j < n; j++) {
        ct[j] = cat(j, j, m + 1);
    }
    ct = fps_inv(ct);
    vector<Mint> f2((n / 2) + 1);
    for (int i = 0; i < n; i++) {
        if ((i + 1) % 2 == (b0 + 1) % 2) {
            f2[i / 2] = f[i];
        }
    }
    f2 = convolve(f2, ct);

    vector<Mint> pw1(n + 1, 1);
    vector<Mint> pw0(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        pw1[i] = pw1[i - 1] * (m - 1);
        pw0[i] = pw0[i - 1] * m;
    }
    for (int i = 1; i <= n; i++) {
        if (i >= b0 + 1 && (i - b0 - 1) % 2 == 0) {
            int cnt_up = (i - b0 - 1) / 2;
            tot -= ((i - 1) / 2 < f2.size() ? f2[(i - 1) / 2] : Mint(0)) * pw1[cnt_up] * pw0[n - i];
        }
    }
    return tot;
}

void solve() {
    int n, m, b0;
    cin >> n >> m >> b0;
    //cout << slow(n, m, b0) << "\n";
    cout << fast(n, m, b0) << "\n";
}

void init() {
    fact[0] = 1;
    for (int i = 1; i < M; i++) {
        fact[i] = fact[i - 1] * i;
    }
    inv[M - 1] = Mint(1) / fact[M - 1];
    for (int i = M - 2; i >= 0; i--) {
        inv[i] = inv[i + 1] * (i + 1);
    }
}

int32_t main() {
#ifdef ONPC
    freopen("input", "r", stdin);
    //freopen("output", "w", stdout);
#endif
    Init();

    init();

    int t = 1;

    cin >> t;

    while (t--) {
        solve();
    }

#ifdef ONPC
    cout << endl;
    cout << "___" << endl;
    cout << "working time: " << TIME << endl;
#endif

    return 0;
}