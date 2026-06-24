#include <bits/extc++.h>

using i64 = long long;

template<typename Info>
using orderedSet = __gnu_pbds::tree<Info, __gnu_pbds::null_type, std::less<Info>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

void solve() {
    int n, c;
    std::cin >> n >> c;
    std::vector<int> s(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }
    i64 res = 1LL * c * (c + 1) / 2 + c + 1;
    for (int i = n - 1; i > -1; i--) {
        res -= c - s[i] + 1;
        res -= s[i] / 2 + 1;
    }
    std::vector<std::vector<int>> t(2);
    for (int i = 0; i < n; i++) {
        t[s[i] % 2].emplace_back(s[i]);
    }
    for (int i = n - 1; i > -1; i--) {
        int p = s[i] % 2;
        auto itl = std::lower_bound(t[p].begin(), t[p].end(), s[i]);
        auto itr = --std::upper_bound(t[p].begin(), t[p].end(), 2 * c - s[i]);
        res += itr - itl + 1;
    }
    std::cout << res << "\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("/home/q1n/coding/input.txt", "r", stdin);
        freopen("/home/q1n/coding/output.txt", "w", stdout);
    #else
        // online submission
    #endif

    int t = 1;
    std::cin >> t;

    while (t--) {
        solve();
    }
}