#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b) - 1; i >= (a); --i)

typedef long long ll;

constexpr int mod = 998'244'353;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (auto &x : a)
            cin >> x;
        int mx = *max_element(a.begin(), a.end());
        int count = 0;
        for (auto x : a)
            if (mx == x)
                ++count;

        int ans = 0;
        if (count > 1) {
            ll f = 1;
            for (int i = 1; i <= n; ++i)
                f = f * i % mod;
            ans = f;
        } else {
            int second_mx = 0;
            for (auto x : a)
                if (mx != x)
                    second_mx = max(second_mx, x);
            if (mx - second_mx > 1) ans = 0;
            else {
                for (auto x : a)
                    if (second_mx == x)
                        ++count;
                
                ll f = count - 1;
                for (int i = 1; i <= n; ++i)
                    if (i != count)
                        f = f * i % mod;
                ans = f;
            }
        }

        cout << ans << '\n';
    }
}