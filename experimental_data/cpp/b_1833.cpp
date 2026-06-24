#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <stack>
#include <cstring>
#include <cmath>
#include <numeric>
#include <set>
#include <unordered_map>
#include <algorithm>
using namespace std;

#define int long long
#define endl "\n"

const long long modulo = 1e9 + 7;

void solve() {
    int t, k; cin >> t >> k;
    vector<int> a(t), b(t), ord(t), ans(t);
    iota(ord.begin(), ord.end(), 0);
    for (int i = 0; i < t; i++) cin >> a[i];
    for (int i = 0; i < t; i++) cin >> b[i];
    sort(b.begin(), b.end());
    sort(ord.begin(), ord.end(), [&](int x, int y) { return a[x] < a[y]; });
    for (int i = 0; i < t; i++) {
        ans[ord[i]] = b[i];
    }
    for (int i = 0; i < t; i++) cout << ans[i] << " ";
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t; cin >> t; int kase = 0;
    while (t--) {
        // cout << "Case #" << ++kase << ": ";
        solve();
    }
    return 0;
}