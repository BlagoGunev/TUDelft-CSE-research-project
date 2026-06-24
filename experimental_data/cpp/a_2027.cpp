#include <bits/stdc++.h>

using namespace std;

#define ll long long


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tt;
    cin >> tt;

    while (tt--) {
        int n;
        cin >> n;

        ll x = 0, y = 0;

        for (int i = 0; i < n; i++) {
            ll w, h;
            cin >> w >> h;

            x = max(x, w);
            y = max(y, h);
        }

        cout << (x + y) * 2  << endl;
    }

    return 0;
}