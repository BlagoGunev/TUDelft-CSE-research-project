#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("tune=native")
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    for(int i = 0; i < n; i++) {
        if(a[i] == '0' && b[i] == '1') {
            cout << "NO\n";
            return;
        } else if(a[i] == '1') {
            break;
        }
    }
    cout << "YES\n";
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}