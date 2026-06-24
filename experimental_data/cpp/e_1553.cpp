#include <bits/stdc++.h>
using namespace std;

int count(vector <int>& v, vector <int>& to) {
    int n = (int)v.size();
    int ans = 0;
    vector <int> used(n);
    for (int i = 0; i < n; i++) {
        if (used[v[i]]) continue;
        int cnt = 0, cur = v[i];
        while (!used[cur]) {
            used[cur] = 1;
            cnt++;
            cur = v[to[cur]];
        }
        ans += cnt - 1;
    }
    return ans;
}

void solve() {
    int n, m; cin >> n >> m;
    vector <int> v(n), cnt(n), to(n), ans;
    for (int& u : v) cin >> u, u--;
    for (int i = 0; i < n; i++) cnt[(i - v[i] + n) % n]++, to[v[i]] = i;
    for (int i = 0; i < n; i++) {
        if (cnt[i] < n / 3) continue;
        int p = 0;
        vector <int> cur(n);
        for (int j = i; j < n; j++) cur[j] = p++;
        for (int j = 0; j < i; j++) cur[j] = p++;
        int cnt = count(cur, to);
        if (cnt <= m) ans.push_back(i);
    }
    cout << (int)ans.size() << ' ';
    for (int u : ans) cout << u << ' ';
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