#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    int c[n], cnt[n + 1];
    for (int i = 0; i < n; i++) cin >> c[i];
    for (int i = 0; i <= n; i++) cnt[i] = 0;
    for (int i = 0; i < n; i++) cnt[c[i]]++;
    int c3 = 0, c2 = 0, c1 = 0;
    for (int i = 1; i <= n; i++) {
        if (cnt[i] >= 3) c3++;
        else if (cnt[i] >= 2) c2++;
        else if (cnt[i] >= 1) c1++;
    }
    int points = (c1 + 1) / 2 * 2 + c2 + c3;
    cout << points << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}