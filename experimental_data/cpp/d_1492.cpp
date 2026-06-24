// https://codeforces.com/problemset/problem/1492/D

#include <iostream>
#include <string>
#include <utility>

std::pair<std::string, std::string> solve(
    int zero_count, int one_count, int result_one_count)
{
    const auto first = std::string(one_count, '1') + std::string(zero_count, '0');
    std::string second = first;
    int idx = one_count - 1;
    const int shift = std::min(result_one_count, zero_count);
    std::swap(second[idx], second[idx + shift]); 
    result_one_count -= shift;
    --idx;
    for (; result_one_count > 0; --result_one_count, --idx) {
        std::swap(second[idx], second[idx + 1]);
    }
    return {first, second};
}

int main() {
    std::ios::sync_with_stdio(false);

    int zero_count, one_count, result_one_count;
    std::cin >> zero_count >> one_count >> result_one_count;
    if (result_one_count == 0 || (zero_count > 0 && one_count > 1 && result_one_count <= zero_count + one_count - 2)) {
        std::cout << "YES\n";
        const auto [first, second] = solve(zero_count, one_count, result_one_count);
        std::cout << first << "\n";
        std::cout << second << "\n";
    } else {
        std::cout << "NO\n";
    }

    return 0;
}