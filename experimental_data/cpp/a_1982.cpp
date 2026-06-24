#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
#endif

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
//#define int long long

void solve() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << ((a - b) * (c - d) <= 0 ? "NO" : "YES");
}

void Fast() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Fast();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }
}