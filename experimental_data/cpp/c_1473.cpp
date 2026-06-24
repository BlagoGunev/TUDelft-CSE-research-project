#include <bits/stdc++.h>

#define ll long long
#define endl "\n"
#define ios ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    int x = 2 * k - n - 1;
    if (n == k) {
        for (int i = 1; i <= n; ++ i) cout << i << " ";
        cout << endl;
        return;
    }
    for (int i = 1; i <= x; ++ i) cout << i << " ";
    for (int i = k; i >= x + 1; -- i) cout << i << " ";
    cout << endl;
}

int main() {
    ios
    int tt;
    cin >> tt;
    while(tt --) {
        solve();
    }
    return 0;
}