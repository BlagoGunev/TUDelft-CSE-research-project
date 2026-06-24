#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <deque>
//#include <bits/stdc++.h>
using namespace std;

#define int long long


void solve() {
    string a, b;
    cin >> a >> b;
    int n = a.size();
    int m = b.size();
    int ans = n + m;
    for (int i = 0; i < m; i++) {
        int k = i;
        int cnt = n + m;
        for (int j = 0; j < n; j++)
        {
            if (a[j] == b[k]) {
                k++;
                cnt--;
                if (k == m)
                    break;
            }
        }
        ans = min(ans, cnt);
    }
    cout << ans << "\n";
}

signed main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}