#include <bits/stdc++.h>

using namespace std;

#define int long long
using pii = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), dd(n), d(n), ans(n);
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) a[i] = b[(i * 2) % n];
    
    for (int i = 0; i < n; i++) {
        dd[(i + n / 2 - 1) % n] -= a[i];
        dd[(i + n / 2) % n] -= a[i];
        dd[(i + n - 1) % n] += 2 * a[i];
        if (i + n / 2 + 1 <= n && n < i + n) d[0] -= a[i];
        else if (i == 0 || i <= n && n < i + n / 2) d[0] += a[i];
    }

    for (int i = 0; i < n - 1; i++) {
        d[i + 1] = d[i] + dd[i];
    }

    /*for (int i = 0; i < n; i++) {
        for (int j = 0; j < n / 2; j++) {
            d_[(i + j + n / 2 + 1) % n] -= a[i];
        }
        for (int j = n / 2; j < n - 1; j++) {
            d_[(i + j + n / 2 + 1) % n] += a[i];
        }
    }*/

    for (int i = 0; i < n - 1; i++) {
        ans[i + 1] = ans[i] + d[i];
    }

    int mn = *min_element(ans.begin(), ans.end());
    for (int i = 0; i < n; i++) ans[i] -= mn;

    vector<int> out(n);
    for (int i = 0; i < n; i++) out[(i * 2) % n] = ans[i];

    for (int i = 0; i < n; i++) cout << out[i] << " ";
    cout << "\n";
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}