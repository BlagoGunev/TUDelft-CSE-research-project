// #pragma GCC optimize("O3,unroll-loops,inline")

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

int f(int i) {
    if (i == 0)
        return 1;
    return i * f(i - 1);
}

void solve() {
    int n, d;
    cin >> n >> d;
    cout << 1 << ' ';
    if (d % 3 == 0 || n >= 3 || f(n) * d % 3 == 0)
        cout << 3 << ' ';
    if (d == 0 || d == 5)
        cout << 5 << ' ';
    if (n >= 3 || (d * 10 + d) % 7 == 0)
        cout << 7 << ' ';
    if (d % 9 == 0 || n >= 9 || f(n) * d % 9 == 0)
        cout << 9;
    cout << '\n';
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}