#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    auto solve = [&]() {
        int n;
        i64 k;
        cin >> n >> k;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());
        i64 sum = accumulate(a.begin(), a.end(), 0LL);
        i64 ans = max(0LL, sum - k);

        for (int i = n - 1; i > 0; i--) {
            sum -= a[i] - a[0];
            ans = min(ans, n - i + (max(0LL, sum - k) + n - i) / (n - i + 1));
        }

        cout << ans << '\n';
    };

    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}