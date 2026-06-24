/*
    Code by: KoKoDuDu
    Created: 01.12.2024 12:31:32
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    string s, t;
    cin >> s >> t;
    if (s.size() == 1 || t.size() == 1) {
        cout << -1;
        return;
    }
    vector<int> save(26, -1);
    for (int i = 1; i < s.size(); ++i) {
        if (save[s[i] - 'a'] == -1) {
            save[s[i] - 'a'] = i;
        }
    }
    int best = MOD, pos_s = -1, pos_t = -1;
    for (int i = (int)t.size() - 2; i >= 0; --i) {
        if (save[t[i] - 'a'] != -1) {
            if (best > save[t[i] - 'a'] + (int)t.size() - i + 1) {
                best = save[t[i] - 'a'] + (int)t.size() - i + 1;
                pos_s = save[t[i] - 'a'];
                pos_t = i;
            }
        }
    }
    if (pos_s == -1 || pos_t == -1) {
        cout << -1;
        return;
    }
    for (int j = 0; j < pos_s; ++j) {
        cout << s[j];
    }
    for (int j = pos_t; j < t.size(); ++j) {
        cout << t[j];
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}