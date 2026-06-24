#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 2e5 + 5;

void solve() {
    string s;
    cin >> s;
    bool ok = false;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i - 1] == s[i]) {
            ok = true;
        }
    }
    if (ok) {
        cout << 1 << endl;
    } else {
        cout << s.size() << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
//    freopen("taskA.in", "r", stdin);
//    freopen("taskA.out", "w", stdout);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}