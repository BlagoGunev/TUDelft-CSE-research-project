#include <bits/stdc++.h>



using i64 = long long;



int main() {

    std::ios::sync_with_stdio(false);

    std::cin.tie(nullptr);

    

    int n;

    std::cin >> n;

    

    std::vector<int> x(n), y(n);

    for (int i = 0; i < n; i++) {

        std::cin >> x[i] >> y[i];

    }

    

    if (n % 2) {

        std::cout << "NO\n";

        return 0;

    }

    

    auto dis = [&](int i, int j) {

        return (x[i] - x[j]) * 1LL * (x[i] - x[j]) + (y[i] - y[j]) * 1LL * (y[i] - y[j]);

    };

    

    for (int i = 1, j = n / 2 + 1; i < n / 2; i++, j++) {

        if (dis(0, i) != dis(n / 2, j) || dis(n / 2, i) != dis(0, j)) {

            std::cout << "NO\n";

            return 0;

        }

    }

    

    std::cout << "YES\n";

    

    return 0;

}