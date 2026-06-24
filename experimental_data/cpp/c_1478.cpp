#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector <int64_t> v(2 * n);
    for (int64_t& u : v) cin >> u;
    sort(v.rbegin(), v.rend());
    int64_t cur = 0;
    for (int i = 0; i < 2 * n; i += 2) {
        if (v[i] != v[i + 1] || (i > 0 && v[i] == v[i - 1])) {
            cout << "NO\n";
            return;
        }
        if ((v[i] - cur) <= 0 || (v[i] - cur) % (2 * (n - i / 2)) != 0) {
            cout << "NO\n";
            return;
        }
        cur += (v[i] - cur) / (n - i / 2);
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}