#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;

    for(int i = 0; i < 2 * n; i++) {
        for(int j = 0; j < 2 * n; j++) {
            int a = i / 2, b = j / 2;
            if((a + b) % 2 == 0) {
                std::cout << '#';
            } else {
                std::cout << '.';
            }
        }
        std::cout << "\n";
    }
    
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1; std::cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }

    return 0;
}