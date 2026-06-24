#include <bits/stdc++.h>

using namespace std;

template <ranges::range T,
          class = enable_if_t<!is_convertible_v<T, string_view>>>
istream &operator>>(istream &s, T &&v) {
    for (auto &&x : v) s >> x;
    return s;
}
template <ranges::range T,
          class = enable_if_t<!is_convertible_v<T, string_view>>>
ostream &operator<<(ostream &s, T &&v) {
    for (auto &&x : v) s << x << ' ';
    return s;
}

template <class F, class S>
ostream &operator<<(ostream &s, const pair<F, S> &v) {
    s << v.first << ' ' << v.second;
    return s;
}

#ifdef LOCAL
template <class... T> void dbg(T... x) {
    char e{};
    ((cerr << e << x, e = ' '), ...);
}
#define debug(x...) dbg(#x, '=', x, '\n')
#else
#define debug(...) ((void)0)
#endif

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define ff first
#define ss second

template <class T> inline constexpr T inf = numeric_limits<T>::max() / 2;
template <class T> bool chmin(T &a, T b) { return (b < a and (a = b, true)); }
template <class T> bool chmax(T &a, T b) { return (a < b and (a = b, true)); }

using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using numbers::pi;

using Bit = bitset<21>;

void solve() {
    vector<string> G(21);
    cin >> G;
    
    int n = 21;
    int ans = 0;
    for (int i = 0; i + 4 <= n; i++)
        for (int j = 0; j + 4 <= n; j++) {
            int s = 0;
            for (int a = i; a < i + 4; a++)
                for (int b = j; b < j + 4; b++)
                    s += G[a][b] == '1';
            chmax(ans, s);
        }

    cout << ans << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }
    
    return 0;
}