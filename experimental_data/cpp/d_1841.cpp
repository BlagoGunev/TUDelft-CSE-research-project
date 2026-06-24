#include <bits/stdc++.h>




namespace zawa {

using i16 = std::int16_t;
using i32 = std::int32_t;
using i64 = std::int64_t;
using i128 = __int128_t;

using u8 = std::uint8_t;
using u16 = std::uint16_t;
using u32 = std::uint32_t;
using u64 = std::uint64_t;

using usize = std::size_t;

} // namespace zawa


namespace zawa {

void SetFastIO() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
}

void SetPrecision(u32 dig) {
    std::cout << std::fixed << std::setprecision(dig);
}

} // namespace zawa
using namespace zawa;

bool Intersect(const std::pair<int, int>& i, const std::pair<int, int>& j) {
    return not (i.first < j.second or j.first < i.second);
}

int brute(const std::vector<std::pair<int, int>>& RL) {
    int n{(int)RL.size()};
    int ans{n};
    for (int bit{} ; bit < (1 << n) ; bit++) {
        if (std::popcount((unsigned)bit) % 2) continue;
        std::vector<int> use;
        for (int i{} ; i < n ; i++) if (bit & (1 << i)) use.push_back(i);
        std::vector<std::vector<int>> g(use.size());
        for (int i{} ; i < (int)use.size() ; i++) {
            for (int j{i + 1} ; j < (int)use.size() ; j++) {
                if (Intersect(RL[use[i]], RL[use[j]])) {
                    g[i].emplace_back(j);
                    g[j].emplace_back(i);
                }
            }
        }
        std::vector<bool> vis(use.size());
        int cnt{};
        auto dfs{[&](auto dfs, int v) -> void {
            cnt++;
            vis[v] = true;
            for (auto x : g[v]) if (!vis[x]) {
                dfs(dfs, x);
            }
        }};
        bool ok{true};
        for (int i{} ; i < (int)vis.size() ; i++) {
            if (vis[i]) continue;
            cnt = 0;
            dfs(dfs, i);
            if (cnt != 2) ok = false;
        }
        if (ok) ans = std::min(ans, n - (int)std::popcount((unsigned)bit));
    }
    return ans;
}

int solve() {
    std::mt19937 mt{std::random_device{}()};
    int n;
    std::cin >> n;
    // n = mt() % 5 + 1;
    std::vector<std::pair<int, int>> RL(n);
    for (auto& [R, L] : RL) std::cin >> L >> R;
    // for (auto& [R, L] : RL) {
        // R = mt() % 20;
        // L = mt() % 20;
        // if (R < L) std::swap(L, R);
    // }
    std::vector g(n, std::vector<bool>(n));
    for (int i{} ; i < n ; i++) {
        for (int j{i + 1} ; j < n ; j++) {
            if (Intersect(RL[i], RL[j])) {
                g[i][j] = true;
            }
        }
    }
    using qt = std::tuple<int, int, int>;
    std::priority_queue<qt, std::vector<qt>, std::greater<qt>> que;
    for (int i{} ; i < n ; i++) {
        for (int j{i + 1} ; j < n ; j++) {
            if (g[i][j]) {
                que.emplace(std::max(RL[i].first, RL[j].first), i, j); 
            }
        }
    }
    std::vector<bool> del(n);
    int ans{n};
    while (que.size()) {
        auto [_, i, j]{que.top()};
        que.pop();
        if (del[i] or del[j]) continue;
        ans -= 2;
        for (int k{} ; k < n ; k++) {
            if (del[k]) continue;
            if (g[i][k] or g[k][i]) del[k] = true;
            if (g[j][k] or g[k][j]) del[k] = true;
        }
    }
    // if (ans != brute(RL)) {
    //     for (auto [R, L] : RL) std::cout << L << ' ' << R << std::endl;
    //     std::cout << "you " << ans << std::endl;
    //     std::cout << "tak " << brute(RL) << std::endl;
    //     exit(0);
    // }
    return ans;
}
    
int main() {
    SetFastIO();

    int t; std::cin >> t;
    while (t--) {
        std::cout << solve() << '\n';
        // std::cout << solve() << std::endl;
    }
}