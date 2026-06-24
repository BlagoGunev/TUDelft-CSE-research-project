#include <iostream>

using namespace std;

void solve() {
    int x, y;
    cin >>  x >> y;
    if (y % x == 0) {
        cout << 1 << ' ' << double(y) / double(x) << '\n';
    } else cout << "0 0\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--)
        solve();
    return 0;
}