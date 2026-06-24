#include <bits/stdc++.h>

using namespace std;



using ll = long long;

using ld = long double;



#define all(a) begin(a), end(a)

#define len(a) int((a).size())



namespace rn = ranges;

namespace vw = rn::views;



#ifdef LOCAL

    #include "debug.h"

#else

    #define dbg(...)

    #define dprint(...)

#endif // LOCAL



template<typename T>

int normalize(T value, int mod) {

    if (value < -mod || value >= 2 * mod)

        value %= mod;



    if (value < 0)

        value += mod;



    if (value >= mod)

        value -= mod;



    return value;

}



template<int mod>

struct static_modular_int {

    using mint = static_modular_int<mod>;



    int value;



    static_modular_int() : value(0) {}

    static_modular_int(const mint &x) : value(x.value) {}



    template<typename T, typename U = std::enable_if_t<std::is_integral<T>::value>>

    static_modular_int(T value) : value(normalize(value, mod)) {}



    template<typename T>

    mint power(T degree) const {

        degree = normalize(degree, mod - 1);

        mint prod = 1;

        mint a = *this;



        for (; degree > 0; degree >>= 1, a *= a)

            if (degree & 1)

                prod *= a;



        return prod;

    }



    mint inv() const {

        return power(-1);

    }



    mint& operator=(const mint &x) {

        value = x.value;

        return *this;

    }



    mint& operator+=(const mint &x) {

        value += x.value;

        if (value >= mod)

            value -= mod;



        return *this;

    }



    mint& operator-=(const mint &x) {

        value -= x.value;

        if (value < 0)

            value += mod;



        return *this;

    }



    mint& operator*=(const mint &x) {

        value = (long long) value * x.value % mod;

        return *this;

    }



    mint& operator/=(const mint &x) {

        return *this *= x.inv();

    }



    friend mint operator+(const mint &x, const mint &y) {

        return mint(x) += y;

    }



    friend mint operator-(const mint &x, const mint &y) {

        return mint(x) -= y;

    }



    friend mint operator*(const mint &x, const mint &y) {

        return mint(x) *= y;

    }



    friend mint operator/(const mint &x, const mint &y) {

        return mint(x) /= y;

    }



    mint& operator++() {

        ++value;

        if (value == mod)

            value = 0;



        return *this;

    }



    mint& operator--() {

        --value;

        if (value == -1)

            value = mod - 1;



        return *this;

    }



    mint operator++(int) {

        mint prev = *this;

        value++;

        if (value == mod)

            value = 0;



        return prev;

    }



    mint operator--(int) {

        mint prev = *this;

        value--;

        if (value == -1)

            value = mod - 1;



        return prev;

    }



    mint operator-() const {

        return mint(0) - *this;

    }



    bool operator==(const mint &x) const {

        return value == x.value;

    }



    bool operator!=(const mint &x) const {

        return value != x.value;

    }



    template<typename T>

    explicit operator T() {

        return value;

    }



    friend std::istream& operator>>(std::istream &in, mint &x) {

        std::string s;

        in >> s;

        x = 0;

        for (const auto c : s)

            x = x * 10 + (c - '0');



        return in;

    }



    friend std::ostream& operator<<(std::ostream &out, const mint &x) {

        return out << x.value;

    }



    static int primitive_root() {

        if constexpr (mod == 1'000'000'007)

            return 5;



        if constexpr (mod == 998'244'353)

            return 3;



        if constexpr (mod == 786433)

            return 10;



        static int root = -1;

        if (root != -1)

            return root;



        std::vector<int> primes;

        int value = mod - 1;

        for (int i = 2; i * i <= value; i++)

            if (value % i == 0) {

                primes.push_back(i);

                while (value % i == 0)

                    value /= i;

            }



        if (value != 1)

            primes.push_back(value);



        for (int r = 2;; r++) {

            bool ok = true;

            for (auto p : primes)

                if ((mint(r).power((mod - 1) / p)).value == 1) {

                    ok = false;

                    break;

                }



            if (ok)

                return root = r;

        }

    }

};



constexpr int MOD = 1'000'000'007;

// constexpr int MOD = 998'244'353;

using mint = static_modular_int<MOD>;



void solve(int test_num) {

    int n;

    cin >> n;

    vector<int> p(n);

    rn::for_each(p, [](auto &x) {

        cin >> x;

        if (x != -1) x--;

    });



    mint ans = 0;

    for (int rot : {0, 1}) {

        vector<int> inv_p(n, -1);

        for (int i = 0; i < n; i++) {

            if (p[i] != -1) inv_p[p[i]] = i;

        }



        vector<int> ord, inv_ord(n);

        for (int i = 0; i < n; i += 2) ord.push_back(i);

        for (int i = n - 1 - n % 2; i >= 0; i -= 2) ord.push_back(i);

        for (int i = 0; i < n; i++) inv_ord[ord[i]] = i;



        auto can_paste = [&](int i, int val) {

            bool ok = inv_p[val] == -1 || p[ord[i]] == val;

            if (val == 0) ok &= ord[i] % 2 == 0;

            if (val == n - 1) ok &= ord[i] % 2;

            return ok;

        };



        vector dp(n, vector<mint>(n));

        for (int i = 0; i < n; i++) {

            if (can_paste(i, n - 1)) dp[i][i] = 1;

        }

        for (int delta = 1; delta < n; delta++) {

            for (int i = 0; i < n; i++) {

                int j = (i + delta) % n, val = n - 1 - delta;

                auto in_seg = [&](int pos) {

                    pos = inv_ord[pos];

                    return i < j ? (i <= pos && pos <= j) : (pos <= j || i <= pos);

                };

                auto check = [&](int pos) {

                    if (!can_paste(pos, val)) return false;

                    for (int d : {-1, 1}) {

                        if (ord[pos] + d < 0 || ord[pos] + d >= n) continue;

                        if (!in_seg(ord[pos] + d) ^ (ord[pos] % 2)) return false;

                    }

                    return true;

                };



                if (check(i)) dp[i][j] += dp[(i + 1) % n][j];

                if (check(j)) dp[i][j] += dp[i][(j + n - 1) % n];

                if (delta == n - 1) ans += dp[i][j];

            }

        }



        // dbg(rot);

        // dbg(ord);

        // for (int delta = 0; delta < n; delta++) {

        //     for (int i = 0; i < n; i++) {

        //         int j = (i + delta) % n;

        //         dprint(i, j, dp[i][j]);

        //     }

        //     dprint();

        // }

        // dprint();



        for (auto &x : p) {

            if (x != -1) x = n - 1 - x;

        }

    }

    cout << ans / 2 << '\n';

}



int main() {

    cin.tie(nullptr)->sync_with_stdio(false);



    int tests;

    cin >> tests;

    for (int test_num = 1; test_num <= tests; test_num++) {

        solve(test_num);

    }

}