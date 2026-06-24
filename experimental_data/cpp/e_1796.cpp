#include <bits/stdc++.h>
using namespace std;

#ifdef XOX
#include "../debug.hpp"
#else
#define debug(...) (void)0
#endif

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }
auto rae(auto x, auto y) { return ra(x, y + 1); }
using i64 = int64_t;

void solve() {
    int n;
    cin >> n;
    vector g(n, vector<int>());
    for (auto _ : ra(0, n - 1)) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }

    multiset<int> done{numeric_limits<int>::max()}; // stores discontinued paths
    vector paths(n, multiset<int>());
    auto shortest = [&](int u) -> int {
        auto &s = paths[u];
        if (empty(s)) {
            return 1;
        }
        return *begin(s) + 1;
    };
    auto second = [&](int u) {
        auto &s = paths[u];
        if (ssize(s) < 2) {
            return numeric_limits<int>::max();
        }
        return *next(begin(s));
    };
    auto dfs_ans = [&](auto &&self, int u, int p) -> void {
        for (auto to : g[u]) {
            if (to == p) {
                continue;
            }
            self(self, to, u);
            paths[u].emplace(shortest(to));
        }
        if (ssize(paths[u]) > 1) {
            done.emplace(second(u));
        }
    };
    dfs_ans(dfs_ans, 0, -1);

    int ans = 0;
    auto dfs_reroot = [&](auto &&self, int u, int p) -> void {
        ans = max(ans,
                  min(shortest(u), *begin(done)));

        for (auto to : g[u]) {
            if (to == p) {
                continue;
            }
            // ide do to
            done.extract(second(u));
            paths[u].extract(shortest(to));
            done.emplace(second(u));

            done.extract(second(to));
            paths[to].emplace(shortest(u));
            done.emplace(second(to));

            self(self, to, u);

            // wrocilem
            done.extract(second(to));
            paths[to].extract(shortest(u));
            done.emplace(second(to));

            done.extract(second(u));
            paths[u].emplace(shortest(to));
            done.emplace(second(u));
        }
    };
    dfs_reroot(dfs_reroot, 0, -1);
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        debug(tc);
        solve();
    }
}