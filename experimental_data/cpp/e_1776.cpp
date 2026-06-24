#include <bits/stdc++.h>



template<typename T = long long>

struct Frac {

    T num, den;



    constexpr void norm() {

        // T gcd = std::gcd(num, den);

        // num /= gcd, den /= gcd;

    }



    constexpr Frac() : Frac(0, 1) {}

    constexpr Frac(T num) : Frac(num, 1) {}

    constexpr Frac(T num, T den) {

        assert(den != 0);

        if (den < 0) {

            den = -den;

            num = -num;

        }

        this->num = num;

        this->den = den;

        norm();

    }



    constexpr double toDouble() const {

        return 1.0 * num / den;

    }



    constexpr Frac& operator+=(const Frac& rhs) {

        T lcm = std::lcm(den, rhs.den);

        num = num * (lcm / den) + rhs.num * (lcm / rhs.den);

        den = lcm;

        norm();

        return *this;

    }

    constexpr Frac& operator-=(const Frac& rhs) {

        T lcm = std::lcm(den, rhs.den);

        num = num * (lcm / den) - rhs.num * (lcm / rhs.den);

        den = lcm;

        norm();

        return *this;

    }

    constexpr Frac& operator*=(const Frac& rhs) {

        num *= rhs.num;

        den *= rhs.den;

        norm();

        return *this;

    }

    constexpr Frac& operator/=(const Frac& rhs) {

        assert(rhs.num != 0);

        num *= rhs.den;

        den *= rhs.num;

        if (den < 0) {

            num = -num;

            den = -den;

        }

        norm();

        return *this;

    }

    

    friend constexpr Frac operator+(Frac lhs, const Frac& rhs) {

        return lhs += rhs;

    }

    friend constexpr Frac operator-(Frac lhs, const Frac& rhs) {

        return lhs -= rhs;

    }

    friend constexpr Frac operator*(Frac lhs, const Frac& rhs) {

        return lhs *= rhs;

    }

    friend constexpr Frac operator/(Frac lhs, const Frac& rhs) {

        return lhs /= rhs;

    }

    friend constexpr Frac operator-(const Frac& a) {

        return Frac(-a.num, a.den);

    }

    friend constexpr bool operator==(const Frac& lhs, const Frac& rhs) {

        return lhs.num * rhs.den == rhs.num * lhs.den;

    }

    friend constexpr bool operator!=(const Frac& lhs, const Frac& rhs) {

        return lhs.num * rhs.den != rhs.num * lhs.den;

    }

    friend constexpr bool operator<(const Frac& lhs, const Frac& rhs) {

        return lhs.num * rhs.den < rhs.num * lhs.den;

    }

    friend constexpr bool operator>(const Frac& lhs, const Frac& rhs) {

        return lhs.num * rhs.den > rhs.num * lhs.den;

    }

    friend constexpr bool operator<=(const Frac& lhs, const Frac& rhs) {

        return lhs.num * rhs.den <= rhs.num * lhs.den;

    }

    friend constexpr bool operator>=(const Frac& lhs, const Frac& rhs) {

        return lhs.num * rhs.den >= rhs.num * lhs.den;

    }



    friend constexpr std::istream& operator>>(std::istream& is, Frac& a) {

        T num, den;

        is >> num;

        is.ignore(1, '/');

        is >> den;

        a = Frac(num, den);

        return is;

    }

    friend constexpr std::ostream& operator<<(std::ostream& os, const Frac& a) {

        os << a.num << '/' << a.den;

        return os;

    }

};



using i64 = long long;

using F = Frac<i64>;

template <typename T>

struct Fenwick {

    int n;

    std::vector<T> a;

    

    Fenwick(int n = 0) {

        init(n);

    }

    

    void init(int n) {

        this->n = n;

        a.assign(n, T());

    }

    

    void add(int x, T v) {

        for (int i = x + 1; i <= n; i += i & -i) {

            a[i - 1] += v;

        }

    }

    

    T sum(int x) {

        auto ans = T();

        for (int i = x; i > 0; i -= i & -i) {

            ans += a[i - 1];

        }

        return ans;

    }

    

    T rangeSum(int l, int r) {

        return sum(r) - sum(l);

    }

    

    int kth(T k) {

        int x = 0;

        for (int i = 1 << std::__lg(n); i; i /= 2) {

            if (x + i <= n && k >= a[x + i - 1]) {

                x += i;

                k -= a[x - 1];

            }

        }

        return x;

    }

};



constexpr int inf = 1E9;



struct Min {

    int x = inf;

    Min &operator+=(Min a) {

        x = std::min(x, a.x);

        return *this;

    }

};



int main() {

    std::ios::sync_with_stdio(false);

    std::cin.tie(nullptr);

    

    int n, m;

    i64 s, v;

    std::cin >> n >> m >> s >> v;

    

    s -= (m + 1) * v;

    

    if (s < 0) {

        std::cout << -1 << "\n";

        return 0;

    }

    

    std::vector<std::vector<std::pair<i64, i64>>> trains(m + 1);

    for (int i = 0; i < n; i++) {

        i64 a, b;

        int r;

        std::cin >> a >> b >> r;

        a -= v * r;

        b -= v * r;

        

        if (b >= 0 && a <= s) {

            trains[r].emplace_back(a, b);

        }

    }

    

    std::vector<std::vector<std::pair<i64, i64>>> ranges(m + 2);

    ranges[0].emplace_back(0, s);

    ranges[m + 1].emplace_back(0, s);

    std::vector<std::pair<int, i64>> pts;

    pts.emplace_back(0, 0);

    pts.emplace_back(0, s);

    pts.emplace_back(m + 1, 0);

    pts.emplace_back(m + 1, s);

    for (int i = 1; i <= m; i++) {

        i64 cur = 0;

        std::sort(trains[i].begin(), trains[i].end());

        for (auto [x, y] : trains[i]) {

            if (cur <= x) {

                ranges[i].emplace_back(cur, x);

            }

            cur = std::max(cur, y);

        }

        if (cur <= s) {

            ranges[i].emplace_back(cur, s);

        }

        for (auto [l, r] : ranges[i]) {

            pts.emplace_back(i, l);

            pts.emplace_back(i, r);

        }

    }

    

    std::sort(pts.begin(), pts.end());

    pts.erase(std::unique(pts.begin(), pts.end()), pts.end());

    

    auto check = [&](int x, F y) {

        if (y < 0) {

            return false;

        }

        if (y > s) {

            return false;

        }

        i64 v = y.num / y.den + 1;

        auto &s = ranges[x];

        auto it = std::lower_bound(s.begin(), s.end(), std::pair(v, -1LL));

        if (it == s.begin()) {

            return false;

        }

        it--;

        return y <= it->second;

    };

    

    struct Line {

        int x;

        i64 y;

        F k;

        int l;

        int r;

    };

    std::vector<Line> line;

    auto add = [&](int x, i64 y, F k) {

        int l = x, r = x;

        while (l > 0 && check(l - 1, y + (l - 1 - x) * k)) {

            l--;

        }

        while (r < m + 1 && check(r + 1, y + (r + 1 - x) * k)) {

            r++;

        }

        line.push_back({x, y, k, l, r});

    };

    

    for (int i = 0; i < pts.size(); i++) {

        add(pts[i].first, pts[i].second, 0);

        for (int j = i + 1; j < pts.size(); j++) {

            if (pts[i].first < pts[j].first && pts[i].second < pts[j].second) {

                add(pts[i].first, pts[i].second, F(pts[j].second - pts[i].second, pts[j].first - pts[i].first));

            }

        }

    }

    

    int N = line.size();

    std::vector<int> dp(N, inf);

    for (int i = 0; i < N; i++) {

        if (line[i].l == 0) {

            dp[i] = 0;

        }

    }

    

    std::vector<F> fl(N), fr(N);

    std::vector<int> frx(N);

    

    for (int x = 1; x <= m + 1; x++) {

        std::vector<int> g(N, inf);

        

        std::vector<int> L, R;

        for (int i = 0; i < N; i++) {

            if (line[i].l <= x - 1 && x - 1 <= line[i].r) {

                L.push_back(i);

            }

            if (line[i].l <= x && x <= line[i].r) {

                g[i] = dp[i];

                R.push_back(i);

            }

            fl[i] = line[i].y + (x - 1 - line[i].x) * line[i].k;

            fr[i] = line[i].y + (x - line[i].x) * line[i].k;

        }

        

        auto vr = fr;

        std::sort(vr.begin(), vr.end());

        for (int i = 0; i < N; i++) {

            frx[i] = std::lower_bound(vr.begin(), vr.end(), fr[i]) - vr.begin();

        }

        

        auto cmp = [&](int i, int j) {

            return fl[i] < fl[j];

        };

        

        std::sort(L.begin(), L.end(), cmp);

        std::sort(R.begin(), R.end(), cmp);

        

        Fenwick<Min> fen(N);

        

        for (int i = 0, j = 0; i < R.size(); i++) {

            while (j < L.size() && fl[L[j]] <= fl[R[i]]) {

                fen.add(N - 1 - frx[L[j]], {dp[L[j]]});

                j++;

            }

            g[R[i]] = std::min(g[R[i]], fen.sum(N - frx[R[i]]).x + 1);

        }

        

        fen.init(N);

        std::reverse(L.begin(), L.end());

        std::reverse(R.begin(), R.end());

        for (int i = 0, j = 0; i < R.size(); i++) {

            while (j < L.size() && fl[L[j]] >= fl[R[i]]) {

                fen.add(frx[L[j]], {dp[L[j]]});

                j++;

            }

            g[R[i]] = std::min(g[R[i]], fen.sum(frx[R[i]] + 1).x + 1);

        }

        dp = g;

    }

    

    int ans = inf;

    for (int i = 0; i < N; i++) {

        ans = std::min(ans, dp[i]);

    }

    if (ans == inf) {

        ans = -1;

    }

    std::cout << ans << "\n";

    

    return 0;

}