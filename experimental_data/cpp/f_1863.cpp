#include <bits/stdc++.h>

using namespace std;

#define time erpg
#define int long long
#define unll unsigned long long

inline unll highest(unll x) {
    if (x == 0) return 1;
    return (1ll << (64 -__builtin_clzll(x)));
}

void solve() {
    int n;
    cin >> n;
    vector<unll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    if (n == 1) {
        cout << 1 << endl;
        return;
    }
    vector<unll> pr(n + 1);
    for (int i = 0; i < n; ++i) {
        pr[i + 1] = pr[i] ^ a[i];
    }

    vector<unll> beg(n), end(n);

    beg[0] |= highest(pr.back());
    end[n - 1] |= highest(pr.back());

    vector<bool> ans(n);
        // cout << "beg - ";
        // for (auto i : beg) cout << i << " ";
        //     cout << endl;
        // cout << "end - ";
        // for (auto i : end) cout << i << " ";
        //     cout << endl;
        // cout << endl;
    // cout << "pr - ";
    // for (auto i : pr) cout << i << " ";
    //     cout << endl;
    for (int len = n - 2; len >= 0; --len) {
        for (int l = 0; l + len < n; ++l) {
            int r = l + len;
            int xo = pr[r + 1] ^ pr[l];
            unll t = highest(xo);
            if (beg[l] & (xo << 1 | 1)) {
                beg[l] |= t;
                end[r] |= t;
                if (len == 0) ans[l] = true;
                // cout << "left " << xo << " " << l << "..." << r << endl;
            } else if (end[r] & (xo << 1 | 1)) {
                beg[l] |= t;
                end[r] |= t;
                if (len == 0) ans[l] = true;
                // cout << "right " << xo << " " << l << "..." << r << endl;
            }
            // if (l == 1 && r == 6) {
            //     cout << "                lulz " << (beg[l]) << " " << (xo << 1 | 1) << endl;
            // }
        }
        // cout << "len - " << len << endl;
        // cout << "beg - ";
        // for (auto i : beg) cout << i << " ";
        //     cout << endl;
        // cout << "end - ";
        // for (auto i : end) cout << i << " ";
        //     cout << endl;
        //     cout << endl;
    }
    for (int i = 0; i < n; ++i) cout << ans[i];
        cout << endl;
}

signed main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) solve();
}