// In the name of GOD

#include <bits/stdc++.h>

using namespace std;

#define sz(x) (int) x.size()
#define all(x) x.begin(), x.end()

typedef long long ll;

const int N = 1e5 + 5;
const int M = 1e9 + 7;

int x, y, k;
void solve() {
    cin >> x >> y >> k;
    if (y <= x) {
        cout << x << '\n';
    } else {
        if (x + k >= y) {
            cout << y << '\n';
        } else {
            cout << y + (y - (x + k)) << '\n';
        }
    }
}

int main() {
    ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
    }
}