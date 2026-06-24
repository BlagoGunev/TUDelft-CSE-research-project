#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector <pair <int, int>> v = {{s[0], 1}};
    for (int i = 1; i < n; i++) {
        if (s[i] == v.back().first) v.back().second++;
        else v.push_back({s[i], 1});
    }
    if ((int)v.size() == 1) {
        cout << (v[0].second <= 2 ? 0 : (v[0].second + 2) / 3) << '\n';
        return;
    }
    if (v.back().first == v[0].first) {
        v[0].second += v.back().second;
        v.pop_back();
    }
    int ans = 0;
    for (auto u : v) ans += u.second / 3;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}