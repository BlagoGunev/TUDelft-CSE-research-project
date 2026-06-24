#ifdef DEBUG
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <chrono>
#include <random>
#include <complex>
#include <numeric>
#include <assert.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ui = unsigned int;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, long long>;
using pli = pair<long long, int>;
using pll = pair<long long, long long>;
template <typename T>
using uset = unordered_set<T>;
template <typename T1, typename T2>
using umap = unordered_map<T1, T2>;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

template <uint32_t mod>
class Montgomery {
    using mint = Montgomery<mod>;
private:
    uint32_t value;

    static constexpr uint32_t inv_neg_mod = (mod == 998'244'353) ? 998'244'351 : ((mod == 1'000'000'007) ? 2226617417 : 0);

    static constexpr uint32_t neg_mod = (0 - uint64_t(mod)) % mod; // since R = 2^32, R^2 = 2^64 and 2^64 mod MOD = (2^64 - MOD) mod MOD

    static uint32_t reduce(const uint64_t& value) {
        return (value + uint64_t(uint32_t(value) * inv_neg_mod) * mod) >> 32;
    }
public:
    Montgomery() : value(0) {}

    Montgomery(const mint& other) : value(other.value) {}

    template<typename T>
    Montgomery(const T& x) : value(!x ? 0 : reduce(uint64_t(x % int32_t(mod) + int32_t(mod)) * neg_mod)) {}

    uint32_t get() const {
        uint32_t real = reduce(value);
        return real < mod ? real : real - mod;
    }

    mint& operator=(const mint& other) {
        value = other.value;
        return *this;
    }

    mint& operator+=(const mint& other) { // operations are made in range [0, 2 * mod)
        if (int32_t(value += other.value - (mod << 1)) < 0) {
            value += mod << 1;
        }
        return *this;
    }

    mint& operator-=(const mint& other) {
        if (int32_t(value -= other.value) < 0) {
            value += mod << 1;
        }
        return *this;
    }

    mint& operator*=(const mint& other) {
        value = reduce(uint64_t(value) * other.value);
        return *this;
    }

    mint& operator/=(const mint& other) {
        return *this *= other.inv();
    }

    friend mint operator+(const mint& a, const mint& b) {
        return mint(a) += b;
    }

    friend mint operator-(const mint& a, const mint& b) {
        return mint(a) -= b;
    }

    friend mint operator*(const mint& a, const mint& b) {
        return mint(a) *= b;
    }

    friend mint operator/(const mint& a, const mint& b) {
        return mint(a) /= b;
    }

    mint operator-() const {
        return mint(0) - *this;
    }

    bool operator==(const mint& other) const {
        return get() == other.get();
    }

    bool operator!=(const mint& other) const {
        return get() != other.get();
    }

    bool operator<(const mint& other) const {
        return get() < other.get();
    }

    friend std::istream& operator>>(std::istream& in, mint& other) {
        std::string s;
        in >> s;
        other = 0;
        bool neg = s[0] == '-';
        for (const auto c : s)
            if (c != '-')
                other = other * 10 + (c - '0');

        if (neg)
            other *= -1;

        return in;
    }

    friend std::ostream& operator<<(std::ostream& out, const mint& other) {
        return out << other.get();
    }

    template <typename T>
    mint power(T pw) const {
        mint b = 1, a = *this;
        for (; pw; pw >>= 1, a *= a)
            if (pw & 1)
                b *= a;
        return b;
    }

    mint inv() const {
        return power(mod - 2);
    }

    static int32_t primitive_root() {
        if constexpr (mod == 1'000'000'007)
            return 5;
        if constexpr (mod == 998'244'353)
            return 3;
        if constexpr (mod == 786433)
            return 10;
        return 0;
    }
};

const int mod = 1e9 + 7;
using mint = Montgomery<mod>;

inline void solve() {
    string s;
    cin >> s;
    int n = s.size();
    mint ans = 0;
    vector<int> p(n + 1);
    for (int i = 0; i < n; i++)
        p[i + 1] = p[i] + (s[i] == '1' ? 1 : -1);
    map<int, vector<int>> buc;
    for (int i = 0; i <= n; i++)
        buc[p[i]].push_back(i);
    map<int, mint> sum;
    sum[0] += 1;
    for (int r = 1; r <= n; r++) {
        ans += mint(n - r + 1) * sum[p[r]];
        sum[p[r]] += r + 1;
    }
    cout << ans << '\n';
}

signed main() {
#ifdef DEBUG
    freopen("01.dat", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--) {
#ifdef DEBUG
        cout << "Testcase#\n";
#endif
        solve();
    }
    return 0;
}