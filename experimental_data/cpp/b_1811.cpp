#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, X1, Y1, X2, Y2;
    cin >> N >> X1 >> Y1 >> X2 >> Y2;
    int ans1 = min({X1, Y1, N + 1 - X1, N + 1 - Y1});
    int ans2 = min({X2, Y2, N + 1 - X2, N + 1 - Y2});
    cout << abs(ans1 - ans2) << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T; 
    while (T--) solve();
    return 0;
}