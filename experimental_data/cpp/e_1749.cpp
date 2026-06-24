#define MULTI_TESTCASES

// #define NDEBUG



// Utility

#include <algorithm>

#include <chrono>

#include <functional>

#include <iterator>

#include <limits>

#include <memory>

#include <numeric>

#include <random>

#include <type_traits>

#include <utility>



// I/O

#include <fstream>

#include <iomanip>

#include <iostream>

#include <sstream>



// Data Structure

#include <array>

#include <bitset>

#include <deque>

#include <map>

#include <queue>

#include <set>

#include <stack>

#include <string>

#include <unordered_map>

#include <unordered_set>

#include <vector>



// Other Types

#include <complex>

#include <optional>

#include <tuple>

#include <variant>



// C

#include <cassert>

#include <cmath>

#include <cstddef>

#include <cstdint>

#include <cstdio>

#include <cstdlib>

#include <cstring>

#include <ctime>



namespace kod {

namespace util {



template <class F> class FixedPoint : private F {

    constexpr FixedPoint(F&& f) : F(std::forward<F>(f)) {}

    template <class G> friend constexpr decltype(auto) make_fixed(G&&);



  public:

    template <class... Args> constexpr decltype(auto) operator()(Args&&... args) const {

        return F::operator()(*this, std::forward<Args>(args)...);

    }

};



template <class G> [[nodiscard]] constexpr decltype(auto) make_fixed(G&& g) {

    using F = std::decay_t<G>;

    return FixedPoint<F>(std::forward<F>(g));

}



}  // namespace util

}  // namespace kod



namespace kod {

namespace util {



class ForwardLoop {

    int src, dst;



    constexpr ForwardLoop(const int x, const int y) : src(x), dst(y) {}

    friend constexpr ForwardLoop rep(const int, const int);

    friend constexpr ForwardLoop rep(const int);



  public:

    constexpr ForwardLoop begin() const { return *this; }

    constexpr std::monostate end() const { return {}; }

    constexpr bool operator!=(std::monostate) const { return src < dst; }

    constexpr void operator++() const {}

    constexpr int operator*() { return src++; }

};



[[nodiscard]] constexpr ForwardLoop rep(const int l, const int r) { return ForwardLoop(l, r); }

[[nodiscard]] constexpr ForwardLoop rep(const int n) { return ForwardLoop(0, n); }



class BackwardLoop {

    int src, dst;



    constexpr BackwardLoop(const int x, const int y) : src(x), dst(y) {}

    friend constexpr BackwardLoop revrep(const int, const int);

    friend constexpr BackwardLoop revrep(const int);



  public:

    constexpr BackwardLoop begin() const { return *this; }

    constexpr std::monostate end() const { return {}; }

    constexpr bool operator!=(std::monostate) const { return src > dst; }

    constexpr void operator++() const {}

    constexpr int operator*() { return --src; }

};



[[nodiscard]] constexpr BackwardLoop revrep(const int l, const int r) { return BackwardLoop(r, l); }

[[nodiscard]] constexpr BackwardLoop revrep(const int n) { return BackwardLoop(n, 0); }



template <class F> constexpr void repeat(int n, const F& f) {

    assert(n >= 0);

    while (n--) f();

}



}  // namespace util

}  // namespace kod



namespace kod {

namespace util {



struct Int1 {};

struct Chars {};



namespace stdio_impl {



template <class T> struct InputTypeImpl {

    using Type = T;

};

template <> struct InputTypeImpl<Int1> {

    using Type = int;

};

template <> struct InputTypeImpl<Chars> {

    using Type = std::vector<char>;

};



template <class T> using InputType = typename InputTypeImpl<T>::Type;



}  // namespace stdio_impl



template <class T> stdio_impl::InputType<T> scan() {

    T x;

    std::cin >> x;

    return x;

}

template <> int scan<Int1>() {

    int x;

    std::cin >> x;

    return x - 1;

}

template <> std::vector<char> scan<Chars>() {

    std::string s;

    std::cin >> s;

    return std::vector<char>(std::cbegin(s), std::cend(s));

}



template <class T, int N> std::array<stdio_impl::InputType<T>, N> scan_arr() {

    std::array<stdio_impl::InputType<T>, N> a;

    for (auto& x : a) x = scan<T>();

    return a;

}

template <class T> std::vector<stdio_impl::InputType<T>> scan_vec(int n) {

    if (n == -1) n = scan<int>();

    assert(n >= 0);

    std::vector<stdio_impl::InputType<T>> v;

    v.reserve(n);

    while (n--) v.push_back(scan<T>());

    return v;

}



void print() {}

template <class T, class... Args> void print(const T& x, const Args&... args) {

    std::cout << x;

    if (sizeof...(args) != 0) std::cout << ' ';

    print(args...);

}

template <class... Args> void println(const Args&... args) {

    print(args...);

    std::cout << '\n';

}



template <class C> void print_seq(const C& c, const char* sep = " ", const char* end = "\n") {

    bool f = false;

    for (const auto& x : c) {

        if (f) {

            std::cout << sep;

        } else {

            f = true;

        }

        std::cout << x;

    }

    std::cout << end;

}



}  // namespace util

}  // namespace kod



namespace kod {

namespace sol {



using i32 = std::int32_t;

using i64 = std::int64_t;

using i128 = __int128_t;

using u32 = std::uint32_t;

using u64 = std::uint64_t;

using u128 = __uint128_t;

using f64 = double;

using f80 = long double;



using std::array;

using std::pair;

using std::string;

using std::tuple;

using std::vector;



using namespace util;



constexpr i32 inf32 = std::numeric_limits<i32>::max() / 2;

constexpr i64 inf64 = std::numeric_limits<i64>::max() / 2;

constexpr array<char, 2> sepl = {' ', '\n'};



i64 floor_div(const i64 x, const i64 y) {

    assert(y != 0);

    return x / y - ((x ^ y) < 0 && x % y != 0);

}

i64 ceil_div(const i64 x, const i64 y) {

    assert(y != 0);

    return x / y + ((x ^ y) >= 0 && x % y != 0);

}



template <class T> constexpr bool setmin(T& lhs, const T& rhs) {

    if (lhs > rhs) {

        lhs = rhs;

        return true;

    }

    return false;

}

template <class T> constexpr bool setmax(T& lhs, const T& rhs) {

    if (lhs < rhs) {

        lhs = rhs;

        return true;

    }

    return false;

}



void run();



}  // namespace sol

}  // namespace kod



int main() {

    std::ios_base::sync_with_stdio(false);

    std::cin.tie(nullptr);

    std::cout << std::fixed << std::setprecision(20);

    int cases = 1;

#ifdef MULTI_TESTCASES

    std::cin >> cases;

#endif

    while (cases--) kod::sol::run();

    return 0;

}



#ifdef KOD_LOCAL

#define OJ_LOCAL(a, b) b

#include <kodlib/misc/debug>

#else

#define OJ_LOCAL(a, b) a

#define DBG(...)

#endif



namespace kod {

namespace sol {



void run() {

    const int n = scan<int>();

    const int m = scan<int>();

    vector<char> grid(n * m);

    vector<char> put(n * m, true);

    for (const int i : rep(n)) {

        for (const int j : rep(m)) {

            const int u = i * m + j;

            std::cin >> grid[u];

            if (grid[u] == '#') {

                if (i + 1 < n) put[u + m] = false;

                if (i > 0) put[u - m] = false;

                if (j + 1 < m) put[u + 1] = false;

                if (j > 0) put[u - 1] = false;

            }

        }

    }

    vector<int> dist(n * m, inf32);

    vector<int> last(n * m, -1);

    std::deque<int> deq;

    const auto push = [&](const int u, const int p) {

        const int d = (p == -1 ? 0 : dist[p]);

        if (put[u]) {

            if (grid[u] == '#') {

                if (setmin(dist[u], d)) {

                    last[u] = p;

                    deq.push_front(u);

                }

            } else {

                if (setmin(dist[u], d + 1)) {

                    last[u] = p;

                    deq.push_back(u);

                }

            }

        }

    };

    for (const int i : rep(n)) {

        push(i * m, -1);

    }

    while (!deq.empty()) {

        const int u = deq.front();

        DBG(u);

        deq.pop_front();

        const int i = u / m;

        const int j = u % m;

        for (const int x : {+1, -1}) {

            for (const int y : {+1, -1}) {

                if (0 <= i + x && i + x < n && 0 <= j + y && j + y < m) {

                    push((i + x) * m + (j + y), u);

                }

            }

        }

    }

    int s = m - 1;

    for (const int i : rep(n)) {

        if (dist[s] > dist[i * m + (m - 1)]) {

            s = i * m + (m - 1);

        }

    }

    if (dist[s] == inf32) {

        println("NO");

        return;

    }

    println("YES");

    while (s != -1) {

        grid[s] = '#';

        s = last[s];

    }

    for (const int i : rep(n)) {

        for (const int j : rep(m)) {

            std::cout << grid[i * m + j];

        }

        std::cout << '\n';

    }

}



}  // namespace sol

}  // namespace kod