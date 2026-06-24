#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) int((a).size())

template<typename Fun>
struct y_combinator {
    const Fun fun;

    explicit y_combinator(const Fun&& fun) : fun(std::forward<const Fun>(fun)) {}

    template<typename... Args>
    auto operator()(Args&&... args) const {
        return fun(std::ref(*this), std::forward<Args>(args)...);
    }
};

/*
 ! WARNING: MOD must be prime if you use division or .inv().
 ! WARNING: 2 * (MOD - 1) must be smaller than INT_MAX
 * Use .value to get the stored value.
 */
template<typename T>
int normalize(T value, int mod) {
    if (value < -mod || value >= 2 * mod) value %= mod;
    if (value < 0) value += mod;
    if (value >= mod) value -= mod;
    return value;
}

template<int mod>
struct static_modular_int {
    static_assert(mod - 2 <= std::numeric_limits<int>::max() - mod, "2(mod - 1) <= INT_MAX");
    using mint = static_modular_int<mod>;

    int value;

    static_modular_int() : value(0) {}
    static_modular_int(const mint &x) : value(x.value) {}

    template<typename T, typename U = std::enable_if_t<std::is_integral<T>::value>>
    static_modular_int(T value) : value(normalize(value, mod)) {}

    static constexpr int get_mod() {
		return mod;
	}

    template<typename T>
    mint power(T degree) const {
        mint prod = 1, a = *this;
        for (; degree > 0; degree >>= 1, a *= a)
            if (degree & 1)
                prod *= a;

        return prod;
    }

    mint inv() const {
        return power(mod - 2);
    }

    mint& operator=(const mint &x) {
        value = x.value;
        return *this;
    }

    mint& operator+=(const mint &x) {
        value += x.value;
        if (value >= mod) value -= mod;
        return *this;
    }

    mint& operator-=(const mint &x) {
        value -= x.value;
        if (value < 0) value += mod;
        return *this;
    }

    mint& operator*=(const mint &x) {
        value = int64_t(value) * x.value % mod;
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
        if (value == mod) value = 0;
        return *this;
    }

    mint& operator--() {
        --value;
        if (value == -1) value = mod - 1;
        return *this;
    }

    mint operator++(int) {
        mint prev = *this;
        value++;
        if (value == mod) value = 0;
        return prev;
    }

    mint operator--(int) {
        mint prev = *this;
        value--;
        if (value == -1) value = mod - 1;
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
        bool neg = s[0] == '-';
        for (const auto c : s)
            if (c != '-')
                x = x * 10 + (c - '0');

        if (neg)
            x *= -1;

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

const mint INV3 = mint(3).inv();

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<vector<tuple<int, int, mint>>> g(n);
    while (m--) {
        int v, u, d;
        cin >> v >> u >> d;
        v--, u--;
        mint p2 = mint(2).power(d);
        g[v].emplace_back(u, d, p2);
        g[u].emplace_back(v, d, p2);
    }

    vector<bool> used(n);
    vector<tuple<int, int, mint>> par(n, {-1, -1, mint(0)});
    vector<int> dep(n, -1), which(n, -1);
    vector<vector<tuple<int, int, mint>>> cycles;

    y_combinator([&](auto dfs, int v) -> void {
        used[v] = true;
        for (auto [u, w, p2] : g[v]) {
            if (!used[u]) {
                par[u] = {v, w, p2};
                dep[u] = dep[v] + 1;
                dfs(u);
            } else if (dep[u] < dep[v] && u != get<0>(par[v])) {
                int cur_id = len(cycles);
                cycles.push_back({});

                which[u] = cur_id;
                for (int x = v; x != u; x = get<0>(par[x])) {
                    which[x] = cur_id;
                    cycles.back().emplace_back(x, get<1>(par[x]), get<2>(par[x]));
                }
                cycles.back().emplace_back(u, w, p2);
            }
        }
    })(0);

    fill(all(used), false);

    using Dp = array<array<mint, 4>, 4>; // [vertex value][xor of adjacent edges]

    Dp zero_dp;
    for (int i : {0, 1, 2, 3}) {
        zero_dp[i].fill(0);
    }
    vector<Dp> dp(n, zero_dp);

    vector<int> ord{0};
    ord.reserve(n);
    vector<bool> root(n);
    for (int ptr = 0; ptr < n; ptr++) {
        int v = ord[ptr];
        if (used[v]) {
            continue;
        }
        root[v] = true;
        used[v] = true;

        if (which[v] == -1) {
            for (auto [u, _, __] : g[v]) {
                if (!used[u]) {
                    ord.push_back(u);
                }
            }
        } else{
            for (auto [x, _, __] : cycles[which[v]]) {
                if (!used[x]) {
                    used[x] = true;
                    ord.push_back(x);
                }
            }
            for (auto [x, _, __] : cycles[which[v]]) {
                for (auto [u, _, __] : g[x]) {
                    if (!used[u]) {
                        ord.push_back(u);
                    }
                }
            }
        }
    }
    reverse(all(ord));

    for (auto v : ord) {
        auto base_dp = zero_dp;
        for (int val : {1, 2, 3}) {
            base_dp[val][0] = 1;
        }

        auto apply = [&](const Dp &udp, array<mint, 4> &equal, array<mint, 4> &different) {
            array<mint, 4> nequal{}, ndifferent{};
            for (int e : {1, 2, 3}) {
                for (int u : {1, 2, 3}) {
                    mint ways = (e == u ? equal[e] : different[e]);
                    for (int nxt : {1, 2, 3}) {
                        for (int ue : {0, 1, 2, 3}) {
                            int cur_xor = (ue ^ e ^ nxt);
                            if (cur_xor == 0 || cur_xor == u) {
                                continue;
                            }

                            if (nxt == u) {
                                ndifferent[nxt] += ways * udp[u][ue];
                            } else {
                                nequal[nxt] += ways * udp[u][ue];
                            }
                        }
                    }
                }
            }
            equal.swap(nequal);
            different.swap(ndifferent);
        };

        auto apply_many = [&](int d, mint bottom, array<mint, 4> &equal, array<mint, 4> &different) {
            if (d % 2 == 0) {
                bottom--;
            } else {
                bottom++;
            }
            bottom *= INV3;
            mint top = bottom + (d % 2 == 0 ? 1 : -1);

            array<mint, 4> nequal{}, ndifferent{};
            for (int e : {1, 2, 3}) {
                for (int e2 : {1, 2, 3}) {
                    mint coeff = (e == e2 ? top : bottom);
                    nequal[e2] += equal[e] * coeff;
                    ndifferent[e2] += different[e] * coeff;
                }
            }
            equal.swap(nequal);
            different.swap(ndifferent);
        };

        auto calc_dp = [&](int v) -> Dp {
            auto res = base_dp;
            for (auto [u, d, p2] : g[v]) {
                if (!used[u]) {
                    array<mint, 4> equal{}, different{};
                    for (int uv : {1, 2, 3}) {
                        for (int ue : {0, 1, 2, 3}) {
                            for (int nxt : {1, 2, 3}) {
                                if ((ue ^ nxt) == 0 || (ue ^ nxt) == uv) {
                                    continue;
                                }
                                if (uv == nxt) {
                                    different[nxt] += dp[u][uv][ue];
                                } else {
                                    equal[nxt] += dp[u][uv][ue];
                                }
                            }
                        }
                    }
                    apply_many(d, p2, equal, different);

                    auto nres = zero_dp;
                    for (int vv : {1, 2, 3}) {
                        for (int ve : {0, 1, 2, 3}) {
                            for (int prev : {1, 2, 3}) {
                                mint ways = (prev == vv ? equal[prev] : different[prev]);
                                nres[vv][ve ^ prev] += ways * res[vv][ve];
                            }
                        }
                    }
                    res.swap(nres);
                }
            }
            return res;
        };

        if (!root[v]) {
            dp[v] = calc_dp(v);
            continue;
        }

        if (which[v] == -1) {
            dp[v] = calc_dp(v);
            used[v] = false;
            continue;
        }

        auto &cycle = cycles[which[v]];
        int pos_v = 0;
        while (get<0>(cycle[pos_v]) != v) {
            pos_v++;
        }
        rotate(cycle.begin(), pos_v + all(cycle));

        for (auto [x, _, __] : cycle) {
            dp[x] = calc_dp(x);
        }

        auto ndp_v = zero_dp;
        for (int first_e : {1, 2, 3}) {
            for (int vv : {1, 2, 3}) {
                array<mint, 4> equal{}, different{};
                if (vv == first_e) {
                    different[first_e] = 1;
                } else {
                    equal[first_e] = 1;
                }

                for (int i = 1; i < len(cycle); i++) {
                    apply_many(get<1>(cycle[i - 1]), get<2>(cycle[i - 1]), equal, different);
                    apply(dp[get<0>(cycle[i])], equal, different);
                }
                apply_many(get<1>(cycle.back()), get<2>(cycle.back()), equal, different);

                for (int ve : {0, 1, 2, 3}) {
                    for (int prev : {1, 2, 3}) {
                        mint ways = (prev == vv ? equal[prev] : different[prev]);
                        ndp_v[vv][ve ^ prev ^ first_e] += ways * dp[v][vv][ve];
                    }
                }
            }
        }
        dp[v] = ndp_v;

        for (auto [x, _, __] : cycle) {
            used[x] = false;
        }
    }

    mint ans = 0;
    for (int x : {1, 2, 3}) {
        for (int y : {1, 2, 3}) {
            if (x != y) {
                ans += dp[0][x][y];
            }
        }
    }
    cout << ans << '\n';
}