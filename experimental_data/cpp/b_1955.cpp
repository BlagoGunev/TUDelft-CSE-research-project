// https://www.youtube.com/watch?v=R0P_f0gXXqs
// I could feel your heartbeat
// I could feel somewhere you’re looking down
// ‘Cause it’s you who I’m loving
// And it’s you that I want in need

#ifndef ONLINE_JUDGE
#include "templates/debug.hpp"
#else
#define debug(...)
#endif

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;

#define int i64
void solve() {
    int n, c, d;
    cin >> n >> c >> d;
    vector<int> a(n * n);
    for (int &x : a) cin >> x;
    ranges::sort(a);
    int f = a[0];
    vector<int> b(n * n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            b[i * n + j] = f + c * i + d * j;
        }
    }
    ranges::sort(b);
    cout << (a == b ? "YES" : "NO") << "\n";
}
#undef int

// 大胆猜想，小心求证 Make bold hypotheses and verify carefully
// - You REALLY need some key observations...
// - Don't trust seemaxgly trival conclusions
// - Do something instead of nothing and stay organized
// - Don't get stuck on one approach
// - Formalization is the death of intuition

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}