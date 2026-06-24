#include <algorithm>
#include <array>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <ostream>
#include <queue>
#include <ranges>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>
const int N = 1e6 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
// #define int long long
using PII = std::pair<int, int>;
using LL = int64_t;
// struct Edge
// {
//     int to, w;
//     int next;
// } edge[N];
// int head[N], cnt_;
// void add_edge(int from, int to, int w)
// {
//     edge[++cnt_] = {to, w, head[from]};
//     head[from] = cnt_;
// }

int dir[4][2]{
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1},
};

void solve()
{
    int n;
    std::cin >> n;
    std::string s, ans;
    std::cin >> s;
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += s[i] - '0';
    int ca = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int now = (sum + ca) % 10;
        ans.append(std::to_string(now));
        ca = (sum + ca) / 10;
        sum -= (s[i] - '0');
    }
    if (ca)
        ans.append(std::to_string(ca));

    while (!ans.empty() && ans.back() == '0')
        ans.pop_back();

    std::reverse(ans.begin(), ans.end());
    std::cout << ans << "\n";
}
auto main() -> int32_t
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    //   std::cout.tie(nullptr)->sync_with_stdio(false);
    int _ = 1;
    std::cin >> _;
    while (_--)
    {
        solve();
    }
}