#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
#define log(x) (63^__bulitin_clzll(x))
mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    for(int k = n; k >= 1; --k) {
        vector<int> a(n);
        for(int i = 0; i < n; ++i) a[i] = s[i] - '0';

        vector<int> inv(n, 0);
        int x = 0, ok = 1;

        for(int i = 0; i < n; ++i) {
            x += inv[i];
            x %= 2;
            if(x) a[i] = !a[i];
            if(a[i] == 0) {
                if(i + k - 1 < n) {
                    ++x;
                    if(i + k < n) ++inv[i + k];
                }
                else ok = 0;
            }    
        }

        if(ok) {
            cout << k << endl;
            return;
        }
    }

    return;
}

main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int t = 1;
    cin >> t;
    while(t--) solve();

    return 0;
}