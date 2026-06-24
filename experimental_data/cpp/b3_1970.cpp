#include <bits/stdc++.h>

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define dbg(...) ;
#define timer(...) ;
#endif

#define nl '\n'

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<std::array<int, 2>> a(n + 1);
    std::map<int, std::vector<int>> mp;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i][0];
        a[i][1] = i;
        mp[a[i][0]].push_back(i);
    }
    std::sort(a.begin() + 1, a.end());

    std::vector<std::array<int, 2>> where(n + 1);
    std::vector<int> with(n + 1);

    auto run_normal = [&](int from) {
        for (int i = from; i <= n; i++) {
            auto& [x, y] = where[a[i][1]];
            x = i;
            if (a[i][0] == 0) {
                with[a[i][1]] = a[i][1];
                y = i;
            } else {
                if (a[i][0] >= i) {
                    with[a[i][1]] = a[1][1];
                    y = where[a[1][1]][1] + (a[i][0] - i) + 1;
                } else {
                    with[a[i][1]] = a[i - a[i][0]][1];
                    y = where[a[i - a[i][0]][1]][1];
                }
            }
        }
    };

    if (a[1][0] == 0) {
        where[a[1][1]] = {1, 1};
        with[a[1][1]] = a[1][1];
        run_normal(2);
    } else {
        if ((int) mp.size() == n) {
            if (n == 2) {
                std::cout << "NO" << nl;
                return 0;
            } else {
                with[a[1][1]] = a[2][1];
                with[a[2][1]] = a[3][1];
                with[a[3][1]] = a[1][1];
                where[a[1][1]] = {1, 1};
                where[a[2][1]] = {2, 1};
                where[a[3][1]] = {3, 2};
                run_normal(4);
            }
        } else {
            for (int i = 1; i + 1 <= n; i++) {
                if (a[i][0] == a[i + 1][0]) {
                    // we met good stuff
                    std::swap(a[1], a[i]);
                    std::swap(a[2], a[i + 1]);
                }
            }

            with[a[1][1]] = a[2][1];
            with[a[2][1]] = a[1][1];
            where[a[1][1]] = {1, 1};
            where[a[2][1]] = {2, 0};
            if (a[2][0] >= 2) {
                where[a[2][1]][1] = where[a[1][1]][1] + (a[2][0] - 2) + 1;
            } else {
                where[a[2][1]][1] = where[a[2 - a[2][0]][1]][1];
            }
            run_normal(3);
        }
    }


    std::cout << "YES" << nl;
    for (int i = 1; i <= n; i++) {
        std::cout << where[i][0] << " " << where[i][1] << nl;
    }

    for (int i = 1; i <= n; i++) {
        std::cout << with[i] << " ";
    }
    std::cout << nl;
}