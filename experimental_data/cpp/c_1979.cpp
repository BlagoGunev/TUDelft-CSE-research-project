#include <bits/stdc++.h>
#ifdef SHARAELONG
#include "../../cpp-header/debug.hpp"
#endif
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve() {
    int n;
    cin >> n;
    vector<int> k(n);
    for (int& x: k) cin >> x;

    const int LCM = 19 * 17 * 13 * 11 * 7 * 5 * 9 * 16;
    ll sum = 0;
    for (int i=0; i<n; ++i) sum += LCM / k[i];
    if (sum >= LCM) {
        cout << -1 << '\n';
    } else {
        for (int i=0; i<n; ++i) cout << LCM / k[i] << ' ';
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int cases;
    cin >> cases;
    while (cases--) solve();
}