#include<bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    if (count(s.begin(), s.end(), 'a') == s.size()) {
        cout << s.size() - 1 << '\n';
        return;
    }
    vector<vector<int>> pos(26);
    for (int i = 0; i < s.size(); ++i) {
        pos[s[i] - 'a'].push_back(i);
    }
    int g = 0;
    for (int i = 1; i < 26; ++i) g = gcd(g, pos[i].size());
    ll ans = 0;
    for (int occ = 1; occ <= n; ++occ) {
        if (g % occ == 0) {
            int i = 0;
            while (s[i] == 'a') ++i;
            vector<int> need(26);
            for (int c = 0; c < 26; ++c) need[c] = pos[c].size() / occ;
            int j;
            for (j = i; *max_element(need.begin() + 1, need.end()) > 0; ++j) {
                need[s[j] - 'a']--;
            }
            if (*min_element( need.begin() + 1, need.end()) < 0) continue;
            string t(s.begin() + i, s.begin() + j);
//            cout << t << endl;
            vector<int> occ = {i};
            bool ok = true;
            for (; j < n; ++j) {
                if (s[j] == 'a') continue;
                if (j + t.size() > n || s.substr(j, t.size()) != t) {
                    ok = false;
                    break;
                } else {
                    occ.push_back(j);
                    j += t.size() - 1;
                }
            }
            if (!ok) continue;
            int left_bound = occ[0], sum_bound = n, right_bound = n - occ.back() - t.size();
            for (int i = 0; i + 1 < occ.size(); ++i) {
                sum_bound = min(sum_bound, occ[i + 1] - occ[i] - (int)t.size());
            }
            for (int left = 0; left <= left_bound && left <= sum_bound; ++left) {
                int right = min(sum_bound - left, right_bound);
                ans += right + 1;
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    int tests;
    cin >> tests;
    while (tests--) {
        solve();
    }
}