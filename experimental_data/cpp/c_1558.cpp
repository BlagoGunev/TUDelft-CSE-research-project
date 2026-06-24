#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector <int> v(n), ans;
    for (int& u : v) cin >> u;
    for (int i = 0; i < n; i++) {
        if (v[i] % 2 == i % 2) {
            cout << -1 << '\n';
            return;
        }
    }
    for (int p = n; p > 1; p -= 2) {
        for (int i = 0; i < n; i += 2) {
            if (v[i] == p) {
                ans.push_back(i + 1);
                reverse(v.begin(), v.begin() + i + 1);
                break;
            }
        }
        for (int i = 1; i < n; i += 2) {
            if (v[i] == p - 1) {
                ans.push_back(i);
                reverse(v.begin(), v.begin() + i);
                break;
            }
        }
        for (int i = 0; i < n; i += 2) {
            if (v[i] == p) {
                ans.push_back(i + 3);
                reverse(v.begin(), v.begin() + i + 3);
                break;
            }
        }
        ans.push_back(3);
        reverse(v.begin(), v.begin() + 3);
        ans.push_back(p);
        reverse(v.begin(), v.begin() + p);
    }
    cout << (int)ans.size() << '\n';
    for (auto u : ans) cout << u << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}