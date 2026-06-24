#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int ans = 0;
    for (int i = 1; i < n - 1; ++i) {
        if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
            if (i < n - 2) {
                a[i + 1] = max(a[i], a[i + 2]);
            } else {
                a[i + 1] = a[i];
            }
            ans++;
        }
    }

    cout << ans << "\n";
    for (int ai: a) {
        cout << ai << " ";
    }
    cout << "\n";
}

int main() {
#ifndef NEKSTAS
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#endif

    int t = 1;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
}