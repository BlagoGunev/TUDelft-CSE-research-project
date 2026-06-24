// clang-format off
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
template<class Fun>
class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(ref(*this), forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<decay_t<Fun>>(forward<Fun>(fun)); }
// using namespace __gnu_pbds;
// template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef XOX
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) { ris << "(" << d.first << ", " << d.second << ")"; }
sim dor(rge<c> d) { *this << "["; for (auto it = d.b; it != d.e; ++it) *this << ", " + 2 * (it == d.b) << *it; ris << "]"; }
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
struct { template <class T> operator T() { T x; cin >> x; return x; } } in;
#define endl '\n'
#define pb emplace_back
#define vt vector
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using i64 = long long;
// define int long long
// clang-format on

void solve() {
    int n = in;
    vector<int> a(n);
    for (auto &x : a)
        x = in;
    while (true) {
        bool t = 0;
        for (int i = 1; i < n - 1; i++) {
            if (a[i - 1] < a[i] && a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                t = 1;
            }
        }
        if (!t) break;
    }
    cout << (is_sorted(all(a)) ? "YES" : "NO") << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    // int t = 1;
    int t = in;
    while (t--) {
        solve();
    }
}