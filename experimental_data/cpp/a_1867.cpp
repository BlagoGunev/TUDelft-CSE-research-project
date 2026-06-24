#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <utility>
#include <algorithm>
#include <map>
#include <numeric>
#include <stack>
#include <cstdint>
#include <queue>

using ll = long long;
using ull = unsigned long long;


void solve()
{   
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1), b;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    b = a;
    std::sort(b.begin(), b.end());
    std::map<int, std::queue<int>> map;
    for (int i = 1; i <= n; ++i)
    {
        int el = b[i];
        map[el].push(n - i + 1);

    }
    for (int i = 1; i <= n; ++i)
    {
        std::cout << map[a[i]].front() << ' ';
        map[a[i]].pop();
    }
    std::cout << '\n';
}

int main()
{   
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt; std::cin >> tt;
    
    while (tt--)
    {   
        solve();
    }
    return 0;
}