#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef long long ll;
typedef long double ld;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define ar(x) array<int, x>

ar(2) doublemex(vector<int> a) {
    set<int> q;
    for (auto el: a)q.insert(el);
    int mex1 = 0;
    while (q.find(mex1) != q.end())mex1++;
    int mex2 = mex1 + 1;
    while (q.find(mex2) != q.end())mex2++;
    return {mex1, mex2};
}

int range_sum(int l, int r) {
    return (l + r) * (r - l + 1) / 2;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<ar(2) > a(n);
    int kek = 0;
    for (int i = 0; i < n; i++) {
        int l;
        cin >> l;
        vector<int> b(l);
        for (auto &x: b) cin >> x;
        a[i] = doublemex(b);
        kek = max(kek, a[i][1]);
    }
    int ans = 0;
    if (kek >= m) {
        ans += (m + 1) * kek;
    } else {
        ans += kek * (kek + 1);
        ans += range_sum(kek + 1, m);
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}