#include <iostream>
#include <cmath>
#include <cctype>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <deque>
#include <stack>
#include <unordered_set>
#include <sstream>
#include <cstring>
#include <iomanip>
#include <queue>
#include <unordered_map>
#include <random>
#include <cfloat>
#include <chrono>
#include <bitset>
#include <complex>
#include <immintrin.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    
    int32_t n;
    std::cin >> n;

    int32_t* arr = new int32_t[n];
    std::mt19937 rng;
    for(int32_t i = 0; i < (n + 1) / 2; i++)
        std::cin >> arr[i];

    std::cin >> arr[(n + 1) / 2];
    for(int32_t i = (n + 1) / 2 + 1; i < n; i++)
        arr[i] = arr[i - 1];

    int64_t* pref_sums = new int64_t[n + 1];
    pref_sums[0] = 0;
    for(int32_t i = 1; i <= n; i++)
        pref_sums[i] = pref_sums[i - 1] + arr[i - 1];

    int32_t k = 1;
    while(true) {
        int32_t old_k = k;
        for(int32_t i = 0; i < n; i++) {
            while(i < n - k && pref_sums[i + k] - pref_sums[i] <= 0)
                k++;
            while(i >= k && pref_sums[i + 1] - pref_sums[i + 1 - k] <= 0)
                k++;
        }

        bool ok = true;
        for(int32_t i = 0; i < n; i++) {
            if(i <= n - k && pref_sums[i + k] - pref_sums[i] <= 0)
                ok = false;
            if(i + 1 >= k && pref_sums[i + 1] - pref_sums[i + 1 - k] <= 0)
                ok = false;
        }

        if(ok && old_k == k) {
            std::cout << k;
            return 0;
        }
        if(!ok && old_k == k) {
            std::cout << -1;
            return 0;
        }
    }
    return 0;
}