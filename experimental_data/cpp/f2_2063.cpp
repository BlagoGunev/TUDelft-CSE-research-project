#include <bits/stdc++.h>
#define rep(i,x,y) for (int i = x; i <= y; i++)
#define repd(i,x,y) for (int i = x; i >= y; i--)

using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;

template<class T>
constexpr T power(T a, u64 b, T res = 1) {
    for (; b != 0; b /= 2, a *= a) {
        if (b & 1) {
            res *= a;
        }
    }
    return res;
}

template<u32 P>
constexpr u32 mulMod(u32 a, u32 b) {
    return u64(a) * b % P;
}

template<u64 P>
constexpr u64 mulMod(u64 a, u64 b) {
    u64 res = a * b - u64(1.L * a * b / P - 0.5L) * P;
    res %= P;
    return res;
}

constexpr i64 safeMod(i64 x, i64 m) {
    x %= m;
    if (x < 0) {
        x += m;
    }
    return x;
}

constexpr std::pair<i64, i64> invGcd(i64 a, i64 b) {
    a = safeMod(a, b);
    if (a == 0) {
        return {b, 0};
    }
    
    i64 s = b, t = a;
    i64 m0 = 0, m1 = 1;

    while (t) {
        i64 u = s / t;
        s -= t * u;
        m0 -= m1 * u;
        
        std::swap(s, t);
        std::swap(m0, m1);
    }
    
    if (m0 < 0) {
        m0 += b / s;
    }
    
    return {s, m0};
}

template<std::unsigned_integral U, U P>
struct ModIntBase {
public:
    constexpr ModIntBase() : x(0) {}
    template<std::unsigned_integral T>
    constexpr ModIntBase(T x_) : x(x_ % mod()) {}
    template<std::signed_integral T>
    constexpr ModIntBase(T x_) {
        using S = std::make_signed_t<U>;
        S v = x_ % S(mod());
        if (v < 0) {
            v += mod();
        }
        x = v;
    }
    
    constexpr static U mod() {
        return P;
    }
    
    constexpr U val() const {
        return x;
    }
    
    constexpr ModIntBase operator-() const {
        ModIntBase res;
        res.x = (x == 0 ? 0 : mod() - x);
        return res;
    }
    
    constexpr ModIntBase inv() const {
        return power(*this, mod() - 2);
    }
    
    constexpr ModIntBase &operator*=(const ModIntBase &rhs) & {
        x = mulMod<mod()>(x, rhs.val());
        return *this;
    }
    constexpr ModIntBase &operator+=(const ModIntBase &rhs) & {
        x += rhs.val();
        if (x >= mod()) {
            x -= mod();
        }
        return *this;
    }
    constexpr ModIntBase &operator-=(const ModIntBase &rhs) & {
        x -= rhs.val();
        if (x >= mod()) {
            x += mod();
        }
        return *this;
    }
    constexpr ModIntBase &operator/=(const ModIntBase &rhs) & {
        return *this *= rhs.inv();
    }
    
    friend constexpr ModIntBase operator*(ModIntBase lhs, const ModIntBase &rhs) {
        lhs *= rhs;
        return lhs;
    }
    friend constexpr ModIntBase operator+(ModIntBase lhs, const ModIntBase &rhs) {
        lhs += rhs;
        return lhs;
    }
    friend constexpr ModIntBase operator-(ModIntBase lhs, const ModIntBase &rhs) {
        lhs -= rhs;
        return lhs;
    }
    friend constexpr ModIntBase operator/(ModIntBase lhs, const ModIntBase &rhs) {
        lhs /= rhs;
        return lhs;
    }
    
    friend constexpr std::istream &operator>>(std::istream &is, ModIntBase &a) {
        i64 i;
        is >> i;
        a = i;
        return is;
    }
    friend constexpr std::ostream &operator<<(std::ostream &os, const ModIntBase &a) {
        return os << a.val();
    }
    
    friend constexpr std::strong_ordering operator<=>(ModIntBase lhs, ModIntBase rhs) {
        return lhs.val() <=> rhs.val();
    }
    
private:
    U x;
};

template<u32 P>
using ModInt = ModIntBase<u32, P>;
template<u64 P>
using ModInt64 = ModIntBase<u64, P>;

struct Barrett {
public:
    Barrett(u32 m_) : m(m_), im((u64)(-1) / m_ + 1) {}

    constexpr u32 mod() const {
        return m;
    }

    constexpr u32 mul(u32 a, u32 b) const {
        u64 z = a;
        z *= b;
        
        u64 x = u64((u128(z) * im) >> 64);
        
        u32 v = u32(z - x * m);
        if (m <= v) {
            v += m;
        }
        return v;
    }

private:
    u32 m;
    u64 im;
};

template<u32 Id>
struct DynModInt {
public:
    constexpr DynModInt() : x(0) {}
    template<std::unsigned_integral T>
    constexpr DynModInt(T x_) : x(x_ % mod()) {}
    template<std::signed_integral T>
    constexpr DynModInt(T x_) {
        int v = x_ %= int(mod());
        if (v < 0) {
            v += mod();
        }
        x = v;
    }
    
    constexpr static void setMod(u32 m) {
        bt = m;
    }
    
    static u32 mod() {
        return bt.mod();
    }
    
    constexpr u32 val() const {
        return x;
    }
    
    constexpr DynModInt operator-() const {
        DynModInt res;
        res.x = (x == 0 ? 0 : mod() - x);
        return res;
    }
    
    constexpr DynModInt inv() const {
        auto v = invGcd(x, mod());
        assert(v.first == 1);
        return v.second;
    }
    
    constexpr DynModInt &operator*=(const DynModInt &rhs) & {
        x = bt.mul(x, rhs.val());
        return *this;
    }
    constexpr DynModInt &operator+=(const DynModInt &rhs) & {
        x += rhs.val();
        if (x >= mod()) {
            x -= mod();
        }
        return *this;
    }
    constexpr DynModInt &operator-=(const DynModInt &rhs) & {
        x -= rhs.val();
        if (x >= mod()) {
            x += mod();
        }
        return *this;
    }
    constexpr DynModInt &operator/=(const DynModInt &rhs) & {
        return *this *= rhs.inv();
    }
    
    friend constexpr DynModInt operator*(DynModInt lhs, const DynModInt &rhs) {
        lhs *= rhs;
        return lhs;
    }
    friend constexpr DynModInt operator+(DynModInt lhs, const DynModInt &rhs) {
        lhs += rhs;
        return lhs;
    }
    friend constexpr DynModInt operator-(DynModInt lhs, const DynModInt &rhs) {
        lhs -= rhs;
        return lhs;
    }
    friend constexpr DynModInt operator/(DynModInt lhs, const DynModInt &rhs) {
        lhs /= rhs;
        return lhs;
    }
    
    friend constexpr std::istream &operator>>(std::istream &is, DynModInt &a) {
        i64 i;
        is >> i;
        a = i;
        return is;
    }
    friend constexpr std::ostream &operator<<(std::ostream &os, const DynModInt &a) {
        return os << a.val();
    }
    
    friend constexpr std::strong_ordering operator<=>(DynModInt lhs, DynModInt rhs) {
        return lhs.val() <=> rhs.val();
    }
    
private:
    u32 x;
    static Barrett bt;
};

template<u32 Id>
Barrett DynModInt<Id>::bt = 998244353;

using Z = ModInt<998244353>;

struct Comb {
    int n;
    std::vector<Z> _fac;
    std::vector<Z> _invfac;
    std::vector<Z> _inv;
    
    Comb() : n{0}, _fac{1}, _invfac{1}, _inv{0} {}
    Comb(int n) : Comb() {
        init(n);
    }
    
    void init(int m) {
        if (m <= n) return;
        _fac.resize(m + 1);
        _invfac.resize(m + 1);
        _inv.resize(m + 1);
        
        for (int i = n + 1; i <= m; i++) {
            _fac[i] = _fac[i - 1] * i;
        }
        _invfac[m] = _fac[m].inv();
        for (int i = m; i > n; i--) {
            _invfac[i - 1] = _invfac[i] * i;
            _inv[i] = _invfac[i] * _fac[i - 1];
        }
        n = m;
    }
    
    Z fac(int m) {
        if (m > n) init(2 * m);
        return _fac[m];
    }
    Z invfac(int m) {
        if (m > n) init(2 * m);
        return _invfac[m];
    }
    Z inv(int m) {
        if (m > n) init(2 * m);
        return _inv[m];
    }
    Z binom(int n, int m) {
        if (n < m || m < 0) return 0;
        return fac(n) * invfac(m) * invfac(n - m);
    }
} comb;

Z calc(int n) {
    return comb.binom(n, n / 2) * comb.inv(n / 2 + 1);
}

/*
    PAY ATTENTION TO CONSTRUCT FUNCTION OF CLASS INFO!!!
*/
template<class Info>
struct SegmentTree {
    int n;
    std::vector<Info> info;
    SegmentTree() : n(0) {}
    SegmentTree(int n_, Info v_ = Info()) {
        init(n_, v_);
    }
    template<class T>
    SegmentTree(std::vector<T> init_) {
        init(init_);
    }
    void init(int n_, Info v_ = Info()) {
        init(std::vector(n_, v_));
    }
    template<class T>
    void init(std::vector<T> init_) {
        n = init_.size();
        info.assign(4 << std::__lg(n), Info());
        std::function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r - l == 1) {
                info[p] = init_[l];
                return;
            }
            int m = (l + r) / 2;
            build(2 * p, l, m);
            build(2 * p + 1, m, r);
            pull(p);
        };
        build(1, 0, n);
    }
    void pull(int p) {
        info[p] = info[2 * p] + info[2 * p + 1];
    }
    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        if (x < m) {
            modify(2 * p, l, m, x, v);
        } else {
            modify(2 * p + 1, m, r, x, v);
        }
        pull(p);
    }
    void modify(int p, const Info &v) {
        modify(1, 0, n, p, v);
    }
    Info rangeQuery(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return Info();
        }
        if (l >= x && r <= y) {
            return info[p];
        }
        int m = (l + r) / 2;
        return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
    }
    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n, l, r);
    }
    template<class F>
    int findFirst(int p, int l, int r, int x, int y, F &&pred) {
        if (l >= y || r <= x) {
            return -1;
        }
        if (l >= x && r <= y && !pred(info[p])) {
            return -1;
        }
        if (r - l == 1) {
            return l;
        }
        int m = (l + r) / 2;
        int res = findFirst(2 * p, l, m, x, y, pred);
        if (res == -1) {
            res = findFirst(2 * p + 1, m, r, x, y, pred);
        }
        return res;
    }
    template<class F>
    int findFirst(int l, int r, F &&pred) {
        return findFirst(1, 0, n, l, r, pred);
    }
    template<class F>
    int findLast(int p, int l, int r, int x, int y, F &&pred) {
        if (l >= y || r <= x) {
            return -1;
        }
        if (l >= x && r <= y && !pred(info[p])) {
            return -1;
        }
        if (r - l == 1) {
            return l;
        }
        int m = (l + r) / 2;
        int res = findLast(2 * p + 1, m, r, x, y, pred);
        if (res == -1) {
            res = findLast(2 * p, l, m, x, y, pred);
        }
        return res;
    }
    template<class F>
    int findLast(int l, int r, F &&pred) {
        return findLast(1, 0, n, l, r, pred);
    }
};

struct Info {
    int x = 0;
};

Info operator+(Info a, Info b) {
    return {max(a.x, b.x)};
}

void solve() {
    int n;
    cin >> n;

    vector<int> p(n + 1);
    p[0] = 2 * n;
    vector<int> id(2 * n + 1);
    Z ans = calc(2 * n);
    
    vector<int> t(2 * n + 1);

    auto ins = [&](int x, int y) {
        if (!x) {
            return;
        }
        for (int i = x; i <= 2 * n; i += i & -i) {
            t[i] += y;
        }
    };

    auto query = [&](int x) {
        int res = 0;
        for (int i = x; i; i -= i & -i) {
            res += t[i];
        }
        return res;
    };

    SegmentTree<Info> seg(2 * n + 1);
    seg.modify(0, {2 * n + 1});
    
    cout << ans;

    rep(i,1,n) {
        int l, r;
        cin >> l >> r;

        id[l] = i;

        auto it = seg.findLast(0, l, [&](auto t) {
            return t.x > r;
        });

        seg.modify(l, {r});
        int x = id[it];
        ans /= calc(p[x]);
        ins(it, -p[x] - 2);

        p[i] = r - l - 1 - (query(r) - query(l - 1));
        ins(l, p[i] + 2);
        p[x] -= p[i] + 2;
        ins(it, p[x] + 2);

        ans *= calc(p[i]) * calc(p[x]);
        cout << ' ' << ans;
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}