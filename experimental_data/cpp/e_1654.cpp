/**
 * the_hyp0cr1t3
 * 26.07.2022 16:38:46
**/
#ifdef W
    #include <k_II.h>
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif

#include <ext/pb_ds/assoc_container.hpp>
namespace Hashing {
    using hash_t = pair<int, uint64_t>;
    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();

    struct custom_hash {
        static uint64_t splitmix64(uint64_t x) {
            x += 0x9e3779b97f4a7c15;
            x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
            x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
            return x ^ (x >> 31);
        }
        size_t operator()(uint64_t x) const { return splitmix64(x + FIXED_RANDOM); }
        size_t operator()(const hash_t& x) const { return splitmix64(FIXED_RANDOM + x.second) ^ (splitmix64(FIXED_RANDOM + x.first) << 1); }
    };

    template<typename K, typename V, typename Hash = custom_hash>
    using hash_map = __gnu_pbds::gp_hash_table<K, V, Hash>;

    template<typename K, typename Hash = custom_hash>
    using hash_set = hash_map<K, __gnu_pbds::null_type, Hash>;

} using namespace Hashing;

int main() {
#if __cplusplus > 201703L
    namespace R = ranges;
#endif
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    constexpr int N = 1e5 + 5;
    constexpr int SQRT = sqrt(N) + 1;
    constexpr int NROOT = N * SQRT;

    array<int, 2 * NROOT + N> cnt{};

    int n; cin >> n;
    vector<int> a(n);
    for(auto &x: a) cin >> x;

    int ans = 1;
    for(auto _: {0, 1}) {

        {   // d < sqrt
            for(int d = 0; d <= SQRT; d++) {
                for(int i = 0; i < n; i++)
                    cnt[a[i] - d * i + NROOT]++;
                for(int i = 0; i < n; i++)
                    ans = max(ans, cnt[a[i] - d * i + NROOT]--);
            }
        }

        {   // d > sqrt
            for(int i = 0; i < n; i++) {
                for(int j = 1; j <= SQRT; j++) {
                    if(i - j >= 0 and (a[i] - a[i - j]) % j == 0)
                        cnt[(a[i] - a[i - j]) / j + NROOT]++;
                    if(i + j < n and (a[i + j] - a[i]) % j == 0)
                        cnt[(a[i + j] - a[i]) / j + NROOT]++;
                }
                for(int j = 1; j <= SQRT; j++) {
                    if(i - j >= 0 and (a[i] - a[i - j]) % j == 0)
                        ans = max(ans, cnt[(a[i] - a[i - j]) / j + NROOT]-- + 1);
                    if(i + j < n and (a[i + j] - a[i]) % j == 0)
                        ans = max(ans, cnt[(a[i + j] - a[i]) / j + NROOT]-- + 1);
                }
            }
        }

        R::reverse(a);
    }

    cout << n - ans;
} // ~W