#include <bits/stdc++.h>

using namespace std;



using ll = long long;

using ld = long double;



#define all(a) begin(a), end(a)

#define len(a) int((a).size())



namespace rn = ranges;

namespace vw = rn::views;



namespace helpers {

    template<typename T, typename = void>

    struct is_printable : std::false_type {};



    template<typename T>

    struct is_printable<T, typename std::enable_if_t<std::is_same_v<decltype(std::cout << std::declval<T>()), std::ostream&>>> : std::true_type {};



    template<typename T, typename = void>

    struct is_iterable : std::false_type {};



    template<typename T>

    struct is_iterable<T, std::void_t<decltype(std::begin(std::declval<T>())), decltype(std::end(std::declval<T>()))>> : std::true_type {};

}



namespace __to_string {

    std::string to_string(const bool &b) {

        return b ? "true" : "false";

    }



    template<size_t SZ>

    std::string to_string(const std::bitset<SZ> &bs) {

        std::string s;

        for (size_t i = 0; i < SZ; i++)

            s += bs[i] ? "1" : "0";



        return s;

    }



    std::string to_string(const std::vector<bool> &v) {

        std::string s;

        for (size_t i = 0; i < v.size(); i++)

            s += v[i] ? "1" : "0";



        return s;

    }



    template<typename T>

    typename std::enable_if_t<helpers::is_printable<T>::value, std::string> to_string(const T &t);



    template<typename T>

    typename std::enable_if_t<helpers::is_iterable<T>::value && !helpers::is_printable<T>::value, std::string> to_string(const T &v);



    template<typename A, typename B>

    std::string to_string(const std::pair<A, B> &p);



    template<typename T, typename _Container, typename _Compare>

    std::string to_string(std::priority_queue<T, _Container, _Compare> pq);



    template<typename T>

    typename std::enable_if_t<helpers::is_printable<T>::value, std::string> to_string(const T &t) {

        std::stringstream ss;

        if constexpr (helpers::is_iterable<T>::value)

            ss << '{';



        ss << std::fixed << std::setprecision(10) << t;

        if constexpr (helpers::is_iterable<T>::value)

            ss << '}';



        return ss.str();

    }



    template<typename T>

    typename std::enable_if_t<helpers::is_iterable<T>::value && !helpers::is_printable<T>::value, std::string> to_string(const T &v) {

        std::string s = "{", sep;

        for (const auto &x : v) {

            s += sep + to_string(x);

            sep = ", ";

        }

        return s + "}";

    }



    template<typename A, typename B>

    std::string to_string(const std::pair<A, B> &p) {

        return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";

    }



    template<typename T, typename _Container, typename _Compare>

    std::string to_string(std::priority_queue<T, _Container, _Compare> pq) {

        std::string res = "{", sep;

        while (!pq.empty()) {

            res += sep + to_string(pq.top());

            sep = ", ";

            pq.pop();

        }

        res += "}";

        return res;

    }

}



void __dbg_out() {

    std::cout << std::endl;

}



template<typename Head, typename... Tail>

void __dbg_out(Head head, Tail... tail) {

    std::cout << __to_string::to_string(head);

    if (sizeof...(tail))

        std::cout << ", ";



    __dbg_out(tail...);

}



// #define LOCAL



#ifdef LOCAL

    #define dprint(...) __dbg_out(__VA_ARGS__)

    #define dbg(...) std::cout << "#" << __LINE__ << " [" << #__VA_ARGS__ << "]: ", __dbg_out(__VA_ARGS__)

    #define debug if constexpr (true)

#else

    #define dbg(...)

    #define dprint(...)

    #define debug if constexpr (false)

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



    bool operator<(const mint &x) const {

        return value < x.value;

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



// constexpr int MOD = 1'000'000'007;

constexpr int MOD = 998'244'353;

using mint = static_modular_int<MOD>;



int main() {

    cin.tie(nullptr)->sync_with_stdio(false);



    vector<array<int, 2>> states{array{0, 0}, array{1, 0}, array{0, 1}, array{1, 1}};

    array<mint, 3> ans;

    ans.fill(0);



    static constexpr int p4[5]{1, 4, 16, 64, 256};

    constexpr int MASK = p4[4];

    auto get = [&](int mask, int id) {

        return mask / p4[id] % 4;

    };

    auto set = [&](int &mask, int id, int value) {

        mask += value * p4[id];

    };



    int precalc_mask[1 << 4][MASK][256];

    int precalc_delta[1 << 4][MASK][256];

    for (int mask_used = 0; mask_used < (1 << 4); mask_used++) {

        for (int mask = 0; mask < MASK; mask++) {

            for (char c : {'a', 'b'}) {

                int nmask = 0, delta = 0;

                for (int i : {0, 1, 2, 3}) {

                    static array<int, 2> cur;

                    cur = states[get(mask, i)];

                    cur[c == 'b']++;

                    if (cur[0] > 1 || cur[1] > 1) {

                        if (mask_used >> i & 1) delta += cur[0] == 2 ? -1 : 1;

                        cur = {0, 0};

                    }

                    set(nmask, i, rn::find(states, cur) - states.begin());

                }

                precalc_mask[mask_used][mask][c] = nmask;

                precalc_delta[mask_used][mask][c] = delta;

            }

        }

    }



    auto solve = [&](string s, int n) {

        dprint("solve", s, n);



        auto get_mask_used = [&](int mask) {

            array<int, 4> used;

            used.fill(0);

            for (int i = 0; used[i] <= 3; i = get(mask, i)) {

                used[i]++;

            }

            int mask_used = 0;

            for (int i : {0, 1, 2, 3}) {

                if (used[i] >= 2) mask_used ^= 1 << i;

            }

            return mask_used;

        };



        for (int mask_used = 0; mask_used < (1 << 4); mask_used++) {

            vector<array<mint, MASK>> dp(4 * n + 1);



            int init_mask = 0;

            for (int i : {0, 1, 2, 3}) set(init_mask, i, i);

            dp[2 * n][init_mask] = 1;

            array<vector<int>, MASK> good;

            good[init_mask].push_back(2 * n);

            array<vector<int>, MASK> ngood;

            array<vector<int>, MASK> used;

            used.fill(vector<int>(4 * n + 1, -1));

            int timer = 0;



            vector<array<mint, MASK>> ndp(4 * n + 1);

            for (int i = 0; i < n; i++) {

                timer++;

                for (auto &arr : ndp) arr.fill(0);

                for (auto &v : ngood) v.clear();



                for (char c : {'a', 'b'}) {

                    if (s[i] != '?' && c != s[i]) continue;

                    for (int mask = 0; mask < MASK; mask++) {

                        if (good[mask].empty()) continue;

                        int nmask = precalc_mask[mask_used][mask][c];

                        int delta_balance = precalc_delta[mask_used][mask][c];

                        for (auto balance : good[mask]) {

                            int nbalance = balance + delta_balance;

                            if (0 <= nbalance && nbalance <= 4 * n) {

                                ndp[nbalance][nmask] += dp[balance][mask];

                                if (used[nmask][nbalance] != timer) {

                                    used[nmask][nbalance] = timer;

                                    ngood[nmask].push_back(nbalance);

                                }

                            }

                        }

                    }

                }

                dp.swap(ndp);

                good.swap(ngood);

            }



            for (int balance = 0; balance <= 4 * n; balance++) {

                for (int mask = 0; mask < MASK; mask++) {

                    if (mask_used != get_mask_used(mask)) continue;

                    mint cur = dp[balance][mask];

                    if (balance < 2 * n) {

                        ans[0] += cur;

                    } else if (balance == 2 * n) {

                        ans[1] += cur;

                    } else {

                        debug {

                            if (cur != mint(0)) {

                                dprint();

                                dprint("add");

                                cout << "mask_used: ";

                                for (int i : {0, 1, 2, 3}) cout << (mask_used >> i & 1);

                                cout << endl;

                                cout << endl;

                                int cur_mask = init_mask;

                                int delta = 0;

                                for (char c : s) {

                                    for (int i = 0; i < 4; i++) cout << get(cur_mask, i);

                                    cout << endl;

                                    cout << "delta = " << delta << endl;

                                    dprint();

                                    int nmask = precalc_mask[mask_used][cur_mask][c];

                                    int ndelta = precalc_delta[mask_used][cur_mask][c];

                                    delta += ndelta;

                                    cur_mask = nmask;

                                }

                                for (int i = 0; i < 4; i++) cout << get(mask, i);

                                cout << endl;

                                cout << cur << endl;

                                dprint();

                            }

                        }

                        ans[2] += cur;

                    }

                }

            }

        }

        dbg(ans);

    };



    string s;

    cin >> s;

    // s = string(200, '?');

    int n = len(s);

    if (n <= 4) {

        for (int mask = 0; mask < (1 << n); mask++) {

            string cur_s(n, '?');

            bool ok = true;

            for (int i = 0; i < n; i++) {

                cur_s[i] = (mask >> i & 1) ? 'a' : 'b';

                if (s[i] != '?' && cur_s[i] != s[i]) ok = false;

            }

            if (!ok) continue;

            solve(cur_s + cur_s + cur_s, 3 * n);

        }

    } else {

        solve(s, n);

    }



    rn::for_each(ans, [](auto &x) { cout << x << '\n'; });

}