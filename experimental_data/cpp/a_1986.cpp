#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 2e5 + 5;

void solve() {
    vector<int> a(3);
    cin >> a[0] >> a[1] >> a[2];
    sort(a.begin(), a.end());
    cout << a[1] - a[0] + a[2] - a[1] << endl;
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