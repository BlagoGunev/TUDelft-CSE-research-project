#include <bits/stdc++.h>

using namespace std;

void solve() {

    int n;

    cin >> n;

    vector<int> a(n);

    for(auto &x : a) cin >> x;

    int ans = 0;

    for(int bit = 0; bit < 30; bit ++) {

        bool fg1 = false, fg2 = false;

        for(int i = 0; i < n; i ++) {

            if(a[i] & (1 << bit)) fg1 = true;

            else fg2 = true;

        }

        if(fg1 && fg2) ans += (1 << bit);

    }

    cout << ans << '\n';

}



int main() {

    int tc;

    ios::sync_with_stdio(0);

    cin.tie(0), cout.tie(0);

    cin >> tc;

    for(; tc; tc --) solve();

}