#include <bits/stdc++.h>
#ifdef SHARAELONG
#include "../../cpp-header/debug.hpp"
#endif
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int x, y;
    cin >> x >> y;
    bool possible = true;
    for (int i=0; i<k; ++i) {
        int xx, yy;
        cin >> xx >> yy;
        if ((x+y) % 2 == (xx+yy) % 2) {
            possible = false;
        }
    }
    cout << (possible ? "YES\n" : "NO\n");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int cases;
    cin >> cases;
    while (cases--) solve();
}