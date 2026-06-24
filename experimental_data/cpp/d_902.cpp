#include <iostream>
#include <vector>

int main() {
    std::size_t m;
    std::cin >> m;

    std::vector<long long> a = { 1, 0 };
    std::vector<long long> b = { 1 };

    for (std::size_t i = 1; i < m; ++i) {
        auto temp = b;
        b = a;
        a.push_back(0);

        bool neg = false;

        for (std::size_t j = 0; j < i; ++j) {
            a[j + 2] += temp[j];
            if (a[j + 2] < -1 || a[j + 2] > 1) {
                neg = true;
            }
        }
        if (neg) {
            for (std::size_t j = 0; j < i; ++j) {
                a[j + 2] -= 2 * temp[j];
            }
        }
    }

    std::cout << m << "\n";
    for (std::size_t i = 0; i <= m; ++i) {
        std::cout << a[m - i] << " ";
    }
    std::cout << "\n";
    std::cout << m - 1 << "\n";
    for (std::size_t i = 0; i <= m - 1; ++i) {
        std::cout << b[m - 1 - i] << " ";
    }
    std::cout << "\n";
}