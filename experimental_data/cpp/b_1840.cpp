#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n, k;
    cin >> n >> k;
    if (k > 40) {
        cout << n + 1 << endl;
    } else {
        cout << min(n + 1, 1LL << k) << endl;
    }
}

int main() {
    int t;
    cin >> t;
    for (; t--;) solve();
}