#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template<typename T> using maxheap = priority_queue<T>;
template<typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;

constexpr int inf = 0x3f3f3f3f;
constexpr int ninf = -0x3f3f3f40;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr ll nlinf = -0x3f3f3f3f3f3f3f40;

template<typename T> bool chmax(T& a, const T& b) { return a < b ? (a = b, true) : false; }
template<typename T> bool chmin(T& a, const T& b) { return a > b ? (a = b, true) : false; }

template<typename T> concept tuple_like = requires { tuple_size<T>::value; };
template<typename T> concept set_like = requires { typename T::node_type::value_type; };
template<typename T> concept map_like = requires { typename T::node_type::mapped_type; };
template<typename T> concept originally_printable = requires(T t) { cout << t; };
template<typename T> concept newly_printable = ranges::range<T> || tuple_like<T>;

template<typename Ch, typename Tr, newly_printable T> basic_istream<Ch, Tr>& operator>>(basic_istream<Ch, Tr>& is, T& obj) {
    if constexpr (ranges::range<T>)
        for (auto& val : obj) is >> val;
    else apply([&](auto&... args) { (is >> ... >> args); }, obj);
    return is;
}

template<typename Ch, typename Tr, newly_printable T> basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr>& os, const T& obj) {
    int i = 0;
    if constexpr (ranges::range<T>) {
        constexpr const char* sep = newly_printable<ranges::range_value_t<T>> ? "\n" : " ";
        for (const auto& val : obj) os << val << (++i == obj.size() ? "" : sep);
    }
    else apply([&](const auto&... args) { ((os << args << (++i == sizeof...(args) ? "" : " ")), ...); }, obj);
    return os;
}

void read(auto&... args) { (cin >> ... >> args); }

template<input_or_output_iterator It> void read(It first, It last) {
    for (; first != last; first++) cin >> *first;
}

void print(const auto&... args) {
    int i = 0;
    ((cout << args << (++i == sizeof...(args) ? "" : " ")), ...);
    cout << '\n';
}

template<input_or_output_iterator It> void print(It first, It last) {
    if (first != last) {
        constexpr const char* sep = newly_printable<iter_value_t<It>> ? "\n" : " ";
        cout << *first;
        while (++first != last) cout << sep << *first;
    }
    cout << '\n';
}

template<typename T> void debug_print(const T& obj) {
    if constexpr (originally_printable<T>) clog << obj;
    else if constexpr (ranges::range<T>) {
        int i = 0;
        if constexpr (set_like<T> || map_like<T>) clog << '{';
        else clog << '[';
        for (const auto& val : obj) {
            if constexpr (map_like<T>) {
                debug_print(val.first);
                clog << ": ";
                debug_print(val.second);
            }
            else debug_print(val);
            clog << (++i == obj.size() ? "" : ", ");
        }
        if constexpr (set_like<T> || map_like<T>) clog << '}';
        else clog << ']';
    }
    else {
        int i = 0;
        clog << '(';
        apply([&](const auto&... args) { ((debug_print(args), clog << (++i == sizeof...(args) ? "" : ", ")), ...); }, obj);
        clog << ')';
    }
}

void debug(const auto&... args) {
    clog << "debug: ";
    int i = 0;
    ((debug_print(args), clog << (++i == sizeof...(args) ? "" : " ")), ...);
    clog << '\n';
}

template<input_or_output_iterator It> void debug(It first, It last) {
    clog << "debug: ";
    if (first != last) {
        debug_print(*first);
        while (++first != last) {
            clog << " ";
            debug_print(*first);
        }
    }
    clog << '\n';
}

void run() {
    int t;
    cin >> t;
    vector<string> s(t);
    for (auto& x : s) cin >> x;
    for (int i = 0; i < t; i++) {
        string s1;
        for (int j = 0; j < t; j++)
            if (i < s[j].length()) s1 += s[j][i];
        string s2 = s1;
        reverse(s2.begin(), s2.end());
        if (s1 == s2) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(10);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case #" << i << ": ";
        run();
    }
    return 0;
}