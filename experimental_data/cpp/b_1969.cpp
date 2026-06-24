#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

using namespace std;

const ll mod = 998244353;


void solve() {
    string x;
    cin >> x;
    ll ans = 0;
    ll last0 = 0;
    ll n = x.size();
    for (ll i = 0; i < n; i += 1) {
        if (x[i] == '0') {
            if(i == last0){
                last0 += 1;
                continue;
            }
            ans += i - last0 + 1;
            last0 += 1;
        }
    }
    cout << ans << '\n';
}

/*


 */

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}